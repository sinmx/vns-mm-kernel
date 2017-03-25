#ifndef __MDRV_CCORE_DSP_H__
#define __MDRV_CCORE_DSP_H__
#ifdef __cplusplus
extern "C"
{
#endif


typedef enum bsp_dsp_type_e
{
    BSP_DSP_TLBBE,      /* TLBBE16 */
    BSP_DSP_CBBE,       /* CBBE16 */
    BSP_DSP_HIFI,       /* 用来将来扩展HIFI的加载 */
    BSP_DSP_BUTT
}BSP_DSP_TYPE_E;


typedef struct dsp_addr_info_stru{
    unsigned int load_addr;     /* BIN文件加载到DDR中的地址 */
    unsigned int backup_addr;   /* DSP数据备份地址 */
}BSP_DSP_ADDR_INFO_STRU;


/*****************************************************************************
* 函 数 名  : mdrv_dsp_load_bbe
*
* 功能描述  : 完成BBE16镜像的加载
*
* 输入参数  :
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_dsp_load_bbe();

/*****************************************************************************
* 函 数 名  : mdrv_dsp_run_bbe
*
* 功能描述  : 激活BBE16
*
* 输入参数  :
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_dsp_run_bbe();

/*****************************************************************************
* 函 数 名  : mdrv_dsp_backup_bbe
*
* 功能描述  : 启动BBE16镜像备份
*
* 输入参数  :
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  : 1 调用该接口前必须使能中断
*
*****************************************************************************/
int mdrv_dsp_backup_bbe();

/*****************************************************************************
* 函 数 名  : mdrv_dsp_restore_bbe
*
* 功能描述  : 启动BBE16镜像恢复
*
* 输入参数  :
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  : 1 调用该接口前必须使能中断
*
*****************************************************************************/
int mdrv_dsp_restore_bbe();

/*****************************************************************************
* 函 数 名  : mdrv_dsp_get_br_status
*
* 功能描述  : 查询BBE16镜像备份和恢复是否完成
*
* 输入参数  :
* 输出参数  :
*
* 返 回 值  : 1 调用该接口后，若EDMA对BBE16镜像的备份或恢复未完成，调用者将被阻塞，直至镜像的备份或恢复完成为止，故该接口不能在中断上下文中使用。
*             2 该接口必须与BBE16镜像的备份接口或恢复接口成对调用。从启动镜像搬运到镜像搬运操作完成期间，必须使能中断。
* 其它说明  :
*
*****************************************************************************/
int mdrv_dsp_get_br_status();

/*****************************************************************************
* 函 数 名  : mdrv_dsp_stop_bbe
*
* 功能描述  : 停止BBE16运行
*
* 输入参数  :
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_dsp_stop_bbe();

/*****************************************************************************
* 函 数 名  : mdrv_dsp_unreset_bbe
*
* 功能描述  : 解复位BBE16
*
* 输入参数  :
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_dsp_unreset_bbe();

/*****************************************************************************
* 函 数 名  : mdrv_dsp_reset_bbe
*
* 功能描述  : 复位BBE16
*
* 输入参数  :
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_dsp_reset_bbe();

/*****************************************************************************
* 函 数 名  : mdrv_dsp_enable_clk
*
* 功能描述  : 开启BBE16时钟
*
* 输入参数  :
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_dsp_enable_clk();

/*****************************************************************************
* 函 数 名  : mdrv_dsp_disable_clk
*
* 功能描述  : 关闭BBE16时钟
*
* 输入参数  :
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_dsp_disable_clk();

/************************************************************************
 * FUNCTION
 *       mdrv_dsp_update_shareinfo
 * DESCRIPTION
 *       完成DSP共享的动态信息获取和更新功能
 * INPUTS
 *       NONE
 * OUTPUTS
 *       BSP_OK/BSP_ERR
 **************************************************************************/
int mdrv_dsp_update_shareinfo(unsigned long shareAddr);


/*****************************************************************************
* 函 数 名  : mdrv_dsp_load
*
* 功能描述  : 完成BBE16镜像的加载
*
* 输入参数  : edsptype(见BSP_DSP_TYPE_E描述)
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_dsp_load(BSP_DSP_TYPE_E edsptype);

/*****************************************************************************
* 函 数 名  : mdrv_dsp_run
*
* 功能描述  : 激活BBE16
*
* 输入参数  : edsptype(见BSP_DSP_TYPE_E描述)
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_dsp_run(BSP_DSP_TYPE_E edsptype);


/*****************************************************************************
* 函 数 名  : mdrv_dsp_stop
*
* 功能描述  : 停止BBE16运行
*
* 输入参数  : edsptype(见BSP_DSP_TYPE_E描述)
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_dsp_stop(BSP_DSP_TYPE_E edsptype);

/*****************************************************************************
* 函 数 名  : mdrv_dsp_unreset
*
* 功能描述  : 解复位BBE16
*
* 输入参数  : edsptype(见BSP_DSP_TYPE_E描述)
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_dsp_unreset(BSP_DSP_TYPE_E edsptype);

/*****************************************************************************
* 函 数 名  : mdrv_dsp_reset
*
* 功能描述  : 复位BBE16
*
* 输入参数  : edsptype(见BSP_DSP_TYPE_E描述)
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_dsp_reset(BSP_DSP_TYPE_E edsptype);

/*****************************************************************************
* 函 数 名  : mdrv_dsp_enable_clock
*
* 功能描述  : 开启BBE16时钟
*
* 输入参数  : edsptype(见BSP_DSP_TYPE_E描述)
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_dsp_enable_clock(BSP_DSP_TYPE_E edsptype);

/*****************************************************************************
* 函 数 名  : mdrv_dsp_disable_clock
*
* 功能描述  : 关闭BBE16时钟
*
* 输入参数  : edsptype(见BSP_DSP_TYPE_E描述)
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_dsp_disable_clock(BSP_DSP_TYPE_E edsptype);

/*****************************************************************************
* 函 数 名  : mdrv_dsp_backup
*
* 功能描述  : 启动BBE16镜像备份
*
* 输入参数  : edsptype(见BSP_DSP_TYPE_E描述)
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  : 1 调用该接口前必须使能中断
*
*****************************************************************************/
int mdrv_dsp_backup(BSP_DSP_TYPE_E edsptype);

/*****************************************************************************
* 函 数 名  : mdrv_dsp_restore
*
* 功能描述  : 启动BBE16镜像恢复
*
* 输入参数  : edsptype(见BSP_DSP_TYPE_E描述)
* 输出参数  :
*
* 返 回 值  : 0，成功；1，失败
*
* 其它说明  : 1 调用该接口前必须使能中断
*
*****************************************************************************/
int mdrv_dsp_restore(BSP_DSP_TYPE_E edsptype);

/*****************************************************************************
* 函 数 名  : mdrv_dsp_wait_backup_over
*
* 功能描述  : 查询BBE16镜像备份是否完成
*
* 输入参数  : edsptype(见BSP_DSP_TYPE_E描述)
* 输出参数  :
*
* 返 回 值  : 
* 其它说明  : 1 调用该接口后，若EDMA对BBE16镜像的备份未完成，调用者将被阻塞，
                直至镜像的备份完成为止，故该接口不能在中断上下文中使用。
*             2 该接口必须与BBE16镜像的备份接口成对调用。
                从启动镜像搬运到镜像搬运操作完成期间，必须使能中断。
*
*****************************************************************************/
int mdrv_dsp_wait_backup_over(BSP_DSP_TYPE_E edsptype);

/*****************************************************************************
* 函 数 名  : mdrv_dsp_wait_restore_over
*
* 功能描述  : 查询BBE16镜像恢复是否完成
*
* 输入参数  : edsptype(见BSP_DSP_TYPE_E描述)
* 输出参数  :
*
* 返 回 值  :
* 其它说明  : 1 调用该接口后，若EDMA对BBE16镜像的恢复未完成，调用者将被阻塞，
                直至镜像的恢复完成为止，故该接口不能在中断上下文中使用。
*             2 该接口必须与BBE16镜像的恢复接口成对调用。
                从启动镜像搬运到镜像搬运操作完成期间，必须使能中断。
*
*****************************************************************************/
int mdrv_dsp_wait_restore_over(BSP_DSP_TYPE_E edsptype);



/*****************************************************************************
* 函 数 名  : mdrv_dsp_get_addr_info
*
* 功能描述  : 获取DSP相关地址信息
*
* 输入参数  : pAddrInfo
* 输出参数  : pAddrInfo
*
* 返 回 值  : 0-成功; 1-失败
* 其它说明  : 如果调用此接口时镜像加载驱动还没有初始化，则返回失败
*
*****************************************************************************/
int mdrv_dsp_get_addr_info(BSP_DSP_TYPE_E edsptype, BSP_DSP_ADDR_INFO_STRU *pAddrInfo);

#ifdef __cplusplus
}
#endif
#endif

