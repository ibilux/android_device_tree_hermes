#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cutils/properties.h>
#include <sys/wait.h>

#define LOG_TAG "md_ctrl"
#include <cutils/log.h>
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <poll.h>

#define ARRAY_SIZE(x)   (sizeof(x) / sizeof(*(x)))
static void
usage(void)
{
    fprintf(stderr, "%s\n%s\n",
        "usage: md_ctrl 0,   stop modem",
        "       md_ctrl 1,   start modem");
    exit(1);
}

static void do_log_line(char *btag, char *line) {
  ALOG(LOG_INFO, btag, "%s", line);
}

static int parent(char *tag, int parent_read, pid_t pid, int *chld_sts) {
    int status = 0;
    char buffer[4096];
    struct pollfd poll_fds[] = {
        [0] = {
            .fd = parent_read,
            .events = POLLIN,
        },
    };
    int rc = 0;
    int ret = 0;
    int fd;

    int a = 0;  // start index of unprocessed data
    int b = 0;  // end index of unprocessed data
    int sz;
    bool found_child = false;
    char tmpbuf[256];

    char *btag = basename(tag);
    if (!btag) {
        btag = (char*) tag;
    }

    while (!found_child) {
        ret = TEMP_FAILURE_RETRY(poll(poll_fds, ARRAY_SIZE(poll_fds), 5000));
        if (ret < 0) {
            SLOGE("poll failed\n");
            rc = -1;
            goto err_poll;
        }

        if (ret == 0) {
            ret = waitpid(pid, &status, WNOHANG);
            if (ret < 0) {
                rc = errno;
                SLOGE("waitpid failed with %s\n", strerror(errno));
                goto err_waitpid;
            }
            if (ret > 0) {
                found_child = true;
            }
            continue;
        }

        if (poll_fds[0].revents & POLLIN) {
            sz = TEMP_FAILURE_RETRY(
                read(parent_read, &buffer[b], sizeof(buffer) - 1 - b));

            sz += b;
            // Log one line at a time
            for (b = 0; b < sz; b++) {
                if (buffer[b] == '\r') {
                    buffer[b] = '\0';
                } else if (buffer[b] == '\n') {
                    buffer[b] = '\0';
                    do_log_line(btag, &buffer[a]);
                    a = b + 1;
                }
            }

            if (a == 0 && b == sizeof(buffer) - 1) {
                // buffer is full, flush
                buffer[b] = '\0';
                do_log_line(btag, &buffer[a]);
                b = 0;
            } else if (a != b) {
                // Keep left-overs
                b -= a;
                memmove(buffer, &buffer[a], b);
                a = 0;
            } else {
                a = 0;
                b = 0;
            }
        }

        if (poll_fds[0].revents & POLLHUP) {

            ret = waitpid(pid, &status, WNOHANG);
            if (ret < 0) {
                rc = errno;
                SLOGE("waitpid failed with %s\n", strerror(errno));
                goto err_waitpid;
            }
            if (ret > 0) {
                found_child = true;
            }
        }
    }

    if (chld_sts != NULL) {
        *chld_sts = status;
    } else {
      if (WIFEXITED(status))
        rc = WEXITSTATUS(status);
      else
        rc = -ECHILD;
    }

    // Flush remaining data
    if (a != b) {
      buffer[b] = '\0';
      do_log_line(btag, &buffer[a]);
    }

    if (WIFEXITED(status)) {
      if (WEXITSTATUS(status)) {
        snprintf(tmpbuf, sizeof(tmpbuf),
                 "%s terminated by exit(%d)\n", btag, WEXITSTATUS(status));
        do_log_line(btag, tmpbuf);
      }
    } else {
      if (WIFSIGNALED(status)) {
        snprintf(tmpbuf, sizeof(tmpbuf),
                       "%s terminated by signal %d\n", btag, WTERMSIG(status));
        do_log_line(btag, tmpbuf);
      } else if (WIFSTOPPED(status)) {
        snprintf(tmpbuf, sizeof(tmpbuf),
                       "%s stopped by signal %d\n", btag, WSTOPSIG(status));
        do_log_line(btag, tmpbuf);
      }
    }

err_waitpid:
err_poll:
    return rc;
}

int fork_execvp(char* argv[], int *status) {
    int parent_ptty;
    int child_ptty;
    pid_t pid;
    int rc = 0;

    /* Use ptty instead of socketpair so that STDOUT is not buffered */
    parent_ptty = TEMP_FAILURE_RETRY(open("/dev/ptmx", O_RDWR));
    if (parent_ptty < 0) {
        SLOGE("Cannot create parent ptty\n");
        rc = -1;
        goto err_open;
    }

    char child_devname[64];
    if (grantpt(parent_ptty) || unlockpt(parent_ptty) ||
            ptsname_r(parent_ptty, child_devname, sizeof(child_devname)) != 0) {
        SLOGE("Problem with /dev/ptmx\n");
        rc = -1;
        goto err_ptty;
    }

    child_ptty = TEMP_FAILURE_RETRY(open(child_devname, O_RDWR));
    if (child_ptty < 0) {
        SLOGE("Cannot open child_ptty\n");
        rc = -1;
        goto err_child_ptty;
    }

    pid = fork();
    if (pid < 0) {
        close(child_ptty);
        SLOGE("Failed to fork\n");
        rc = -1;
        goto err_fork;
    } else if (pid == 0) {
         dup2(child_ptty, 1);
         dup2(child_ptty, 2);
         close(child_ptty);

         if (execvp(argv[0], argv)) {
            SLOGE("executing %s failed: %s\n", argv[0], strerror(errno));
        }
    } else {
        /* Parent.  Wait for the child to return */
        close(child_ptty);

        SLOGD("muxreport pid: %d", pid);
        rc = parent(argv[0], parent_ptty, pid, status);
    }

err_fork:
err_child_ptty:
err_ptty:
    close(parent_ptty);
err_open:

    SLOGD("rc: %d", rc);
    return rc;
}

void stop_modem(){
    int fd;
    const char *args[3];
    int rc;
    int status;

    SLOGD("Use muxreport to stop modem\n");

    args[0] = "/system/vendor/bin/muxreport";
    args[1] = "3";
    args[2] = NULL;

    rc = fork_execvp((char **)args, &status);
    if (rc != 0) {
        SLOGE("stop md1 failed due to logwrap error");
    }

    args[1] = "7";
    rc = fork_execvp((char **)args, &status);
    if (rc != 0) {
        SLOGE("stop md2 failed due to logwrap error");
    }
}

void start_modem(){
    int fd;
    const char *args[3];
    int rc;
    int status;
    SLOGD("Just use muxreport to start modem\n");

    args[0] = "/system/vendor/bin/muxreport";
    args[1] = "4";
    args[2] = NULL;

    rc = fork_execvp((char **)args, &status);
    if (rc != 0) {
        SLOGE("start md1 failed due to logwrap error");
    }

    args[1] = "8";
    rc = fork_execvp((char **)args, &status);
    if (rc != 0) {
        SLOGE("start md2 failed due to logwrap error");
    }
}

int
main(int argc, char **argv)
{
    int ret = 0, erg;
    int ch;

#ifndef CUSTOM_MODEM
    SLOGI("there is no modem inside,return directly");
#else
    if (argc!=2) {
        usage();
    }
    if (*argv[1] !='0' && *argv[1] !='1' ) {
        usage();
    }

    char state[PROPERTY_VALUE_MAX];
    char decrypt[PROPERTY_VALUE_MAX];
    char encryption_type [PROPERTY_VALUE_MAX];

    property_get("ro.crypto.state", state, "");
    property_get("vold.decrypt", decrypt, "");
    property_get("vold.encryption.type", encryption_type, "");

    SLOGI("ro.crypto.state=%s, vold.decrypt=%s, vold.encryption.type=%s, start/stop=%c", state, decrypt, encryption_type, *argv[1]);
    if(!strcmp(state, "")) {   /* first boot and to encrypt-ing */
       SLOGI("this is first boot and will to encrypt. set vold.encryption.type to default");
       property_set("vold.encryption.type", "default");
       SLOGE("ccci is waiting. No need to start/stop modem");
       return -1;
    }
    else if(!strcmp(state, "encrypted")){
       // set property, vold.encryption.type
       if(!strcmp(decrypt, "trigger_restart_min_framework")) {
         property_set("vold.encryption.type", "not_default");
         property_get("vold.encryption.type", encryption_type, "");
       }
       else {
           if(strcmp(encryption_type, "not_default") && !strcmp(decrypt, "trigger_restart_framework")) {
              property_set("vold.encryption.type", "default");
              property_get("vold.encryption.type", encryption_type, "");
           }
       }

       if(!strcmp(encryption_type, "not_default")) {
         /* pin, password, pattern type */
         if(!strcmp(decrypt, "trigger_restart_min_framework")) {
            SLOGE("encryption.type is NOT default. ccci is waiting. No need to start/stop modem");
            return -1;
         }
       }
       else if(!strcmp(encryption_type, "default")) { /* default type */
          SLOGE("encryption.type is default. ccci is waiting. No need to start/stop modem");
          return -1;
       }
    }

    if(*argv[1] =='0') {
        stop_modem();
    }

    if(*argv[1] =='1') {
        start_modem();
    }
#endif

    return 0;
}


