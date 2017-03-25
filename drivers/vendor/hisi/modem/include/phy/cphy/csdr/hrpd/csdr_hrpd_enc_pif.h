/** ****************************************************************************

                    Huawei Technologies Sweden AB (C), 2001-2015

 ********************************************************************************
 * @author    Automatically generated by DAISY
 * @version
 * @date      2015-11-05
 * @file
 * @brief
 * This interface carries data to be transmitted in the reverse channel on
 * dedicate state, including the corresponding control information. This
 * includes:
 * -  Input: Data MAC Layer packets for RTC.
 * -  Input: Access Data MAC Layer packets.
 * -  Input: Tx Gain levels (Physical Layer Subtype 2 only).
 * The information exchange between CTTF_HRPD and CSDR_HRPD is done via a shared
 * buffer of the type CSDR_HRPD_REV_DATA_BUF_INFO_STRU. A visual representation
 * of this buffer is outlined in .
 *
 * ATTENTION:
 * CSDR_HRPD_ADDR_INFO_STRU, @ulFCtrlMgmtAddr and @ulRCtrlMgmtAddr are needed to
 * put into non-power-down area.
 * Due to the handling data in non-TCH state by mac, it's better to use signal
 * to do it. So do not put anything in common state into share-memory.
 * @copyright Huawei Technologies Sweden AB
 *******************************************************************************/
#ifndef CSDR_HRPD_ENC_PIF_H
#define CSDR_HRPD_ENC_PIF_H

/*******************************************************************************
 1. Other files included
*******************************************************************************/

#include "vos.h"

#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#pragma pack(4)

/*******************************************************************************
 2. Macro definitions
*******************************************************************************/

/**
 * the maximum bit of Mac layer packet on Reverse Traffic channel is 12288
 * bits, then transfers into 32-bit for DSP
 * 32-bit align(12288bit) = 384
 */
#define CSDR_HRPD_MAX_32BIT_WORD_ENCODE_SIZE                ( 384 )

/*******************************************************************************
 3. Enumerations declarations
*******************************************************************************/

/** ****************************************************************************
 * Name        : CSDR_HRPD_TX_CTRL_ENUM_UINT16
 *
 * Description : This flag provides a mechanism to forbid MAC to transmit data.
 *******************************************************************************/
enum CSDR_HRPD_TX_CTRL_ENUM
{
    CSDR_HRPD_ALLOW_TX                  = 0x0000, /**< It's allowed MAC to tx data by CSDR. */
    CSDR_HRPD_NOT_ALLOW_TX              = 0x0001, /**< It's forbidden MAC to tx data by CSDR. */
    CSDR_HRPD_TX_CTRL_BUTT              = 0x0002
};
typedef VOS_UINT16 CSDR_HRPD_TX_CTRL_ENUM_UINT16;

/** ****************************************************************************
 * Name        : CSDR_HRPD_MUTEX_DATA_ENUM_UINT16
 *
 * Description : It's used to indicate whether data has been written or not.
 * The purpose is avoid data is being writing, SDR begins to read data; or SDR
 * is busy on reading data, MAC goes to update data.
 *
 * The initial state is data not existed. At this state, CTTF_HRPD is allowed
 * to use the buffer and fill buffer with MAC layer packet. And CSDR_HRPD is
 * not allowed to read the data including parameters in this state. After
 * CTTF_HRPD finished filling the MAC layer packet and parameters, then set
 * @enMutexFlag to data existed. Till then, CSDR_HRPD is allowed to read the
 * data and parameters. After CSDR_HRPD read them out, it sets @enMutexFlag to
 * data not existed.
 *
 * ATTENTION: It's always filled data and parameter defined in
 * CSDR_HRPD_REV_DATA_BUF_INFO_STRU at the same time by MAC. And after
 * @enMutexFlag turns into data existed, SDR always reads them out at the same
 * time, too.
 *
 * After CSDR_HRPD has done release operation, CSDR_HRPD set mutex into not
 * exsit.
 *******************************************************************************/
enum CSDR_HRPD_MUTEX_DATA_ENUM
{
    CSDR_HRPD_MUTEX_DATA_NOT_EXIST      = 0x0000,
    CSDR_HRPD_MUTEX_DATA_EXIST          = 0x0001,
    CSDR_HRPD_MUTEX_DATA_ENUM_BUTT      = 0x0002
};
typedef VOS_UINT16 CSDR_HRPD_MUTEX_DATA_ENUM_UINT16;

/** ****************************************************************************
 * Name        : CSDR_HRPD_REV_DATA_TYPE_ENUM_UINT16
 *
 * Description : This enumeration is used to set the transmission encode type.
 *******************************************************************************/
enum CSDR_HRPD_REV_DATA_TYPE_ENUM
{
    CSDR_HRPD_REV_DATA_TYPE_PHY_DEFAULT_RTC                 = 0x0000, /**< Subtype 0 PHY protocol, MAC default RTC */
    CSDR_HRPD_REV_DATA_TYPE_PHY_ST2_RTC                     = 0x0001, /**< Subtype 2 PHY protocol, MAC Subtype3 */
    CSDR_HRPD_REV_DATA_TYPE_PHY_DEFAULT_AC                  = 0x0002, /**< Subtype 0/2 PHY protocol, MAC default AC */
    CSDR_HRPD_REV_DATA_TYPE_PHY_ENHANCED_AC                 = 0x0003, /**< Subtype 2 PHY protocol, MAC enhanced AC */
    CSDR_HRPD_REV_DATA_TYPE_ENUM_BUTT                       = 0x0004
};
typedef VOS_UINT16 CSDR_HRPD_REV_DATA_TYPE_ENUM_UINT16;

/** ****************************************************************************
 * Name        : CSDR_HRPD_T2P_TRANSITION_VALUE_ENUM_UINT16
 *
 * Description :
 *******************************************************************************/
enum CSDR_HRPD_T2P_TRANSITION_VALUE_ENUM
{
    CSDR_HRPD_T2P_TRANSITION_VALUE_0                        = 0x0000,
    CSDR_HRPD_T2P_TRANSITION_VALUE_1                        = 0x0001,
    CSDR_HRPD_T2P_TRANSITION_VALUE_2                        = 0x0002,
    CSDR_HRPD_T2P_TRANSITION_VALUE_3                        = 0x0003,
    CSDR_HRPD_T2P_TRANSITION_VALUE_ENUM_BUTT                = 0x0004
};
typedef VOS_UINT16 CSDR_HRPD_T2P_TRANSITION_VALUE_ENUM_UINT16;

/*******************************************************************************
 4. Message Header declaration
*******************************************************************************/

/*******************************************************************************
 5. Message declaration
*******************************************************************************/

/*******************************************************************************
 6. STRUCT and UNION declaration
*******************************************************************************/

/** ****************************************************************************
 * Name        : CSDR_HRPD_REV_DATA_BUF_STRU
 *
 * Description : Data is always filled from start address of data buffer
 * -  Data in the memory is like an octet array. E.g. Data[0] to Data[n]
 * |Data[0] Data[1] Data[2] Data[3]|Data[4] Data[5] Data[6] Data[7]| ...
 * Data[n]|
 * |         aulDataBuffer[0]      |      aulDataBuffer[1]         | ...       
 *        |
 * -  In an octet, bit 7 is MSB, bit 0 is LSB. 1st bit is put into MSB, 2nd bit
 *    is put into the next MSB, and so on.
 * MSB                                    LSB
 * |bit7 bit6 bit5 bit4 bit3 bit2 bit1 bit0|
 * |1st  2nd            ...             7th|
 * -  As bit length of data may not be times of 8, so the last byte, only some
 *    bits starts from MSB are valid. E.g. bit length is 98bit, for the last
 *    byte, only 2 bits starts from MSB are valid. The left bits are unused
 *    with bit value zero.
 * |bit7 bit6 bit5 bit4 bit3 bit2 bit1 bit0|
 * | x    x    0    0    0    0    0    0  |
 *******************************************************************************/
typedef struct
{
    VOS_UINT32                          aulDataBuffer[CSDR_HRPD_MAX_32BIT_WORD_ENCODE_SIZE]; /**< used to fill Data */
} CSDR_HRPD_REV_DATA_BUF_STRU;

/** ****************************************************************************
 * Name        : CSDR_HRPD_REV_DATA_BUF_INFO_STRU
 *
 * Description : It's control header for reverse management, we call it"
 * reverse data buffer information", including data address and parameters of
 * data.
 *
 * Additional parameter information:
 * After reverse MAC has been established, every 4 slots MAC will calculate
 * boundary of reverse link silence interval, and try to read
 * @enEncodeBufferCtrlMutex to decide whether it can put a MAC layer packet
 * into buffer or not:
 * If MAC decides to put a packet, it needs to update all related parameters
 * (defined in this structure) at the same moment. So, MAC sets the size of MAC
 * layer packet, and Physical layer type. If @enPhyEncodeType is ST-2, MAC
 * needs to fill ArqPacketId and T2P, RRI transition gains, too.
 * @enAllowedTx is used by CSDR when it wants to forbid MAC transmission. It's
 * useful in multi-modem scenario.
 * MAC Packet size = Physical Layer Packet Size - (FCS + Tail bits)
 *******************************************************************************/
typedef struct
{
    CSDR_HRPD_MUTEX_DATA_ENUM_UINT16                        enEncodeBufferCtrlMutex; /**< buffer control mutex */
    CSDR_HRPD_TX_CTRL_ENUM_UINT16                           enAllowedTx;
    VOS_UINT16                                              ausReserve1[1];
    CSDR_HRPD_REV_DATA_TYPE_ENUM_UINT16                     enPhyEncodeType;         /**< Physical RTC Default, Physical SubType 2(shorted as ST-2) */
    VOS_UINT16                                              usMacPacketSize;         /**< Size of MAC layer packet, unit: bit */
    VOS_UINT16                                              usArqPacketID;           /**< only for ST-2, to be echoed back in FWD SLOT BUFFER (ARQ) */
    CSDR_HRPD_T2P_TRANSITION_VALUE_ENUM_UINT16              enT2PTransitionValueM;   /**< only for ST-2 */
    VOS_UINT16                                              usT2PPreTransitionGain;  /**< only for ST-2, this field indictes the data channel power relative to the pilot channel power when transmitting a usMacPacketSize bit payload prior to the T2P transition. in units of 0.25db */
    VOS_UINT16                                              usT2PPostTransitionGain; /**< only for ST-2,  this field indictes the data channel power relative to the pilot channel power when transmitting a usMacPacketSize bit payload following the T2P transition. in units of 0.25db */
    VOS_INT16                                               sRRIPreTransitionGain;   /**< only for ST-2. this filed indicates the RRI channel gain for sub-packes transimitted prior to the T2P transition. in units of 1 db */
    VOS_INT16                                               sRRIPostTransitionGain;  /**< only for ST-2.  this filed indicates the RRI channel gain for sub-packes transimitted following the T2P transition. in units of 1 db */
    VOS_UINT16                                              ausReserve2[1];
    VOS_UINT32                                              ulDataBufferStartAddr;   /**< it records the start address of Reverse Data Buffer. CSDR initial it to the address of @aulDataBuffer in CSDR_HRPD_REV_DATA_BUF_STRU */
} CSDR_HRPD_REV_DATA_BUF_INFO_STRU;

/*******************************************************************************
 7. OTHER declarations
*******************************************************************************/

/*******************************************************************************
 8. Global  declaration
*******************************************************************************/

/*******************************************************************************
 9. Function declarations
*******************************************************************************/

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#endif