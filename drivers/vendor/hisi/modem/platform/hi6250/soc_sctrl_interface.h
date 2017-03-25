/******************************************************************************

                 版权所有 (C), 2001-2012, 华为技术有限公司

 ******************************************************************************
  文 件 名   : soc_sctrl_interface.h
  版 本 号   : 初稿
  作    者   : Excel2Code
  生成日期   : 2013-01-25 14:01:14
  最近修改   :
  功能描述   : 接口头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2013年1月25日
    作    者   : x59651
    修改内容   : 仿照SFT目录下同名文件编写，为了产品共分支需求

******************************************************************************/

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/

#ifndef __SOC_SCTRL_INTERFACE_H__
#define __SOC_SCTRL_INTERFACE_H__

#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif


/*****************************************************************************
  2 宏定义
*****************************************************************************/

/****************************************************************************
                     (1/1) register_define
 ****************************************************************************/

/* 时钟使能控制 */
#define SOC_SCTRL_MDM_CRG_PERIPH_CLKEN_ADDR(base)       ((base) + (0x000))

/* 时钟关闭控制 */
#define SOC_SCTRL_MDM_CRG_PERIPH_CLKDIS_ADDR(base)      ((base) + (0x004))

/* 时钟控制状态 */
#define SOC_SCTRL_MDM_CRG_PERIPH_CLKSTAT_ADDR(base)     ((base) + (0x008))

/* 寄存器说明：外设控制寄存器1。控制CICOM模式选择，为了FPGA和SFT分支一致，使用同样的名字
   位域定义UNION结构:  SOC_SCtrl_SC_PERIPH_CTRL1_UNION */
#define SOC_SCTRL_SC_PERIPH_CTRL4_ADDR(base)            ((base) + (0x410))

/*****************************************************************************
  3 枚举定义
*****************************************************************************/
/*****************************************************************************
 结构名    : SOC_PERICTRL_CICOM0_MOD_SEL_UNION
 结构说明  : CICOM0_MOD_SEL 寄存器结构定义。地址偏移量:0x410，初值:0x00000000，宽度:32
 寄存器说明: 
*****************************************************************************/
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  gucicom0sel_mode : 1;  /* bit[0]   : CICOM0模式配置
                                                           0：WCDMA加解密模式
                                                           1：GSM加解密模式 */  
        unsigned int  gucicom1sel_mode : 1;  /* bit[1]   : CICOM1模式配置
                                                           0：WCDMA加解密模式
                                                           1：GSM加解密模式 */ 
        unsigned int  reserved         : 30; /* bit[2-31]: 保留 */
    } reg;
} SOC_SCtrl_SC_PERIPH_CTRL1_UNION;
#define SOC_SCtrl_SC_PERIPH_CTRL1_cicomsel_mode_START                   (0)
#define SOC_SCtrl_SC_PERIPH_CTRL1_cicomsel_mode_END                     (0)


/*****************************************************************************
  4 消息头定义
*****************************************************************************/


/*****************************************************************************
  5 消息定义
*****************************************************************************/



/*****************************************************************************
  6 STRUCT定义
*****************************************************************************/



/*****************************************************************************
  7 UNION定义
*****************************************************************************/




/*****************************************************************************
  8 OTHERS定义
*****************************************************************************/



/*****************************************************************************
  9 全局变量声明
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of soc_sctrl_interface.h */
