/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
  文 件 名   : NasCcMmccProc.h
  版 本 号   : 初稿
  作    者   : 丁庆 49431
  生成日期   : 2007年8月31日
  最近修改   : 2007年8月31日
  功能描述   : 接收和处理来自MM的MMCC原语
  函数列表   :
  修改历史   :
  1.日    期   : 2007年8月31日
    作    者   : 丁庆 49431
    修改内容   : 创建文件

  2.日    期   : 2010年3月2日
    作    者   : zhoujun /z40661
    修改内容   : NAS R7协议升级
******************************************************************************/
#ifndef  NAS_CC_MMCC_PROC_H
#define  NAS_CC_MMCC_PROC_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include "vos.h"
#include  "NasOmInterface.h"
#include "NasOmTrans.h"

/*****************************************************************************
  3 类型定义
*****************************************************************************/
typedef struct
{
    NAS_CC_MSG_TYPE_ENUM_U8       enCcMsgId;
    NAS_OTA_MSG_ID_ENUM_UINT16    enOtaMsgId;
} NAS_CC_OTA_MSG_ID_STRU;

/*****************************************************************************
  4 函数声明
*****************************************************************************/
/*****************************************************************************
 函 数 名  : NAS_CC_ProcMmccPrimitive
 功能描述  : 接收和处理来自MM的MMCC原语
 输入参数  : pMsg - MM发给CC的消息
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2008年1月16日
    作    者   : 丁庆 49431
    修改内容   : 新生成函数
*****************************************************************************/
VOS_VOID  NAS_CC_ProcMmccPrimitive(
    const VOS_VOID                      *pMsg
);

/*****************************************************************************
 函 数 名  : NAS_CC_LocalAbortDtmf
 功能描述  : 通知MN DTMF操作结果
 输入参数  : pMsg - MM发给CC的消息
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2008年07月02日
    作    者   : 丁庆 49431
    修改内容   : 新生成函数
*****************************************************************************/
VOS_VOID NAS_CC_LocalAbortDtmf(
    NAS_CC_ENTITY_ID_T                  entityId
);

/*****************************************************************************
 函 数 名  : NAS_CC_ProcMmccRrcConnRelInd
 功能描述  : 接收和处理来自MM的清buff原语
 输入参数  : pMsg - MM发给CC的消息
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2015年12月12日
    作    者   : j00174725
    修改内容   : DTS2015121001913
*****************************************************************************/
VOS_VOID  NAS_CC_ProcMmccRrcConnRelInd(
    const VOS_VOID                      *pMsg
);



#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* NAS_CC_MMCC_PROC_H */

