#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <log/log.h>
#include <unistd.h>

#define SIOCSTXQSTATE (SIOCDEVPRIVATE + 0)  //start/stop ccmni tx queue
#define SIOCSCCMNICFG (SIOCDEVPRIVATE + 1)  //configure ccmni/md remapping

static void ifc_init_ifr(const char *name, struct ifreq *ifr)
{
    memset(ifr, 0, sizeof(struct ifreq));
    strlcpy(ifr->ifr_name, name, IFNAMSIZ);
}

int ifc_set_txq_state(const char *ifname, int state)
{
    struct ifreq ifr;
    int ret, ctl_sock;

    memset(&ifr, 0, sizeof(struct ifreq));
    strncpy(ifr.ifr_name, ifname, IFNAMSIZ);
    ifr.ifr_name[IFNAMSIZ - 1] = 0;
    ifr.ifr_ifru.ifru_ivalue = state;

    ctl_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (ctl_sock < 0) {
		ALOGE("create ctl socket failed\n");
		return -1;
    }
    ret = ioctl(ctl_sock, SIOCSTXQSTATE, &ifr);
    if(ret < 0)
		ALOGE("ifc_set_txq_state failed, err:%d(%s)\n", errno, strerror(errno));
    else
		ALOGI("ifc_set_txq_state as %d, ret: %d\n", state, ret);

    close(ctl_sock);

    return ret;
}

int ifc_ccmni_md_cfg(const char *ifname, int md_id)
{
    struct ifreq ifr;
    int ret = 0;
    int ctl_sock = 0;

    ifc_init_ifr(ifname, &ifr);
    ifr.ifr_ifru.ifru_ivalue = md_id;

    ctl_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(ctl_sock < 0) {
		ALOGE("ifc_ccmni_md_cfg: create ctl socket failed\n");
		return -1;
    }

    if(ioctl(ctl_sock, SIOCSCCMNICFG, &ifr) < 0) {
		ALOGE("ifc_ccmni_md_configure(ifname=%s, md_id=%d) error:%d(%s)",
			ifname, md_id, errno, strerror(errno));
		ret = -1;
    } else {
		ALOGE("ifc_ccmni_md_configure(ifname=%s, md_id=%d) OK", ifname, md_id);
    }

    close(ctl_sock);
    return ret;
}
