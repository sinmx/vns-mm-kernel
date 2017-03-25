/******************************************************************************

                  ��Ȩ���� (C), 2003-2013, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : phyerrorlog.h
  �� �� ��   : ����
  ��    ��   : ����ȫ/57356
  ��������   : 2013��9��21��
  ����޸�   :
  ��������   : ����ERRORLOG������ģʽ�ϱ�ʹ�õ�ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��09��21��
    ��    ��   : ����ȫ/57356
    �޸�����   : �����ļ�

******************************************************************************/

#ifndef __PHY_ERRORLOG_H__
#define __PHY_ERRORLOG_H__

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "vos.h"
#include "omerrorlog.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 �궨��
*****************************************************************************/



#define PHY_ERR_LOG_CTRL_LEVEL_NULL             (0)                             /* ErrLog�ȼ�δ����*/
#define PHY_ERR_LOG_CTRL_LEVEL_CRITICAL         (1)                             /* ErrLog�ȼ�Ϊ���� */
#define PHY_ERR_LOG_CTRL_LEVEL_MAJOR            (2)                             /* ErrLog�ȼ�Ϊ��Ҫ */
#define PHY_ERR_LOG_CTRL_LEVEL_MINOR            (3)                             /* ErrLog�ȼ�Ϊ��Ҫ */
#define PHY_ERR_LOG_CTRL_LEVEL_WARNING          (4)                             /* ErrLog�ȼ�Ϊ��ʾ */


/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/

/*****************************************************************************
 ö����    : PHY_ERR_LOG_ALM_TYPE_ENUM
 ö��˵��  : ���ϸ澯����
 1.��    ��   : 2013��09��23��
   ��    ��   : luoqingquan
   �޸�����   : �½�
*****************************************************************************/
enum PHY_ERR_LOG_ALM_TYPE_ENUM
{
    PHY_ERR_LOG_ALM_TYPE_COMMUNICATION    = 0x00,                               /* ͨ�� */
    PHY_ERR_LOG_ALM_TYPE_TRAFFIC_QUALITY  = 0x01,                               /* ҵ������ */
    PHY_ERR_LOG_ALM_TYPE_DEAL_WRONG       = 0x02,                               /* �������� */
    PHY_ERR_LOG_ALM_TYPE_DEVICE_FAILURE   = 0x03,                               /* �豸���� */
    PHY_ERR_LOG_ALM_TYPE_ENV_FAILURE      = 0x04,                               /* �������� */
    PHY_ERR_LOG_ALM_TYPE_BUTT
};
typedef VOS_UINT16 PHY_ERR_LOG_ALM_TYPE_ENUM_UINT16;


/*****************************************************************************
 ö����    : PHY_ERR_LOG_ALM_ID_ENUM
 ö��˵��  : ���ϸ澯ID
 1.��    ��   : 2013��09��23��
   ��    ��   : luoqingquan
   �޸�����   : �½�
*****************************************************************************/
enum PHY_ERR_LOG_ALM_ID_ENUM
{
    /* ������� */
    PHY_ERR_LOG_ALM_WCDMA_OUT_SYNC                      = 0x01,                 /* ʧ�� */
    PHY_ERR_LOG_ALM_WCDMA_BCCH_FAIL                     = 0x02,                 /* BCCHʧ�� */
    PHY_ERR_LOG_ALM_WCDMA_RL_FAIL                       = 0x03,                 /* ��·ʧ�� */
    PHY_ERR_LOG_ALM_GSM_DEC_FAIL                        = 0x04,                 /* DSC��¼ */
    PHY_ERR_LOG_ALM_GSM_RXLEV_MEAS                      = 0x05,                 /* ������¼ */
    PHY_ERR_LOG_ALM_GSM_FB_SB_IND                       = 0x06,                 /* ������¼ */
    PHY_ERR_LOG_ALM_RING_BUFFER_OVERFLOW                = 0x07,                 /* ����buffer�����¼ */
    PHY_ERR_LOG_ALM_TAS_GSM_INFO                        = 0x08,                 /* GSM_TAS�ؼ���Ϣ */
    PHY_ERR_LOG_ALM_TAS_WCDMA_INFO                      = 0x09,                 /* WCDMA_TAS�ؼ���Ϣ */
    PHY_ERR_LOG_ALM_GSM_CS_MR_ERROR                     = 0x0a,                 /* CS����������� */

    /* ��������ϸ澯 */
    PHY_ERR_LOG_ALM_CS_RLB                              = 0x1001,               /* CS ��·������ */
    PHY_ERR_LOG_ALM_CS_NO_UL_DATA                       = 0x1002,               /* CS ���������� */
    PHY_ERR_LOG_ALM_GSM_CS_ERROR_DETECT                 = 0x1003,               /* ��⵽�쳣error */
    PHY_ERR_LOG_ALM_GSM_DCXO_SAMPLE_ERR_DETECT          = 0x1004,               /* ��⵽DCXO�������쳣��CHR */

    /* ҵ������ϸ澯 */
    PHY_ERR_LOG_ALM_WCDMA_TX_POWER_DROP_DETECT          = 0x2001,               /* ��⵽���书��̫�� */
    PHY_ERR_LOG_ALM_WCDMA_PILOT_BER_RISE_DETECT         = 0x2002,               /* ��⵽pilotber���� */
    PHY_ERR_LOG_ALM_WCDMA_RA_INFO_DETECT                = 0x2003,               /* ��⵽��������ϱ���Ϣ */
    PHY_ERR_LOG_ALM_WCDMA_DCXO_SAMPLE_ERR_DETECT        = 0x2004,               /* ��⵽DCXO�������쳣��CHR */
    PHY_ERR_LOG_ALM_WCDMA_PD_ABNORMAL_DETECT            = 0x2005,               /* ��⵽PD����쳣��CHR */

    PHY_ERR_LOG_ALM_ID_BUTT
};
typedef VOS_UINT16 PHY_ERR_LOG_ALM_ID_ENUM_UINT16;


/*****************************************************************************
 ö����    : PHY_FTM_LOG_ID_ENUM
 ö��˵��  : ����ģʽ�ϱ��Ĺ���ID
 1.��    ��   : 2013��08��27��
   ��    ��   : l57356
   �޸�����   : �½�
*****************************************************************************/
enum PHY_FTM_LOG_ID_ENUM
{
    PHY_FTM_LOG_ID_WPHY,
    PHY_FTM_LOG_ID_GPHY,

    PHY_FTM_LOG_ID_BUTT,
};
typedef PHY_UINT16 PHY_FTM_LOG_ID_ENUM_UINT16;


/*****************************************************************************
 ö����    : PHY_WCDMA_RL_OUT_OF_SYNC_REASON_ENUM
 ö��˵��  : ע�������Ϣ
 1.��    ��   : 2013��09��21��
   ��    ��   : l57356
   �޸�����   : �½�
*****************************************************************************/
enum PHY_WCDMA_RL_OUT_OF_SYNC_REASON_ENUM
{
    PHY_WCDMA_RL_OUT_OF_SYNC_REASON_DEMOD        = 0x00,                        /* �ϱ�ԭ��Ϊ��� */
    PHY_WCDMA_RL_OUT_OF_SYNC_REASON_DECODE       = 0x01,                        /* �ϱ�ԭ��Ϊ���� */
    PHY_WCDMA_RL_OUT_OF_SYNC_REASON_BUTT
};
typedef VOS_UINT16 PHY_WCDMA_RL_OUT_OF_SYNC_REASON_ENUM_UINT16;



/*****************************************************************************
 ö����    : PHY_WCDMA_BCCH_FAIL_REASON_ENUM
 ö��˵��  : ע�������Ϣ
 1.��    ��   : 2013��09��21��
   ��    ��   : l57356
   �޸�����   : �½�
*****************************************************************************/
enum PHY_WCDMA_BCCH_FAIL_REASON_ENUM
{
    PHY_WCDMA_BCCH_FAIL_REASON_SFN_UPDATE_FAIL   = 0x00,                        /* �ϱ�ԭ��ΪSFN���� */
    PHY_WCDMA_BCCH_FAIL_REASON_CRC_ERR           = 0x01,                        /* �ϱ�ԭ��ΪCRC���� */
    PHY_WCDMA_BCCH_FAIL_REASON_SCHEDULE_FAIL     = 0x02,                        /* �ϱ�ԭ��Ϊ���ȴ��� */
    PHY_WCDMA_BCCH_FAIL_REASON_WORK_TIME_ERR     = 0x03,                        /* �ϱ�ԭ��Ϊ��ʱ���� */
    PHY_WCDMA_BCCH_FAIL_REASON_BUTT
};
typedef VOS_UINT16 PHY_WCDMA_BCCH_FAIL_REASON_ENUM_UINT16;


/*****************************************************************************
 ö����    : PHY_GSM_RPT_REASON_ENUM
 ö��˵��  : ע�������Ϣ
 1.��    ��   : 2013��09��21��
   ��    ��   : l57356
   �޸�����   : �½�
*****************************************************************************/
enum PHY_GSM_RPT_REASON_ENUM
{
    PHY_GSM_RPT_REASON_DSC                      = 0x00,                         /* �ϱ�ԭ��ΪDSC���� */
    PHY_GSM_RPT_REASON_CRC_ERR                  = 0x01,                         /* �ϱ�ԭ��ΪCRC���� */
    PHY_GSM_RPT_REASON_BUTT
};
typedef VOS_UINT16 PHY_GSM_RPT_REASON_ENUM_UINT16;


/*****************************************************************************
 ö����    : PHY_GSM_CS_ERROR_REASON_ENUM
 ö��˵��  : CS�����ڼ�澯�ϱ�ԭ��
 1.��    ��   : 2014��07��07��
   ��    ��   : j00178524
   �޸�����   : �½�
*****************************************************************************/
enum PHY_GSM_CS_ERROR_REASON_ENUM
{
    PHY_GSM_CS_ERROR_RLB            = 0,                         /* CS��·�� */
    PHY_GSM_CS_ERROR_NO_UL_DATA     = 1,                         /* �������������� */
    PHY_GSM_CS_ERROR_DETECT         = 2,                         /* �쳣error */
    PHY_GSM_CS_ERROR_REASON_BUTT
};
typedef VOS_UINT16 PHY_GSM_CS_ERROR_REASON_ENUM_UINT16;


/*****************************************************************************
 ö����    : PHY_WCDMA_CS_ERROR_REASON_ENUM_UINT16
 ö��˵��  : CS�����ڼ�澯�ϱ�ԭ��
 1.��    ��   : 2014��10��10��
   ��    ��   : l00184004
   �޸�����   : �½�
*****************************************************************************/
enum PHY_WCDMA_CS_ERROR_REASON_ENUM
{
    PHY_WCDMA_CS_ERROR_RLB          = 0,                        /* CS��·�� */
    PHY_WCDMA_CS_ERROR_NO_UL_DATA   = 1,                        /* �������������� */
    PHY_WCDMA_CS_ERROR_REASON_BUTT
};

typedef VOS_UINT16 PHY_WCDMA_CS_ERROR_REASON_ENUM_UINT16;
/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/



/*******************************************************************************
 �ṹ��    : PHY_WCDMA_ERRLOG_FG_INFO_STRU
 �ṹ˵��  : WCDMA���ɺ͸��º��ϱ�����Ϣ�ṹ��
 1.��    ��   : 2013��09��21��
   ��    ��   : l57356
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    VOS_UINT32                                  ulFgPos;
    VOS_UINT32                                  ulFgPower;
}PHY_WCDMA_ERRLOG_FG_INFO_STRU;


/*******************************************************************************
 �ṹ��    : PHY_ERRLOG_WCDMA_RL_OUT_OF_SYNC_EVENT_STRU
 �ṹ˵��  : WCDMA���ɺ͸��º��ϱ�����Ϣ�ṹ��
 1.��    ��   : 2013��09��21��
   ��    ��   : l57356
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                      stHeader;
    PHY_WCDMA_RL_OUT_OF_SYNC_REASON_ENUM_UINT16 enRlOutOfSyncReason;
    VOS_INT16                                   sTxPwr;
    VOS_INT16                                   sCQI;
    VOS_INT16                                   sRsv;
    VOS_UINT32                                  ulDemodSyncInfo;
    VOS_UINT32                                  ulDecSyncInfo;
    VOS_UINT32                                  ulDecOutSyncInfo;
    VOS_UINT16                                  usFgEn;
    VOS_UINT16                                  usFgLock;
    PHY_WCDMA_ERRLOG_FG_INFO_STRU               stFgInfo;
}PHY_ERRLOG_WCDMA_RL_OUT_OF_SYNC_EVENT_STRU;



/*******************************************************************************
 �ṹ��    : PHY_ERRLOG_WCDMA_RL_FAIL_EVENT_STRU
 �ṹ˵��  : WCDMA���ɺ͸��º��ϱ�����Ϣ�ṹ��
 1.��    ��   : 2013��09��21��
   ��    ��   : l57356
   �޸�����   : �½�
*******************************************************************************/

typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    PHY_WCDMA_BCCH_FAIL_REASON_ENUM_UINT16  enBcchFailReason;
    VOS_INT16                               sRsv;
    VOS_UINT16                              usFgEn;
    VOS_UINT16                              usFgLock;
    PHY_WCDMA_ERRLOG_FG_INFO_STRU           astFgInfo[3];
    VOS_UINT16                              usBcchCrcErrNum;
    VOS_UINT16                              usBgSchdlFailNum;
}PHY_ERRLOG_WCDMA_BCCH_FAIL_EVENT_STRU;




/*******************************************************************************
 �ṹ��    : PHY_ERRLOG_WCDMA_RL_FAIL_EVENT_STRU
 �ṹ˵��  : WCDMA���ɺ͸��º��ϱ�����Ϣ�ṹ��
 1.��    ��   : 2013��09��21��
   ��    ��   : l57356
   �޸�����   : �½�
*******************************************************************************/

typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    VOS_INT16                               sTxPwr;
    VOS_INT16                               sCQI;
    VOS_UINT32                              ulDemodSyncInfo;
    VOS_UINT32                              ulDecSyncInfo;
    VOS_UINT32                              ulDecOutSyncInfo;
    VOS_UINT16                              usFgEn;
    VOS_UINT16                              usFgLock;
    PHY_WCDMA_ERRLOG_FG_INFO_STRU           stFgInfo;
    VOS_UINT16                              uhwGoodSignalDropFlag;              /* ���ź������ǣ����Ϊ1��Ϊ���ź����롣�����ǣ�RSCP��EcN0������Ϊ0 */
    VOS_INT16                               shwRscp;                            /* RSCP */
    VOS_INT16                               shwEcN0;                            /* EcN0 */
    VOS_UINT16                              usReserved;
}PHY_ERRLOG_WCDMA_RL_FAIL_EVENT_STRU;





/*******************************************************************************
 �ṹ��    : PHY_ERRLOG_GSM_DECODE_FAIL_EVENT_STRU
 �ṹ˵��  : GSM���ɺ͸��º��ϱ�����Ϣ�ṹ��
 1.��    ��   : 2013��09��21��
   ��    ��   : l57356
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    PHY_GSM_RPT_REASON_ENUM_UINT16          enRptReason;
    VOS_UINT16                              usArfcn;
    VOS_UINT16                              usRxlev;
    VOS_UINT16                              usDscInitValue;
    VOS_UINT32                              ulCurFn;
    VOS_UINT16                              usAfc;
    VOS_UINT16                              usTxPwr;
    VOS_UINT16                              usCI;
    VOS_INT16                               sToa;
    VOS_UINT32                              ulCarrirIn;
    VOS_UINT32                              ulInterfereIn;
    VOS_UINT32                              ulCarrirOut;
    VOS_UINT32                              ulInterfereOut;
    VOS_UINT32                              ulLsDcValue;
    VOS_UINT32                              ulRemoveDc;
    VOS_UINT32                              ulBurstRemoveDc;
    VOS_UINT32                              aulDemodData[2];
}PHY_ERRLOG_GSM_DECODE_FAIL_EVENT_STRU;




/*******************************************************************************
 �ṹ��    : PHY_ERRLOG_GSM_DECODE_FAIL_EVENT_STRU
 �ṹ˵��  : GSM���ɺ͸��º��ϱ�����Ϣ�ṹ��
 1.��    ��   : 2013��09��21��
   ��    ��   : l57356
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    VOS_UINT16                              usArfcn;
    VOS_UINT16                              usAfc;
    VOS_UINT32                              ulCurFn;
    VOS_UINT32                              uwReg5250;
    VOS_UINT32                              uwDrssi;
    VOS_UINT32                              uwFastDrssi;
    VOS_UINT32                              ulLsDcValue;
    VOS_UINT32                              ulRemoveDc;
    VOS_UINT32                              ulBurstRemoveDc;
}PHY_ERRLOG_GSM_RXLEV_MEAS_EVENT_STRU;




/*******************************************************************************
 �ṹ��    : PHY_ERRLOG_GSM_FB_SB_EVENT_STRU
 �ṹ˵��  : GSM���ɺ͸��º��ϱ�����Ϣ�ṹ��
 1.��    ��   : 2013��09��21��
   ��    ��   : l57356
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    VOS_UINT16                              usArfcn;
    VOS_UINT16                              usAfc;
    VOS_UINT32                              ulSrchMode;
    VOS_UINT32                              ulRptStatus;
    VOS_UINT32                              ulSbData;
    VOS_UINT32                              ulCurFn;
    VOS_UINT32                              ulReg5250;
    VOS_UINT32                              ulDrssi;
    VOS_UINT32                              ulFastDrssi;
    VOS_UINT32                              ulLsDcValue;
    VOS_UINT32                              ulRemoveDc;
    VOS_UINT32                              ulBurstRemoveDc;
    VOS_UINT32                              aulDemodData[2];
}PHY_ERRLOG_GSM_FB_SB_EVENT_STRU;




/*******************************************************************************
 �ṹ��    : PHY_FTM_WCDMA_DCH_PARA_EVENT_STRU
 �ṹ˵��  : WCDMA���ɺ͸��º��ϱ�����Ϣ�ṹ��
 1.��    ��   : 2013��09��21��
   ��    ��   : l57356
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_FTM_HEADER_STRU                      stHeader;
    VOS_INT16                               sTxPwr;
    VOS_INT16                               sCQI;
    VOS_UINT32                              ulErrBlk;
    VOS_UINT32                              ulDecBlk;
}PHY_FTM_WCDMA_DCH_PARA_EVENT_STRU;


/*******************************************************************************
 �ṹ��    : PHY_FTM_GSM_DCH_PARA_EVENT_STRU
 �ṹ˵��  : GSM���ɺ͸��º��ϱ�����Ϣ�ṹ��
 1.��    ��   : 2013��09��21��
   ��    ��   : l57356
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_FTM_HEADER_STRU                      stHeader;
    VOS_UINT16                              usTxPwr;
    VOS_UINT16                              usErrBlk;
    VOS_UINT16                              usDecBlk;
    VOS_UINT16                              usResv;
}PHY_FTM_GSM_DCH_PARA_EVENT_STRU;

/*******************************************************************************
 �ṹ��    : PHY_ERRLOG_GSM_CS_RLB_EVENT_STRU
 �ṹ˵��  : CS ��·���¼�
 1.��    ��   : 2014��07��05��
   ��    ��   : j00178524
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    PHY_GSM_CS_ERROR_REASON_ENUM_UINT16     enRptReason;
    VOS_UINT16                              usChannelType;                      /* �ŵ����� */
    VOS_UINT16                              usAssignRxTs;                       /* ҵ��ʱ϶ */
    VOS_UINT16                              usRxlev;                            /* �ź�ǿ�� */
    VOS_UINT16                              usCIAverage;                        /* CIƽ��ֵ */
    VOS_UINT16                              usErrBitSub;                        /* SUB ��bit���� */
    VOS_UINT16                              usTotalBitSub;                      /* SUB bitͳ������ */
    VOS_UINT16                              usResv;
}PHY_ERRLOG_GSM_CS_RLB_EVENT_STRU;


/*******************************************************************************
 �ṹ��    : PHY_ERRLOG_GSM_CS_NO_UL_DATA_EVENT_STRU
 �ṹ˵��  : GSM��������������ʱ�ϱ�����Ϣ�ṹ��
 1.��    ��   : 2014��7��5��
   ��    ��   : lmx
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    PHY_GSM_CS_ERROR_REASON_ENUM_UINT16     enCsErrorReason;
    VOS_UINT16                              usChannelType;
    VOS_UINT16                              usAssignRxTs;
    VOS_UINT16                              usResv;
    VOS_UINT32                              ulFn;                                   /* ֡�� */
    VOS_UINT32                              ulQb;                                   /* QB 0~4999 */
    VOS_UINT32                              ulTimeSlice;                            /* ����ʱ��ʱ�� */
    VOS_UINT16                              usChanCodeTime;                        /* ���б���ʱ��, ��λ:0.1 ms */
    VOS_UINT16                              usChanDecodeTime;
}PHY_ERRLOG_GSM_CS_NO_UL_DATA_EVENT_STRU;


/*******************************************************************************
 �ṹ��    : PHY_ERRLOG_GSM_CS_ERROR_DETECT_EVENT_STRU
 �ṹ˵��  : ��⵽�쳣error�¼�
 1.��    ��   : 2014��07��05��
   ��    ��   : j00178524
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    PHY_GSM_CS_ERROR_REASON_ENUM_UINT16     enRptReason;
    VOS_UINT16                              usChannelType;                      /* �ŵ����� */
    VOS_UINT16                              usAssignRxTs;                       /* ҵ��ʱ϶ */
    VOS_UINT16                              usResv;
}PHY_ERRLOG_GSM_CS_ERROR_DETECT_EVENT_STRU;


/*******************************************************************************
 �ṹ��    : PHY_MNTN_GSM_DCXO_SAMPLE_ERR_EVENT_STRU
 �ṹ˵��  : G DCXO�������쳣��CHR
 1.��    ��   : 2015��09��19��
   ��    ��   : w00286360
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    PHY_INT32                               swFreqErrPpm;                       /* ��ǰ�����Ƶƫֵ */
    PHY_INT16                               shwTemp;                            /* ��ǰ�¶ȣ���λ0.1�� */
    PHY_INT16                               shwRealA0Value;                     /* ��ʵ��a0 */
    PHY_INT32                               swMinThreshold;                     /* ��Сֵ���� */
    PHY_INT32                               swMaxThreshold;                     /* ���ֵ���� */
    PHY_UINT32                              uwTaskType;                         /* ��ǰ�������� */
    PHY_UINT16                              uhwPhyMode;                         /* �������ģʽ */
    PHY_UINT16                              uhwReserved;
}PHY_MNTN_GSM_DCXO_SAMPLE_ERR_EVENT_STRU;


/*******************************************************************************
 �ṹ��    : PHY_ERRLOG_GSM_CS_RLB_EVENT_STRU
 �ṹ˵��  : ����buffer��������ṹ
 1.��    ��   : 2014��07��05��
   ��    ��   : j00178524
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    VOS_UINT32                              ulOverflowCnt;                      /* ����buffer������� */
}PHY_ERRLOG_RING_BUFFER_OVERFLOW_EVENT_STRU;

/*******************************************************************************
 �ṹ��    : PHY_ERRLOG_WCDMA_CS_ERROR_RLB_EVENT_STRU
 �ṹ˵��  : CS��·�������¼�
 1.��    ��   : 2014��10��10��
   ��    ��   : l00184004
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    PHY_WCDMA_CS_ERROR_REASON_ENUM_UINT16   enCsErrorReason;                    /* �����쳣�澯���� */
    PHY_UINT16                              uhwChannelType;                     /* �ŵ����� */
    PHY_UINT16                              uhwCpichEcN0;                       /* CPICH Ec/N0 */
    PHY_UINT16                              uhwCpichRscp;                       /* CPICH RSCP */
    PHY_UINT16                              uhwSIR;                             /* �����ŵ�SIRƽ��ֵ */
    PHY_UINT16                              uhwCRCErrBlkNum;                    /* CRC���������block���� */
    PHY_UINT16                              uhwTotalCRCBlkNum;                  /* ����blockͳ������ */
    PHY_UINT16                              uhwErrPilotBitNum;                  /* Pilot bit�������� */
    PHY_UINT16                              uhwTotalPilotBitNum;                /* Pilot bitͳ������ */
    PHY_UINT16                              uhwDCHOutOfSyncInd;                 /* DCH out of sync ָʾ*/
}PHY_ERRLOG_WCDMA_CS_ERROR_RLB_EVENT_STRU;

/*******************************************************************************
 �ṹ��    : PHY_ERRLOG_WCDMA_CS_NO_UL_DATA_EVENT_STRU
 �ṹ˵��  : ����������ݶ�ʧ
 1.��    ��   : 2014��07��05��
   ��    ��   : l00184004
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    PHY_WCDMA_CS_ERROR_REASON_ENUM_UINT16   enCsErrorReason;                    /* �����쳣�澯���� */
    PHY_UINT16                              uhwChannelType;                     /* �ŵ����� */
    PHY_UINT16                              uhwFrameNum;                         /* ���һ�η�������֡�� */
    PHY_UINT16                              uhwSlotNum;                          /*  ���һ�η�������ʱ϶��*/
    PHY_UINT16                              uhwUlTFCI;                           /*  ���һ�η���������TFCIֵ*/
    PHY_UINT16                              uhwReseved;
}PHY_MNTN_WCDMA_CS_ERROR_NO_UL_DATA_EVENT_STRU;

/*******************************************************************************
 �ṹ��    : PHY_MNTN_WCDMA_TX_POWER_DROP_EVENT_STRU
 �ṹ˵��  : ��ⷢ�书��̫��
 1.��    ��   : 2015��01��17��
   ��    ��   : w00286360
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    PHY_INT16                               shwTxPwr;                           /* ��ǰ���书�ʣ���λ0.1dBm */
    PHY_UINT16                              uhwReseved;
}PHY_MNTN_WCDMA_TX_POWER_DROP_EVENT_STRU;

/*******************************************************************************
 �ṹ��    : PHY_MNTN_WCDMA_PILOT_BER_RISE_EVENT_STRU
 �ṹ˵��  : pilot beŗ�����¼�
 1.��    ��   : 2015��01��17��
   ��    ��   : w00286360
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    PHY_UINT16                              uhwPrePilotBer;                     /* ǰ�����ڵ�pilot ber��50��ʾ50% */
    PHY_UINT16                              uhwCurrPilotBer;                    /* ������ڵ�pilot ber��10��ʾ10% */
}PHY_MNTN_WCDMA_PILOT_BER_RISE_EVENT_STRU;


/*******************************************************************************
 �ṹ��    : PHY_MNTN_WCDMA_FACH_RA_FAIL_EVENT_STRU
 �ṹ˵��  : ���������쳣ʧ�ܼ��
 1.��    ��   : 2015��01��17��
   ��    ��   : w00286360
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    PHY_INT16                               shwRscp;                            /* �������ʧ��ʱ��RSCP 1dBm */
    PHY_INT16                               shwEcn0;                            /* �������ʧ���ǵ�ECN0 1dB */
}PHY_MNTN_WCDMA_FACH_RA_FAIL_EVENT_STRU;


/*******************************************************************************
 �ṹ��    : PHY_MNTN_GOOD_SNR_NOACK_INFO_STRU
 �ṹ˵��  : �������Ľ�����
 1.��    ��   : 2015��01��17��
   ��    ��   : w00286360
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    UPHY_BOOL_ENUM_UINT16                   enGoodSnrNoAckFlag;                 /* �Ƿ���ֺ��ź��������ʧ�ܵı�� */
    PHY_INT16                               shwRscp;                            /* �������ʧ��ʱ��RSCP 1dBm */
    PHY_INT16                               shwEcn0;                            /* �������ʧ���ǵ�ECN0 1dB */
    PHY_UINT16                              uhwReserved;
}PHY_MNTN_GOOD_SNR_NOACK_INFO_STRU;


/*******************************************************************************
 �ṹ��    : PHY_MNTN_WCDMA_FACH_RA_INFO_EVENT_STRU
 �ṹ˵��  : �������Ľ�����
 1.��    ��   : 2015��01��17��
   ��    ��   : w00286360
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    PHY_UINT16                              uhwFreq;
    PHY_UINT16                              uhwPriScramCode;
    PHY_UINT16                              uhwAckNum;
    PHY_UINT16                              uhwNAckNum;
    PHY_UINT16                              uhwNoAckNum;
    PHY_INT16                               shwPrachInitialTxPower;             /* Preamble��ʼ���ʿ���,��λdBm */
    PHY_UINT16                              uhwPowerRampStep;                   /* ��������Preamble�Ĺ��ʲ�ֵ,��λdB */
    PHY_UINT16                              uhwPreambleRetryMax;                /* һ��������̷���Preamble������������� */
    PHY_INT16                               shwRscp;                            /* �������ʧ��ʱ��RSCP 1dBm */
    PHY_INT16                               shwEcn0;                            /* �������ʧ���ǵ�ECN0 1dB */
    PHY_MNTN_GOOD_SNR_NOACK_INFO_STRU       stGoodSnrNoAck;
}PHY_MNTN_WCDMA_FACH_RA_INFO_EVENT_STRU;



/*******************************************************************************
 �ṹ��    : PHY_ERRLOG_WCDMA_TAS_INFO_STRU
 �ṹ˵��  : �ϱ����һ�������л�tas�ؼ���Ϣ
 1.��    ��   : 2015��01��06��
   ��    ��   : c00242732
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    PHY_UINT32                              uwAntSwitchSlice;                   /* �����л�ʱ��� */
    PHY_UINT16                              uhwDpdtStatus;                      /* �л���dpdt״̬ */
    PHY_INT16                               shwDeltaValue;                      /* ����������ֵ��λ0.125dBm */
    PHY_INT16                               shwCurrAntRscp;                     /* ��ǰ��������ֵ��λ0.125dBm */
    PHY_UINT16                              uhwSignalState;                     /* �ź�good/poor״̬ */
    PHY_UINT16                              uhwHappyState;                      /* ������happy/unhappy״̬ */
    PHY_UINT16                              uhwRrcState;                        /* ϵͳ��ʱ״̬:idle/dch */
    PHY_UINT16                              uhwAuthorizeFlag;                   /* W��������Ȩ״̬ */
    PHY_UINT16                              uhwAgentSwitchFlag;                 /* �Ƿ�Ϊ�����л� */
}PHY_ERRLOG_WCDMA_TAS_INFO_STRU;

/*******************************************************************************
 �ṹ��    : PHY_ERRLOG_GSM_TAS_INFO_STRU
 �ṹ˵��  : �ϱ����һ�������л�tas�ؼ���Ϣ
 1.��    ��   : 2015��01��07��
   ��    ��   : m00251053
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    PHY_UINT16                              uhwConnDpdtStatus;                  /* ����̬�л���DPDT״̬ */
    PHY_UINT16                              uhwConnTasState;                    /* ����̬MAS�㷨�׶�: Estimate/Compare/Delay */

    PHY_UINT32                              uwWholeSwitchSlice;                 /* �����л�ʱ��� */
    PHY_UINT16                              uhwWholeSwitchBand;                 /* �����л�Ƶ�� */
    PHY_UINT16                              uhwWholeSwitchDirection;            /* �����л�ʱDPDT״̬�Ӻδ��е��δ�  (ex: 0x23 = ��ant2�е�ant3)*/
    PHY_INT16                               shwWholeSwitchBefRSSI;              /* �����л�ǰ����RSSI */
    PHY_INT16                               shwWholeSwitchAftRSSI;              /* �����л������RSSI */
    PHY_INT16                               shwWholeSwitchBefTxPower;           /* �����л�ǰ���书�� */
    PHY_INT16                               shwWholeSwitchAftTxPower;           /* �����л����书�� */

    PHY_UINT32                              uwSwitchSlice;                      /* �����л�ʱ��� */
    PHY_UINT16                              uhwSwitchRoundCount;                /* �����л�ʱ�ȽϽ׶�  (ex: 0x23 = Round2 Count3) */
    PHY_UINT16                              uhwSwitchDirection;                 /* �����л�ʱDPDT״̬�Ӻδ��е��δ�  (ex: 0x23 = ��ant2�е�ant3) */
    PHY_INT16                               shwSwitchBefRSSI;                   /* �����л�ǰ����RSSI ��λ1dBm */
    PHY_INT16                               shwSwitchAftRSSI;                   /* �����л������RSSI ��λ1dBm */
    PHY_INT16                               shwSwitchBefTxPower;                /* �����л�ǰ���书�� ��λ0.1dBm */
    PHY_INT16                               shwSwitchAftTxPower;                /* �����л����书�� ��λ0.1dBm */

    PHY_UINT32                              uwCompareSlice;                     /* �ȽϽ׶�ʱ��� */
    PHY_UINT16                              uhwCompareBand;                     /* �ȽϽ׶�band */
    PHY_INT16                               shwCompareAnt0RSSI;                 /* �ȽϽ׶�����0����RSSI ��λ1dBm */
    PHY_INT16                               shwCompareAnt1RSSI;                 /* �ȽϽ׶�����1����RSSI ��λ1dBm */
    PHY_INT16                               shwCompareAnt2RSSI;                 /* �ȽϽ׶�����2����RSSI ��λ1dBm */
    PHY_INT16                               shwCompareAnt3RSSI;                 /* �ȽϽ׶�����3����RSSI ��λ1dBm */

    PHY_UINT16                              uhwNonConnDpdtStatus;               /* ������̬�л���DPDT״̬ */
    PHY_UINT16                              uhwNonConnTasAlgo;                  /* ������̬TAS�л��㷨: Idle/Access/Searching/Agent */
    PHY_UINT16                              uhwIdleSwitchStatus;                /* �л����Ƿ���Happy */

    PHY_UINT16                              uhwAuthorizeFlag;                   /* ����TAS��Ȩ״̬ TAS=0,MAS=0/TAS=1,MAS=0/TAS=0,MAS=1/TAS=1,MAS=1 */
    PHY_UINT16                              uhwIdleHappyState;                  /* ����Idle Happy״̬: Happy/Unhappy */
    PHY_UINT16                              uhwSignalState;                     /* �����ź�״̬: Good/Poor */

    PHY_UINT16                              uhwRlfAuthorizeFlag;                /* RLFʱTAS��Ȩ״̬ */
}PHY_ERRLOG_GSM_TAS_INFO_STRU;


/*******************************************************************************
 �ṹ��    : PHY_ERRLOG_WCDMA_MAS_INFO_STRU
 �ṹ˵��  : �ϱ����һ�������л�tas�ؼ���Ϣ
 1.��    ��   : 2015��11��4��
   ��    ��   : w00181973
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;

    PHY_UINT16                              uhwConnDpdtStatus;                  /* ����̬TAS��MAS״̬ */
    PHY_UINT16                              uhwConnDpdtAlgo;                    /* 0: Nonblind; 1:Blind */
    PHY_UINT16                              uhwConnTasState;                    /* MAS(TAS) ��ǰSTATE */
    PHY_UINT16                              uhwRsv3;                            /* ���ֽڶ��� */

    PHY_UINT32                              uwWholeSwitchSlice;                 /* �����л�ʱ��� */
    PHY_UINT16                              uhwWholeSwitchBand;                 /* �����л�ʱ����BAND */
    PHY_UINT16                              uhwWholeSwitchDirection;            /* �����л�����(�Ӻ����߿�ʼ,�ں����߽���) */
    PHY_INT16                               shwWholeSwitchBefRSCP;              /* �����л���ʼʱ����RSCP���� */
    PHY_INT16                               shwWholeSwitchAftRSCP;              /* �����л�����ʱ����RSCP���� */
    PHY_INT16                               shwWholeSwitchBefTxPower;           /* �����л���ʼʱ���书�� */
    PHY_INT16                               shwWholeSwitchAftTxPower;           /* �����л�����ʱ���书�� */

    PHY_UINT32                              uwSingleSwitchSlice;                /* �����л���ʼʱ��� */
    PHY_UINT16                              uhwSingleSwitchRoundCount;          /* �����л��������� */
    PHY_UINT16                              uhwSingleSwitchDirection;           /* �����л�����(�Ӻ����߿�ʼ,�ں����߽���) */
    PHY_INT16                               shwSingleSwitchBefRSCP;             /* �����л���ʼʱ����RSCP���� */
    PHY_INT16                               shwSingleSwitchAftRSCP;             /* �����л�����ʱ����RSCP���� */
    PHY_INT16                               shwSingleSwitchBefTxPower;          /* �����л���ʼʱ���书�� */
    PHY_INT16                               shwSingleSwitchAftTxPower;          /* �����л�����ʱ���书�� */

    PHY_UINT32                              uwCompareSlice;                     /* �Ƚ�ʱ��� */
    PHY_UINT16                              uhwCompareBand;                     /* �Ƚ�����BAND */
    PHY_INT16                               shwCompareAnt0RSCP;                 /* ����0���� */
    PHY_INT16                               shwCompareAnt1RSCP;                 /* ����1���� */
    PHY_INT16                               shwCompareAnt2RSCP;                 /* ����2���� */
    PHY_INT16                               shwCompareAnt3RSCP;                 /* ����3���� */

    PHY_UINT16                              uhwNonConnDpdtStatus;               /* ������̬TAS��MAS״̬ */
    PHY_UINT16                              uhwNonConnDpdtAlgo;                 /* ������̬�㷨 */
    PHY_UINT16                              uhwIdleSwitchStatus;                /* IDLE̬�л����ߺ���û�б�HAPPY */

    PHY_UINT16                              uhwAuthorizeFlag;                   /* TAS��Ȩ��Ϣ */
    PHY_UINT16                              uhwIdleHappyState;                  /* IDLE̬�Ƿ�HAPPY:0,unhappy; 1,hapy */
    PHY_UINT16                              uhwSignalState;                     /* SIGNAL�Ƿ�GOOD:0,poor; 1,good */
    PHY_UINT16                              uhwRsv6;                            /* ���ֽڶ��� */

    PHY_UINT16                              uhwRlfAuthorizeFlag;                /* RL FAILʱTAS��Ȩ��Ϣ */
}PHY_ERRLOG_WCDMA_MAS_INFO_STRU;

/*******************************************************************************
 �ṹ��    : PHY_ERRLOG_GSM_MEASUREMENT_REPORT_ERROR_STRU
 �ṹ˵��  : �����������
 1.��    ��   : 2015��03��09��
   ��    ��   : j00178524
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHeader;
    VOS_UINT16                          usStrongNcellBsicUnknown;               /* δͬ���ϵ�ǿ���� */
    VOS_UINT16                          usStrongNcellRxlev;                     /* δͬ���ϵ�ǿ�����Ĳ���ֵ */
}PHY_ERRLOG_GSM_MEASUREMENT_REPORT_ERROR_STRU;

/*******************************************************************************
 �ṹ��    : PHY_MNTN_WCDMA_DCXO_SAMPLE_ERR_EVENT_STRU
 �ṹ˵��  : W DCXO�������쳣��CHR
 1.��    ��   : 2015��09��19��
   ��    ��   : w00286360
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    PHY_UINT16                              uhwFreq;                            /* ��ǰ����Ƶ��� */
    PHY_UINT16                              uhwAfcValue;                        /* AFC�ϱ�ֵ */
    PHY_INT32                               swFreqErrPpm;                       /* ��ǰ�����Ƶƫֵ */
    PHY_INT16                               shwTemp;                            /* ��ǰ�¶ȣ���λ0.1�� */
    PHY_UINT16                              uhwRrcState;                        /* ��ǰW RRC״̬��0:FREE̬;1:CPICH̬;2:FACH̬;3:DPCH̬ */
    PHY_INT32                               swMinThreshold;                     /* ��Сֵ������ */
    PHY_INT32                               swMaxThreshold;                     /* ���ֵ������ */
    PHY_INT16                               shwRealA0Value;                     /* ��ʵ��A0 */
    PHY_UINT16                              uhwReserved;
}PHY_MNTN_WCDMA_DCXO_SAMPLE_ERR_EVENT_STRU;

/*******************************************************************************
 �ṹ��    : PHY_MNTN_WCDMA_PD_ABNORMAL_EVENT_STRU
 �ṹ˵��  : ���PD�쳣
 1.��    ��   : 2016��01��05��
   ��    ��   : l00241951
   �޸�����   : �½�
*******************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;
    VOS_INT32                               swPdErrorAver;                      /* PD������ƽ��ֵ����λ0.1dBm */
    VOS_INT32                               swPdErrorTemp;                      /* PD������˲ʱֵ����λ0.1dBm */
    VOS_INT16                               shwTxAvrgPwr;                       /* ���书��ƽ��ֵ */
    VOS_INT16                               shwFilterDpcchPwr;                  /* ���书��ƽ��ֵ */
}PHY_MNTN_WCDMA_PD_ABNORMAL_EVENT_STRU;

/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/


#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of phyerrorlog.h */

