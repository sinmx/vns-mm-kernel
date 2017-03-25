#include "gtest/gtest.h"
#include "llt_mockcpp.h"

#include "uttest_AtCmdSimProc.h"


//�����������ã����������ùؼ���ʱ��Ҫ��ǰ׺ testing::
using namespace testing;

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define    THIS_FILE_ID                 PS_FILE_ID_AT_CMD_SIM_PROC_C

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

//˵��������������gtest+�������׺Ͳ����������ֲ�����Ϊ��
//      ������ú�gtest��ͬ�Ĺؼ��֣����ⲻ��Ҫ���鷳
//      gtest�ṩ EXPECT �� ASSERT ����,���庬����Կ���Ƭ�����׺궼��һһ��Ӧ�ģ�������EXPECTΪ��

//1���ȶԲ������� EXPECT_TRUE��EXPECT_FALSE/ASSERT_TRUE
//2���Ƚ����� EXPECT_EQ EXPECT_NE
//3���Ƚ��ַ��� EXPECT_STREQ
//4������ʧ�������Ϣ ADD_FAILUREd
//5�����óɹ���ʧ�� SUCCEED FAIL
//6���Զ����ʽ EXPECT_PRED_FORMAT3
//7�����������������TRUE EXPECT_PRED1
//8�������ͱȽ� EXPECT_FLOAT_EQ EXPECT_PRED_FORMAT2 ASSERT_PRED_FORMAT2
//9�����ͼ�� StaticAssertTypeEq
//10������3�ֲ��Լ����¼�
//11����ȡ������������ test_case_name()
//12���Ƚ��쳣 EXPECT_THROW
//13���ṹ�����ͱȽ�ASSERT_SAME_DATA ASSERT_SAME_MEMORY

/*****************************************************************************
����     : Test_At_QrySIMSlotPara
�������� : At_QrySIMSlotPara UT������
�޸���ʷ :
1.��    ��    : 2013��07��05��
  ��    ��    : L47619
  �޸�����    : add for SIM Insert
*****************************************************************************/
class Test_At_QrySIMSlotPara: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};

/******************************************************************************
�����������: Test_At_QrySIMSlotPara_001
������������: ��ȡNVʧ��
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-07-05
   ��   ��  : L47619
   �޸����� : add for SIM Insert
******************************************************************************/
TEST_F(Test_At_QrySIMSlotPara, Test_At_QrySIMSlotPara_001)
{
    // ��������
    VOS_UINT32  ulresult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���

    // MOCKER����
    MOCKER(NV_ReadEx)
        .stubs()
        .will(returnValue((VOS_UINT32)NV_ID_NOT_EXIST));

    // ���ñ��⺯��
    ulresult = At_QrySIMSlotPara(0);

    // ִ�м��
    EXPECT_EQ(AT_ERROR, ulresult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_QrySIMSlotPara_002
������������: ��ȡNV�ɹ�
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-07-05
   ��   ��  : L47619
   �޸����� : add for SIM Insert
******************************************************************************/
TEST_F(Test_At_QrySIMSlotPara, Test_At_QrySIMSlotPara_002)
{
    // ��������
    VOS_UINT32  ulresult;
    VOS_UINT8   ucIndex = 0;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    g_stParseContext[ucIndex].pstCmdElement = (AT_PAR_CMD_ELEMENT_STRU*)PS_MEM_ALLOC(WUEPS_PID_AT, sizeof(AT_PAR_CMD_ELEMENT_STRU));
    memset(g_stParseContext[ucIndex].pstCmdElement, 0 ,sizeof(AT_PAR_CMD_ELEMENT_STRU));
    g_stParseContext[ucIndex].pstCmdElement->pszCmdName = (VOS_UINT8*)"^SIMSLOT";

    // MOCKER����
    MOCKER(NV_ReadEx)
        .stubs()
        .will(returnValue((VOS_UINT32)NV_OK));
    // ���ñ��⺯��
    ulresult = At_QrySIMSlotPara(0);

    // ִ�м��
    EXPECT_EQ(AT_OK, ulresult);

    GlobalMockObject::verify();
}

/*****************************************************************************
����     : Test_At_SetSIMSlotPara
�������� : At_SetSIMSlotPara UT������
�޸���ʷ :
1.��    ��    : 2013��07��05��
  ��    ��    : L47619
  �޸�����    : add for SIM Insert
*****************************************************************************/
class Test_At_SetSIMSlotPara: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};

/******************************************************************************
�����������: Test_At_SetSIMSlotPara_001
������������: SIMSLOT���ucCmdOptType����ȷ
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-07-05
   ��   ��  : L47619
   �޸����� : add for SIM Insert
******************************************************************************/
TEST_F(Test_At_SetSIMSlotPara, Test_At_SetSIMSlotPara_001)
{
    // ��������
    VOS_UINT32  ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    g_stATParseCmd.ucCmdOptType = AT_CMD_OPT_SET_CMD_NO_PARA;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetSIMSlotPara(0);
    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetSIMSlotPara_002
������������: SIMSLOT���gucAtParaIndex����ȷ
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-07-05
   ��   ��  : L47619
   �޸����� : add for SIM Insert
******************************************************************************/
TEST_F(Test_At_SetSIMSlotPara, Test_At_SetSIMSlotPara_002)
{
    // ��������
    VOS_UINT32  ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    g_stATParseCmd.ucCmdOptType = AT_CMD_OPT_SET_PARA_CMD;
    gucAtParaIndex = 1;
    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetSIMSlotPara(0);
    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetSIMSlotPara_003
������������: SIMSLOT�������SIM1STATEΪ��
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-07-05
   ��   ��  : L47619
   �޸����� : add for SIM Insert
******************************************************************************/
TEST_F(Test_At_SetSIMSlotPara, Test_At_SetSIMSlotPara_003)
{
    // ��������
    VOS_UINT32  ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    g_stATParseCmd.ucCmdOptType = AT_CMD_OPT_SET_PARA_CMD;
    gucAtParaIndex = 2;
    gastAtParaList[0].usParaLen = 0;
    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetSIMSlotPara(0);
    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetSIMSlotPara_004
������������: SIMSLOT�������SIM2STATEΪ��
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-07-05
   ��   ��  : L47619
   �޸����� : add for SIM Insert
******************************************************************************/
TEST_F(Test_At_SetSIMSlotPara, Test_At_SetSIMSlotPara_004)
{
    // ��������
    VOS_UINT32  ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    g_stATParseCmd.ucCmdOptType = AT_CMD_OPT_SET_PARA_CMD;
    gucAtParaIndex = 2;
    gastAtParaList[0].usParaLen = 1;
    gastAtParaList[0].ulParaValue = 1;
    gastAtParaList[1].usParaLen = 0;
    gastAtParaList[1].ulParaValue = 1;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetSIMSlotPara(0);
    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetSIMSlotPara_005
������������: SIMSLOT�����ȡNV��ʧ��
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-07-05
   ��   ��  : L47619
   �޸����� : add for SIM Insert
******************************************************************************/
TEST_F(Test_At_SetSIMSlotPara, Test_At_SetSIMSlotPara_005)
{
    // ��������
    VOS_UINT32  ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    g_stATParseCmd.ucCmdOptType = AT_CMD_OPT_SET_PARA_CMD;
    gucAtParaIndex = 2;
    gastAtParaList[0].usParaLen = 1;
    gastAtParaList[0].ulParaValue = 1;
    gastAtParaList[1].usParaLen = 1;
    gastAtParaList[1].ulParaValue = 2;

    // MOCKER����
    MOCKER(NV_ReadEx)
        .stubs()
        .will(returnValue((VOS_UINT32)NV_ID_NOT_EXIST));

    // ���ñ��⺯��
    ulResult = At_SetSIMSlotPara(0);

    // ִ�м��
    EXPECT_EQ(AT_ERROR, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetSIMSlotPara_006
������������: ���õĲ�����Ϊ0���������
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-07-05
   ��   ��  : L47619
   �޸����� : add for SIM Insert
******************************************************************************/
TEST_F(Test_At_SetSIMSlotPara, Test_At_SetSIMSlotPara_006)
{
    // ��������
    VOS_UINT32                          ulResult;
    TAF_NV_SCI_CFG_STRU                 stSCICfg;

    // ������ʼ��
    stSCICfg.ulValue = 0;

    // ��ʼ��ȫ�ֱ���
    g_stATParseCmd.ucCmdOptType = AT_CMD_OPT_SET_PARA_CMD;
    gucAtParaIndex = 2;
    gastAtParaList[0].usParaLen = 1;
    gastAtParaList[0].ulParaValue = 0;
    gastAtParaList[1].usParaLen = 1;
    gastAtParaList[1].ulParaValue = 0;

    // MOCKER����
    MOCKER(NV_ReadEx)
        .expects(exactly(1))
        .with(any(), eq((VOS_UINT16)ev_NV_Item_SCI_DSDA_CFG), outBoundP((void *)&stSCICfg, (VOS_UINT32)sizeof(stSCICfg)), any())
        .will(returnValue((VOS_UINT32)NV_OK));

    // ���ñ��⺯��
    ulResult = At_SetSIMSlotPara(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetSIMSlotPara_007
������������: дNVʧ��
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-07-05
   ��   ��  : L47619
   �޸����� : add for SIM Insert
******************************************************************************/
TEST_F(Test_At_SetSIMSlotPara, Test_At_SetSIMSlotPara_007)
{
    // ��������
    VOS_UINT32                          ulResult;
    TAF_NV_SCI_CFG_STRU                 stSCICfg;

    // ������ʼ��
    stSCICfg.ulValue = 0;

    // ��ʼ��ȫ�ֱ���
    g_stATParseCmd.ucCmdOptType = AT_CMD_OPT_SET_PARA_CMD;
    gucAtParaIndex = 2;
    gastAtParaList[0].usParaLen = 1;
    gastAtParaList[0].ulParaValue = 1;
    gastAtParaList[1].usParaLen = 1;
    gastAtParaList[1].ulParaValue = 2;

    // MOCKER����
    MOCKER(NV_ReadEx)
        .expects(exactly(1))
        .with(any(), any(), outBoundP((void *)&stSCICfg, (VOS_UINT32)sizeof(stSCICfg)), any())
        .will(returnValue((VOS_UINT32)NV_OK));

    MOCKER(NV_WriteEx)
        .expects(exactly(1))
        .will(returnValue((VOS_UINT32)NV_ID_NOT_EXIST));

    // ���ñ��⺯��
    ulResult = At_SetSIMSlotPara(0);

    // ִ�м��
    EXPECT_EQ(AT_ERROR, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetSIMSlotPara_008
������������: дNV�ɹ�
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-07-05
   ��   ��  : L47619
   �޸����� : add for SIM Insert
******************************************************************************/
TEST_F(Test_At_SetSIMSlotPara, Test_At_SetSIMSlotPara_008)
{
    // ��������
    VOS_UINT32                          ulResult;
    TAF_NV_SCI_CFG_STRU                 stSCICfg;

    // ������ʼ��
    stSCICfg.ulValue = 0;

    // ��ʼ��ȫ�ֱ���
    g_stATParseCmd.ucCmdOptType = AT_CMD_OPT_SET_PARA_CMD;
    gucAtParaIndex = 2;
    gastAtParaList[0].usParaLen = 1;
    gastAtParaList[0].ulParaValue = 1;
    gastAtParaList[1].usParaLen = 1;
    gastAtParaList[1].ulParaValue = 2;

    // MOCKER����
    MOCKER(NV_ReadEx)
        .expects(exactly(1))
        .with(any(), any(), outBoundP((void *)&stSCICfg, (VOS_UINT32)sizeof(stSCICfg)), any())
        .will(returnValue((VOS_UINT32)NV_OK));

    MOCKER(NV_WriteEx)
        .expects(exactly(1))
        .will(returnValue((VOS_UINT32)NV_OK));

    // ���ñ��⺯��
    ulResult = At_SetSIMSlotPara(0);

    // ִ�м��
    EXPECT_EQ(AT_OK, ulResult);

    GlobalMockObject::verify();
}


#if (FEATURE_ON == FEATURE_VSIM)
/******************************************************************************
����     : Test_At_SetHvpDHPara
�������� : At_SetHvpDHPara UT������
�޸���ʷ :
 1.��   ��  : 2013-9-3
   ��   ��  : L47619
   �޸����� : V9R1 vSIM��Ŀ�޸�
******************************************************************************/
class Test_At_SetHvpDHPara: public ::testing::Test
{
public:
    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};
/******************************************************************************
�����������: Test_At_SetHvpDHPara_001
������������: ��������
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-9-3
   ��   ��  : L47619
   �޸����� : V9R1 vSIM��Ŀ�޸�
******************************************************************************/
TEST_F(Test_At_SetHvpDHPara, Test_At_SetHvpDHPara_001)
{
    // ��������
    VOS_UINT8       ucIndex = 0;
    VOS_UINT32      ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 3;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetHvpDHPara(ucIndex);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvpDHPara_002
������������: ��һ������Ϊ��
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-9-3
   ��   ��  : L47619
   �޸����� : V9R1 vSIM��Ŀ�޸�
******************************************************************************/
TEST_F(Test_At_SetHvpDHPara, Test_At_SetHvpDHPara_002)
{
    // ��������
    VOS_UINT8       ucIndex = 0;
    VOS_UINT32      ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 2;
    gastAtParaList[0].usParaLen = 0;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetHvpDHPara(ucIndex);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvpDHPara_003
������������: �ڶ�������Ϊ��
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-9-3
   ��   ��  : L47619
   �޸����� : V9R1 vSIM��Ŀ�޸�
******************************************************************************/
TEST_F(Test_At_SetHvpDHPara, Test_At_SetHvpDHPara_003)
{
    // ��������
    VOS_UINT8       ucIndex = 0;
    VOS_UINT32      ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 2;
    gastAtParaList[0].usParaLen = 1;
    gastAtParaList[1].usParaLen = 0;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetHvpDHPara(ucIndex);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvpDHPara_004
������������: �ڶ�����������Ϊ����
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-9-3
   ��   ��  : L47619
   �޸����� : V9R1 vSIM��Ŀ�޸�
******************************************************************************/
TEST_F(Test_At_SetHvpDHPara, Test_At_SetHvpDHPara_004)
{
    // ��������
    VOS_UINT8       ucIndex = 0;
    VOS_UINT32      ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 2;
    gastAtParaList[0].usParaLen = 1;
    gastAtParaList[1].usParaLen = 255;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetHvpDHPara(ucIndex);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvpDHPara_005
������������: ���붯̬�ڴ�ʧ��
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-9-3
   ��   ��  : L47619
   �޸����� : V9R1 vSIM��Ŀ�޸�
******************************************************************************/
TEST_F(Test_At_SetHvpDHPara, Test_At_SetHvpDHPara_005)
{
    // ��������
    VOS_UINT8       ucIndex = 0;
    VOS_UINT32      ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 2;
    gastAtParaList[0].usParaLen = 1;
    gastAtParaList[1].usParaLen = 256;

    // MOCKER����
    MOCKER(V_MemAlloc)
        .stubs()
        .will(returnValue(VOS_NULL_PTR));

    // ���ñ��⺯��
    ulResult = At_SetHvpDHPara(ucIndex);

    // ִ�м��
    EXPECT_EQ(AT_ERROR, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvpDHPara_006
������������: ��������ԿBASE16����󳤶ȴ���
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-9-3
   ��   ��  : L47619
   �޸����� : V9R1 vSIM��Ŀ�޸�
******************************************************************************/
TEST_F(Test_At_SetHvpDHPara, Test_At_SetHvpDHPara_006)
{
    // ��������
    VOS_UINT8       ucIndex = 0;
    VOS_UINT32      ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 2;
    gastAtParaList[0].usParaLen = 1;
    gastAtParaList[0].ulParaValue = DRV_AGENT_DH_KEY_SERVER_PUBLIC_KEY;
    gastAtParaList[1].usParaLen = 256;

    // MOCKER����
    MOCKER(At_Base16Decode)
        .stubs()
        .will(returnValue(200));

    // ���ñ��⺯��
    ulResult = At_SetHvpDHPara(ucIndex);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvpDHPara_007
������������: Modem��˽ԿBASE16����󳤶ȴ���
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-9-3
   ��   ��  : L47619
   �޸����� : V9R1 vSIM��Ŀ�޸�
******************************************************************************/
TEST_F(Test_At_SetHvpDHPara, Test_At_SetHvpDHPara_007)
{
    // ��������
    VOS_UINT8       ucIndex = 0;
    VOS_UINT32      ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 2;
    gastAtParaList[0].usParaLen = 1;
    gastAtParaList[0].ulParaValue = DRV_AGENT_DH_KEY_MODEM_PRIVATE_KEY;
    gastAtParaList[1].usParaLen = 96;

    // MOCKER����
    MOCKER(At_Base16Decode)
        .stubs()
        .will(returnValue(200));

    // ���ñ��⺯��
    ulResult = At_SetHvpDHPara(ucIndex);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvpDHPara_008
������������: ���÷�������Կ����������Ϣʧ��
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-9-3
   ��   ��  : L47619
   �޸����� : V9R1 vSIM��Ŀ�޸�
******************************************************************************/
TEST_F(Test_At_SetHvpDHPara, Test_At_SetHvpDHPara_008)
{
    // ��������
    VOS_UINT8       ucIndex = 0;
    VOS_UINT32      ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 2;
    gastAtParaList[0].usParaLen = 1;
    gastAtParaList[0].ulParaValue = DRV_AGENT_DH_KEY_SERVER_PUBLIC_KEY;
    gastAtParaList[1].usParaLen = 256;

    // MOCKER����
    MOCKER(At_Base16Decode)
        .stubs()
        .will(returnValue(128));

    MOCKER(AT_FillAndSndAppReqMsg)
        .stubs()
        .will(returnValue(TAF_FAILURE));


    // ���ñ��⺯��
    ulResult = At_SetHvpDHPara(ucIndex);

    // ִ�м��
    EXPECT_EQ(AT_ERROR, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvpDHPara_009
������������: ����Modem��˽Կ��������Ϣ�ɹ�
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-9-3
   ��   ��  : L47619
   �޸����� : V9R1 vSIM��Ŀ�޸�
******************************************************************************/
TEST_F(Test_At_SetHvpDHPara, Test_At_SetHvpDHPara_009)
{
    // ��������
    VOS_UINT8       ucIndex = 0;
    VOS_UINT32      ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 2;
    gastAtParaList[0].usParaLen = 1;
    gastAtParaList[0].ulParaValue = DRV_AGENT_DH_KEY_MODEM_PRIVATE_KEY;
    gastAtParaList[1].usParaLen = 96;

    // MOCKER����
    MOCKER(At_Base16Decode)
        .stubs()
        .will(returnValue(48));

    MOCKER(AT_FillAndSndAppReqMsg)
        .stubs()
        .will(returnValue(TAF_SUCCESS));


    // ���ñ��⺯��
    ulResult = At_SetHvpDHPara(ucIndex);

    // ִ�м��
    EXPECT_EQ(AT_WAIT_ASYNC_RETURN, ulResult);
    EXPECT_EQ(AT_CMD_HVPDH_SET, gastAtClientTab[ucIndex].CmdCurrentOpt);

    GlobalMockObject::verify();
}

/******************************************************************************
����     : Test_At_TestHvpDHPara
�������� : At_TestHvpDHPara UT������
�޸���ʷ :
 1.��   ��  : 2013-9-3
   ��   ��  : L47619
   �޸����� : V9R1 vSIM��Ŀ�޸�
******************************************************************************/
class Test_At_TestHvpDHPara: public ::testing::Test
{
public:
    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};
/******************************************************************************
�����������: Test_At_TestHvpDHPara_001
������������: HVPDH��������
Ԥ�ڽ��    :
�޸���ʷ    :
 1.��   ��  : 2013-9-3
   ��   ��  : L47619
   �޸����� : V9R1 vSIM��Ŀ�޸�
******************************************************************************/
TEST_F(Test_At_TestHvpDHPara, Test_At_TestHvpDHPara_001)
{
    // ��������
    VOS_UINT32      ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_TestHvpDHPara(0);

    // ִ�м��
    EXPECT_EQ(AT_OK, ulResult);

    GlobalMockObject::verify();
}

/*****************************************************************************
����     : Test_At_SetHvsDHPara
�������� : At_SetHvsDHPara UT������
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
*****************************************************************************/
class Test_At_SetHvsDHPara: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};

/******************************************************************************
�����������: Test_At_SetHvsDHPara_001
������������: ��������
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_CME_INCORRECT_PARAMETERS
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsDHPara, Test_At_SetHvsDHPara_001)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 2;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetHvsDHPara(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsDHPara_002
������������: �����ַ���Ϊ��
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_CME_INCORRECT_PARAMETERS
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsDHPara, Test_At_SetHvsDHPara_002)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 1;
    gastAtParaList[0].usParaLen = 0;

    // ���ñ��⺯��
    ulResult = At_SetHvsDHPara(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    // ִ�м��

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsDHPara_003
������������: �����ַ�������Ϊ����
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_CME_INCORRECT_PARAMETERS
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsDHPara, Test_At_SetHvsDHPara_003)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 1;
    gastAtParaList[0].usParaLen = 31;

    // ���ñ��⺯��
    ulResult = At_SetHvsDHPara(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    // ִ�м��

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsDHPara_004
������������: ����ռ�ʧ��
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_ERROR
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsDHPara, Test_At_SetHvsDHPara_004)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 1;
    gastAtParaList[0].usParaLen = 30;

    // MOCKER�����������ڴ�ʧ��
    MOCKER(V_MemAlloc)
        .expects(exactly(1))
        .will(returnValue(VOS_NULL_PTR));

    // ���ñ��⺯��
    ulResult = At_SetHvsDHPara(0);

    // ִ�м��
    EXPECT_EQ(AT_ERROR, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsDHPara_005
������������: ��Կ���ȳ������ֵ
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_CME_INCORRECT_PARAMETERS
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsDHPara, Test_At_SetHvsDHPara_005)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 1;
    gastAtParaList[0].usParaLen = 30;

    // MOCKER����
    MOCKER(At_Base16Decode)
        .expects(exactly(1))
        .will(returnValue(VSIM_KEYLEN_MAX+1));

    // ���ñ��⺯��
    ulResult = At_SetHvsDHPara(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsDHPara_006
������������: SI_PIH_HvsDHSet����ʧ��
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_ERROR
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsDHPara, Test_At_SetHvsDHPara_006)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 1;
    gastAtParaList[0].usParaLen = 30;

    // MOCKER����
    MOCKER(At_Base16Decode)
        .stubs()
        .will(returnValue(VSIM_KEYLEN_MAX));
    MOCKER(SI_PIH_HvsDHSet)
        .stubs()
        .will(returnValue(TAF_FAILURE));

    MOCKER(V_MemCpy)
        .expects(exactly(1));

    // ���ñ��⺯��
    ulResult = At_SetHvsDHPara(0);

    // ִ�м��
    EXPECT_EQ(AT_ERROR, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsDHPara_007
������������: �����Ⱦ���ȷ
Ԥ�ڽ��    : �����ɹ�������AT_WAIT_ASYNC_RETURN
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsDHPara, Test_At_SetHvsDHPara_007)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 1;
    gastAtParaList[0].usParaLen = 30;

    // MOCKER����
    MOCKER(At_Base16Decode)
        .expects(exactly(1))
        .will(returnValue(VSIM_KEYLEN_MAX));

    MOCKER(SI_PIH_HvsDHSet)
        .expects(exactly(1))
        .will(returnValue(TAF_SUCCESS));

    MOCKER(V_MemCpy)
        .expects(exactly(1));

    // ���ñ��⺯��
    ulResult = At_SetHvsDHPara(0);

    // ִ�м��
    EXPECT_EQ(AT_WAIT_ASYNC_RETURN, ulResult);

    GlobalMockObject::verify();
}

/*****************************************************************************
����     : Test_At_QryHvsDHPara
�������� : At_QryHvsDHPara UT������
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
*****************************************************************************/
class Test_At_QryHvsDHPara: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};

/******************************************************************************
�����������: Test_At_QryHvsDHPara_001
������������: SI_PIH_HvsDHQueryʧ��
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_CME_INCORRECT_PARAMETERS
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_QryHvsDHPara, Test_At_QryHvsDHPara_001)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���

    // MOCKER����
    MOCKER(SI_PIH_HvsDHQuery)
        .expects(exactly(1))
        .will(returnValue(TAF_FAILURE));

    // ���ñ��⺯��
    ulResult = At_QryHvsDHPara(0);

    // ִ�м��
    EXPECT_EQ(AT_ERROR, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_QryHvsDHPara_002
������������: SI_PIH_HvsDHQuery�ɹ�
Ԥ�ڽ��    : �����ɹ�������AT_WAIT_ASYNC_RETURN
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_QryHvsDHPara, Test_At_QryHvsDHPara_002)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���

    // MOCKER����
    MOCKER(SI_PIH_HvsDHQuery)
        .expects(exactly(1))
        .will(returnValue(TAF_SUCCESS));

    // ���ñ��⺯��
    ulResult = At_QryHvsDHPara(0);

    // ִ�м��
    EXPECT_EQ(AT_WAIT_ASYNC_RETURN, ulResult);

    GlobalMockObject::verify();
}

/*****************************************************************************
����     : Test_At_TestHvsDHPara
�������� : At_TestHvsDHPara UT������
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
*****************************************************************************/
class Test_At_TestHvsDHPara: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};

/******************************************************************************
�����������: Test_At_TestHvsDHPara_001
������������: At_TestHvsDHPara��������
Ԥ�ڽ��    : �����ɹ�������AT_OK
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_TestHvsDHPara, Test_At_TestHvsDHPara_001)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���

    // MOCKER����
   /* MOCKER(At_sprintf)
        .expects(exactly(1));*/

    // ���ñ��⺯��
    ulResult = At_TestHvsDHPara(0);

    // ִ�м��
    EXPECT_EQ(AT_OK, ulResult);

    GlobalMockObject::verify();
}

/*****************************************************************************
����     : Test_At_SetHvsstPara
�������� : At_SetHvsstPara UT������
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
*****************************************************************************/
class Test_At_SetHvsstPara: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};

/******************************************************************************
�����������: Test_At_SetHvsstPara_001
������������: ��������
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_ERROR
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsstPara, Test_At_SetHvsstPara_001)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 4;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetHvsstPara(0);

    // ִ�м��
    EXPECT_EQ(AT_ERROR, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsstPara_002
������������: ����ȱʧ
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_CME_INCORRECT_PARAMETERS
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsstPara, Test_At_SetHvsstPara_002)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 3;
    gastAtParaList[0].usParaLen = 0;
    gastAtParaList[1].usParaLen = 1;
    gastAtParaList[2].usParaLen = 1;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetHvsstPara(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsstPara_003
������������: ����ȱʧ
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_CME_INCORRECT_PARAMETERS
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsstPara, Test_At_SetHvsstPara_003)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 3;
    gastAtParaList[0].usParaLen = 1;
    gastAtParaList[1].usParaLen = 0;
    gastAtParaList[2].usParaLen = 1;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetHvsstPara(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsstPara_004
������������: ����ȱʧ
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_CME_INCORRECT_PARAMETERS
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsstPara, Test_At_SetHvsstPara_004)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 3;
    gastAtParaList[0].usParaLen = 1;
    gastAtParaList[1].usParaLen = 1;
    gastAtParaList[2].usParaLen = 0;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetHvsstPara(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsstPara_005
������������: �����Index ����ȷ
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_CME_INCORRECT_PARAMETERS
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsstPara, Test_At_SetHvsstPara_005)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 3;
    gastAtParaList[0].usParaLen = 1;
    gastAtParaList[1].usParaLen = 1;
    gastAtParaList[2].usParaLen = 1;
    gastAtParaList[0].ulParaValue = SI_PIH_SIM_REAL_SIM1+1;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetHvsstPara(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsstPara_006
������������: �����Index ����ȷ
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_CME_INCORRECT_PARAMETERS
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsstPara, Test_At_SetHvsstPara_006)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 3;
    gastAtParaList[0].usParaLen = 2;
    gastAtParaList[1].usParaLen = 1;
    gastAtParaList[2].usParaLen = 1;
    gastAtParaList[0].ulParaValue = SI_PIH_SIM_INDEX_BUTT;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetHvsstPara(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsstPara_007
������������: �����enable ��������ȷ
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_CME_INCORRECT_PARAMETERS
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsstPara, Test_At_SetHvsstPara_007)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    gucAtParaIndex = 3;
    gastAtParaList[0].usParaLen = 2;
    gastAtParaList[1].usParaLen = 1;
    gastAtParaList[2].usParaLen = 1;
    gastAtParaList[0].ulParaValue = SI_PIH_SIM_VIRT_SIM1+1;
    gastAtParaList[1].ulParaValue = SI_PIH_SIM_STATE_BUTT;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetHvsstPara(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsstPara_008
������������: �����slot ��������ȷ
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_CME_INCORRECT_PARAMETERS
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsstPara, Test_At_SetHvsstPara_008)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 3;
    gastAtParaList[0].usParaLen = 2;
    gastAtParaList[1].usParaLen = 1;
    gastAtParaList[2].usParaLen = 1;
    gastAtParaList[0].ulParaValue = SI_PIH_SIM_VIRT_SIM1+1;
    gastAtParaList[1].ulParaValue = SI_PIH_SIM_DISABLE;
    gastAtParaList[2].ulParaValue = SI_PIH_SIM_SLOT_BUTT;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_SetHvsstPara(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsstPara_009
������������: SI_PIH_HvSstSetʧ��
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_CME_PHONE_FAILURE
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsstPara, Test_At_SetHvsstPara_009)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 3;
    gastAtParaList[0].usParaLen = 2;
    gastAtParaList[1].usParaLen = 1;
    gastAtParaList[2].usParaLen = 1;
    gastAtParaList[0].ulParaValue = SI_PIH_SIM_VIRT_SIM1;
    gastAtParaList[1].ulParaValue = SI_PIH_SIM_DISABLE;
    gastAtParaList[2].ulParaValue = SI_PIH_SIM_SLOT1;

    // MOCKER����
    MOCKER(SI_PIH_HvSstSet)
        .expects(exactly(1))
        .will(returnValue(TAF_FAILURE));

    // ���ñ��⺯��
    ulResult = At_SetHvsstPara(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_PHONE_FAILURE, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsstPara_010
������������: SI_PIH_HvSstSet�ɹ�
Ԥ�ڽ��    : ���Գɹ�
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsstPara, Test_At_SetHvsstPara_010)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 3;
    gastAtParaList[0].usParaLen = 2;
    gastAtParaList[1].usParaLen = 1;
    gastAtParaList[2].usParaLen = 1;
    gastAtParaList[0].ulParaValue = SI_PIH_SIM_VIRT_SIM1;
    gastAtParaList[1].ulParaValue = SI_PIH_SIM_DISABLE;
    gastAtParaList[2].ulParaValue = SI_PIH_SIM_SLOT1;

    // MOCKER����
    MOCKER(SI_PIH_HvSstSet)
        .expects(exactly(1))
        .will(returnValue(TAF_SUCCESS));

    // ���ñ��⺯��
    ulResult = At_SetHvsstPara(0);

    // ִ�м��
    EXPECT_EQ(AT_WAIT_ASYNC_RETURN, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsstPara_011
������������: SI_PIH_HvSstSet�����������ȷ
Ԥ�ڽ��    : ���Գɹ�
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsstPara, Test_At_SetHvsstPara_011)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 3;
    gastAtParaList[0].usParaLen = 2;
    gastAtParaList[1].usParaLen = 1;
    gastAtParaList[2].usParaLen = 1;
    gastAtParaList[0].ulParaValue = SI_PIH_SIM_VIRT_SIM1;
    gastAtParaList[1].ulParaValue = SI_PIH_SIM_STATE_BUTT;
    gastAtParaList[2].ulParaValue = SI_PIH_SIM_SLOT1;

    // MOCKER����
    MOCKER(SI_PIH_HvSstSet)
        .expects(never())
        .will(returnValue(TAF_SUCCESS));

    // ���ñ��⺯��
    ulResult = At_SetHvsstPara(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_SetHvsstPara_012
������������: SI_PIH_HvSstSet���뿨�۲�������ȷ
Ԥ�ڽ��    : ���Գɹ�
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_SetHvsstPara, Test_At_SetHvsstPara_012)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gucAtParaIndex = 3;
    gastAtParaList[0].usParaLen = 2;
    gastAtParaList[1].usParaLen = 1;
    gastAtParaList[2].usParaLen = 1;
    gastAtParaList[0].ulParaValue = SI_PIH_SIM_VIRT_SIM1;
    gastAtParaList[1].ulParaValue = SI_PIH_SIM_DISABLE;
    gastAtParaList[2].ulParaValue = SI_PIH_SIM_SLOT_BUTT;

    // MOCKER����
    MOCKER(SI_PIH_HvSstSet)
        .expects(never())
        .will(returnValue(TAF_SUCCESS));

    // ���ñ��⺯��
    ulResult = At_SetHvsstPara(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/*****************************************************************************
����     : Test_At_QryHvsstPara
�������� : At_QryHvsstPara UT������
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
*****************************************************************************/
class Test_At_QryHvsstPara: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};

/******************************************************************************
�����������: Test_At_QryHvsstPara_001
������������: SI_PIH_HvSstQuery����ʧ��
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_ERROR
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_QryHvsstPara, Test_At_QryHvsstPara_001)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���

    // MOCKER����
    MOCKER(SI_PIH_HvSstQuery)
        .expects(exactly(1))
        .will(returnValue(TAF_FAILURE));

    // ���ñ��⺯��
    ulResult = At_QryHvsstPara(0);

    // ִ�м��
    EXPECT_EQ(AT_ERROR, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_TestHvsstPara_002
������������:
Ԥ�ڽ��    : �����ɹ�������AT_OK
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_QryHvsstPara, Test_At_QryHvsstPara_002)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���

    // MOCKER����
    MOCKER(SI_PIH_HvSstQuery)
        .expects(exactly(1))
        .will(returnValue(TAF_SUCCESS));

    // ���ñ��⺯��
    ulResult = At_QryHvsstPara(0);

    // ִ�м��
    EXPECT_EQ(AT_WAIT_ASYNC_RETURN, ulResult);

    GlobalMockObject::verify();
}

/*****************************************************************************
����     : Test_At_TestHvsstPara
�������� : At_TestHvsstPara UT������
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
*****************************************************************************/
class Test_At_TestHvsstPara: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};

/******************************************************************************
�����������: Test_At_SetHvsstPara_001
������������:
Ԥ�ڽ��    : �����ɹ�������AT_OK
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_TestHvsstPara, Test_At_TestHvsstPara_001)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���

    // MOCKER����
    /*MOCKER(At_sprintf)
        .expects(exactly(1));*/

    // ���ñ��⺯��
    ulResult = At_TestHvsstPara(0);

    // ִ�м��
    EXPECT_EQ(AT_OK, ulResult);

    GlobalMockObject::verify();
}

/*****************************************************************************
����     : Test_At_QryHvsContPara
�������� : At_QryHvsContPara UT������
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
*****************************************************************************/
class Test_At_QryHvsContPara: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};

/******************************************************************************
�����������: Test_At_QryHvsContPara_001
������������: SI_PIH_HvsContQuery����ʧ��
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_ERROR
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_QryHvsContPara, Test_At_QryHvsContPara_001)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���

    // MOCKER����
    MOCKER(SI_PIH_HvsContQuery)
        .expects(exactly(1))
        .will(returnValue(TAF_FAILURE));

    // ���ñ��⺯��
    ulResult = At_QryHvsContPara(0);

    // ִ�м��
    EXPECT_EQ(AT_ERROR, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_TestHvsstPara_002
������������: SI_PIH_HvsContQuery�����ɹ�s
Ԥ�ڽ��    : �����ɹ�������AT_OK
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_QryHvsContPara, Test_At_QryHvsContPara_002)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���

    // MOCKER����
    MOCKER(SI_PIH_HvsContQuery)
        .expects(exactly(1))
        .will(returnValue(TAF_SUCCESS));

    // ���ñ��⺯��
    ulResult = At_QryHvsContPara(0);

    // ִ�м��
    EXPECT_EQ(AT_WAIT_ASYNC_RETURN, ulResult);

    GlobalMockObject::verify();
}

/*****************************************************************************
����     : Test_At_DealRSFWVsim
�������� : At_DealRSFWVsim UT������
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
*****************************************************************************/
class Test_At_DealRSFWVsim: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};

/******************************************************************************
�����������: Test_At_DealRSFWVsim_001
������������: ��ǰIndex����������
Ԥ�ڽ��    : ����ʧ�ܣ�����AT_CME_INVALID_INDEX
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_DealRSFWVsim, Test_At_DealRSFWVsim_001)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gastAtParaList[4].ulParaValue = 2;
    gastAtParaList[3].ulParaValue = 1;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_DealRSFWVsim(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_INVALID_INDEX, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_DealRSFWVsim_002
������������: ��������ݳ��ȳ����������
Ԥ�ڽ��    : ����ʧ�ܣ�AT_CME_TEXT_STRING_TOO_LONG
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_DealRSFWVsim, Test_At_DealRSFWVsim_002)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gastAtParaList[4].ulParaValue = 2;
    gastAtParaList[3].ulParaValue = 2;
    gastAtParaList[5].usParaLen = AT_PARA_MAX_LEN + 1;

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_DealRSFWVsim(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_TEXT_STRING_TOO_LONG, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_DealRSFWVsim_003
������������: ����ռ�ʧ��
Ԥ�ڽ��    : ����ʧ�ܣ�AT_CME_MEMORY_FAILURE
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_DealRSFWVsim, Test_At_DealRSFWVsim_003)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gastAtParaList[4].ulParaValue = 2;
    gastAtParaList[3].ulParaValue = 2;
    gastAtParaList[5].usParaLen = AT_PARA_MAX_LEN;

    // MOCKER����
    MOCKER(V_MemAlloc)
        .stubs()
        .will(returnValue(VOS_NULL_PTR));

    // ���ñ��⺯��
    ulResult = At_DealRSFWVsim(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_MEMORY_FAILURE, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_DealRSFWVsim_004
������������: AtBase64Decodeʧ��
Ԥ�ڽ��    : ����ʧ�ܣ�AT_CME_INCORRECT_PARAMETERS
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_DealRSFWVsim, Test_At_DealRSFWVsim_004)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gastAtParaList[4].ulParaValue = 2;
    gastAtParaList[3].ulParaValue = 2;
    gastAtParaList[5].usParaLen = AT_PARA_MAX_LEN;

    // MOCKER����
    MOCKER(AtBase64Decode)
        .stubs()
        .will(returnValue(b64Result_CODE_SIZE_ERROR));

    // ���ñ��⺯��
    ulResult = At_DealRSFWVsim(0);

    // ִ�м��
    EXPECT_EQ(AT_CME_INCORRECT_PARAMETERS, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_DealRSFWVsim_005
������������: SI_PIH_AtFileWriteʧ��
Ԥ�ڽ��    : ����ʧ�ܣ�AT_ERROR
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_DealRSFWVsim, Test_At_DealRSFWVsim_005)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gastAtParaList[4].ulParaValue = 2;
    gastAtParaList[3].ulParaValue = 2;
    gastAtParaList[5].usParaLen = AT_PARA_MAX_LEN;

    // MOCKER����
    MOCKER(AtBase64Decode)
        .stubs()
        .will(returnValue(b64Result_OK));
    MOCKER(SI_PIH_AtFileWrite)
        .stubs()
        .will(returnValue(TAF_FAILURE));

    // ���ñ��⺯��
    ulResult = At_DealRSFWVsim(0);

    // ִ�м��
    EXPECT_EQ(AT_ERROR, ulResult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_DealRSFWVsim_006
������������: �����ɹ�
Ԥ�ڽ��    : �����ɹ���AT_SUCCESS
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_DealRSFWVsim, Test_At_DealRSFWVsim_006)
{
    // ��������
    VOS_UINT32 ulResult;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���
    gastAtParaList[4].ulParaValue = 2;
    gastAtParaList[3].ulParaValue = 2;
    gastAtParaList[5].usParaLen = AT_PARA_MAX_LEN;

    // MOCKER����
    MOCKER(AtBase64Decode)
        .stubs()
        .will(returnValue(b64Result_OK));
    MOCKER(SI_PIH_AtFileWrite)
        .stubs()
        .will(returnValue(TAF_SUCCESS));

    // ���ñ��⺯��
    ulResult = At_DealRSFWVsim(0);

    // ִ�м��
    EXPECT_EQ(AT_SUCCESS, ulResult);

    GlobalMockObject::verify();
}

/*****************************************************************************
����     : Test_At_HvsstQueryCnf
�������� : At_HvsstQueryCnf UT������
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
*****************************************************************************/
class Test_At_HvsstQueryCnf: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};

/******************************************************************************
�����������: Test_At_HvsstQueryCnf_001
������������: VSIMʹ��״̬
Ԥ�ڽ��    : �����ɹ�
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_HvsstQueryCnf, Test_At_HvsstQueryCnf_001)
{
    // ��������
    SI_PIH_EVENT_INFO_STRU stEvent;

    // ������ʼ��
    V_MemSet(&stEvent, 0, sizeof(SI_PIH_EVENT_INFO_STRU), 0, 0);
    stEvent.PIHEvent.HVSSTQueryCnf.enVSimState = SI_PIH_SIM_ENABLE;
    stEvent.PIHEvent.HVSSTQueryCnf.enSlot = 1;
    stEvent.PIHEvent.HVSSTQueryCnf.enCardUse = 1;

    // ��ʼ��ȫ�ֱ���

    // ���ñ��⺯��
    At_HvsstQueryCnf(&stEvent);

    // ִ�м��

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_HvsstQueryCnf_002
������������: VSIM ��ʹ��״̬
Ԥ�ڽ��    : �����ɹ�
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_HvsstQueryCnf, Test_At_HvsstQueryCnf_002)
{
    // ��������
    SI_PIH_EVENT_INFO_STRU stEvent;

    // ������ʼ��
    V_MemSet(&stEvent, 0, sizeof(SI_PIH_EVENT_INFO_STRU), 0, 0);
    stEvent.PIHEvent.HVSSTQueryCnf.enVSimState = SI_PIH_SIM_DISABLE;
    stEvent.PIHEvent.HVSSTQueryCnf.enSlot = 1;
    stEvent.PIHEvent.HVSSTQueryCnf.enCardUse = 1;

    // ��ʼ��ȫ�ֱ���

    // MOCKER����

    // ���ñ��⺯��
    At_HvsstQueryCnf(&stEvent);

    // ִ�м��

    GlobalMockObject::verify();
}

/*****************************************************************************
����     : Test_At_HvsContQueryCnf
�������� : At_HvsContQueryCnf UT������
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
*****************************************************************************/
class Test_At_HvsContQueryCnf: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};

/******************************************************************************
�����������: Test_At_HvsContQueryCnf_001
������������: �ϱ�SIM�����ݣ�MNC����Ϊ2
Ԥ�ڽ��    : �����ɹ�
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_HvsContQueryCnf, Test_At_HvsContQueryCnf_001)
{
    // ��������
    SI_PIH_EVENT_INFO_STRU  stEvent;
    VOS_UINT8               aucImsi[] = {4,5,4,0,3,0,0,0,1,3,0,0,8,4,9};

    // ������ʼ��
    V_MemSet(&stEvent, 0, sizeof(SI_PIH_EVENT_INFO_STRU), 0, 0);
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_RSIM].ucIndex = 1;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_RSIM].ucCardCap = 3;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_RSIM].ucCardType = 2;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_RSIM].ucRsv = 0;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_RSIM].usPlmnNum = 0;

    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_VSIM].ucIndex = 11;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_VSIM].ucCardCap = 3;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_VSIM].ucCardType = 2;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_VSIM].ucRsv = 0;
    V_MemCpy(stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_VSIM].aucImsi, aucImsi, sizeof(aucImsi), 0, 0);
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_VSIM].usPlmnNum = 1;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_VSIM].astPlmn[0].ulMCC = 0x40504;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_VSIM].astPlmn[0].ulMNC = 0xF0300;

    // ��ʼ��ȫ�ֱ���

    // MOCKER����

    // ���ñ��⺯��
    At_HvsContQueryCnf(&stEvent);

    // ִ�м��


    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_At_HvsContQueryCnf_002
������������: �ϱ�SIM�����ݣ�Ӳ��������Ϊ0��������MNC����Ϊ3
Ԥ�ڽ��    : �����ɹ�
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_HvsContQueryCnf, Test_At_HvsContQueryCnf_002)
{
    // ��������
    SI_PIH_EVENT_INFO_STRU  stEvent;
    VOS_UINT8               aucImsi[] = {4,5,4,0,3,0,0,0,1,3,0,0,8,4,9};

    // ������ʼ��
    V_MemSet(&stEvent, 0, sizeof(SI_PIH_EVENT_INFO_STRU), 0, 0);
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_RSIM].ucIndex = 1;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_RSIM].ucCardCap = 3;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_RSIM].ucCardType = 0;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_RSIM].ucRsv = 0;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_RSIM].usPlmnNum = 0;

    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_VSIM].ucIndex = 11;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_VSIM].ucCardCap = 3;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_VSIM].ucCardType = 2;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_VSIM].ucRsv = 0;
    V_MemCpy(stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_VSIM].aucImsi, aucImsi, sizeof(aucImsi), 0, 0);
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_VSIM].usPlmnNum = 1;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_VSIM].astPlmn[0].ulMCC = 0x40504;
    stEvent.PIHEvent.HvsContCnf.astSimCard[SI_PIH_VSIM].astPlmn[0].ulMNC = 0x30300;

    // ��ʼ��ȫ�ֱ���

    // MOCKER����

    // ���ñ��⺯��
    At_HvsContQueryCnf(&stEvent);

    // ִ�м��


    GlobalMockObject::verify();
}

/*****************************************************************************
����     : Test_AT_HvsDHQueryCnf
�������� : AT_HvsDHQueryCnf UT������
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
*****************************************************************************/
class Test_AT_HvsDHQueryCnf: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};

/******************************************************************************
�����������: Test_AT_HvsDHQueryCnf_001
������������: ��������Կ����Ϊ0
Ԥ�ڽ��    : �����ɹ�
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_AT_HvsDHQueryCnf, Test_AT_HvsDHQueryCnf_001)
{
    // ��������
    SI_PIH_EVENT_INFO_STRU  stEvent;

    // ������ʼ��
    V_MemSet(&stEvent, 0, sizeof(SI_PIH_EVENT_INFO_STRU), 0, 0);
    stEvent.PIHEvent.HvsDHCnf.enAlgorithm = 1;
    stEvent.PIHEvent.HvsDHCnf.stSkey.ulKeyLen = 0;

    // ��ʼ��ȫ�ֱ���

    // MOCKER����
    /*MOCKER(At_sprintf)
        .expects(exactly(6))
        .will(returnValue(128));*/
    MOCKER(At_Hex2Base16)
        .expects(exactly(1))
        .will(returnValue(128));

    // ���ñ��⺯��
    AT_HvsDHQueryCnf(&stEvent);

    // ִ�м��

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_AT_HvsDHQueryCnf_002
������������: ��������Կ���Ȳ�Ϊ0
Ԥ�ڽ��    : �����ɹ�
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_AT_HvsDHQueryCnf, Test_AT_HvsDHQueryCnf_002)
{
    // ��������
    SI_PIH_EVENT_INFO_STRU  stEvent;

    // ������ʼ��
    V_MemSet(&stEvent, 0, sizeof(SI_PIH_EVENT_INFO_STRU), 0, 0);
    stEvent.PIHEvent.HvsDHCnf.enAlgorithm = 1;
    stEvent.PIHEvent.HvsDHCnf.stSkey.ulKeyLen = 128;

    // ��ʼ��ȫ�ֱ���

    // MOCKER����
    /*MOCKER(At_sprintf)
        .expects(exactly(6))
        .will(returnValue(128));*/
    MOCKER(At_Hex2Base16)
        .expects(exactly(2))
        .will(returnValue(128));

    // ���ñ��⺯��
    AT_HvsDHQueryCnf(&stEvent);

    // ִ�м��

    GlobalMockObject::verify();
}

/*****************************************************************************
����     : Test_At_Base16Decode
�������� : At_Base16Decode UT������
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
*****************************************************************************/
class Test_At_Base16Decode: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};

/******************************************************************************
�����������: Test_At_Base16Decode_00��
������������: ����Base16�����ַ���
Ԥ�ڽ��    : �����ɹ�
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_Base16Decode, Test_At_Base16Decode_001)
{
    // ��������
    VOS_CHAR    *cInput         = "12BA3F&(bd";
    VOS_UINT32   ulDataLen      = 10;
    VOS_UINT8    ucOutput[10]   = {0};
    VOS_UINT32   ulResult       = 0;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���

    // MOCKER����

    // ���ñ��⺯��
    ulResult = At_Base16Decode(cInput, ulDataLen, ucOutput);

    // ִ�м��
    EXPECT_EQ(5, ulResult);
    EXPECT_EQ(0x12, ucOutput[0]);
    EXPECT_EQ(0xBA, ucOutput[1]);
    EXPECT_EQ(0x3F, ucOutput[2]);
    EXPECT_EQ(0xBD, ucOutput[4]);

    GlobalMockObject::verify();
}

/*****************************************************************************
����     : Test_At_Hex2Base16
�������� : At_Hex2Base16 UT������
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
*****************************************************************************/
class Test_At_Hex2Base16: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};

/******************************************************************************
�����������: Test_At_Hex2Base_001
������������: Hexת��ΪBase16��������
Ԥ�ڽ��    :
�޸���ʷ :
 1.��   ��  : 2013-09-03
   ��   ��  : zhangxuechao 00185430
   �޸����� : �½�CASE
******************************************************************************/
TEST_F(Test_At_Hex2Base16, Test_At_Hex2Base16_001)
{
    // ��������
    VOS_UINT32   ulMaxLength    = AT_CMD_MAX_LEN;
    VOS_UINT8    ucInput[10]    = {0xFF, 0x1E, 0x3E, 0x4F, 0x5A, 0x99, 0x10, 0x58, 0xab, 0xdA};
    VOS_UINT8    ucOutput[21]   = {0};
    VOS_UINT32   ulDataLen      = 10;
    VOS_UINT32   ulResult       = 0;

    // ������ʼ��

    // ��ʼ��ȫ�ֱ���

    // MOCKER����
    /*MOCKER(At_sprintf)
        .expects(exactly(20));*/

    // ���ñ��⺯��
    ulResult = At_Hex2Base16(ulMaxLength, (TAF_CHAR*)ucOutput, (TAF_CHAR*)ucOutput, ucInput, ulDataLen);

    // ִ�м��
    EXPECT_EQ(20, ulResult);

    GlobalMockObject::verify();
}

#endif

#if (FEATURE_ON == FEATURE_IMS)
/*****************************************************************************
����     : Test_AT_UiccAccessFileCnf
�������� : AT_UiccAccessFileCnf UT������
�޸���ʷ :
1.��    ��    : 2014��03��25��
  ��    ��    : H59254
  �޸�����    : GBA������Ŀ
*****************************************************************************/
class Test_AT_UiccAccessFileCnf: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();

    }
    void TearDown()
    {

    }
};

/******************************************************************************
�����������: Test_AT_UiccAccessFileCnf_001
������������: ��ȡ�ļ��ķ���
Ԥ�ڽ��    :
�޸���ʷ    :
1.��    ��    : 2014��03��25��
  ��    ��    : H59254
  �޸�����    : GBA������Ŀ
******************************************************************************/
TEST_F(Test_AT_UiccAccessFileCnf, Test_AT_UiccAccessFileCnf_001)
{
    // ��������
    VOS_UINT32                          ulresult;
    TAF_UINT8                           ucIndex;
    SI_PIH_EVENT_INFO_STRU              stEvent;

    // ������ʼ��
    ucIndex = 0;
    memset(&stEvent, 0, sizeof(SI_PIH_EVENT_INFO_STRU));

    stEvent.PIHEvent.UiccAcsFileCnf.ulDataLen = 100;
    stEvent.PIHEvent.UiccAcsFileCnf.enCmdType = SI_PIH_ACCESS_READ;

    // ��ʼ��ȫ�ֱ���

    // MOCKER����
    /*MOCKER(At_sprintf)
        .stubs()
        .will(returnValue(100));*/

    MOCKER(At_HexAlpha2AsciiString)
        .stubs()
        .will(returnValue(100));

    // ���ñ��⺯��
    ulresult = AT_UiccAccessFileCnf(ucIndex, &stEvent);

    // ִ�м��
    EXPECT_EQ(109, ulresult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_AT_UiccAccessFileCnf_002
������������: д���ļ��ķ���
Ԥ�ڽ��    :
�޸���ʷ    :
1.��    ��    : 2014��03��25��
  ��    ��    : H59254
  �޸�����    : GBA������Ŀ
******************************************************************************/
TEST_F(Test_AT_UiccAccessFileCnf, Test_AT_UiccAccessFileCnf_002)
{
    // ��������
    VOS_UINT32                          ulresult;
    TAF_UINT8                           ucIndex;
    SI_PIH_EVENT_INFO_STRU              stEvent;

    // ������ʼ��
    ucIndex = 0;
    memset(&stEvent, 0, sizeof(SI_PIH_EVENT_INFO_STRU));

    stEvent.PIHEvent.UiccAcsFileCnf.ulDataLen = 0;
    stEvent.PIHEvent.UiccAcsFileCnf.enCmdType = SI_PIH_ACCESS_WRITE;

    // ��ʼ��ȫ�ֱ���

    // MOCKER����
    /*MOCKER(At_sprintf)
        .expects(never())
        .will(returnValue(100));*/

    MOCKER(At_HexAlpha2AsciiString)
        .expects(never())
        .will(returnValue(100));

    // ���ñ��⺯��
    ulresult = AT_UiccAccessFileCnf(ucIndex, &stEvent);

    // ִ�м��
    EXPECT_EQ(0, ulresult);

    GlobalMockObject::verify();
}

/*****************************************************************************
����     : Test_AT_UiccAuthCnf
�������� : AT_UiccAuthCnf UT������
�޸���ʷ :
1.��    ��    : 2014��03��25��
  ��    ��    : H59254
  �޸�����    : GBA������Ŀ
*****************************************************************************/
class Test_AT_UiccAuthCnf: public ::testing::Test
{
    public:

    void SetUp()
    {
        UT_STUB_INIT();
        gastAtClientTab[0].CmdCurrentOpt = AT_CMD_CURRENT_OPT_BUTT;
    }
    void TearDown()
    {
        gastAtClientTab[0].CmdCurrentOpt = AT_CMD_CURRENT_OPT_BUTT;
    }
};

/******************************************************************************
�����������: Test_AT_UiccAuthCnf_001
������������: ^UICCAUTH����AKA��Ȩ
Ԥ�ڽ��    :
�޸���ʷ    :
1.��    ��    : 2014��03��25��
  ��    ��    : H59254
  �޸�����    : GBA������Ŀ
******************************************************************************/
TEST_F(Test_AT_UiccAuthCnf, Test_AT_UiccAuthCnf_001)
{
    // ��������
    VOS_UINT32                          ulresult;
    TAF_UINT8                           ucIndex;
    SI_PIH_EVENT_INFO_STRU              stEvent;

    // ������ʼ��
    ucIndex = 0;
    memset(&stEvent, 0, sizeof(SI_PIH_EVENT_INFO_STRU));

    stEvent.PIHEvent.UiccAuthCnf.enStatus = SI_PIH_AUTH_SUCCESS;
    stEvent.PIHEvent.UiccAuthCnf.enAuthType = SI_PIH_UICCAUTH_AKA;

    // ��ʼ��ȫ�ֱ���
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_UICCAUTH_SET;

    // MOCKER����
    /*MOCKER(At_sprintf)
        .stubs()
        .will(returnValue(10));*/

    MOCKER(At_HexAlpha2AsciiString)
        .stubs()
        .will(returnValue((VOS_UINT32)10));

    // ���ñ��⺯��
    ulresult = AT_UiccAuthCnf(ucIndex, &stEvent);

    // ִ�м��
    EXPECT_EQ(50, ulresult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_AT_UiccAuthCnf_002
������������: ^UICCAUTH����GBA��Ȩ
Ԥ�ڽ��    :
�޸���ʷ    :
1.��    ��    : 2014��03��25��
  ��    ��    : H59254
  �޸�����    : GBA������Ŀ
******************************************************************************/
TEST_F(Test_AT_UiccAuthCnf, Test_AT_UiccAuthCnf_002)
{
    // ��������
    VOS_UINT32                          ulresult;
    TAF_UINT8                           ucIndex;
    SI_PIH_EVENT_INFO_STRU              stEvent;

    // ������ʼ��
    ucIndex = 0;
    memset(&stEvent, 0, sizeof(SI_PIH_EVENT_INFO_STRU));

    stEvent.PIHEvent.UiccAuthCnf.enStatus = SI_PIH_AUTH_SUCCESS;
    stEvent.PIHEvent.UiccAuthCnf.enAuthType = SI_PIH_UICCAUTH_GBA;

    // ��ʼ��ȫ�ֱ���
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_UICCAUTH_SET;

    // MOCKER����
    /*MOCKER(At_sprintf)
        .stubs()
        .will(returnValue(10));*/

    MOCKER(At_HexAlpha2AsciiString)
        .stubs()
        .will(returnValue((VOS_UINT32)10));

    // ���ñ��⺯��
    ulresult = AT_UiccAuthCnf(ucIndex, &stEvent);

    // ִ�м��
    EXPECT_EQ(24, ulresult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_AT_UiccAuthCnf_003
������������: ^UICCAUTH�����Ȩͬ��ʧ��
Ԥ�ڽ��    :
�޸���ʷ    :
1.��    ��    : 2014��03��25��
  ��    ��    : H59254
  �޸�����    : GBA������Ŀ
******************************************************************************/
TEST_F(Test_AT_UiccAuthCnf, Test_AT_UiccAuthCnf_003)
{
    // ��������
    VOS_UINT32                          ulresult;
    TAF_UINT8                           ucIndex;
    SI_PIH_EVENT_INFO_STRU              stEvent;

    // ������ʼ��
    ucIndex = 0;
    memset(&stEvent, 0, sizeof(SI_PIH_EVENT_INFO_STRU));

    stEvent.PIHEvent.UiccAuthCnf.enStatus = SI_PIH_AUTH_SYNC;
    stEvent.PIHEvent.UiccAuthCnf.enAuthType = SI_PIH_UICCAUTH_GBA;

    // ��ʼ��ȫ�ֱ���
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_UICCAUTH_SET;

    // MOCKER����
    /*MOCKER(At_sprintf)
        .stubs()
        .will(returnValue(10));*/

    MOCKER(At_HexAlpha2AsciiString)
        .stubs()
        .will(returnValue((VOS_UINT32)10));

    // ���ñ��⺯��
    ulresult = AT_UiccAuthCnf(ucIndex, &stEvent);

    // ִ�м��
    EXPECT_EQ(33, ulresult);

    GlobalMockObject::verify();
}

/******************************************************************************
�����������: Test_AT_UiccAuthCnf_004
������������: ^KSNAFAUTH�����Ȩ�ɹ�
Ԥ�ڽ��    :
�޸���ʷ    :
1.��    ��    : 2014��03��25��
  ��    ��    : H59254
  �޸�����    : GBA������Ŀ
******************************************************************************/
TEST_F(Test_AT_UiccAuthCnf, Test_AT_UiccAuthCnf_004)
{
    // ��������
    VOS_UINT32                          ulresult;
    TAF_UINT8                           ucIndex;
    SI_PIH_EVENT_INFO_STRU              stEvent;

    // ������ʼ��
    ucIndex = 0;
    memset(&stEvent, 0, sizeof(SI_PIH_EVENT_INFO_STRU));

    stEvent.PIHEvent.UiccAuthCnf.stNAFData.aucKs_ext_NAF[0] = 16;

    // ��ʼ��ȫ�ֱ���
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_KSNAFAUTH_SET;

    // MOCKER����
    /*MOCKER(At_sprintf)
        .stubs()
        .will(returnValue(10));*/

    MOCKER(At_HexAlpha2AsciiString)
        .stubs()
        .will(returnValue((VOS_UINT32)10));

    // ���ñ��⺯��
    ulresult = AT_UiccAuthCnf(ucIndex, &stEvent);

    // ִ�м��
    EXPECT_EQ(25, ulresult);

    GlobalMockObject::verify();
}

#endif