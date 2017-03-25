/*
*                Copyright 2008, Huawei Technologies Co. Ltd.
*                            ALL RIGHTS RESERVED
*
*-------------------------------------------------------------------------------
*
*                              udp_api.h
*
*  Project Code: VISPV1R7
*   Module Name: UDP_API
*  Date Created: 2008-03-07
*        Author: zhengsenhuo(00104483)
*   Description:
*
*-------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*  -----------------------------------------------------------------------------
*   2008-03-07  Zheng SenHuo           Creat the first version.
*
*******************************************************************************/


#ifndef        _RAWIP_API_H_
#define        _RAWIP_API_H_

#ifdef    __cplusplus
extern    "C"{
#endif

#define RAWIP_ERR_NULL_POINT 2          /* ��ȡRAWIPͳ����Ϣ,�����ָ�� */
#define RAWIP_ERR_GETSTAT_INPCB 3       /* ��ȡRAWIPͳ����Ϣ,INPCB�ṹΪ�� */
#define RAWIP_ERR_GETSTAT_SOCKETCB 4    /* ��ȡRAWIPͳ����Ϣ,SOCKETCB�ṹΪ�� */


typedef struct tagRIPSTAT
{
    ULONG rips_ulNoProto;
    ULONG rips_ulDelivered;
    ULONG rips_ulRawOut;
    ULONG rips_ulRawOutErr;
}RIPSTAT_S;

/* ����socket id,task id����Ԫ���ȡͳ����Ϣ����������ݽṹ */
typedef struct tagRAWIP4CONN_S
{
    ULONG    ulVrfIndex;    /* VRF����*/
    ULONG    ulLAddr;       /* ���˵�ַ (������)*/
    ULONG    ulFAddr;       /* �Զ˵�ַ (������)*/
    ULONG    ulProto;       /* Э��� */
    ULONG    ulSocketID ;   /* Socket ID */
    ULONG    ulTaskID;      /* ���� ID */
}RAWIP4CONN_S;

/* ����socket id,task id����Ԫ���ȡͳ����Ϣ���ݽṹ */
typedef struct tagRAWIP4PERSTAT_S
{
    RAWIP4CONN_S stRawIp4Conn;      /*ʵ�ʻ�ȡ��socket id task id ����Ԫ��*/
    ULONG   ulIPackets;             /* ���յ���RAWIP���İ���  */
    ULONG   ulIPacketsByte;         /* ���յ���RAWIP�����ֽ��� */

    ULONG   ulOPackets;              /* ���͵�RAWIP���İ���  */
    ULONG   ulOPacketsByte;          /* ���͵�RAWIP�����ֽ��� */

    /*socket ��������Ϣ*/
    ULONG    ulSndHiWat ;           /*���ͻ�������ˮλ*/
    ULONG    ulRcvHiWat ;           /*���ջ�������ˮλ*/
    ULONG    ulSndCC ;              /*���ͻ�������ʵ������ */
    ULONG    ulRcbCC ;              /*���ջ�������ʵ������ */
    ULONG    ulDropPackets;         /*���ڽ��ջ������������ı�����*/
    ULONG    ulDropPacketBytes;     /*���ڽ��ջ������������ı����ֽ���*/
}RAWIP4PERSTAT_S;

/*OSPF RAWIP socket ��Ϣ�ṹ, Ϊ֧�ֹ�����˫OSPF���Զ����������ݽṹ, 2005-10-31, SWID00024*/
typedef struct tagTargetSOCKET
{
            ULONG ulSockId;        /*socket��*/
            ULONG ulTaskId;        /*�����*/
}TARGET_SOCKET_S;

typedef ULONG (*LocateTargetSocket_HOOK_FUNC)(ULONG ulIfIndex,ULONG ulDestAddr, TARGET_SOCKET_S *pstTargetSkt);

/*******************************************************************************
*    Func Name: TCPIP_ClrRawIPStat
*  Description: ���RawIP4�����ͳ����Ϣ
*        Input: VOID
*       Output:
*       Return: VOID
*      Caution:
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*  ----------------------------------------------------------------------------
*  2008-04-17   Zheng Sen Huo (00104483)  Create
*
*******************************************************************************/
VOID  TCPIP_ClrRawIPStat(VOID);
/*******************************************************************************
*    Func Name: TCPIP_GetRawIPStat
*  Description: ��ȡRawIP4�����ͳ����Ϣ
*        Input: RIPSTAT_S *pstRawipStats: �洢ͳ����Ϣ�ڴ�
*       Output:
*       Return: VOS_OK  �ɹ�
*               VOS_ERR ʧ��
*      Caution:
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*  ----------------------------------------------------------------------------
*  2008-04-17   Zheng Sen Huo (00104483)  Create
*
*******************************************************************************/
ULONG TCPIP_GetRawIPStat(RIPSTAT_S *pstRawipStats);
/****************************************************************************
*    Func Name: TCPIP_RegFuncLocateTargetSocketHook()
*  Description: ע���ȡOSPF����Ŀ��socket��Ϣ�ĺ���
*        Input: LocateTargetSocket_HOOK_FUNC pfHookFunc ע�ṳ�Ӻ�����ָ��
*       Output: ��
*       Return: VOS_OK:�ɹ�
*      Caution:
*------------------------------------------------------------------------------
*  Modification History
*  DATE        NAME             DESCRIPTION
*  ----------------------------------------------------------------------------
*  2008-3-9  Zheng Sen Huo (00104483)         Creat the first version.
*
*******************************************************************************/
ULONG TCPIP_RegFuncLocateTargetSocketHook(LocateTargetSocket_HOOK_FUNC pfHookFunc);
/*******************************************************************************
*    Func Name: TCPIP_ShowRipStatistic
*  Description: ��ʾRawIP4�����ͳ����Ϣ
*        Input: VOID
*       Output:
*       Return: VOID
*      Caution:
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*  ----------------------------------------------------------------------------
*  2008-04-17   Zheng Sen Huo (00104483)  Create
*
*******************************************************************************/
VOID  TCPIP_ShowRipStatistic (VOID);

/*******************************************************************************
*    Func Name: TCPIP_GetPerRawip4ConnStats
* Date Created: 2009-12-28
*       Author: Gexianjun/h00121208
*  Description: ָ��socket id, task id��ָ����Ԫ�飬VRF��ȡָ����RAWIPͳ����Ϣ
*        Input: RAWIP4CONN_S *pstConnInfo:    ��ȡָ��RAWIP Socket�������
*       Output: RAWIP4PERSTAT_S *pstRetStats: ��ȡָ����RAWIPͳ����Ϣ
*       Return: �ɹ�:VOS_OK;ʧ��:������
*      Caution: ���socket��ģʽ��ȫ��socket,����socket id��ȡRAWIPͳ����Ϣ,����Ҫָ��task id;
*               ������Ҫͬʱָ��socket id��task id�����ӿڻ�ȡRAWIPͳ����Ϣ�������������Բ�����ȷ
*               ��ȡ:�����������Ϊsocket id + task idȥ��ȡ;���������Ϊ��Ԫ��+vrfȥ��ȡ��
*               Ҳ����ͬʱָ����������ϡ���ȡ�������ȸ���socket id +task idȥ��ȡ,
*               �����ȡʧ��,�ٸ�����Ԫ��+vrfȥ��ȡ��
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*  ----------------------------------------------------------------------------
*  2009-12-28   Gexianjun/h00121208     Create
*
*******************************************************************************/
extern ULONG TCPIP_GetPerRawip4ConnStats(RAWIP4CONN_S *pstConnInfo, RAWIP4PERSTAT_S  *pstRetStats);

/*******************************************************************************
*    Func Name: TCPIP_ResetPerRawip4ConnStats
* Date Created: 2009-12-28
*       Author: Gexianjun/h00121208
*  Description: ָ��socket id, task id��ָ����Ԫ�飬VRF���ָ����RAWIPͳ����Ϣ
*        Input: RAWIP4CONN_S *pstConnInfo: ���ָ��RAWIP Socket�������
*       Output: 
*       Return: �ɹ�:VOS_OK;ʧ��:������
*      Caution: ���socket��ģʽ��ȫ��socket,����socket id���RAWIPͳ����Ϣ,����Ҫָ��task id;
*               ������Ҫͬʱָ��socket id��task id�����ӿ����RAWIPͳ����Ϣ�������������Բ�����ȷ
*               ���:�����������Ϊsocket id + task idȥ���;���������Ϊ��Ԫ��+vrfȥ�����
*               Ҳ����ͬʱָ����������ϡ�����������ȸ���socket id +task idȥ����RAWIP socket, ���
*               ���ҳɹ�,�����ָ���ĸ�RAWIP socket��ͳ����Ϣ,�������ʧ��,�ٸ�����Ԫ��+vrfȥ����RAWIP socket,
*               ������ҳɹ�,�����ָ���ĸ�RAWIP socket��ͳ����Ϣ��
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*  ----------------------------------------------------------------------------
*  2009-12-28   Gexianjun/h00121208     Create
*
*******************************************************************************/
extern ULONG TCPIP_ResetPerRawip4ConnStats(RAWIP4CONN_S *pstConnInfo);


typedef ULONG (*RAWIPINPUT_HOOK_FUNC)( MBUF_S* pMbuf );
ULONG TCPIP_RegFuncRAWIPInputHook( RAWIPINPUT_HOOK_FUNC pfFuncHook );
extern RAWIPINPUT_HOOK_FUNC g_RawIP_Input_HookFunc;

#define RAWIP_NOT_PROCESSED_BY_INTERMEDIATE              0
/* intermediate found the packet has Error, Stack will Destroy the Packet */
#define RAWIP_INTER_PROCESS_ERROR                        1
/* Intermediate Processing will continue processing and will own the packet
 * PP do not need to process the packet any more */
#define RAWIP_PROCESSED_BY_INTERMEDIATE                  2


#ifdef    __cplusplus
}
#endif    /* end of __cplusplus */

#endif
