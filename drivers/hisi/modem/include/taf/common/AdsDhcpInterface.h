

#ifndef __ADSDHCPINTERFACE_H__
#define __ADSDHCPINTERFACE_H__

/*****************************************************************************
  1 ͷ�ļ�����
*****************************************************************************/
#include "vos.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)


/*****************************************************************************
  2 �궨��
*****************************************************************************/
#define ADS_DHCP_MSG_HDR            (0xFF00)


/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/
/*****************************************************************************
ö����    : ADS_DHCP_ERR_TYPE_ENUM
�ṹ˵��  : ADS��DHCP֮�����Ϣ

  1.��    ��   : 2015��05��18��
    ��    ��   : w00316385
    �޸�����   : ����ADS��DHCP֮���
*****************************************************************************/
enum ADS_DHCP_MSG_ID_ENUM
{
    ID_ADS_DHCP_DATA_IND                      =   ADS_DHCP_MSG_HDR + 0x00,      /* ADS->DHCP DATA IND */
    ID_ADS_DHCP_MSG_ID_ENUM_BUTT
};
typedef VOS_UINT16  ADS_DHCP_MSG_ID_ENUM_UINT16;


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

/*****************************************************************************
�ṹ��    : ADS_DHCP_DATA_IND_STRU
�ṹ˵��  : ADS��DHCP֮���������Ϣ�ṹ
            ���������͸�DHCP�ı��ľ�����IPF���˵�A CPU��
            ��ADSͨ���ýӿڷ��ظ�DHCP��

  1.��    ��   : 2015��05��18��
    ��    ��   : w00316385
    �޸�����   : ����ADS��DHCP֮���������Ϣ�ṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    ADS_DHCP_MSG_ID_ENUM_UINT16         enMsgId;                                /*_H2ASN_Skip*/
    MODEM_ID_ENUM_UINT16                enModemId;
    VOS_UINT8                           ucRabId;                                /* RAB��ʶ��ȡֵ��Χ:[5,15] */
    VOS_UINT8                           aucRsv[3];                              /*����λ*/
    VOS_UINT16                          usLen;                                  /*���ݰ�����*/
    VOS_UINT8                           aucData[2];                             /*���ݰ�����*/
}ADS_DHCP_DATA_IND_STRU;


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

#endif
