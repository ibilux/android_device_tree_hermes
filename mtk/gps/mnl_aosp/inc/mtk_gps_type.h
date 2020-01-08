/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   mtk_gps_type.h
 *
 * Description:
 * ------------
 *   Data types used by MTK navigation library
 *
 ****************************************************************************/

#ifndef MTK_GPS_TYPE_H
#define MTK_GPS_TYPE_H

#ifdef __cplusplus
  extern "C" {
#endif

#define MTK_GPS_SV_MAX_NUM      32
#define MTK_GPS_SV_MAX_PRN      32
#define MTK_QZS_SV_MAX_PRN      5   // QZSS PRN : 193~197
#define MTK_GLEO_SV_MAX_NUM     53  // Galileo SV number, should be >= MGLEOID
#define MTK_GLON_SV_MAX_NUM     24  // Glonass SV number, should be >= MGLONID
#define MTK_BEDO_SV_MAX_NUM     37  // Beidou SV number, should be >= MBEDOID
#define MTK_GPS_ENABLE_DEBUG_MSG (0x01)

// GPS Measurement

#define GPS_MEASUREMENT_HAS_SNR                                            (1<<0) // A valid 'snr' is stored in the data structure. */
#define GPS_MEASUREMENT_HAS_ELEVATION                                (1<<1) // A valid 'elevation' is stored in the data structure. */
#define GPS_MEASUREMENT_HAS_ELEVATION_UNCERTAINTY        (1<<2) // A valid 'elevation uncertainty' is stored in the data structure. */
#define GPS_MEASUREMENT_HAS_AZIMUTH                                    (1<<3) // A valid 'azimuth' is stored in the data structure. */
#define GPS_MEASUREMENT_HAS_AZIMUTH_UNCERTAINTY            (1<<4) // A valid 'azimuth uncertainty' is stored in the data structure. */
#define GPS_MEASUREMENT_HAS_PSEUDORANGE                            (1<<5) // A valid 'pseudorange' is stored in the data structure. */
#define GPS_MEASUREMENT_HAS_PSEUDORANGE_UNCERTAINTY   (1<<6) // A valid 'pseudorange uncertainty' is stored in the data structure. */
#define GPS_MEASUREMENT_HAS_CODE_PHASE                              (1<<7) // A valid 'code phase' is stored in the data structure. */
#define GPS_MEASUREMENT_HAS_CODE_PHASE_UNCERTAINTY      (1<<8) // A valid 'code phase uncertainty' is stored in the data structure. */
#define GPS_MEASUREMENT_HAS_CARRIER_FREQUENCY                 (1<<9) // A valid 'carrier frequency' is stored in the data structure. */
#define GPS_MEASUREMENT_HAS_CARRIER_CYCLES                       (1<<10) // A valid 'carrier cycles' is stored in the data structure. */
#define GPS_MEASUREMENT_HAS_CARRIER_PHASE                         (1<<11) // A valid 'carrier phase' is stored in the data structure. */
#define GPS_MEASUREMENT_HAS_CARRIER_PHASE_UNCERTAINTY (1<<12) // A valid 'carrier phase uncertainty' is stored in the data structure. */
#define GPS_MEASUREMENT_HAS_BIT_NUMBER                               (1<<13) // A valid 'bit number' is stored in the data structure. */
#define GPS_MEASUREMENT_HAS_TIME_FROM_LAST_BIT               (1<<14) // A valid 'time from last bit' is stored in the data structure. */
#define GPS_MEASUREMENT_HAS_DOPPLER_SHIFT                         (1<<15) // A valid 'doppler shift' is stored in the data structure. */
#define GPS_MEASUREMENT_HAS_DOPPLER_SHIFT_UNCERTAINTY (1<<16) // A valid 'doppler shift uncertainty' is stored in the data structure.
#define GPS_MEASUREMENT_HAS_USED_IN_FIX                              (1<<17) // A valid 'used in fix' flag is stored in the data structure.

#define GPS_LOSS_OF_LOCK_UNKNOWN      0 // The indicator is not available or it is unknown.
#define GPS_LOSS_OF_LOCK_OK                  1 // The measurement does not present any indication of loss of lock.
#define GPS_LOSS_OF_LOCK_CYCLE_SLIP   2 // Loss of lock between previous and current observation: cycle slip possible.

#define GPS_MULTIPATH_INDICATOR_UNKNOWN     0 // The indicator is not available or unknown.
#define GPS_MULTIPATH_INDICATOR_DETECTED     1 // The measurement has been indicated to use multipath.
#define GPS_MULTIPATH_INDICATOR_NOT_USED     2 // The measurement has been indicated Not to use multipath.

#define GPS_MEASUREMENT_STATE_UNKNOWN              0
#define GPS_MEASUREMENT_STATE_CODE_LOCK            (1<<0)
#define GPS_MEASUREMENT_STATE_BIT_SYNC               (1<<1)
#define GPS_MEASUREMENT_STATE_SUBFRAME_SYNC   (1<<2)
#define GPS_MEASUREMENT_STATE_TOW_DECODED      (1<<3)

#define GPS_ADR_STATE_UNKNOWN                       0
#define GPS_ADR_STATE_VALID                     (1<<0)
#define GPS_ADR_STATE_RESET                     (1<<1)
#define GPS_ADR_STATE_CYCLE_SLIP                (1<<2)

// Gps Clock 
#define GPS_CLOCK_HAS_LEAP_SECOND             (1<<0)  // A valid 'leap second' is stored in the data structure.
#define GPS_CLOCK_HAS_TIME_UNCERTAINTY   (1<<1)  // A valid 'time uncertainty' is stored in the data structure.
#define GPS_CLOCK_HAS_FULL_BIAS                  (1<<2)  // A valid 'full bias' is stored in the data structure.
#define GPS_CLOCK_HAS_BIAS                            (1<<3)  // A valid 'bias' is stored in the data structure.
#define GPS_CLOCK_HAS_BIAS_UNCERTAINTY   (1<<4)  // A valid 'bias uncertainty' is stored in the data structure.
#define GPS_CLOCK_HAS_DRIFT                          (1<<5 ) // A valid 'drift' is stored in the data structure.
#define GPS_CLOCK_HAS_DRIFT_UNCERTAINTY  (1<<6) // A valid 'drift uncertainty' is stored in the data structure.

#define GPS_CLOCK_TYPE_UNKNOWN                  0
#define GPS_CLOCK_TYPE_LOCAL_HW_TIME       1
#define GPS_CLOCK_TYPE_GPS_TIME                  2

// Gps NavigationMessage
#define GPS_NAVIGATION_MESSAGE_TYPE_UNKNOWN    0 
#define GPS_NAVIGATION_MESSAGE_TYPE_L1CA            1 // L1 C/A message contained in the structure.
#define GPS_NAVIGATION_MESSAGE_TYPE_L2CNAV        2 // L2-CNAV message contained in the structure.
#define GPS_NAVIGATION_MESSAGE_TYPE_L5CNAV        3 // L5-CNAV message contained in the structure. 
#define GPS_NAVIGATION_MESSAGE_TYPE_CNAV2          4 // CNAV-2 message contained in the structure.

#define GPS_DEBUG_LOG_FILE_NAME_MAX_LEN    128 //The max lenght of debug log file name, include the path name

#define ASSIST_REQ_BIT_NTP  0x01    // NTP request bitmap
#define ASSIST_REQ_BIT_NLP  0x02    // NLP request bitmap

/*******************************************************************************
 * Type Definitions
 *******************************************************************************/
typedef  unsigned int             UINT4;
typedef  signed int               INT4;

typedef unsigned char           UINT8;
typedef signed char             INT8;

typedef unsigned short int      UINT16;
typedef signed short int        INT16;

typedef unsigned int            UINT32;
typedef signed int              INT32;

typedef signed long long       INT64;

#if ( defined(__ARMCC_VERSION) && (__ARMCC_VERSION < 200000 ))
// for ADS1.x
#elif ( defined(__ARMCC_VERSION) && (__ARMCC_VERSION < 400000 ) ) 
// for RVCT2.x or RVCT3.x
#else
#pragma pack(4)
#endif

//*****************************************************************************
// User System Configurations
//*****************************************************************************
typedef enum
{
    HOST_USER_CONFIG_SYS_1 = 1, // user configuration in system operation
    HOST_USER_CONFIG_SYS_2 = 2, // user configuration in GPS operation
    HOST_USER_CONFIG_SYS_3 = 3,  // user configuration in Anti-Jamming Debug
    HOST_USER_CONFIG_SYS_4 = 4,  //  user configuration for aiding data to NVRAM  
    HOST_USER_CONFIG_SYS_5 = 5,  //  user configuration for aiding almanac data to NVRAM 
    HOST_USER_CONFIG_SYS_6 = 6,  //  user configuration for aiding eph data to NVRAM 
    HOST_USER_CONFIG_SYS_7 = 7,  //  user configuration for aiding position data to NVRAM    
    HOST_USER_CONFIG_SYS_8 = 8,  //  user configuration for aiding time data to NVRAM       
    HOST_USER_CONFIG_SYS_9 = 9,  //  user configuration for clean ehp data from NVRAM     
    HOST_USER_CONFIG_SYS_10 = 10,  //  user configuration for clean alman data from NVRAM     
    HOST_USER_CONFIG_SYS_11 = 11,  //  user configuration for chn test     
    HOST_USER_CONFIG_SYS_12 = 12,  //  user configuration for jammer test     
    HOST_USER_CONFIG_SYS_13 = 13,  //  user configuration for phase test    
    HOST_USER_CONFIG_SYS_14 = 14,  //  user configuration for phase test    
    HOST_USER_CONFIG_SYS_15 = 15,  //  user configuration for time_change_notify    
    HOST_USER_CONFIG_SYS_16 = 16,  //  user configuration for time_update_notify     
    HOST_USER_CONFIG_SYS_17 = 17,  //  user configuration for debug_config 
    HOST_USER_CONFIG_SYS_18 = 18,  //  user configuration for update NVfile immedate
    HOST_USER_CONFIG_SYS_19 = 19,  //  user configuration for setting tcxo mode
      HOST_USER_CONFIG_SYS_20 = 20,  //  user configuration for TSX XVT
    HOST_USER_CONFIG_SYS_21 = 21,  //  user configuration for GNSS jammer test     
    HOST_USER_CONFIG_SYS_END  //  user configuration for aiding almanac data to NVRAM 
}MTK_GPS_USER_SYSTEM_CONFIG;

#define USER_SYS_1_ENABLE_DEBUG ( 1 << 0)
#define USER_SYS_2_TRIGGER_PPS ( 1 << 0)

//*****************************************************************************
// User System Stauts
//*****************************************************************************
typedef enum
{
    USER_SYS_ANT_STATUS = 1
}MTK_GPS_SYSTEM_STATUS;
#define MTK_SYS_ANT_STATUS_AOK ( 1 << 0)
#define MTK_SYS_ANT_STATUS_ASHORT ( 1 << 1)



typedef enum
{
  MTK_GPS_FALSE = 0,
  MTK_GPS_TRUE = 1
} MTK_GPS_BOOL;

typedef enum
{
  MTK_GPS_START_DEFAULT = 0,
  MTK_GPS_START_HOT,
  MTK_GPS_START_WARM,
  MTK_GPS_START_COLD,
  MTK_GPS_START_FULL,
  MTK_GPS_START_BATTERY,
  MTK_GPS_START_AGPS
} MTK_GPS_START_TYPE;

typedef enum
{
  MTK_GPS_START_RESULT_ERROR = 0,
  MTK_GPS_START_RESULT_OK
} MTK_GPS_START_RESULT;

typedef enum
{
  MTK_GPS_MSG_FIX_READY,
  MTK_GPS_MSG_DEBUG_READY,
  MTK_GPS_MSG_CONFIG_READY,
  MTK_GPS_MSG_TEST_STATUS_READY,
  MTK_GPS_MSG_BUFFER_ENOUGH,
  MTK_GPS_MSG_AGPS_RESPONSE,
  MTK_GPS_MSG_PMTK_RESPONSE,
  MTK_GPS_MSG_FIX_PROHIBITED,
  MTK_GPS_MSG_ASSIST_READY,
  MTK_GPS_MSG_MNL_START,
  MTK_GPS_MSG_MNL_RESTART_NTF,
  MTK_GPS_MSG_MNL_INIT_FAIL,
  MTK_GPS_MSG_REQUEST_NW_LOCATION
} MTK_GPS_NOTIFICATION_TYPE;

typedef enum
{
  MTK_GPS_FIX_Q_INVALID = 0,
  MTK_GPS_FIX_Q_GPS = 1,
  MTK_GPS_FIX_Q_DGPS = 2,
  MTK_GPS_FIX_Q_EST = 6
} MTK_GPS_FIX_QUALITY;

typedef enum
{
  MTK_GPS_FIX_TYPE_INVALID = 1,
  MTK_GPS_FIX_TYPE_2D = 2,
  MTK_GPS_FIX_TYPE_3D = 3
} MTK_GPS_FIX_TYPE;

typedef enum
{
  MTK_DGPS_MODE_NONE = 0,
  MTK_DGPS_MODE_RTCM = 1,
  MTK_DGPS_MODE_SBAS = 2,
  MTK_DGPS_MODE_AUTO = 3
} MTK_GPS_DGPS_MODE;

typedef enum
{
  MTK_AGPS_MODE_NONE = 1,
  MTK_AGPS_MODE_SUPL = 2,
  MTK_AGPS_MODE_EPO  = 4,
  MTK_AGPS_MODE_BEE  = 8,
  MTK_AGPS_MODE_AUTO = 16
} MTK_GPS_AGPS_MODE;

// Thread definition
typedef enum
{
    MTK_MOD_NIL = 0,
    MTK_MOD_MNL,
    MTK_MOD_DSPIN,
    MTK_MOD_PMTKIN,
    MTK_MOD_AGENT,
    MTK_MOD_BEE_GEN,
    MTK_MOD_DISPATCHER,
    MTK_MOD_RTCM,    
    MTK_MOD_END_LIST
} MTK_GPS_MODULE;

// API from Dispatcher to Agent
typedef enum
{
    MTK_AGPS_MSG_EPO = 0,
    MTK_AGPS_MSG_BEE,
    MTK_AGPS_MSG_SUPL,
    MTK_AGPS_MSG_SUPL_PMTK,
    MTK_AGPS_MSG_PROFILE,
    MTK_AGPS_MSG_SUPL_TERMINATE,  //dispatcher send terminate to indicate SUPL stop
    MTK_AGPS_MSG_REQ_NI,          //request AGPS aiding from dispatcher    
    MTK_AGPS_MSG_REQ,             //request AGPS aiding from mnl
    MTK_AGPS_MSG_AGT_BEE_REQ,     //AGENT request next mode(BEE)
    MTK_AGPS_MSG_AGT_SUPL_REQ,    //AGENT request next mode(SUPL)
    MTK_AGPS_MSG_END_LIST,
    MTK_AGPS_MSG_TERMINATE
} MTK_GPS_AGPS_AGENT_MSG_TYPE;

// Callback from Agent to Dispatcher
typedef enum
{
    MTK_AGPS_CB_SUPL_PMTK = 0,
    MTK_AGPS_CB_ASSIST_REQ,
    MTK_AGPS_CB_SUPL_NI_REQ,
    MTK_AGPS_CB_START_REQ,
    MTK_AGPS_CB_AGPS_RAWDATA_CONT,
    MTK_AGPS_CB_BITMAP_UPDATE,      //this message is used for NTP NTP request to MNLD->HAL GPS->locationservice
    MTK_AGPS_CB_END_LIST
} MTK_GPS_AGPS_CB_MSG_TYPE;
typedef struct
{
  UINT32 ntp[2];           //ntp: mini-second, indicate the time tick(mini-second) from Jan.1.1970
  UINT32 timeReference[2]; //indicate the timestamp of ntp sync with network 
  INT32 uncertainty;
}MTK_GPS_NTP_T;

typedef struct
{
  double lattidude;
  double longitude;
  float  accuracy;
  UINT32 timeReference[2]; //indicate the timestamp of location generated
  UINT8  type;            // indicate location type: 0: NLP, 1: fixed location
}MTK_GPS_NLP_T;

// AGPS feature on/off
typedef enum
{
    MTK_AGPS_FEATURE_OFF = 0,
    MTK_AGPS_FEATURE_ON = 1
} MTK_GPS_AGPS_FUNC_ONOFF;

typedef struct
{
  UINT8 EPO_enabled;
  UINT8 BEE_enabled;
  UINT8 SUPL_enabled;
  UINT8 SUPLSI_enabled;
  UINT8 EPO_priority;
  UINT8 BEE_priority;
  UINT8 SUPL_priority;
  UINT8 fgGpsAosp_Ver;
} MTK_AGPS_USER_PROFILE;

typedef struct 
{
  UINT16    type;           /* message ID */
  UINT16    length;         /* length of 'data' */
  char      data[1];        /* message content */
} MTK_GPS_MSG;

typedef struct
{
  UINT16    srcMod;
  UINT16    dstMod;
  UINT16    type;           /* message ID */
  UINT16    length;         /* length of 'data' */
  char      data[1];        /* message content */
} MTK_GPS_AGPS_AGENT_MSG;
//MTK_GPS_AGPS_AGENT_MSG definition need to sync to SUPL msg 's definition
typedef enum
{
  MTK_BEE_DISABLE = 0,
  MTK_BEE_ENABLE = 1
} MTK_GPS_BEE_EN;

typedef enum
{
  MTK_BRDC_DISABLE = 0,
  MTK_BRDC_ENABLE = 1
} MTK_GPS_BRDC_EN;

typedef enum
{
  MTK_DBG_DISABLE = 0,
  MTK_DBG_ERR,
  MTK_DBG_WRN,
  MTK_DBG_INFO,
  MTK_DBG_END
} MTK_GPS_DBG_LEVEL;


typedef enum
{
  MDBG_BOOT = 0,
  MDBG_TIME,
  MDBG_COMM,
  MDBG_MEM,
  MDBG_MSG,
  MDBG_STORE,
  MDBG_AL,
  MDBG_GPS,
  MDBG_AGPS,
  MDBG_FS,
  MDBG_ALL,
  MDBG_TYPE_END
} MTK_GPS_DBG_TYPE;

typedef enum
{
  MTK_QZSS_DISABLE = 0,
  MTK_QZSS_ENABLE = 1
} MTK_QZSS_SEARCH_MODE;

typedef enum
{
  MTK_NO_SPEED_FILTERING = 0,
  MTK_SPEED_FILTERING_0_POINT_2 = 1,
  MTK_SPEED_FILTERING_0_POINT_4 = 2,
  MTK_SPEED_FILTERING_0_POINT_6 = 3,
  MTK_SPEED_FILTERING_0_POINT_8 = 4,
  MTK_SPEED_FILTERING_1_POINT_0 = 5,
  MTK_SPEED_FILTERING_1_POINT_5 = 6,
  MTK_SPEED_FILTERING_2_POINT_0 = 7
} MTK_LOW_SPEED_FILTERING_MODE;



typedef struct
{
  UINT16    year;           /* years since 1900 */
  UINT8     month;          /* 0-11 */
  UINT8     mday;           /* 1-31 */
  UINT8     hour;           /* 0-23 */
  UINT8     min;            /* 0-59 */
  UINT8     sec;            /* 0-59 */
  UINT8     pad1;
  UINT16    msec;           /* 0-999 */
  UINT16    pad2;
} MTK_GPS_TIME;

typedef enum
{
  MTK_TCXO_NORMAL,  //normal mode 
  MTK_TCXO_PHONE    //bad mode
} MTK_GPS_TCXO_MODE;

typedef enum
{
  MTK_AIC_OFF,  //AIC off 
  MTK_AIC_ON    //AIC on
} MTK_GPS_AIC_MODE;


typedef struct
{
  UINT16    version;
  UINT16    size;
  MTK_GPS_TIME      utc_time;
  INT16     leap_second;            /* GPS-UTC time difference */
  UINT16    WeekNo;                 /* GPS week number */
  UINT32    TOW;                    /* GPS time of week (integer part) */
  UINT8     fix_quality;            /* MTK_GPS_FIX_QUALITY for GPGGA */
  UINT8     fix_type;               /* MTK_GPS_FIX_TYPE for GPGSA */
  double        clock_drift;            /* clock drift (s/s) */
  double        clock_bias;             /* clock bias (s) */
  double        LLH[4];                 /* LLH[0]: Latitude (degree) */
                                        /* LLH[1]: Longitude (degree) */
                                        /* LLH[2]: Height WGS84 (m) */
                                        /* LLH[3]: Height Mean Sea Level (m) */
  float         gspeed;                 /* 2D ground speed (m/s) */
  float         vspeed;                 /* vertical speed (m/s) */
  float         heading;                /* track angle (deg) */
  float         PDOP, HDOP, VDOP, TDOP; /* dilution of precision */
  float         EPE[3];                 /* estimated position error (m) */
                                        /* EPE[0]: North accuracy */
                                        /* EPE[1]: East accuracy */
                                        /* EPE[2]: vertical accuracy */
  float         EVE[3];                 /* estimated velocity error (m/s) */
                                        /* EVE[0]: North accuracy */
                                        /* EVE[1]: East accuracy */
                                        /* EVE[2]: vertical accuracy */
  float         Pos_2D_Accuracy; // Position Accuracy in Horizontal Direction [m]
  float         Pos_3D_Accuracy; // Position Accuracy in 3-D space [m]
  float         Vel_3D_Accuracy;  // Velocity Accuracy in 3-D space [m]
  float         DGPS_age;               /* time since last DGPS update (s) */
  UINT16    DGPS_station_ID;
  UINT8     DGPS_fix_mode;          /* MTK_GPS_DGPS_MODE: 0(N/A); 1(RTCM); 2(SBAS) */
  UINT8     sv_used_num;            /* for GPGSA */
  UINT8     sv_in_view_num;         /* for GPGSV */
  UINT8     sv_used_prn_list[MTK_GPS_SV_MAX_NUM];
  UINT8     sv_in_view_prn_list[MTK_GPS_SV_MAX_NUM];
  INT8      sv_in_view_elev[MTK_GPS_SV_MAX_NUM];
  UINT16    sv_in_view_azim[MTK_GPS_SV_MAX_NUM];
  float     sv_in_view_snr[MTK_GPS_SV_MAX_NUM];
  UINT8    sv_eph_valid[MTK_GPS_SV_MAX_PRN];  /*  sv ephemeris status 0: no ephemeris, 1: broadcast eph, 2: BEE ephmeris, */
  UINT8    sv_eph_day[MTK_GPS_SV_MAX_PRN]; /* day of BEE  */
  UINT8    fgMulti_GNSS;
} MTK_GPS_POSITION;

typedef struct
{ /* GPSS/QZSS index 0~31 represents PRN 1~32, respectively */
  UINT8     health[MTK_GPS_SV_MAX_PRN];   /* nonzero: healthy */
  UINT8     eph[MTK_GPS_SV_MAX_PRN];      /* nonzero: ephemeris available */
  UINT8     alm[MTK_GPS_SV_MAX_PRN];      /* nonzero: almanac available */
  UINT8     dgps[MTK_GPS_SV_MAX_PRN];     /* nonzero: DGPS correction ready */
  UINT8     codelock[MTK_GPS_SV_MAX_PRN]; /* nonzero: code lock */
  UINT8     freqlock[MTK_GPS_SV_MAX_PRN]; /* nonzero: frequency lock */
  UINT8     carrlock[MTK_GPS_SV_MAX_PRN]; /* nonzero: carrier lock */

  /* index 0~4 represents PRN 193~197, respectively */
  UINT8     qzshealth[MTK_QZS_SV_MAX_PRN];   /* nonzero: healthy */
  UINT8     qzseph[MTK_QZS_SV_MAX_PRN];      /* nonzero: ephemeris available */
  UINT8     qzsalm[MTK_QZS_SV_MAX_PRN];      /* nonzero: almanac available */
  UINT8     qzsdgps[MTK_QZS_SV_MAX_PRN];     /* nonzero: DGPS correction ready */
  UINT8     qzscodelock[MTK_QZS_SV_MAX_PRN]; /* nonzero: code lock */
  UINT8     qzsfreqlock[MTK_QZS_SV_MAX_PRN]; /* nonzero: frequency lock */
  UINT8     qzscarrlock[MTK_QZS_SV_MAX_PRN]; /* nonzero: carrier lock */  
} MTK_GPS_SV_INFO;

typedef struct
{ /* GALILEO */
  UINT8     health[MTK_GLEO_SV_MAX_NUM];   /* nonzero: healthy */
  UINT8     eph[MTK_GLEO_SV_MAX_NUM];      /* nonzero: ephemeris available */
  UINT8     alm[MTK_GLEO_SV_MAX_NUM];      /* nonzero: almanac available */
  UINT8     dgps[MTK_GLEO_SV_MAX_NUM];     /* nonzero: DGPS correction ready */
  UINT8     codelock[MTK_GLEO_SV_MAX_NUM]; /* nonzero: code lock */
  UINT8     freqlock[MTK_GLEO_SV_MAX_NUM]; /* nonzero: frequency lock */
  UINT8     carrlock[MTK_GLEO_SV_MAX_NUM]; /* nonzero: carrier lock */
} MTK_GLEO_SV_INFO;

typedef struct
{ /* BLONASS PRN 1~24 represents */
  UINT8     health[MTK_GLON_SV_MAX_NUM];   /* nonzero: healthy */
  UINT8     eph[MTK_GLON_SV_MAX_NUM];      /* nonzero: ephemeris available */
  UINT8     alm[MTK_GLON_SV_MAX_NUM];      /* nonzero: almanac available */
  UINT8     dgps[MTK_GLON_SV_MAX_NUM];     /* nonzero: DGPS correction ready */
  UINT8     codelock[MTK_GLON_SV_MAX_NUM]; /* nonzero: code lock */
  UINT8     freqlock[MTK_GLON_SV_MAX_NUM]; /* nonzero: frequency lock */
  UINT8     carrlock[MTK_GLON_SV_MAX_NUM]; /* nonzero: carrier lock */
} MTK_GLON_SV_INFO;

typedef struct
{ // Beidou
    UINT8     health[MTK_BEDO_SV_MAX_NUM];   /* nonzero: healthy */
    UINT8     eph[MTK_BEDO_SV_MAX_NUM];      /* nonzero: ephemeris available */
    UINT8     alm[MTK_BEDO_SV_MAX_NUM];      /* nonzero: almanac available */
    UINT8     dgps[MTK_BEDO_SV_MAX_NUM];     /* nonzero: DGPS correction ready */
    UINT8     codelock[MTK_BEDO_SV_MAX_NUM]; /* nonzero: code lock */
    UINT8     freqlock[MTK_BEDO_SV_MAX_NUM]; /* nonzero: frequency lock */
    UINT8     carrlock[MTK_BEDO_SV_MAX_NUM]; /* nonzero: carrier lock */
} MTK_BEDO_SV_INFO; 

typedef INT32 (*MTK_GPS_CALLBACK)(MTK_GPS_NOTIFICATION_TYPE msg);


typedef enum
{
  MTK_DATUM_WGS84,
  MTK_DATUM_TOKYO_M,
  MTK_DATUM_TOKYO_A,
  MTK_DATUM_USER_SETTING,
  MTK_DATUM_ADINDAN_BURKINA_FASO,
  MTK_DATUM_ADINDAN_CAMEROON,
  MTK_DATUM_ADINDAN_ETHIOPIA,
  MTK_DATUM_ADINDAN_MALI,
  MTK_DATUM_ADINDAN_MEAN_FOR_ETHIOPIA_SUDAN,
  MTK_DATUM_ADINDAN_SENEGAL,
  MTK_DATUM_ADINDAN_SUDAN,
  MTK_DATUM_AFGOOYE_SOMALIA,
  MTK_DATUM_AIN_EL_ABD1970_BAHRAIN,
  MTK_DATUM_AIN_EL_ABD1970_SAUDI_ARABIA,
  MTK_DATUM_AMERICAN_SAMOA1962_AMERICAN_SAMOA,
  MTK_DATUM_ANNA_1_ASTRO1965_COCOS_ISLAND,
  MTK_DATUM_ANTIGU_ISLAND_ASTRO1943_ANTIGUA,
  MTK_DATUM_ARC1950_BOTSWANA,
  MTK_DATUM_ARC1950_BURUNDI,
  MTK_DATUM_ARC1950_LESOTHO,
  MTK_DATUM_ARC1950_MALAWI,
  MTK_DATUM_ARC1950_MEAN_FOR_BOTSWANA,
  MTK_DATUM_ARC1950_SWAZILAND,
  MTK_DATUM_ARC1950_ZAIRE,
  MTK_DATUM_ARC1950_ZAMBIA,
  MTK_DATUM_ARC1950_ZIMBABWE,
  MTK_DATUM_ARC1960_MEAN_FOR_KENYA_TANZANIA,
  MTK_DATUM_ARC1960_KENYA,
  MTK_DATUM_ARC1960_TAMZAMIA,
  MTK_DATUM_ASCENSION_ISLAND1958_ASCENSION,
  MTK_DATUM_ASTRO_BEACONE1945_IWO_JIMA,
  MTK_DATUM_ASTRO_DOS714_ST_HELENA_ISLAND,
  MTK_DATUM_ASTRO_TERN_ISLAND_FRIG1961_TERN_ISLAND,
  MTK_DATUM_ASTRONOMICAL_STATION1952_MARCUS_ISLAND,
  MTK_DATUM_AUSTRALIAN_GEODETIC1966_AUSTRALIA_TASMANIA,
  MTK_DATUM_AUSTRALIAN_GEODETIC1984_AUSTRALIA_TASMANIA,
  MTK_DATUM_AYABELLE_LIGHTHOUSE_DJIBOUTI,
  MTK_DATUM_BELLEVUE_IGN_EFATE_ERROMANGO_ISLAND,
  MTK_DATUM_BERMUDA1957_BERMUDA,
  MTK_DATUM_BISSAU_GUUINEA_BISSAU,
  MTK_DATUM_BOGOTA_OBSERVAORY_COLOMBIA,
  MTK_DATUM_BUKIT_RIMPAH_INDONESIA,
  MTK_DATUM_CAMP_AREA_ASTRO_ANTARCTICA,
  MTK_DATUM_CAMPO_INCHAUSPE_ARGENTINA,
  MTK_DATUM_CANTON_ASTRO1966_PHOENIX_ISLAND,
  MTK_DATUM_CAPE_SOUTH_AFRICA,
  MTK_DATUM_CAPE_CANAVERAL_BAHAMAS_FLORIDA,
  MTK_DATUM_CARTHAGE_TUNISIA,
  MTK_DATUM_CHATHAM_ISLAND_ASTRO1971_NEW_ZEALAND,
  MTK_DATUM_CHUA_ASTRO_PARAGUAY,
  MTK_DATUM_CORREGO_ALEGRE_BRAZIL,
  MTK_DATUM_DABOLA_GUINEA,
  MTK_DATUM_DECEPTION_ISLAND_DECEPTION_ISLAND_ANTARCTIA,
  MTK_DATUM_DJAKARTA_BATAVIA_INDONESIA_SUMATRA,
  MTK_DATUM_DOS1968_NEW_GEORGIA_ISLAND_GIZO_ISLAND,
  MTK_DATUM_EASTER_ISLAND1967_EASTER_ISLAND,
  MTK_DATUM_ESTONIA_COORDINATE_SYSTEM1937_ESTONIA,
  MTK_DATUM_EUROPEAN1950_CYPRUS,
  MTK_DATUM_EUROPEAN1950_EGYPT,
  MTK_DATUM_EUROPEAN1950_ENGLAND_CHANNEL_ISLANDS_SCOTLAND_SHETLAND_ISLANDS,
  MTK_DATUM_EUROPEAN1950_ENGLAND_IRELAND_SCOTLAND_SHETLAND_ISLANDS,
  MTK_DATUM_EUROPEAN1950_FINLAND_NORWAY,
  MTK_DATUM_EUROPEAN1950_GREECE,
  MTK_DATUM_EUROPEAN1950_IRAN,
  MTK_DATUM_EUROPEAN1950_ITALY_SARDINIA,
  MTK_DATUM_EUROPEAN1950_ITALT_SLCILY,
  MTK_DATUM_EUROPEAN1950_MALTA,
  MTK_DATUM_EUROPEAN1950_MEAN_FOR_AUSTRIA_BELGIUM,//_DENMARK_FINLAND_FRANCE_WGERMANY_GIBRALTAR_GREECE_ITALY_LUXEMBOURG_NETHERLANDS_NORWAY_PORTUGAL_SPAIN_SWEDEN_SWITZERLAND,
  MTK_DATUM_EUROPEAN1950_MEAN_FOR_AUSTRIA_DEBNMARK,//_FRANCE_WGERMANY_NETHERLAND_SWITZERLAND,
  MTK_DATUM_EUROPEAN1950_MEAN_FOR_IRAG_ISRAEL_JORDAN,//_LEBANON_KUWAIT_SAUDI_ARABIA_SYRIA,
  MTK_DATUM_EUROPEAN1950_PORTUGAL_SPAIN,
  MTK_DATUM_EUROPEAN1950_TUNISIA,
  MTK_DATUM_EUROPEAN1979_MEAN_FOR_AUSTRIA_FINLAND_,//NETHERLANDS_NORWAY_SPAIN_SWEDEN_SWITZERLAND,
  MTK_DATUM_FORT_THOMAS1955_NEVIS_ST_KITTS_LEEWARD_ISLANDS,
  MTK_DATUM_GAN1970_REPUBLIC_OF_MALDIVES,
  MTK_DATUM_GEODETIC_DATAUM1970_NEW_ZEALAND,
  MTK_DATUM_GRACIOSA_BASE_SW1948_AZORES_FAIAL_GRACIOSA_PICO_SAO,
  MTK_DATUM_GUAM1963_GUAM,
  MTK_DATUM_GUNUNG_SEGARA_INDONESIA_KALIMANTAN,
  MTK_DATUM_GUX_1_ASTRO_GUADALCANAL_ISLAND,
  MTK_DATUM_HERAT_NORTH_AFGHANISTAN,
  MTK_DATUM_HERMANNSKOGEL_DATUM_CROATIA_SERBIA_BOSNIA_HERZEGOIVNA,
  MTK_DATUM_HJORSEY1955_ICELAND,
  MTK_DATUM_HONGKONG1963_HONGKONG,
  MTK_DATUM_HU_TZU_SHAN_TAIWAN,
  MTK_DATUM_INDIAN_BANGLADESH,
  MTK_DATUM_INDIAN_INDIA_NEPAL,
  MTK_DATUM_INDIAN_PAKISTAN,
  MTK_DATUM_INDIAN1954_THAILAND,
  MTK_DATUM_INDIAN1960_VIETNAM_CON_SON_ISLAND,
  MTK_DATUM_INDIAN1960_VIETNAM_NEAR16N,
  MTK_DATUM_INDIAN1975_THAILAND,
  MTK_DATUM_INDONESIAN1974_INDONESIA,
  MTK_DATUM_IRELAND1965_IRELAND,
  MTK_DATUM_ISTS061_ASTRO1968_SOUTH_GEORGIA_ISLANDS,
  MTK_DATUM_ISTS073_ASTRO1969_DIEGO_GARCIA,
  MTK_DATUM_JOHNSTON_ISLAND1961_JOHNSTON_ISLAND,
  MTK_DATUM_KANDAWALA_SRI_LANKA,
  MTK_DATUM_KERGUELEN_ISLAND1949_KERGUELEN_ISLAND,
  MTK_DATUM_KERTAU1948_WEST_MALAYSIA_SINGAPORE,
  MTK_DATUM_KUSAIE_ASTRO1951_CAROLINE_ISLANDS,
  MTK_DATUM_KOREAN_GEODETIC_SYSTEM_SOUTH_KOREA,
  MTK_DATUM_LC5_ASTRO1961_CAYMAN_BRAC_ISLAND,
  MTK_DATUM_LEIGON_GHANA,
  MTK_DATUM_LIBERIA1964_LIBERIA,
  MTK_DATUM_LUZON_PHILIPPINES_EXCLUDING_MINDANAO,
  MTK_DATUM_LUZON_PHILLIPPINES_MINDANAO,
  MTK_DATUM_MPORALOKO_GABON,
  MTK_DATUM_MAHE1971_MAHE_ISLAND,
  MTK_DATUM_MASSAWA_ETHIOPIA_ERITREA,
  MTK_DATUM_MERCHICH_MOROCCO,
  MTK_DATUM_MIDWAY_ASTRO1961_MIDWAY_ISLANDS,
  MTK_DATUM_MINNA_CAMEROON,
  MTK_DATUM_MINNA_NIGERIA,
  MTK_DATUM_MONTSERRAT_ISLAND_ASTRO1958_MONTSERRAT_LEEWARD_ISLAND,
  MTK_DATUM_NAHRWAN_OMAN_MASIRAH_ISLAND,
  MTK_DATUM_NAHRWAN_SAUDI_ARABIA,
  MTK_DATUM_NAHRWAN_UNITED_ARAB_EMIRATES,
  MTK_DATUM_NAPARIMA_BWI_TRINIDAD_TOBAGO,
  MTK_DATUM_NORTH_AMERICAN1927_ALASKA_EXCLUDING_ALEUTIAN_IDS,
  MTK_DATUM_NORTH_AMERICAN1927_ALASKA_ALEUTIAN_IDS_EAST_OF_180W,
  MTK_DATUM_NORTH_AMERICAN1927_ALASKA_ALEUTIAN_IDS_WEST_OF_180W,
  MTK_DATUM_NORTH_AMERICAN1927_BAHAMAS_EXCEPT_SAN_SALVADOR_ISLANDS,
  MTK_DATUM_NORTH_AMERICAN1927_BAHAMAS_SAN_SALVADOR_ISLANDS,
  MTK_DATUM_NORTH_AMERICAN1927_CANADA_ALBERTA_BRITISH_COLUMBIA,
  MTK_DATUM_NORTH_AMERICAN1927_CANADA_MANITOBA_ONTARIO,
  MTK_DATUM_NORTH_AMERICAN1927_CANADA_NEW_BRUNSWICK_NEWFOUNDLAND_NOVA_SCOTIA_QUBEC,
  MTK_DATUM_NORTH_AMERICAN1927_CANADA_NORTHWEST_TERRITORIES_SASKATCHEWAN,
  MTK_DATUM_NORTH_AMERICAN1927_CANADA_YUKON,
  MTK_DATUM_NORTH_AMERICAN1927_CANAL_ZONE,
  MTK_DATUM_NORTH_AMERICAN1927_CUBA,
  MTK_DATUM_NORTH_AMERICAN1927_GREENLAND_HAYES_PENINSULA,
  MTK_DATUM_NORTH_AMERICAN1927_MEAN_FOR_ANTIGUA_BARBADOS_BARBUDA_CAICOS, // _ISLANDS_CUBA_DOMINICAN_GRAND_CAYMAN_JAMAICA_TURKS_ISLANDS,
  MTK_DATUM_NORTH_AMERICAN1927_MEAN_FOR_BELIZE_COSTA_RICA_SALVADOR_GUATEMALA,//_HONDURAS_NICARAGUA,
  MTK_DATUM_NORTH_AMERICAN1927_MEAN_FOR_CANADA,
  MTK_DATUM_NORTH_AMERICAN1927_MEAN_FOR_CONUS,
  MTK_DATUM_NORTH_AMERICAN1927_MEAN_FOR_CONUS_EAST_OF_MISSISSIPPI_RIVER, //_INCLUDING_LOUISIANA_MISSOURI_MINNESOTA,
  MTK_DATUM_NORTH_AMERICAN1927_MEAN_FOR_CONUS_WEST_OF_MISSISSIPPI_RIVER,//_EXCLUDING_LOUISIANA_MINNESOTA_MISSOURI,
  MTK_DATUM_NORTH_AMERICAN1927_MEXICO,
  MTK_DATUM_NORTH_AMERICAN1983_ALASKA_EXCLUDING_ALEUTIAN_IDS,
  MTK_DATUM_NORTH_AMERICAN1983_ALEUTIAN_IDS,
  MTK_DATUM_NORTH_AMERICAN1983_CANADA,
  MTK_DATUM_NORTH_AMERICAN1983_CONUS,
  MTK_DATUM_NORTH_AMERICAN1983_HAHWII,
  MTK_DATUM_NORTH_AMERICAN1983_MEXICO_CENTRAL_AMERICA,
  MTK_DATUM_NORTH_SAHARA1959_ALGERIA,
  MTK_DATUM_OBSERVATORIO_METEOROLOGICO1939_AZORES_CORVO_FLORES_ISLANDS,
  MTK_DATUM_OLD_EGYPTIAN1907_EGYPT,
  MTK_DATUM_OLD_HAWAIIAN_HAWAII,
  MTK_DATUM_OLD_HAWAIIAN_KAUAI,
  MTK_DATUM_OLD_HAWAIIAN_MAUI,
  MTK_DATUM_OLD_HAWAIIAN_MEAN_FOR_HAWAII_KAUAI_MAUI_OAHU,
  MTK_DATUM_OLD_HAWAIIAN_OAHU,
  MTK_DATUM_OMAN_OMAN,
  MTK_DATUM_ORDNANCE_SURVEY_GREAT_BRITIAN1936_ENGLAND,
  MTK_DATUM_ORDNANCE_SURVEY_GREAT_BRITIAN1936_ENGLAND_ISLE_OF_MAN_WALES,
  MTK_DATUM_ORDNANCE_SURVEY_GREAT_BRITIAN1936_MEAN_FOR_ENGLAND_ISLE_OF_MAN,//_SCOTLAND_SHETLAND_ISLAND_WALES,
  MTK_DATUM_ORDNANCE_SURVEY_GREAT_BRITIAN1936_SCOTLAND_SHETLAND_ISLANDS,
  MTK_DATUM_ORDNANCE_SURVEY_GREAT_BRITIAN1936_WALES,
  MTK_DATUM_PICO_DE_LAS_NIEVES_CANARY_ISLANDS,
  MTK_DATUM_PITCAIRN_ASTRO1967_PITCAIRN_ISLAND,
  MTK_DATUM_POINT58_MEAN_FOR_BURKINA_FASO_NIGER,
  MTK_DATUM_POINTE_NOIRE1948_CONGO,
  MTK_DATUM_PORTO_SANTO1936_PORTO_SANTO_MADERIA_ISLANDS,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_BOLOVIA,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_CHILE_NORTHERN_NEAR_19DS,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_CHILE_SOUTHERN_NEAN_43DS,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_COLOMBIA,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_ECUADOR,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_GUYANA,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_MEAN_FOR_BOLIVIA_CHILE,//_COLOMBIA_ECUADOR_GUYANA_PERU_VENEZUELA,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_PERU,
  MTK_DATUM_PROVISIONAL_SOUTH_AMERICAN1956_VENEZUELA,
  MTK_DATUM_PROVISIONAL_SOUTH_CHILEAN1963_CHILE_NEAR_53DS_HITO_XV3,
  MTK_DATUM_PUERTO_RICO_PUERTO_RICO_VIRGIN_ISLANDS,
  MTK_DATUM_PULKOVO1942_RUSSIA,
  MTK_DATUM_QATAR_NATIONAL_QATAR,
  MTK_DATUM_QORNOQ_GREENLAND_SOUTH,
  MTK_DATUM_REUNION_MASCARENE_ISLAND,
  MTK_DATUM_ROME1940_ITALY_SARDINIA,
  MTK_DATUM_S42_PULKOVO1942_HUNGARY,
  MTK_DATUM_S42_PULKOVO1942_POLAND,
  MTK_DATUM_S42_PULKOVO1942_CZECHOSLAVAKIA,
  MTK_DATUM_S42_PULKOVO1942_LATIVA,
  MTK_DATUM_S42_PULKOVO1942_KAZAKHSTAN,
  MTK_DATUM_S42_PULKOVO1942_ALBANIA,
  MTK_DATUM_S42_PULKOVO1942_ROMANIA,
  MTK_DATUM_SJTSK_CZECHOSLAVAKIA_PRIOR1_JAN1993,
  MTK_DATUM_SANTO_DOS1965_ESPIRITO_SANTO_ISLAND,
  MTK_DATUM_SAO_BRAZ_AZORES_SAO_MIGUEL_SANTA_MARIA_IDS,
  MTK_DATUM_SAPPER_HILL1943_EAST_FALKLAND_ISLAND,
  MTK_DATUM_SCHWARZECK_NAMIBIA,
  MTK_DATUM_SELVAGEM_GRANDE1938_SALVAGE_ISLANDS,
  MTK_DATUM_SIERRA_LEONE1960_SIERRA_LEONE,
  MTK_DATUM_SOUTH_AMERICAN1969_ARGENTINA,
  MTK_DATUM_SOUTH_AMERICAN1969_BOLIVIA,
  MTK_DATUM_SOUTH_AMERICAN1969_BRAZIAL,
  MTK_DATUM_SOUTH_AMERICAN1969_CHILE,
  MTK_DATUM_SOUTH_AMERICAN1969_COLOMBIA,
  MTK_DATUM_SOUTH_AMERICAN1969_ECUADOR,
  MTK_DATUM_SOUTH_AMERICAN1969_ECUADOR_BALTRA_GALAPAGOS,
  MTK_DATUM_SOUTH_AMERICAN1969_GUYANA,
  MTK_DATUM_SOUTH_AMERICAN1969_MEAN_FOR_ARGENTINA_BOLIVIA_BRAZIL,//_CHILE_COLOMBIA_ECUADOR_GUYANA_PARAGUAY_PERU_TRINIDAD_TOBAGO_VENEZUELA,
  MTK_DATUM_SOUTH_AMERICAN1969_PARAGUAY,
  MTK_DATUM_SOUTH_AMERICAN1969_PERU,
  MTK_DATUM_SOUTH_AMERICAN1969_TRINIDAD_TOBAGO,
  MTK_DATUM_SOUTH_AMERICAN1969_VENEZUELA,
  MTK_DATUM_SOUTH_ASIA_SINGAPORE,
  MTK_DATUM_TANANARIVE_OBSERVATORY1925_MADAGASCAR,
  MTK_DATUM_TIMBALAI1948_BRUNEI_E_MALAYSIA_SABAH_SARAWAK,
  MTK_DATUM_TOKYO_JAPAN,
  MTK_DATUM_TOKYO_MEAN_FOR_JAPAN_SOUTH_KOREA_OKINAWA,
  MTK_DATUM_TOKYO_OKINAWA,
  MTK_DATUM_TOKYO_SOUTH_KOREA,
  MTK_DATUM_TRISTAN_ASTRO1968_TRISTAM_DA_CUNHA,
  MTK_DATUM_VITI_LEVU1916_FIJI_VITI_LEVU_ISLAND,
  MTK_DATUM_VOIROL1960_ALGERIA,
  MTK_DATUM_WAKE_ISLAND_ASTRO1952_WAKE_ATOLL,
  MTK_DATUM_WAKE_ENIWETOK1960_MARSHALL_ISLANDS,
  MTK_DATUM_WGS1972_GLOBAL_DEFINITION,
  MTK_DATUM_WGS1984_GLOBAL_DEFINITION,
  MTK_DATUM_YACARE_URUGUAY,
  MTK_DATUM_ZANDERIJ_SURINAME
} MTK_GPS_DATUM;

/************************************************
 * defines for set_param and get_param
 ************************************************/
/*-------- keys --------*/
typedef enum
{
  MTK_PARAM_CMD_TERMINATE,
  MTK_PARAM_CMD_RESET_DSP,
  MTK_PARAM_CMD_RESET_KERNEL,
  MTK_PARAM_CMD_CONFIG,
  MTK_PARAM_CMD_TESTMODE,
  MTK_PARAM_CMD_RESTART,
  MTK_PARAM_DGPS_CONFIG,
  MTK_PARAM_NAV_CONFIG,
  MTK_PARAM_BUF_CONFIG,
  MTK_PARAM_LIB_VERSION,
  MTK_PARAM_LIB_RELEASE_INFO,
  MTK_PARAM_TCXO_SINGLE_CONFIG,
  MTK_PARAM_TCXO_MULTIPLE_CONFIG,
  MTK_PARAM_EPH_PROGRESS_CONFIG,
  MTK_PARAM_EPO_STAGE_CONFIG,
  MTK_PARAM_CMD_STOP,
  MTK_PARAM_CMD_SLEEP,
  MTK_PARAM_CMD_WAKEUP,
  MTK_PARAM_CMD_BLOCK,  
  MTK_PARAM_BEE_CONFIG,
  MTK_PARAM_BRDC_CONFIG,
  MTK_PARAM_FRAME_SYNC_RESP,  
  MTK_PARAM_CMD_CONFIG_EPO_DATA,
  MTK_PARAM_CMD_CONFIG_EPO_TIME,
  MTK_PARAM_CMD_CONFIG_EPO_POS,
  MTK_PARAM_CMD_CLR_CLK_DFT,
  MTK_MSG_EPO_REQ,
  MTK_MSG_EPO_RESP,
  MTK_MSG_BEE_REQ,
  MTK_MSG_BEE_RESP,  
  MTK_MSG_REQ_ASSIST,
  MTK_MSG_AGENT_BEE_REQ,
  MTK_MSG_AGENT_SUPL_REQ,
  MTK_MSG_BEE_IND,
  MTK_MSG_AGPS_MSG_REQ_NI,
  MTK_MSG_AGPS_MSG_SUPL_PMTK,
  MTK_MSG_AGPS_MSG_SUPL_TERMINATE,
  MTK_MSG_AGPS_MSG_PROFILE,  
  MTK_MSG_AGPS_MSG_RESET_SM,  
  MTK_MSG_VTIMER_IND,
  MTK_MSG_AL_CFG,
  MTK_MSG_AL_DEE_CFG,
  MTK_PARAM_SYSTEM_CONFIG,
  MTK_PARAM_SYSTEM_STATUS,
  MTK_PARAM_CMD_SEARCH_QZSS,
  MTK_PARAM_CMD_LOW_SPEED_FILTERING,
  MTK_PARAM_NMEA_OUTPUT,
  MTK_PARAM_CMD_RTC_CFG,
  MTK_PARAM_CMD_MNL_INIT,
  MTK_MSG_AGPS_MSG_AGENT_TERMINATE,
  MTK_PARAM_QUERY_AGC,
  MTK_MSG_RAW_MEAS,
  MTK_MSG_REPLACE_LLH
} MTK_GPS_PARAM;

/*------- values -------*/
/* MTK_PARAM_CMD_TERMINATE : terminate GPS main thread: no payload */

/* MTK_PARAM_CMD_CONFIG : schedule an event for get/set aiding data or config:
   no payload */

/* MTK_PARAM_CMD_TESTMODE : enter/leave a test mode */
typedef enum
{
  MTK_TESTMODE_OFF = 0,
  MTK_TESTMODE_CHANNEL,
  MTK_TESTMODE_JAMMER,
  MTK_TESTMODE_PHASE,
  MTK_TESTMODE_PER,
  MTK_TESTMODE_TTICK_OVERFLOW,
  MTK_TESTMODE_ENTER_MP,
  MTK_TESTMODE_LEAVE_MP,
  MTK_TESTMODE_CW_MODE,
  MTK_TESTMODE_GNSS_JAMMER
} MTK_GPS_TESTMODE;

typedef struct
{
  MTK_GPS_TESTMODE test_mode;
  UINT8     svid;
  UINT8     SVid_GLO1;    // SVid_GLO1    :  201 ~214 to represent GLONASS Frequency ID
  UINT8     SVid_GLO2;    // SVid_GLO2    :  for example, GLONASS FreqID = -7 ==> SVid_GLO1 = -7 +208 = 201;
  UINT8     SVid_GLO3;    // SVid_GLO3    :  for example, GLONASS FreqID = 6 ==> SVid_GLO1 = 6 +208 = 214;
  UINT8     SVid_BD;
  UINT32    time;
  UINT8     threshold;
  UINT16    targetCount;
} MTK_GPS_PARAM_TESTMODE;

/* MTK_PARAM_CMD_RESTART : trigger restart of GPS main thread and dsp code */
typedef struct
{
  MTK_GPS_START_TYPE restart_type;      /* MTK_GPS_START_HOT, MTK_GPS_START_WARM, MTK_GPS_START_COLD, MTK_GPS_START_FULL */
} MTK_GPS_PARAM_RESTART;

/* MTK_PARAM_BEE_CONFIG : configuration of bee */
typedef struct
{
  MTK_GPS_BEE_EN bee_en;      /* MTK_BEE_DISABLE MTK_BEE_ENABLE */
} MTK_GPS_PARAM_BEE_CONFIG;

/* MTK_PARAM_BRDC_CONFIG : configuration of broadcast satellite data */
typedef struct
{
  MTK_GPS_BRDC_EN brdc_en;      /* MTK_BRDC_DISABLE MTK_BRDC_ENABLE */
} MTK_GPS_PARAM_BRDC_CONFIG;


typedef struct
{
    UINT8  ucSVid;
    UINT16 u2Weekno;
    char data[24];
}MTK_AIDING_PARAM_ALMANAC;

typedef struct
{
    UINT8  ucSVid;
    char data[72];
}MTK_AIDING_PARAM_EPHEMERIS;

typedef struct
{
    UINT16 u2Weekno;
    double     Tow;
    float      timeRMS;
}MTK_AIDING_PARAM_TIME;

typedef struct
{
    double LLH[3];
}MTK_AIDING_PARAM_POSITION;

typedef struct
{
    UINT8 SVid;
    UINT8 SVid_GLO1;
    UINT8 SVid_GLO2;
    UINT8 SVid_GLO3;
    UINT8 SVid_BD;
    INT32 action;
}MTK_PARAM_CHN_TEST;

typedef struct
{
    UINT16 mode;
    UINT16 arg;
    INT32 action;
}MTK_PARAM_JAMMER_TEST;

typedef struct
{
    INT32 action;
    UINT32 time;
    UINT8 SVid;
}MTK_PARAM_PHASE_TEST;

typedef struct
{
    INT16 Threshold;
    UINT16 SVid;
    UINT16 TargetCount;
}MTK_PARAM_PER_TEST;

typedef struct
{
    UINT8 fgSyncGpsTime;
    INT32 i4RtcDiff;
}MTK_PARAM_TIME_UPDATE_NOTIFY;

typedef struct
{
    MTK_GPS_DBG_TYPE DbgType;
    MTK_GPS_DBG_LEVEL DbgLevel;
}MTK_PARAM_DEBUG_CONFIG;



//mtk_gps_debug_config(mtk_gps_dbg_type DbgType, mtk_gps_dbg_level DbgLevel)


/* MTK_PARAM_SYSTEM_CONFIG : configuration of system parameters */
typedef struct
{
  MTK_GPS_USER_SYSTEM_CONFIG system_config_type;   /* system config type */
  UINT32 system_config_value;              /* set/get system config  value*/
  MTK_AIDING_PARAM_EPHEMERIS param_eph; 
  MTK_AIDING_PARAM_ALMANAC  param_almanac;
  MTK_AIDING_PARAM_POSITION param_position;
  MTK_AIDING_PARAM_TIME     param_time;
  MTK_PARAM_TIME_UPDATE_NOTIFY param_time_update_notify;
  MTK_PARAM_DEBUG_CONFIG param_debug_config;
    // 
  MTK_PARAM_CHN_TEST       param_chn_test;
  MTK_PARAM_JAMMER_TEST  param_jam_test;
  MTK_PARAM_PHASE_TEST   param_pha_test;
  MTK_PARAM_PER_TEST     param_per_test;
  MTK_GPS_TCXO_MODE      param_tcxo_mode; 
  //
  INT32 i4RtcDiff;
  UINT8 TSX_XVT;
  
} MTK_GPS_PARAM_SYSTEM_CONFIG;

/* MTK_PARAM_SYSTEM_STATUS : status of system parameters */
typedef struct
{
  MTK_GPS_SYSTEM_STATUS system_status_type;   /* system status type */
  UINT32 system_status_value;              /* set/get system status value*/
} MTK_GPS_PARAM_SYSTEM_STATUS;

/* MTK_PARAM_DGPS_CONFIG */
typedef struct
{
  MTK_GPS_DGPS_MODE dgps_mode;          /* Off/RTCM/SBAS */
  UINT8     dgps_timeout;           /* DGPS timeout in seconds */
  MTK_GPS_BOOL      sbas_test_mode;         /* TRUE=test; FALSE=integrity */
  UINT8     sbas_prn;               /* 0=automatic; 120-139=specific PRN */
  MTK_GPS_BOOL      full_correction;        /* SBAS data correction mode */
                                        /* TRUE=full [Fast/Long-Term and IONO] */
                                        /* FALSE=partial [Fast/Long-Term or IONO] */
  MTK_GPS_BOOL      select_corr_only;       /* satellite selection mode */
                                        /* TRUE=only SVs with corrections */
                                        /* FALSE=any SVs available */
} MTK_GPS_PARAM_DGPS_CFG;

/* MTK_PARAM_NAV_CONFIG */
typedef struct
{
  UINT32    fix_interval;           /* fix interval in milliseconds */
                                        /* 1000=>1Hz, 200=>5Hz, 2000=>0.5Hz */
  MTK_GPS_DATUM datum;                  /* datum */
  INT8      elev_mask;              /* elevation angle mask in degree */
} MTK_GPS_PARAM_NAV_CFG;

/*  MTK_PARAM_BUF_CONFIG */
typedef struct
{
  UINT16    buf_empty_threshold;    /* If the buffer free space reach this value
                                           then it will report to callback once */
  UINT16    buf_empty_size;         /* Buffer free space in bytes, read only */
} MTK_GPS_PARAM_BUF_CFG;

/*  MTK_PARAM_AL_CONFIG : config always locate */
typedef enum
{
  MTK_AL_TYPE_NORMAL        =  0, // Navigation
  MTK_AL_TYPE_USER_PERIODIC =  1, // User periodic mode
  MTK_AL_TYPE_AUTO_PERIODIC =  9  // Auto periodic mode
} MTK_GPS_AL_TYPE;

typedef struct
{
  MTK_GPS_AL_TYPE type;                 /* application type */
  UINT32      u4FirstRunTime;              /* run time for peridic mode, (milli-second) */
  UINT32      u4FirstSlpTime;              /* sleep time for peridic mode, (milli-second)*/
  UINT32      u4SecondRunTime;              /* run time for peridic mode, (milli-second) */
  UINT32      u4SecondSlpTime;              /* sleep time for peridic mode, (milli-second)*/
} MTK_PARAM_AL_CFG;

typedef struct
{
  UINT8       u1SV ;                /* SV number for DEE extension start criterion */
  UINT8       u1SNR;              /* SNR threshold for DEE extension start criterion */
  UINT32     u4ExtensionThreshold;     /* Extension time limitation for DEE, (milli-second) */
  UINT32     u4ExtensionGap;              /* Extension gap limitation between neighbor DEE , (milli-second)*/
} MTK_PARAM_AL_DEE_CFG;

typedef struct
{
  UINT32     u4EPOWORD[18];        /* 18 words [LSB first] of one EPO segment data (total 72 bytes) */
  UINT8      u1SatID;              /* 1~32 */
} MTK_GPS_PARAM_EPO_DATA_CFG;

typedef struct 
{
  UINT16      u2YEAR ;             /* > 2000 */
  UINT8       u1MONTH;             /* 1~12 */
  UINT8       u1DAY;               /* 1~31*/
  UINT8       u1HOUR;              /* 0~23*/
  UINT8       u1MIN;               /* 0~59*/ 
  UINT8       u1SEC;               /* 0~59*/ 
} MTK_GPS_PARAM_EPO_TIME_CFG;

typedef struct 
{
  double      dfLAT;              /* > -90 and <90 (degree)*/
  double      dfLON;              /* > -180 and <180 (degree)*/
  double      dfALT;              /* (m) */ 
  UINT16      u2YEAR;               /* > 2000 */
  UINT8       u1MONTH;             /* 1~12 */
  UINT8       u1DAY;               /* 1~31*/
  UINT8       u1HOUR;              /* 0~23*/
  UINT8       u1MIN;               /* 0~59*/ 
  UINT8       u1SEC;               /* 0~59*/ 
} MTK_GPS_PARAM_EPO_POS_CFG;

typedef struct
{
  float      r4TcxoOffest;        /*  TCXO offest frequency (Hz)*/
  UINT8      u1SatID;              /* 1~32 */
} MTK_GPS_PARAM_TCXO_CFG;

typedef struct
{
  float         r4EphProgress[MTK_GPS_SV_MAX_PRN];        /* The current Eph Progress (0~1)*/
} MTK_GPS_PARAM_EPH_PROGRESS_CFG;

typedef struct
{
  UINT32     u4EpoStage;              /* The invalid/valid Epo Stage in bit map format(0/1)*/
} MTK_GPS_PARAM_EPO_STAGE_CFG; 

typedef enum
{
  MTK_GPS_FS_RESULT_INIT = 0,           /* FS request initial value  */
  MTK_GPS_FS_RESULT_ERR,                /* FS request error and clear naram's data  */
  MTK_GPS_FS_RESULT_ERR_NOT_CLR,        /* FS request error but don't clear nvram's data */
  MTK_GPS_FS_RESULT_OK                  /* FS request success */  
} MTK_GPS_FS_RESULT;

typedef enum
{
  MTK_GPS_FS_WORK_MODE_AIDING = 0,      /* FS request for aiding phase  */
  MTK_GPS_FS_WORK_MODE_MAINTAIN         /* FS request for maintain phase  */
} MTK_GPS_FS_WORK_MODE;

/* MTK_PARAM_FRAME_SYNC_RESP : receive a result of a frame sync meas request */
typedef struct
{
  MTK_GPS_FS_RESULT eResult;            /* frame sync measurement request result */  
  double            dfFrameTime;        /* frame time of the issued frame pulse */
} MTK_GPS_PARAM_FRAME_SYNC_RESP;

/* MTK_PARAM_QZSS_SEARCH_CONFIG : configuration of broadcast satellite data */
typedef struct
{
  MTK_QZSS_SEARCH_MODE qzss_en;      /* MTK_QZSS_DISABLE MTK_QZSS_ENABLE */
} MTK_PARAM_QZSS_SEARCH_MODE;


/* MTK_PARAM_LOW_SPEED_FILTERING_CONFIGURATION : configuration of low speed filtering setting */
typedef struct
{
  MTK_LOW_SPEED_FILTERING_MODE low_speed_filtering_en;      /* MTK_LOW_SPEED_FILTERING_SETTING */
} MTK_PARAM_LOW_SPEED_FILTERING;



/* MTK_PARAM_QUERY_AGC : query AGC value */
typedef struct
{
  UINT16 u2AGC;               /* AGC value */
} MTK_GPS_PARAM_QUERY_AGC_VALUE;


/*  MTK_PARAM_PMTK_CMD : receive a PMTK message for BEE safety design */
#define MTK_PMTK_CMD_MAX_SIZE            256
typedef struct
{
  char pmtk[MTK_PMTK_CMD_MAX_SIZE];         /* Buffer free space in bytes, read only */
} MTK_GPS_PARAM_PMTK_CMD;

typedef struct
{
  UINT16  u2Bitmap;
  INT16   i2WeekNo;
  INT32   i4Tow;
  MTK_GPS_BOOL    fgFirstReq;
} MTK_GPS_PARAM_AGPS_REQ;

typedef struct
{
  UINT16 u2AckCmd;
  UINT8 u1Flag;
} MTK_GPS_PMTKD_001T;

typedef struct{
  double dfRtcDltTime;
} MTK_GPS_PMTKD_243_T;

typedef struct{
  MTK_GPS_BOOL fgSet; // reference location: 0 - clear,  1 - set
  double dfRefLat;
  double dfRefLon;
  float fRefAlt;
} MTK_GPS_PMTKD_244_T;

typedef struct
{
    UINT16 u2Cmd;  // PMTK command ID:
                       // please get the data arguements in the following corresponding data structure.
    union
    {
        MTK_GPS_PMTKD_001T rAck;              // PMTK001
    } uData;
} MTK_GPS_PMTK_RESPONSE_T;

typedef struct
{
  UINT16    u2Cmd;  // PMTK command ID: if the PMTK command has data arguments,
                        // please assign the data in the following corresponding data structure.
  union
  {
    MTK_GPS_PMTKD_243_T r243;
    MTK_GPS_PMTKD_244_T r244;
  } uData;
} MTK_GPS_PMTK_DATA_T;


typedef struct 
{
  UINT16 type;
  UINT16 mcc; 
  UINT16 mnc;  
  UINT16 lac; 
  UINT16 cid;
} MTK_GPS_REF_LOCATION_CELLID;

typedef struct
{  
  UINT8 mac[6];
} MTK_GPS_REF_LOCATION_MAC;

/** Represents ref locations */
typedef struct 
{
  UINT16 type; // 0 : Cell ID; 1: MAC
  union 
  {
     MTK_GPS_REF_LOCATION_CELLID   cellID; 
     MTK_GPS_REF_LOCATION_MAC      mac;
  }u;
} MTK_GPS_REF_LOCATION;


typedef enum
{
  MTK_IF_SW_EMULATION = 0,
  MTK_IF_UART_NO_HW_FLOW_CTRL,
  MTK_IF_UART_HW_FLOW_CTRL,
  MTK_IF_SPI,
  MTK_IF_APB
} MTK_GPS_IF_TYPE;

typedef enum
{
  MTK_PPS_DISABLE = 0,
  MTK_PPS_ENABLE_1PPS,
  MTK_PPS_ENABLE_NPPS
} MTK_GPS_PPS_MODE;

// ******************   Important Notice *************************//
// In oder to make sure the GNSS configuration works correctly, 
// Please delete "mtk_gps.dat" after change the MTK_GNSS_CONFIGURATION setting.
typedef enum
{
  MTK_CONFIG_GPS_GLONASS = 0,
  MTK_CONFIG_GPS_BEIDOU,
  MTK_CONFIG_GPS_GLONASS_BEIDOU,
  MTK_CONFIG_GPS_ONLY,
  MTK_CONFIG_BEIDOU_ONLY,
  MTK_CONFIG_GLONASS_ONLY
} MTK_GNSS_CONFIGURATION;


// for AOSP AGPS:
//   1. PMTK data don't encript
//   2. don't output PMTK010 to AGPSD
typedef enum
{
    MTK_GPS_NORMAL_MODE = 0, // used for legacy AGPS 
    MTK_GPS_AOSP_MODE = 1,   // used in AOSP AGPS 
}MTK_GPS_VERSION_MODE;

/* factory default configuration for mtk_gps_init() */
typedef struct
{
  MTK_GPS_IF_TYPE   if_type;        /* interface type UART/SPI */
  MTK_GPS_PPS_MODE  pps_mode;       /* 1PPS mode */
  MTK_GPS_DATUM     datum;          /* datum */
  MTK_GPS_DGPS_MODE dgps_mode;  /* Off/RTCM/SBAS */
  MTK_GPS_TCXO_MODE tcxo_mode;
  UINT16    pps_duty;       /* PPS pulse high duration (ms) */
  UINT8     pps_port;       /* pps output port select */
  UINT8     u1ClockType;    // FLASH_SIG_USE_16368_TCXO         0     // 16.368M integer, the most stable
                            // FLASH_SIG_USE_16369M_TCXO    1    // 16.369M integer, generated freq has bias
                            // FLASH_SIG_USE_26M_FRAC_TCXO  2    // not used
                            // FLASH_SIG_USE_26M_INT_TCXO   3    // 26M integer, generated freq has bias, 
                            // FLASH_SIG_USE_WIDERANGE_XTAL 0xFE // wide range crystal.
                            // FLASH_SIG_USE_WIDERANGE      0xFF // wide range, more power consumption, no freq bias 
  UINT16    hw_Clock_Drift;    /* TCXO clock drift in ppb (500=0.5ppm; 2500=2.5ppm) */
  UINT32    hw_Clock_Freq;     /* TCXO frequency in Hz */
  UINT32    if_link_spd;    /* interface link speed (bps of UART) */
  UINT32    fix_interval;   /* fix interval in milliseconds */
                                /* 1000=>1Hz, 200=>5Hz, 2000=>0.5Hz */
  UINT8     Int_LNA_Config; /* for 3326, 1: internal LNA, for 3336,1: high gain, for 3332, 1: high gain */

  UINT32    reservedx;
  void*     reservedy;
  MTK_GNSS_CONFIGURATION  GNSSOPMode;      // In oder to make sure the GNSS configuration works correctly, 
                                           // Please delete "mtk_gps.dat" after change the MTK_GNSS_CONFIGURATION setting.
  UINT32 C0;
  UINT32 C1;
  UINT32 initU;
  UINT32 lastU;
  MTK_GPS_VERSION_MODE mtk_gps_version_mode; //AOSP or not
} MTK_GPS_INIT_CFG;


typedef struct
{
  UINT32       nmea_link_spd; //NMEA Baydrate
  UINT8        DebugType;       
                  // 1: Enable Agent debug
                   // 0: Disable Agent debug
  char         nv_file_name[30]; // NV ram file name
  char         dbg_file_name[GPS_DEBUG_LOG_FILE_NAME_MAX_LEN]; // NMEA dbg file name
  char         dsp_port_name[30];  //DSP port name
  char         nmea_port_name[30]; //NMEA out port name
  char         nmeain_port_name[30];//NMEA in port name
  UINT8        bee_path_name[30];  // HS patch name
  UINT8        epo_file_name[30]; // epo working file
  UINT8        epo_update_file_name[30]; // epo updated file
  INT32        gps_test_mode; // GPS TEST MODE, 1: Enable TSET MODE, 0 : Normal MODE 
  UINT8        u1AgpsMachine; // 0: for field test or Spirent ULTS (Default value in MNL), 1: R&S CRTU
  int          dsp_fd;
  UINT8        reserved;
  UINT32       log_file_max_size; //The max size limitation of one debug log file, 1MB(1024*1024)~48MB(48*1024*1024), default is 20MB
  UINT32       log_folder_max_size; //The max size limitation of the debug log folder, log_file_max_size*12~512MB(512*1024*1024), default is 240MB
} MTK_GPS_DRIVER_CFG;

/** GPS measurement support **/
typedef struct
{
   UINT32 size;
   UINT32 flag;
   INT8 PRN;
   double TimeOffsetInNs;
   UINT16 state;
   INT64 ReGpsTowInNs;                    //Re: Received
   INT64 ReGpsTowUnInNs;               //Re: Received, Un:Uncertainty
   double Cn0InDbHz;
   double PRRateInMeterPreSec;       // PR: Pseuderange
   double PRRateUnInMeterPreSec;   // PR: Pseuderange Un:Uncertainty
   UINT16 AcDRState10;                      // Ac:Accumulated, DR:Delta Range
   double AcDRInMeters;                    // Ac:Accumulated, DR:Delta Range
   double AcDRUnInMeters;                // Ac:Accumulated, DR:Delta Range, Un:Uncertainty
   double PRInMeters;                        // PR: Pseuderange
   double PRUnInMeters; 
   double CPInChips;                          // CP: Code Phase
   double CPUnInChips;                      // CP: Code Phase
   float CFInhZ;                                  // CP: Carrier Frequency
   INT64 CarrierCycle;
   double CarrierPhase;
   double CarrierPhaseUn;                 // Un:Uncertainty
   UINT8 LossOfLock;
   INT32 BitNumber;
   INT16 TimeFromLastBitInMs;
   double DopperShiftInHz;
   double DopperShiftUnInHz;           // Un:Uncertainty
   UINT8 MultipathIndicater;
   double SnrInDb;
   double ElInDeg;                             // El: elevation
   double ElUnInDeg;                         // El: elevation, Un:Uncertainty
   double AzInDeg;                            // Az: Azimuth
   double AzUnInDeg;                        // Az: Azimuth
   char UsedInFix;
}MTK_GPS_MEASUREMENT;

typedef struct
{
   UINT32 size;
   UINT16 flag;
   INT16 leapsecond;
   UINT8 type;
   INT64 TimeInNs; 
   double TimeUncertaintyInNs;
   INT64 FullBiasInNs;
   double BiasInNs;
   double BiasUncertaintyInNs;
   double DriftInNsPerSec;
   double DriftUncertaintyInNsPerSec;
}MTK_GPS_CLOCK;

typedef struct
{
   UINT32 size;
   INT8 type;
   UINT8 prn;  
   INT16 messageID;
   INT16 submessageID;
   UINT32 length;
   UINT8 data[40]; // 10 word  
} MTK_GPS_NAVIGATION_EVENT;
// MTK_GPS_INIT_CFG.opmode defines
#define	MTK_INITCFG_OPMODE_2D_FIRSTFIX  (1 << 2)

// Task synchronization related type
typedef enum
{
  MTK_MUTEX_BIN_Q = 0,
  MTK_MUTEX_MSG_CNT,
  MTK_MUTEX_NV_HANDLE,
  MTK_MUTEX_DEBUG,
  MTK_MUTEX_MSG_Q,
  MTK_MUTEX_AGPS_MSG_CNT,
  MTK_MUTEX_AGPS_MSG_Q,  
  //#ifdef SUPPORT_MULTI_INTERFACE
  //#endif
  //MTK_MUTEX_STAGE1,  
  MTK_MUTEX_AARDVARK_I2C_DATA,  
  MTK_MUTEX_AARDVARK_I2C,
  MTK_MUTEX_AARDVARK_SPI,
  MTK_MUTEX_FILE,
  MTK_MUTEX_END
} MTK_GPS_MUTEX_ENUM;

typedef enum
{
  MTK_EVENT_GPS = 0,
  MTK_EVENT_HS,
  MTK_EVENT_AGENT,
  MTK_EVENT_FILE,
  MTK_EVENT_END
} MTK_GPS_EVENT_ENUM;

typedef enum
{
    GPS_MNL_THREAD_UNKNOWN      = -1,
    GPS_MNL_THREAD_DSP_INPUT    = 0,
    GPS_MNL_THREAD_PMTK_INPUT   = 1,
    GPS_MNL_THREAD_BEE          = 2,
    GPS_MNL_THREAD_MNL          = 3,
    GPS_MNL_THREAD_AGENT        = 4,
    GPS_MNL_THREAD_FILE_CONTROL = 5,
    GPS_MNL_THREAD_NUM          = 6
} MTK_GPS_THREAD_ID_ENUM;

typedef enum
{
  MNL_STATUS_DEF = 0,
  MNL_DSP_UART_INIT_ERR,
  MNL_NMEA_UART_INIT_ERR,
  MNL_NMEAIN_UART_INIT_ERR,
  MNL_GPS_HW_CHECK_ERR,
  MNL_GPS_MUTEX_INIT_ERR,
  MNL_GPS_MUTEX_CREATE_ERR,
  MNL_MNL_THREAD_CREATE_ERR,
  MNL_MNL_THREAD_ADJUST_ERR,
  MNL_DSP_THREAD_CREATE_ERR,
  MNL_DSP_THREAD_ADJUST_ERR,
  MNL_PMTK_THREAD_CREATE_ERR,
  MNL_PMTK_THREAD_ADJUST_ERR,
  MNL_PMTK_APP_THREAD_CREATE_ERR,
  MNL_BEE_THREAD_CREATE_ERR,
  MNL_AGT_THREAD_CREATE_ERR,
  MNL_FILE_CONTROL_THREAD_CREATE_ERR,
  MNL_DSP_BOOT_ERR,
  MNL_INIT_SUCCESS
} MTK_GPS_BOOT_STATUS;


typedef enum
{
   HS_DEFAULT_STATUS,
   HS_INIT_ERR,
   HS_RUN_SUCCESS
}mtk_gps_hotstill_status;

typedef enum
{
    /*MT6620*/
    MT6620_E1 = 0,
    MT6620_E2,
    MT6620_E3,
    MT6620_E4,
    MT6620_EN,  // MUST smaller than 0x10
    /*MT6628*/
    MT6628_E1 = 0 + (0x10),
    MT6628_E2,
    MT6628_EN,  // MUST smaller then 0x20
    /*MT3332*/
    MT3332_E1 = 0 + (0x20),
    MT3332_E2,
    MT3332_EN,  // MUST smaller then 0x30
    /*MT3336*/
    MT3336_E1 = 0 + (0x30),
    MT3336_E2,
    MT3336_EN,
    MT6572_E1 = 0 + (0x40),
    MT6572_EN,
    MT6582_E1 = 0 + (0x50),
    MT6582_EN ,       
    MT6592_E1 = 0 + (0x60),
    MT6592_EN , 
    MT6571_E1 = 0 + (0x70),
    MT6571_EN,            
    MT6630_E1 = 0 + (0x80),
    MT6630_E2,
    MT6630_EN,
    MT6752_E1 = 0 + (0x90),
    MT6752_EN,
    MT6735_E1 = 0 + (0xA0),
    MT6735_EN,
    MT6735M_E1 = 0 + (0xB0),
    MT6735M_EN,
    MT6753_E1 = 0 + (0xC0),
    MT6753_EN    
}eMTK_GPS_CHIP_TYPE;

//#define MTK_GPS_THIP_KEY          (0xFFFF6620) //
#define MTK_GPS_CHIP_KEY_MT6620   (0xFFFF6620)
#define MTK_GPS_CHIP_KEY_MT6628   (0xFFFF6628)
#define MTK_GPS_CHIP_KEY_MT3332   (0xFFFF3332)
#define MTK_GPS_CHIP_KEY_MT3336   (0xFFFF3336)
#define MTK_GPS_CHIP_KEY_MT6572   (0xFFFF6572)
#define MTK_GPS_CHIP_KEY_MT6582   (0xFFFF6582)
#define MTK_GPS_CHIP_KEY_MT6592   (0xFFFF6592)
#define MTK_GPS_CHIP_KEY_MT6571   (0xFFFF6571)
#define MTK_GPS_CHIP_KEY_MT6630   (0xFFFF6630)
#define MTK_GPS_CHIP_KEY_MT6752   (0xFFFF6752)
#define MTK_GPS_CHIP_KEY_MT6735   (0xFFFF6735)
#define MTK_GPS_CHIP_KEY_MT6735M   (0xFFFE6735) // Denali 2 (GPS only)
#define MTK_GPS_CHIP_KEY_MT6753   (0xFFFF6753)


/* Return value for most APIs */
#define MTK_GPS_SUCCESS                 (0)
#define MTK_GPS_ERROR                   (-1)
#define MTK_GPS_ERROR_NMEA_INCOMPLETE   (-2)
#define MTK_GPS_ERROR_TIME_CHANGED      (1)
#define MTK_GPS_NO_MSG_RECEIVED         (1)


#define GPS_DELETE_EPHEMERIS        0x0001
#define GPS_DELETE_ALMANAC          0x0002
#define GPS_DELETE_POSITION         0x0004
#define GPS_DELETE_TIME             0x0008
#define GPS_DELETE_IONO             0x0010
#define GPS_DELETE_UTC              0x0020
#define GPS_DELETE_HEALTH           0x0040
#define GPS_DELETE_SVDIR            0x0080
#define GPS_DELETE_SVSTEER          0x0100
#define GPS_DELETE_SADATA           0x0200
#define GPS_DELETE_RTI              0x0400
#define GPS_DELETE_CLK              0x0800
#define GPS_DELETE_CELLDB_INFO      0x8000
#define GPS_DELETE_ALL              0xFFFF  


//start for AGPS_SUPPORT_GNSS 
#define GNSS_MAX_REF_TIME_SAT_ELEMENT                    16  /* 64 for LPP, 16 for RRC, 12 for RRLP. Use 16 to reduce structure size */
#define GNSS_MAX_REF_CELL_FTA_ELEMENT                    16  /* 16 for LPP, 1 for RRC/RRLP */

#define GNSS_MAX_GNSS_GENERIC_ASSIST_DATA_ELEMENT        16  /* 16 for LPP, 8 for RRC/RRLP in provide assistance data;
                                                                16 for LPP/RRLP, 8 for RRC in capability */

/* GNSS Time Model */
#define GNSS_MAX_TIME_MODEL_ELEMENT                       4  /* 15 for LPP, 7 for RRC/RRLP, Use 4 since gnss-TO-ID only 4 (GPS, Galileo, QZSS, GLONASS) */

/* GNSS DGNSS */
#define GNSS_MAX_DGNSS_SGN_TYPE_ELEMENT                   3  /* 3 for LPP/RRLP, 8 for RRC */
#define GNSS_MAX_DGNSS_CORRECTION_INFO_ELEMENT           16  /* 64 for LPP/RRC, 16 for RRLP. Use 16 to reduce structure size */

/* GNSS Navigation Model */
#define GNSS_MAX_NAV_SAT_ELEMENT                         16  /* 64 for LPP/RRC, 32 for RRLP. Use 16 to reduce structure size */
#define GNSS_MAX_NAV_SAT_ELEMENT_BIT_POS                 64  /* 64 for LPP/RRC, 32 for RRLP, dedicated for assist data req */
#define GNSS_MAX_NAV_STD_CLK_MODEL_ELEMENT                4  /* 2 for LPP/RRLP, 4 for RRC */
#define GNSS_MAX_NAV_CLOCK_MODEL_ELEMENT                  5  /* currently there is 5 clock models */
#define GNSS_MAX_NAV_ORBIT_MODEL_ELEMENT                  5  /* currently there is 5 orbit models */

/* GNSS Real Time Integrity */
#define GNSS_MAX_RTI_BAD_SAT_ELEMENT                     16  /* 64 for LPP/RRC, 16 for RRLP. Use 16 to reduce structure size */

/* GNSS Data Bit Assistance */
#define GNSS_MAX_DBA_SGN_TYPE_ELEMENT                     8  /* 8 for LPP/RRC/RRLP */
#define GNSS_MAX_DBA_SAT_ELEMENT                         16  /* 64 for LPP/RRC, 32 for RRLP. Use 16 to reduce structure size */
#define GNSS_MAX_DBA_BIT_LENGTH                          64  /* 1024 bit for LPP/RRC/RRLP, but RRLP use integer intead of bit. Process only max 64 bits to reduce structure size */

/* GNSS Acquisition Assitance */
#define GNSS_MAX_ACQ_ASSIST_SAT_ELEMENT                  16  /* 64 for LPP/RRC, 16 for RRLP. Use 16 to reduce structure size */

/* GNSS Almanac */
#define GNSS_MAX_ALMANAC_SAT_ELEMENT                     32  /* 64 for LPP/RRC, 36 for RRLP. Use 32 to reduce structure size */

/* GNSS Auxiliary Information */
#define GNSS_MAX_AUX_SAT_ELEMENT                         16  /* 64 for LPP/RRC/RRLP. Use 16 to reduce structure size */

/* GNSS Measurement Info */
#define GNSS_MAX_MEASURED_GNSS_ELEMENT                   GNSS_MAX_SUPPORT_NUM  /* 16 for LPP, 8 for RRC/RRLP, Use GNSS_MAX_SUPPORT_NUM (4) to reduce structure size */
#define GNSS_MAX_MEASURED_SGN_PER_GNSS_ELEMENT                              4  /* 8 for LPP/RRC/RRLP, Use 4 to reduce structure size */
#define GNSS_MAX_MEASURED_SAT_PER_SGN_ELEMENT                              16  /* 64 for LPP/RRC, 16 for RRLP. Use 16 to reduce structure size */

/* GNSS Request Additional Generic Assist Data */
#define GNSS_MAX_REQ_ADD_GENERIC_ASSIST_DATA_ELEMENT     GNSS_MAX_SUPPORT_NUM  /* 16 for LPP, 8 for RRC, unspecified for RRLP (up to 40 bytes), Use 9 since number of generic assistance data type is only 9 */


/* GNSS ID Bitmap, use one-byte representation */
#define GNSS_ID_BITMAP_NONE     0x00
#define GNSS_ID_BITMAP_GPS      0x8000  /* gps     (0) */
#define GNSS_ID_BITMAP_SBAS     0x4000  /* sbas    (1) */
#define GNSS_ID_BITMAP_QZSS     0x2000  /* qzss    (2) */
#define GNSS_ID_BITMAP_GALILEO  0x1000  /* galileo (3) */
#define GNSS_ID_BITMAP_GLONASS  0x0800  /* glonass (4) */

#define GNSS_ID_BITMAP_GPS_GLONASS  (GNSS_ID_BITMAP_GPS | GNSS_ID_BITMAP_GLONASS)

/* TBD: check with WCN, MT6630 support GPS+QZSS+GLONASS+Galileo+Beidou */
#define GNSS_MAX_SUPPORT_NUM    0x02 /* A-GPS + A-GLONASS */

/* SBAS ID Bitmap, use one-byte representation */
#define SBAS_ID_BITMAP_NONE   0x00
#define SBAS_ID_BITMAP_WASS   0x80  /* waas  (0) */
#define SBAS_ID_BITMAP_EGNOS  0x40  /* egnos (1) */
#define SBAS_ID_BITMAP_MSAS   0x20  /* msas	 (2) */
#define SBAS_ID_BITMAP_GAGAN  0x10  /* gagan (3) */

/* GNSS Signal IDs Bitmap, use one-byte representation
 * GNSS    | Bit 1  | Bit 2 | Bit 3 | Bit 4 | Bit 5 | Bit 6 | Bit 7 | Bit 8 |
 * --------+--------+-------+-------+-------+-------+-------+-------+-------+
 * GPS     | L1 C/A |  L1C  |  L2C  |   L5  | -- reserved --|-------|-------|
 * SBAS    | L1     | -- reserved --|-------|-------|-------|-------|-------|
 * QZSS    | QZS-L1 |QZS-L1C|QZS-L2C| QZS-L5| -- reserved --|-------|-------|
 * GLONASS | G1     |   G2  |  G3   | -- reserved --|-------|-------|-------|
 * Galileo | E1     |   E5a |  E5b  |   E6  |E5a+E5b| -- reserved --|-------|
*/
/* TBD: need confirmation GNSS signal spectrum from WCN */
#define GNSS_SGN_ID_BITMAP_GPS_L1C_A       0x80  /* bit 1 */
#define GNSS_SGN_ID_BITMAP_GPS_L1C         0x40  /* bit 2 */
#define GNSS_SGN_ID_BITMAP_GPS_L2C         0x20  /* bit 3 */
#define GNSS_SGN_ID_BITMAP_GPS_L5          0x10  /* bit 4 */

#define GNSS_SGN_ID_BITMAP_SBAS_L1         0x80  /* bit 1 */

#define GNSS_SGN_ID_BITMAP_QZSS_L1C_A      0x80  /* bit 1 */
#define GNSS_SGN_ID_BITMAP_QZSS_L1C        0x40  /* bit 2 */
#define GNSS_SGN_ID_BITMAP_QZSS_L2C        0x20  /* bit 3 */
#define GNSS_SGN_ID_BITMAP_QZSS_L5         0x10  /* bit 4 */

#define GNSS_SGN_ID_BITMAP_GLONASS_G1      0x80  /* bit 1 */
#define GNSS_SGN_ID_BITMAP_GLONASS_G2      0x40  /* bit 2 */
#define GNSS_SGN_ID_BITMAP_GLONASS_G3      0x20  /* bit 3 */

#define GNSS_SGN_ID_BITMAP_GALILEO_E1      0x80  /* bit 1 */
#define GNSS_SGN_ID_BITMAP_GALILEO_E5A     0x40  /* bit 2 */
#define GNSS_SGN_ID_BITMAP_GALILEO_E5B     0x20  /* bit 3 */
#define GNSS_SGN_ID_BITMAP_GALILEO_E6      0x10  /* bit 4 */
#define GNSS_SGN_ID_BITMAP_GALILEO_E5_A_B  0x08  /* bit 5 */

/* GNSS Signal ID value */
#define GNSS_SGN_ID_VALUE_GPS_L1C_A       0
#define GNSS_SGN_ID_VALUE_GPS_L1C         1
#define GNSS_SGN_ID_VALUE_GPS_L2C         2
#define GNSS_SGN_ID_VALUE_GPS_L5          3

#define GNSS_SGN_ID_VALUE_SBAS_L1         0

#define GNSS_SGN_ID_VALUE_QZSS_L1C_A      0
#define GNSS_SGN_ID_VALUE_QZSS_L1C        1
#define GNSS_SGN_ID_VALUE_QZSS_L2C        2
#define GNSS_SGN_ID_VALUE_QZSS_L5         3

#define GNSS_SGN_ID_VALUE_GLONASS_G1      0
#define GNSS_SGN_ID_VALUE_GLONASS_G2      1
#define GNSS_SGN_ID_VALUE_GLONASS_G3      2

#define GNSS_SGN_ID_VALUE_GALILEO_E1      0
#define GNSS_SGN_ID_VALUE_GALILEO_E5A     1
#define GNSS_SGN_ID_VALUE_GALILEO_E5B     2
#define GNSS_SGN_ID_VALUE_GALILEO_E6      3
#define GNSS_SGN_ID_VALUE_GALILEO_E5_A_B  4

#define GNSS_SGN_ID_VALUE_MAX             7

/* GNSS Clock and Orbit Model Value (for Navigation Model) */
#define GNSS_NAV_CLOCK_MODEL_1_VALUE_STANDARD  1  /* model-1 */
#define GNSS_NAV_CLOCK_MODEL_2_VALUE_NAV       2  /* model-2 */
#define GNSS_NAV_CLOCK_MODEL_3_VALUE_CNAV      3  /* model-3 */
#define GNSS_NAV_CLOCK_MODEL_4_VALUE_GLONASS   4  /* model-4 */
#define GNSS_NAV_CLOCK_MODEL_5_VALUE_SBAS      5  /* model-5 */

#define GNSS_NAV_ORBIT_MODEL_1_VALUE_KEPLERIAN_SET       1  /* model-1 */
#define GNSS_NAV_ORBIT_MODEL_2_VALUE_NAV_KEPLERIAN_SET   2  /* model-2 */
#define GNSS_NAV_ORBIT_MODEL_3_VALUE_CNAV_KEPLERIAN_SET  3  /* model-3 */
#define GNSS_NAV_ORBIT_MODEL_4_VALUE_GLONASS_ECEF        4  /* model-4 */
#define GNSS_NAV_ORBIT_MODEL_5_VALUE_SBAS_ECEF           5  /* model-5 */

/* Almanac Model Value */
#define GNSS_ALMANAC_MODEL_1_VALUE_KEPLERIAN_SET          1  /* model-1 */
#define GNSS_ALMANAC_MODEL_2_VALUE_NAV_KEPLERIAN_SET      2  /* model-2 */
#define GNSS_ALMANAC_MODEL_3_VALUE_REDUCED_KEPLERIAN_SET  3  /* model-3 */
#define GNSS_ALMANAC_MODEL_4_VALUE_MIDI_KEPLERIAN_SET     4  /* model-4 */
#define GNSS_ALMANAC_MODEL_5_VALUE_GLONASS_SET            5  /* model-5 */
#define GNSS_ALMANAC_MODEL_6_VALUE_ECEF_SBAS_SET          6  /* model-6 */

/* UTC Model Value */
#define GNSS_UTC_MODEL_1_VALUE  1  /* model-1 (0) */
#define GNSS_UTC_MODEL_2_VALUE  2  /* model-2 (1) */
#define GNSS_UTC_MODEL_3_VALUE  3  /* model-3 (2) */
#define GNSS_UTC_MODEL_4_VALUE  4  /* model-4 (3) */
/* Ionoshoeruc Model */
#define GNSS_ION_MODEL_KLOBUCHAR  0x80  /* klobuchar (0) */
#define GNSS_ION_MODEL_NEQUICK    0x40  /* neQuick   (1) */


/* Navigation Model */
#define GNSS_NAV_CLOCK_MODEL_1_STANDARD  0x80  /* model-1 (0) */
#define GNSS_NAV_CLOCK_MODEL_2_NAV       0x40  /* model-2 (1) */
#define GNSS_NAV_CLOCK_MODEL_3_CNAV      0x20  /* model-3 (2) */
#define GNSS_NAV_CLOCK_MODEL_4_GLONASS   0x10  /* model-4 (3) */
#define GNSS_NAV_CLOCK_MODEL_5_SBAS      0x08  /* model-5 (4) */

#define GNSS_NAV_ORBIT_MODEL_1_KEPLERIAN_SET       0x80  /* model-1 (0) */
#define GNSS_NAV_ORBIT_MODEL_2_NAV_KEPLERIAN_SET   0x40  /* model-2 (1) */
#define GNSS_NAV_ORBIT_MODEL_3_CNAV_KEPLERIAN_SET  0x20  /* model-3 (2) */
#define GNSS_NAV_ORBIT_MODEL_4_GLONASS_ECEF        0x10  /* model-4 (3) */
#define GNSS_NAV_ORBIT_MODEL_5_SBAS_ECEF           0x08  /* model-5 (4) */


/* Almanac */
#define GNSS_ALMANAC_MODEL_1_KEPLERIAN_SET          0x80  /* model-1 (0) */
#define GNSS_ALMANAC_MODEL_2_NAV_KEPLERIAN_SET      0x40  /* model-2 (1) */
#define GNSS_ALMANAC_MODEL_3_REDUCED_KEPLERIAN_SET  0x20  /* model-3 (2) */
#define GNSS_ALMANAC_MODEL_4_MIDI_KEPLERIAN_SET     0x10  /* model-4 (3) */
#define GNSS_ALMANAC_MODEL_5_GLONASS_SET            0x08  /* model-5 (4) */
#define GNSS_ALMANAC_MODEL_6_ECEF_SBAS_SET          0x04  /* model-6 (5) */


/* UTC Model*/
#define GNSS_UTC_MODEL_1  0x80  /* model-1 (0) */
#define GNSS_UTC_MODEL_2  0x40  /* model-2 (1) */
#define GNSS_UTC_MODEL_3  0x20  /* model-3 (2) */
#define GNSS_UTC_MODEL_4  0x10  /* model-4 (3) */



/* NNUM ********************************************************************/
typedef enum
{
    PMTK_CMD_VER_0 = 0,   //conversional GPS
    PMTK_CMD_VER_1 = 1,   //GNSS
    PMTK_CMD_VER_END
} MTK_GNSS_CMD_VER_ENUM;
typedef enum
{
    MTK_GPS_KLB_WILD_USE  = 0,   //KLB model only for QZSS
    MTK_GPS_KLB_QZSS_ONLY = 3,    //KLB model only for QZSS
    MTK_GPS_KLB_TYPE_END
} MTK_GPS_KLB_DATAID_ENUM;

typedef enum
{
    GNSS_NETWORK_CELL_NULL  = 0,
    GNSS_NETWORK_CELL_EUTRA = 1,
    GNSS_NETWORK_CELL_UTRA  = 2,
    GNSS_NETWORK_CELL_GSM   = 3,
    GNSS_NETWORK_CELL_END
} MTK_GNSS_NETWORK_CELL_ENUM;


typedef enum
{
    GNSS_ID_GPS     = 0,
    GNSS_ID_SBAS    = 1,
    GNSS_ID_QZSS    = 2,
    GNSS_ID_GALILEO = 3,
    GNSS_ID_GLONASS = 4,
    GNSS_ID_MAX_NUM
} MTK_GNSS_ID_ENUM;


typedef enum
{
    GNSS_TO_ID_GPS  = 1,
    GNSS_TO_ID_GALILEO ,
    GNSS_TO_ID_QZSS    ,
    GNSS_TO_ID_GLONASS ,
    GNSS_TO_ID_END
} MTK_GNSS_TO_ID_ENUM;


typedef enum
{
    SBAS_ID_WAAS   = 0,
    SBAS_ID_EGNOS  = 1,
    SBAS_ID_MSAS   = 2,
    SBAS_ID_GAGAN  = 3,
    SBAS_ID_END
} MTK_SBAS_ID_ENUM;


typedef enum
{
    GNSS_COMMON_ASSIST_TIM   = 0,
    GNSS_COMMON_ASSIST_LOC   = 1,
    GNSS_COMMON_ASSIST_ION   = 2,
    GNSS_COMMON_ASSIST_EOP   = 3,
    
} MTK_GNSS_COMMON_ASSIST_ENUM;


typedef enum
{
    GNSS_GENERIC_ASSIST_TMD   = 0,
    GNSS_GENERIC_ASSIST_DGNSS = 1,
    GNSS_GENERIC_ASSIST_EPH   = 2,
    GNSS_GENERIC_ASSIST_RTI   = 3,
    GNSS_GENERIC_ASSIST_DBA   = 4,
    GNSS_GENERIC_ASSIST_ACQ   = 5,
    GNSS_GENERIC_ASSIST_ALM   = 6,
    GNSS_GENERIC_ASSIST_UTC   = 7,
    GNSS_GENERIC_ASSIST_AUX   = 8,
    GNSS_GENERIC_ASSIST_END   = 9,
} MTK_GNSS_GENERIC_ASSIST_ENUM;


typedef enum
{
    GNSS_CLOCK_MODEL_TYPE_STANDARD,
    GNSS_CLOCK_MODEL_TYPE_NAV,
    GNSS_CLOCK_MODEL_TYPE_CNAV,
    GNSS_CLOCK_MODEL_TYPE_GLONASS,
    GNSS_CLOCK_MODEL_TYPE_SBAS
} gnss_clock_model_type_enum;


typedef enum
{
    GNSS_ORBIT_MODEL_TYPE_KEPLERIAN_SET,
    GNSS_ORBIT_MODEL_TYPE_NAV_KEPLERIAN_SET,
    GNSS_ORBIT_MODEL_TYPE_CNAV_KEPLERIAN_SET,
    GNSS_ORBIT_MODEL_TYPE_GLONASS_ECEF,
    GNSS_ORBIT_MODEL_TYPE_SBAS_ECEF
} gnss_orbit_model_type_enum;


typedef enum
{
    GNSS_ACQ_ASSIST_DOPPLER_UNCERTAINTY_EXT_ENUM_D60,
    GNSS_ACQ_ASSIST_DOPPLER_UNCERTAINTY_EXT_ENUM_D80,
    GNSS_ACQ_ASSIST_DOPPLER_UNCERTAINTY_EXT_ENUM_D100,
    GNSS_ACQ_ASSIST_DOPPLER_UNCERTAINTY_EXT_ENUM_D120,
    GNSS_ACQ_ASSIST_DOPPLER_UNCERTAINTY_EXT_ENUM_NO_INFO
} MTK_GNSS_ACQ_DOPP_UNCERT_EXT_ENUM;


typedef enum
{
    GNSS_ALMANAC_TYPE_KEPLERIAN_SET,
    GNSS_ALMANAC_TYPE_NAV_KEPLERIAN_SET,
    GNSS_ALMANAC_TYPE_REDUCED_KEPLERIAN_SET,
    GNSS_ALMANAC_TYPE_MIDI_KEPLERIAN_SET,
    GNSS_ALMANAC_TYPE_GLONASS_SET,
    GNSS_ALMANAC_TYPE_ECEF_SBAS_SET,
} gnss_almanac_type_enum;


typedef enum
{
    UTC_MODEL_GPS,
    UTC_MODEL_QZSS,
    UTC_MODEL_GLO,
    UTC_MODEL_SBAS,
    UTC_MODEL_UNKNOWN,
} MTK_GNSS_UTC_TYPE_ENUM;

typedef enum
{
    GNSS_AUX_TYPE_GPS,
    GNSS_AUX_TYPE_GLONASS
} MTK_GNSS_AUX_TYPE_ENUM;

//end for AGPS_SUPPORT_GNSS
#if ( defined(__ARMCC_VERSION) && (__ARMCC_VERSION < 200000 ))
// for ADS1.x
#elif ( defined(__ARMCC_VERSION) && (__ARMCC_VERSION < 400000 ) ) 
// for RVCT2.x or RVCT3.x
#else
#pragma pack()
#endif

#ifdef __cplusplus
   }
#endif

#endif /* MTK_GPS_TYPE_H */
