/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
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

#ifndef __GPS2AGPS_INTERFACE_H__
#define __GPS2AGPS_INTERFACE_H__

#include "mnl_agps_interface.h"

/*****************************************************************************
 * STRUCTURE
 *  mnl2agpsInterface
 * DESCRIPTION
 *  To handler the message and requirement from AGPSD;
 *****************************************************************************/
typedef struct {
    void (*agps_reboot)();
    
    void (*agps_open_gps_req)(int show_gps_icon);
    void (*agps_close_gps_req)();
    void (*agps_reset_gps_req)(int flags);

    void (*agps_session_done)();
    
    void (*ni_notify)(int session_id, mnl_agps_notify_type type, const char* requestor_id, const char* client_name);
    void (*data_conn_req)(int ipaddr, int is_emergency);
    void (*data_conn_release)();

    void (*set_id_req)(int flags);
    void (*ref_loc_req)(int flags);

    void (*rcv_pmtk)(const char* pmtk);
    void (*gpevt)(gpevt_type type);

    void (*agps_location) (mnl_agps_agps_location* location);
    void (*ni_notify2)(int session_id, mnl_agps_notify_type type, const char* requestor_id, const char* client_name, 
        mnl_agps_ni_encoding_type requestor_id_encoding, mnl_agps_ni_encoding_type client_name_encoding);
    void (*data_conn_req2) (struct sockaddr_storage* addr, int is_emergency);
} mnl2agpsInterface;

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_mnl_reboot
 * DESCRIPTION
 *  Update the status of GPS reboot to AGPSD; 
 *  Be called when GPS driver restart.
 * PARAMETERS
 * 
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_mnl_reboot();

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_open_gps_done
 * DESCRIPTION
 *  Update the status of GPS OPEN DONE to AGPSD; 
 *  Be called ONLY when AGPS open GPS driver successfully.
 * PARAMETERS
 * 
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_open_gps_done();

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_close_gps_done
 * DESCRIPTION
 *  Update the status of GPS CLOSE DONE to AGPSD; 
 *  Be called ONLY when AGPS close GPS driver successfully.
 * PARAMETERS
 * 
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_close_gps_done();

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_reset_gps_done
 * DESCRIPTION
 *  Update the status of GPS RESET DONE to AGPSD; 
 *  Be called ONLY when AGPS reset GPS successfully.
 * PARAMETERS
 * 
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_reset_gps_done();

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_gps_init
 * DESCRIPTION
 *  Update the status of GPS INIT to AGPSD; 
 *  Be called when GPS INIT (Enable GPS)happened.
 * PARAMETERS
 * 
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_gps_init();

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_gps_init
 * DESCRIPTION
 *  Update the status of GPS CLEANUP to AGPSD; 
 *  Be called when GPS CLEANUP (DISABLE GPS) happened.
 * PARAMETERS
 * 
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_gps_cleanup();

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_set_server
 * DESCRIPTION
 *   Update the AGPS server information to AGPSD;
 *   FWK->HAL->MNLD->AGPSD
 * PARAMETERS
 *  type [IN] AGPS server type
 *  hostname [IN] AGPS server hostname
 *  port  [IN] AGPS server port No.
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_set_server(int type, const char* hostname, int port);


/*****************************************************************************
 * FUNCTION
 *  mnl2agps_delete_aiding_data
 * DESCRIPTION
 *   Update the status of GPS DELETE AIDING to AGPSD;
 *   FWK->HAL->MNLD->AGPSD 
 * PARAMETERS
 *  flags [IN] Indicate delete aiding data info: HOT/WARM/COLD/FULL/AGPS 
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_delete_aiding_data(int flags);

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_gps_open
 * DESCRIPTION
 *   Update the status of GPS open to AGPSD;
 *   Be called when GPS APP open GPS driver successfully. 
 * PARAMETERS
 *  assist_req [IN] Indicate if MNL needs ASSIST request. 1: Req, 0: No req.  
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_gps_open(int assist_req);

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_gps_close
 * DESCRIPTION
 *   Update the status of GPS open to AGPSD;
 *   Be called when GPS APP stop GPS driver. 
 * PARAMETERS
 *  
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_gps_close();

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_data_conn_open
 * DESCRIPTION
 *   Update the status of DATA CONNECTION to AGPSD;
 *   FWK->HAL->MNLD->AGPSD
 * PARAMETERS
 *  
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_data_conn_open(const char* apn);
int mnl2agps_data_conn_open_ip_type(const char* apn, int ip_type);

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_data_conn_failed
 * DESCRIPTION
 *   Update the status of DATA CONNECTION FAIL to AGPSD;
 *   FWK->HAL->MNLD->AGPSD
 * PARAMETERS
 *  
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_data_conn_failed();

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_data_conn_closed
 * DESCRIPTION
 *   Update the status of DATA CONNECTION CLOSED to AGPSD;
 *   FWK->HAL->MNLD->AGPSD
 * PARAMETERS
 *  
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_data_conn_closed();

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_ni_message
 * DESCRIPTION
 *   Update the NI message to AGPSD;
 *   FWK->HAL->MNLD->AGPSD
 * PARAMETERS
 *  msg: NI message
 *  len: length of NI message
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_ni_message(const char* msg, int len);

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_ni_respond
 * DESCRIPTION
 *   Update the status of DATA CONNECTION CLOSED to AGPSD;
 *   FWK->HAL->MNLD->AGPSD
 * PARAMETERS
 *  session_id [IN]: NI session ID
 *  user_response [IN]: User response
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_ni_respond(int session_id, int user_response);

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_set_ref_loc
 * DESCRIPTION
 *   Update the reference lcoation to AGPSD;
 *   FWK->HAL->MNLD->AGPSD
 * PARAMETERS
 *  type [IN]: reference loaction type: CELLID or MAC 
 *  mcc  [IN]: User response
 *  mnc  [IN]: mnc
 *  lac  [IN]: lac
 *  cid  [IN]: cellID
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_set_ref_loc(int type, int mcc, int mnc, int lac, int cid);

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_set_set_id
 * DESCRIPTION
 *   Update the set ID to AGPSD;
 *   FWK->HAL->MNLD->AGPSD
 * PARAMETERS
 *  type [IN]: SET ID type.
 *  setid [IN]: setid
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_set_set_id(int type, const char* setid);

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_update_network_state
 * DESCRIPTION
 *   Update Network state to AGPSD;
 *   FWK->HAL->MNLD->AGPSD
 * PARAMETERS
 *  connected [IN]: If network connected.
 *  type [IN]: Network type
 *  roaming [IN]: If in roaming status.
 *  extra_info [IN]: Extra information.
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_update_network_state(int connected, int type, int roaming, const char* extra_info);

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_update_network_availability
 * DESCRIPTION
 *   Update the status if the network is available to AGPSD;
 *   FWK->HAL->MNLD->AGPSD
 * PARAMETERS
 *  avaiable [IN]: If newwork is available currently.
 *  apn [IN]: APN name.
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_update_network_availability(int avaiable, const char* apn);

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_install_certificates
 * DESCRIPTION
 *   Update the status if the network is available to AGPSD;
 *   FWK->HAL->MNLD->AGPSD
 * PARAMETERS
 * index: 
 * total:
 * data: 
 * len:
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_install_certificates(int index, int total, const char* data, int len);

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_revoke_certificates
 * DESCRIPTION
 *   Update the status if the network is available to AGPSD;
 *   FWK->HAL->MNLD->AGPSD
 * PARAMETERS
 *  data:
 *  len: 
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_revoke_certificates(const char* data, int len);

/*****************************************************************************
 *  mnl2agps_pmtk
 * DESCRIPTION
 *   Send PMTK message to AGPSD;
 *   MNL->MNLD->AGPSD.
 * PARAMETERS
 *  pmtk [IN]: PMTK message.
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_pmtk(const char* pmtk);

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_raw_dbg
 * DESCRIPTION
 *   To let AGPSD open raw data debug.
 *   AT command->HAL->MNLD->AGPSD
 * PARAMETERS
 *  enabled [IN]: 1: enable; 0: disable.
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_raw_dbg(int enabled);

/*****************************************************************************
 * FUNCTION
 *  mnl2agps_handler
 * DESCRIPTION
 *   Event handler from AGPSD.
 *   AGPSD->MNLD->HAL or MNL
 * PARAMETERS
 *  fd: agps2mnl socket fd.
 *  mnl_interface: Handler function interface.
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int mnl2agps_handler(int fd, mnl2agpsInterface* mnl_interface);

/*****************************************************************************
 * FUNCTION
 *  create_mnl2agps_fd
 * DESCRIPTION
 *   create the socket between MNLD and AGPSD.
 *   MNLD->AGPSD
 * PARAMETERS
 *  
 * RETURNS
 *  success(0); failure (-1)
 *****************************************************************************/
int create_mnl2agps_fd();

int mnl2agps_reaiding_req();

#endif
