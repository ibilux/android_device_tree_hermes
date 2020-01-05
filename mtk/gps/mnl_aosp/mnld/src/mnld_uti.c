/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2014. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */
/*******************************************************************************
* Dependency
*******************************************************************************/
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <cutils/properties.h>
#include <cutils/xlog.h>
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h> // For 'O_RDWR' & 'O_EXCL'
#include <poll.h>
#include <android/log.h>
#include "mnld_utile.h"
#include <termios.h>
#include "CFG_GPS_File.h"
#include "mnl_agps_interface.h"
#include <private/android_filesystem_config.h>

#define MTK_HAL2MNLD         "/data/gps_mnl/hal2mnld"  //Forward AGPS Info to MNLD, FWK->JNI->HAL->MNLD
#define MTK_MNLD2HAL         "/data/gps_mnl/mnld2hal"  //Forward AGPS Info to HAL, MNLD->HAL->JNI->FWK

//#define MNL_TO_AGPS          "/data/agps_supl/mnl_to_agps" //Forward MNLD(MNL,HAL) Info to AGPSD, HAL/MNL->MNLD->AGPSD
//#define AGPS_TO_MNL          "/data/agps_supl/agps_to_mnl"  //Forward AGPSD Info to MNLD(MNL,HAL), AGPSD->MNLD->HAL/MNL
extern int mtk_gps_sys_init();
ap_nvram_gps_config_struct stGPSReadback;

//#define GPS_PROPERTY "/data/misc/GPS_CHIP.cfg"
/*****************************************************************************/
 //-1 means failure
int hal_sock_mnld() {
    int sockfd;
    struct sockaddr_un soc_addr;
    socklen_t addr_len;

    sockfd = socket(PF_LOCAL, SOCK_DGRAM, 0);
    if(sockfd < 0) {
        MND_ERR("socket failed reason=[%s]\n", strerror(errno));
        return -1;
    }

    strcpy(soc_addr.sun_path, MTK_HAL2MNLD);
    soc_addr.sun_family = AF_UNIX;
    addr_len = (offsetof(struct sockaddr_un, sun_path) + strlen(soc_addr.sun_path) + 1);

    unlink(soc_addr.sun_path);
    if(bind(sockfd, (struct sockaddr *)&soc_addr, addr_len) < 0) {
        MND_ERR("bind failed path=[%s] reason=[%s]\n", MTK_HAL2MNLD, strerror(errno));
        close(sockfd);
        return -1;
    }
    chmod(MTK_HAL2MNLD, 0660);
    if(chown(MTK_HAL2MNLD, -1, AID_INET))
        MND_ERR("chown error: %s", strerror(errno));
    return sockfd;
}

int mnld_sendto_hal(int sockfd, void* dest, char* buf, int size) {
    //dest: MTK_MNLD2HAL
    int ret = 0;
    int len = 0;
    struct sockaddr_un soc_addr;
    socklen_t addr_len;
    int retry = 10;

    strcpy(soc_addr.sun_path, dest);
    soc_addr.sun_family = AF_UNIX;
    addr_len = (offsetof(struct sockaddr_un, sun_path) + strlen(soc_addr.sun_path) + 1);

    MND_MSG("mnld2hal fd: %d\n", sockfd);
    while((len = sendto(sockfd, buf, size, 0,
        (const struct sockaddr *)&soc_addr, (socklen_t)addr_len)) == -1) {
        if(errno == EINTR) continue;
        if(errno == EAGAIN) {
            if(retry-- > 0) {
                usleep(100 * 1000);
                continue;
            }
        }
        MND_ERR("[mnld2hal] ERR: sendto dest=[%s] len=%d reason =[%s]\n",
            (char *)dest, size, strerror(errno));
        ret = -1;
        break;
    }
    return ret;
}

int agpsd_sock_mnld(){
    int agpsd_sock = -1;
    struct sockaddr_un local;
    struct sockaddr_un remote;
    socklen_t remotelen;

    if ((agpsd_sock = socket(AF_LOCAL, SOCK_DGRAM, 0)) < 0)
    {
        MND_ERR("agps2mnld socket open failed: %d, %s", agpsd_sock, strerror(errno));
        return -1;
    }

    unlink(AGPS_TO_MNL);
    memset(&local, 0, sizeof(local));
    local.sun_family = AF_LOCAL;
    strcpy(local.sun_path, AGPS_TO_MNL);

    if (bind(agpsd_sock, (struct sockaddr *)&local, sizeof(local)) < 0 )
    {
        MND_ERR("agps2mnld socket bind failed:%s", strerror(errno));
        close(agpsd_sock);
        agpsd_sock = -1;
        return -1;
    }

    int res = chmod(AGPS_TO_MNL, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP);
    MND_MSG("chmod res = %d, %s", res, strerror(errno));

    return agpsd_sock;
}

int mnld_sock_agpsd(int type, int length, char *data){
    int ret = 0;

    int mnld2agpsd = -1;
    struct sockaddr_un local;
    mtk_agps_msg *pMsg = NULL;
    int total_length = length + sizeof(mtk_agps_msg);
    MND_MSG("MNLD2AGPSD ACK data: %s\n", data);

    pMsg = (mtk_agps_msg *)malloc(total_length);
    if(pMsg)
    {

        pMsg->type = type;
        MND_MSG("MNLD2AGPSD ACK type: %d\n", type);
        pMsg->srcMod = MTK_MOD_GPS;
        pMsg->dstMod = MTK_MOD_SUPL;
        pMsg->length = length;

        if (pMsg->length != 0){
            memcpy(pMsg->data, data, length);
            MND_MSG("MNLD2AGPSD ACK length:%d, data:%s\n", pMsg->length, pMsg->data);
        }
        else {
            MND_MSG("MNLD2AGPSD ACK no data\r\n");
        }

        if((mnld2agpsd = socket(AF_LOCAL, SOCK_DGRAM, 0)) == -1)
        {
            MND_ERR("MNLD2AGPSD socket fail\n");
            free(pMsg);
            pMsg = NULL;
            return -1;
        }

        memset(&local, 0, sizeof(local));
        local.sun_family = AF_LOCAL;
        strcpy(local.sun_path, MNL_TO_AGPS);

        if (sendto(mnld2agpsd, (void *)pMsg, total_length, 0, (struct sockaddr*)&local, sizeof(local)) < 0)
        {
            MND_ERR("MNLD2AGPSD send fail: %s\n", strerror(errno));
            ret = -1;
        }
        close(mnld2agpsd);
        if(pMsg)
        {
            free(pMsg);
            pMsg = NULL;
        }
    }
    return ret;
 }

#if 0
void power_on_3332()
{
    int err;
    err = mnl_write_attr(MNL_ATTR_PWRCTL, GPS_PWRCTL_RST_FORCE);
    if(err != 0)
    {
    	MND_ERR("GPS_Open: GPS power-on error: %d\n", err);
    	return ;
    }
    usleep(1000*100);
    return;
}

void power_off_3332()
{
    int err;
    err = mnl_write_attr(MNL_ATTR_PWRCTL, GPS_PWRCTL_OFF);
    if(err != 0)
    {
    	MND_ERR("GPS_Open: GPS power-on error: %d\n", err);
    	return ;
    }
    usleep(1000*100);
    return;
}
#endif

int read_NVRAM()
{
    int ret = 0;
    ret = mtk_gps_sys_init();
    if(strcmp(stGPSReadback.dsp_dev, "/dev/stpgps") == 0)
    {
        MND_ERR("not 3332 UART port\n");
        return 1;
    }
    return ret;
}

int init_3332_interface(const int fd)
{
    struct termios termOptions;
    //fcntl(fd, F_SETFL, 0);

    //Get the current options:
    tcgetattr(fd, &termOptions);

    // Set 8bit data, No parity, stop 1 bit (8N1):
    termOptions.c_cflag &= ~PARENB;
    termOptions.c_cflag &= ~CSTOPB;
    termOptions.c_cflag &= ~CSIZE;
    termOptions.c_cflag |= CS8 | CLOCAL | CREAD;

    MND_MSG("GPS_Open: c_lflag=%x,c_iflag=%x,c_oflag=%x\n",termOptions.c_lflag,termOptions.c_iflag,
    						termOptions.c_oflag);
    //termOptions.c_lflag

    // Raw mode
    termOptions.c_iflag &= ~(INLCR | ICRNL | IXON | IXOFF | IXANY);
    termOptions.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);  /*raw input*/
    termOptions.c_oflag &= ~OPOST;  /*raw output*/

    tcflush(fd,TCIFLUSH);//clear input buffer
    termOptions.c_cc[VTIME] = 10; /* inter-character timer unused, wait 1s, if no data, return */
    termOptions.c_cc[VMIN] = 0; /* blocking read until 0 character arrives */

     // Set baudrate to 38400 bps
    cfsetispeed(&termOptions, B115200);	/*set baudrate to 115200, which is 3332 default bd*/
    cfsetospeed(&termOptions, B115200);

    tcsetattr(fd, TCSANOW, &termOptions);

    return 0;
}

int hw_test_3332(const int fd)
{
    ssize_t bytewrite, byteread;
    char buf[6] = {0};
    char cmd[] = {0xAA,0xF0,0x6E,0x00,0x08,0xFE,0x1A,0x00,0x00,0x00,0x00,
    			0x00,0xC3,0x01,0xA5,0x02,0x00,0x00,0x00,0x00,0x5A,0x45,0x00,
    			0x80,0x04,0x80,0x00,0x00,0x1A,0x00,0x00,0x00,0x00,0x00,0x05,0x00,
    			0x96,0x00,0x6F,0x3C,0xDE,0xDF,0x8B,0x6D,0x04,0x04,0x00,0xD2,0x00,
    			0xB7,0x00,0x28,0x00,0x5D,0x4A,0x1E,0x00,0xC6,0x37,0x28,0x00,0x5D,
    			0x4A,0x8E,0x65,0x00,0x00,0x01,0x00,0x28,0x00,0xFF,0x00,0x80,0x00,
    			0x47,0x00,0x64,0x00,0x50,0x00,0xD8,0x00,0x50,0x00,0xBB,0x00,0x03,
    			0x00,0x3C,0x00,0x6F,0x00,0x89,0x00,0x88,0x00,0x02,0x00,0xFB,0x00,
    			0x01,0x00,0x00,0x00,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,0x7A,0x16,0xAA,0x0F};
    char ack[] = {0xaa,0xf0,0x0e,0x00,0x31,0xfe};


    bytewrite = write(fd, cmd, sizeof(cmd));
    if (bytewrite == sizeof(cmd))
    {
        usleep(500*000);
        byteread = read(fd, buf, sizeof(buf));
        MND_MSG("ack:%02x %02x %02x %02x %02x %02x\n",
        		 buf[0],buf[1], buf[2], buf[3], buf[4], buf[5]);
        if((byteread == sizeof(ack)) && (memcmp(buf, ack, sizeof(ack)) == 0))
        {
            MND_MSG("it's 3332\n");
            return 0;	/*0 means 3332,   1 means other GPS chips*/
        }
        return 1;
    }
    else
    {
        MND_ERR("write error, write API return is %d, error message is %s\n", bytewrite, strerror(errno));
        return 1;
    }
}

int hand_shake()
{
    int fd;
    int ret;
    int nv;
    nv = read_NVRAM();

    if(nv == 1)
        return 1;
    else if(nv == -1)
        return -1;
    else
        MND_MSG("read NVRAM ok\n");

    fd = open(stGPSReadback.dsp_dev, O_RDWR | O_NOCTTY);
    if (fd == -1)
      {
    	MND_ERR("GPS_Open: Unable to open - %s, %s\n", stGPSReadback.dsp_dev, strerror(errno));
          return -1;
    }
    init_3332_interface(fd);	/*set UART parameter*/

    ret = hw_test_3332(fd);	/*is 3332? 	0:yes  	1:no*/
    close(fd);
    return ret;
}

int confirm_if_3332()
{
    int ret;
    //power_on_3332();
    ret = hand_shake();
    //power_off_3332();
    return ret;
}
extern char chip_id[PROPERTY_VALUE_MAX];

void chip_detector()
{
    int get_time = 20;
    int res;
#if 0
    int fd = -1;
    fd = open(GPS_PROPERTY, O_RDWR|O_CREAT, 0600);
    if(fd == -1)
    {
    	MND_ERR("open %s error, %s\n", GPS_PROPERTY, strerror(errno));
    	return;
    }
    int read_len;
    char buf[100] = {0};
    read_len = read(fd, buf, sizeof(buf));
    if(read_len == -1)
    {
        MND_ERR("read %s error, %s\n", GPS_PROPERTY, strerror(errno));
        goto exit_chip_detector;
    }
    else if(read_len != 0) /*print chip id then return*/
    {
        MND_MSG("gps is %s\n", buf);
        goto exit_chip_detector;
    }
    else
    	  MND_MSG("we need to known which GPS chip is in use\n");
#endif

    while((get_time--!= 0) && ((res = property_get("persist.mtk.wcn.combo.chipid", chip_id, NULL)) < 6))
    {
        MND_ERR("get chip id fail, retry");
        usleep(200000);
    }

    //chip id is like "0xXXXX"
    if (res < 6){
       MND_ERR("combo_chip_id error: %s\n", chip_id);
       return;
    }

    MND_MSG("combo_chip_id is %s\n", chip_id);
   
    /*detect if there is 3332, yes set GPS property to 3332, then else read from combo chip to see which GPS chip used*/
    res = confirm_if_3332();	/*0 means 3332, 1 means not 3332, other value means error*/
    if(res == 0)
    {
		strcpy(chip_id, "0x3332");
		MND_MSG("we get MT3332\n");
    }

    //close(fd);
    MND_MSG("exit chip_detector\n");
	
    return;
}

int buff_get_int(char* buff, int* offset) {
    int ret = *((int*)&buff[*offset]);
    *offset += 4;
    return ret;
}

int buff_get_string(char* str, char* buff, int* offset) {
    int len = *((int*)&buff[*offset]);
    *offset += 4;

    memcpy(str, &buff[*offset], len);
    *offset += len;
    return len;
}

void buff_put_int(int input, char* buff, int* offset) {
    *((int*)&buff[*offset]) = input;
    *offset += 4;
}

void buff_put_string(char* str, char* buff, int* offset) {
    int len = strlen(str) + 1;

    *((int*)&buff[*offset]) = len;
    *offset += 4;

    memcpy(&buff[*offset], str, len);
    *offset += len;
}

void buff_put_struct(void* input, int size, char* buff, int* offset) {
    memcpy(&buff[*offset], input, size);
    *offset += size;
}

void buff_get_struct(char* output, int size, char* buff, int* offset) {
    memcpy(output, &buff[*offset], size);
    *offset += size;
}

int buff_get_binary(void* output, char* buff, int* offset) {
    int len = *((int*)&buff[*offset]);
    *offset += 4;

    memcpy(output, &buff[*offset], len);
    *offset += len;
    return len;
}

//-1 means failure
int safe_read(int fd, void* buf, int len) {
    int n, retry = 10;

    if(fd < 0 || buf == NULL || len < 0) {
        MND_ERR("safe_read fd=%d buf=%p len=%d\n", fd, buf, len);
        return -1;
    }

    if(len == 0) {
        return 0;
    }

    if(fcntl(fd, F_SETFL, O_NONBLOCK) == -1) {
        MND_ERR("safe_read fcntl failure reason=[%s]\n", strerror(errno));
    }

    while((n = read(fd, buf, len)) <= 0) {
        if(errno == EINTR) continue;
        if(errno == EAGAIN) {
            if(retry-- > 0) {
                usleep(100 * 1000);
                continue;
            }
            goto exit;
        }
        goto exit;
    }
    return n;

exit:
    MND_ERR("safe_read reason=[%s]\n", strerror(errno));
    return -1;
}


//Confirm MT3332 -- End
