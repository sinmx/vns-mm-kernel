

#ifndef __NASTCRABMMSGPROC_H__
#define __NASTCRABMMSGPROC_H__

/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#include  "NasETcPublic.h"

/*****************************************************************************
  1.1 Cplusplus Announce
*****************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*****************************************************************************
  #pragma pack(*)    设置字节对齐方式
*****************************************************************************/
#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif

/*****************************************************************************
  2 Macro
*****************************************************************************/


/*****************************************************************************
  3 Massage Declare
*****************************************************************************/


/*****************************************************************************
  4 Enum
*****************************************************************************/


/*****************************************************************************
  5 STRUCT
*****************************************************************************/


/*****************************************************************************
  6 UNION
*****************************************************************************/


/*****************************************************************************
  7 Extern Global Variable
*****************************************************************************/


/*****************************************************************************
  8 Fuction Extern
*****************************************************************************/
extern VOS_VOID  NAS_ETC_RabmMsgDistr( VOS_VOID *pRcvMsg );
extern VOS_VOID  NAS_ETC_SndTcRabmActTestModeMsg( VOS_VOID );
extern VOS_VOID  NAS_ETC_SndTcRabmDeactTestModeMsg( VOS_VOID );
extern VOS_VOID  NAS_ETC_RcvTcRabmSuspendInd(const ETC_ERABM_SUSPEND_IND_STRU *pRcvMsg );
extern VOS_VOID  NAS_ETC_RcvTcRabmResumeInd(const ETC_ERABM_RESUME_IND_STRU *pRcvMsg );
extern VOS_VOID NAS_ETC_SndTcRabmSuspendRsp
(
    ETC_ERABM_RSLT_TYPE_ENUM_UINT32       enRslt
);
extern VOS_VOID NAS_ETC_SndTcRabmResumeRsp
(
    ETC_ERABM_RSLT_TYPE_ENUM_UINT32       enRslt
);

/*****************************************************************************
  9 OTHERS
*****************************************************************************/


#if (VOS_OS_VER != VOS_WIN32)
#pragma pack()
#else
#pragma pack(pop)
#endif


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of NasETcRabmMsgProc.h */
