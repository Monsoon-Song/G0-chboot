
/*****************************************************************************
 *                                                                           *
 * COPYRIGHT (C) 2018 Chaihuo-edu - All Rights Reserved                      *
 *                                                                           *
 * Chaihuo-edu makes no warranty express or implied including but not        *
 * limited to, any warranty of                                               *
 *                                                                           *
 *                                                                           *
 *  (i)  merchantability or fitness for a particular purpose and/or          *
 *                                                                           *
 *  (ii) requirements, for a particular purpose in relation to the LICENSED  *
 *       MATERIALS, which is provided AS IS, WITH ALL FAULTS. Chaihuo-edu    *
 *       does not represent or warrant that the LICENSED MATERIALS provided  *
 *       here under is free of infringement of any third party patents,      *
 *       copyrights, trade secrets or other intellectual property rights.    *
 *       ALL WARRANTIES, CONDITIONS OR OTHER TERMS IMPLIED BY LAW ARE        *
 *       EXCLUDED TO THE FULLEST EXTENT PERMITTED BY LAW                     *
 *                                                                           *
 *****************************************************************************
 * */

/* config.h -*- mode:C; c-file-style: "eay" -*- */
/*
 * @author Monsoon Song <zhengbin.song@chaihuo.org>
 *
 */

#ifndef  __config_H__
#define  __config_H__


#define  HARDWARE_V2

/* 影响boot.hex,和demoinit */
#ifdef   HARDWARE_V2
//#define  UARTSWITCH_DBG
#endif


//#define  DDBG


/*********************************************************************/
/*                                                                   */
/* 系统宏定义,勿修改                                                 */
/*                                                                   */
/*********************************************************************/


/* #define  USE_S112_SECTION  @原用于L0 API配置,不再使用
 * #define  USE_MLIB_SECTION  @原用于stdlib配置,不再使用
 * */


#define  VECT_RAM_ADDR                 0x20001CD0


#define  LEVEL1_ADDR                   0x00018000
#define  LTABLE_ADDR                   0x00019000
#define  LEVEL2_ADDR                   0x0001A000
#define  LEVEL3_ADDR                   0x0001E000

#define  FLASH_END                     0x00080000



/* 来自上位机UART/BLE的命令处理宏定义
 * */

#define  CMD_TYPE_TOCORE               0xA5
#define  CMD_TYPE_TONODE               0xC3
#define  CMD_TYPE_FRCORE               0xD2
#define  CMD_TYPE_FRNODE               0xF0


#define  CMD_EXEC_INFO                 0x00
#define  CMD_EXEC_SCAN                 0x01
#define  CMD_EXEC_UART                 0x02
#define  CMD_EXEC_MODE                 0x08
#define  CMD_EXEC_BOOT                 0x0F
#define  CMD_EXEC_FSTA                 0x10
#define  CMD_EXEC_FDAT                 0x11
#define  CMD_EXEC_FFIN                 0x12
#define  CMD_EXEC_FCHK                 0x13
#define  CMD_EXEC_FRED                 0x14
#define  CMD_EXEC_FENT                 0x15

#define  CMD_EXEC_INST                 0x40


#define  CMD_RESP_INFO                 0x00
#define  CMD_RESP_RAW                  0xD0
#define  CMD_RESP_EVT                  0x0E
#define  CMD_RESP_EXEC                 0x40



#define  CMD_HEAD_LEN                  cmd[0]
#define  CMD_HEAD_TYP                  cmd[1]
#define  CMD_HEAD_EXE                  cmd[2]
#define  CMD_HEAD_OPT                  cmd[3]

#define  CMD_HEAD_DAT                 (cmd+4)



/* systick计数值*/
#define  SYSTICK_CTRL                  0x00
#define  SYSTICK_LOAD                  0x04
#define  SYSTICK_VAL                   0x08
#define  SYSTICK_ADDR                  0xe000e010

#define  tickdown()     \
   *(volatile uint32_t*)(SYSTICK_ADDR + SYSTICK_CTRL) = 0



#if 1

#define  uart_init               ((void(*)(void))0x000179B1)
#define  rx_byte                 ((int (*)(void))0x00017A21)
#define  tx_bytes                ((int (*)(uint8_t*,uint8_t))0x00017A55)
#define  printk                  ((void(*)(const char*, ...))0x00017C51)
#define  printd                  ((void(*)(const char*, ...))0x00017AC5)
#define  rtc1_init               ((void(*)(int ))0x00017901)
#define  checkRtc                ((int (*)(void))0x00017935)
#define  tickup                  ((void(*)(int ))0x00017C25)
#define  sreset                  ((void(*)(int ))0x00017985)
#define  sfeed                   ((void(*)(void))0x0001799D)

#endif


#ifndef  LEVEL1

#define  stcmp                   ((int (*)(uint8_t*,uint8_t*,int))0x00018009)
#define  mmcpy                   ((void(*)(void*,void*,int))0x00018027)
#define  mmset                   ((void(*)(void*,int,int))0x00018091)
#define  checksum                ((uint32_t(*)(uint32_t*,int))0x000180E7)
#define  softDelay               ((void(*)(int ))0x000180FB)
#define  find_default            ((int (*)(void))0x00018113)
#define  sector_entry            ((int (*)(void))0x00018131)
#define  entrypoint              ((void(*)(uint8_t *))0x00018181)
#define  validate_entry          ((int (*)(uint32_t*))0x000181F5)
#define  _fbitchk_               ((int (*)(uint16_t ))0x000181FF)
#define  _fbitset_               ((int (*)(uint8_t  ))0x0001821B)

#endif


#ifndef  LEVEL2

#define  _co_getParam      ((uint32_t(*)(int ))0x0001A011)
#define  _co_setParam      ((void(*)(int ,uint32_t))0x0001A021)
#define  _co_registerCB_   ((int (*)(uint16_t,uint32_t,uint32_t,uint16_t))0x0001A031)
#define  _co_unregisterCB_ ((int (*)(uint16_t,uint32_t))0x0001A06D)
#define  _co_putCmd        ((void(*)(uint8_t*,uint8_t ))0x0001A0E1)
#define  _co_ctrlRaw_      ((void(*)(uint16_t,uint8_t,uint16_t))0x0001A0EB)
#define  _co_delay_        ((void(*)(int ))0x0001A11F)
#define  _co_waitRaw_      ((int (*)(uint16_t,uint8_t,uint8_t,uint8_t*))0x0001A155)

#endif


/* for systick */
#define  tikHead           (*(uint8_t *)(VECT_RAM_ADDR + 17*4 + 2 ))
#define  tikTail           (*(uint8_t *)(VECT_RAM_ADDR + 17*4 + 3 ))


/* @nrf_rtc.c */
#define  rtcHead           (*(uint8_t *)(VECT_RAM_ADDR + 40*4 + 0 ))
#define  rtcTail           (*(uint8_t *)(VECT_RAM_ADDR + 40*4 + 1 ))

/* @nrf_uart.c */
#define  txHead            (*(uint8_t *)(VECT_RAM_ADDR + 16*4 + 0 ))
#define  txTail            (*(uint8_t *)(VECT_RAM_ADDR + 16*4 + 1 ))
#define  rxHead            (*(uint8_t *)(VECT_RAM_ADDR + 16*4 + 2 ))
#define  rxTail            (*(uint8_t *)(VECT_RAM_ADDR + 16*4 + 3 ))
#define  txBuff            ( (uint8_t *)(VECT_RAM_ADDR +  2*4))
#define  rxBuff            ( (uint8_t *)(VECT_RAM_ADDR + 34*4))

/* uart response个数,uspHead,uspTail */
#define  RSPL                          64

/* uart/ble command个数,cmdHead,cmdTail */
#define  CMDL                          200


/* @nrf_gap.c */
#define  EVTL                          4
//#define  chaihuo_service_handle  (*(uint16_t*)(VECT_RAM_ADDR + 17*4 + 0 ))

/* 控制UART切换烧写NODE标记*/
#define boflag             (*(uint8_t *)(VECT_RAM_ADDR + 17*4 + 0 ))


//uint8_t  evtHead = 0 , evtTail = 0 ;
#define  evtHead           (*(uint8_t *)(VECT_RAM_ADDR + 40*4 + 2 ))
#define  evtTail           (*(uint8_t *)(VECT_RAM_ADDR + 40*4 + 3 ))


/* @flashcmd.c */
#define  fbitmap           ( (uint32_t*)(VECT_RAM_ADDR + 20*4))
#define  _fd_              ( (uint32_t*)(VECT_RAM_ADDR + 28*4))
#define  _fstart_          (*(uint32_t*)(VECT_RAM_ADDR + 32*4))



#define  base64char              ( (uint8_t*)0x000178C0 )



#define  hexTable                ( (uint8_t*)0x000178B0 )



/* CORE板在线离线模式*/
#define  offline           (*(uint8_t *)(VECT_RAM_ADDR+48*4+0) )

#define  LINEMODE_OFF                  0
#define  LINEMODE_UART                 1
#define  LINEMODE_BLE                  2


#define  advertData        ( (uint8_t *)(VECT_RAM_ADDR+48*4+1) )
#define  padvertData       ( (uint8_t *)0x00017F81 )

#define  HEXMAC            ( (uint32_t*)0x000183F0 )
/* 用于识别不匹配的MAC */
#define  FAKEMAC           (*(uint32_t*)0x000183F8 )



#define  adv_params        (*(ble_gap_adv_params_t*)(VECT_RAM_ADDR+44*4) )
#define  padv_params       ( (ble_gap_adv_params_t*)0x00017FA0 )



#define  clock_lf_cfg      (*(nrf_clock_lf_cfg_t*)(VECT_RAM_ADDR+41*4))
#define  pclock_lf_cfg     ( (nrf_clock_lf_cfg_t*)0x00017FB0 )



/*********************************************************************/
/*********************************************************************/

#define  usm               (*(uint8_t *)(VECT_RAM_ADDR + 66*4 + 0 ))
#define  ule               (*(uint8_t *)(VECT_RAM_ADDR + 66*4 + 1 ))
#define  ucmd              ( (uint8_t *)(VECT_RAM_ADDR + 56*4 ))
#define  ursp              ( (uint8_t *)(VECT_RAM_ADDR + 61*4 ))
/* UART命令字符间超时,不能大于1秒 */
#define  utm               (*(uint8_t *)(VECT_RAM_ADDR + 66*4 + 2) )
/* */

#define  UARTCMD_STATUS_IDLE           0
#define  UARTCMD_STATUS_LENG           1
#define  UARTCMD_STATUS_CORE           2
#define  UARTCMD_STATUS_TYPE           3
#define  UARTCMD_STATUS_CONT           4
#define  UARTCMD_STATUS_OPTI           5


/* I2C Master出错计数 */
#define  MAXMERR                       2

#define  merr              (*(uint8_t *)(VECT_RAM_ADDR + 66*4 + 3) )


/*XXX*/
#define  chktmo            (*(uint32_t*)(VECT_RAM_ADDR + 67*4 + 3) )

/*********************************************************************/
/*********************************************************************/


/* 运行指示灯*/
#define  led_tmo           (*(uint16_t*)(VECT_RAM_ADDR + 42*4 + 0 ))
#define  trx_tmo           (*(uint16_t*)(VECT_RAM_ADDR + 42*4 + 2 ))


/* BLE-CORE板的唯一按键,DBGPIN*/
#define  DBGPIN                        30

#define  dbg_tmo           (*(uint16_t*)(VECT_RAM_ADDR + 43*4 + 0 ))


#define  LEDPIN                        11
#define  TRXPIN                        12
#define  CTRPIN                        13

/* Connector 上的RX/TX*/
#ifdef   HARDWARE_V2

#define  BUSTXD                        2
#define  BUSRXD                        3

#else

#define  BUSTXD                        4
#define  BUSRXD                        5

#endif


#define  _DBG_()                       ({ \
      NRF_P0->IN & (1UL << DBGPIN );      \
      })


#define  RUNLED_ON()       ({ NRF_P0->OUTCLR = 1UL << LEDPIN ;})
#define  RUNLED_OFF()      ({ NRF_P0->OUTSET = 1UL << LEDPIN ;})

#define  TRXLED_ON()       ({ NRF_P0->OUTCLR = 1UL << TRXPIN ;})
#define  TRXLED_OFF()      ({ NRF_P0->OUTSET = 1UL << TRXPIN ;})


#if 0
#define  BOUART_ON()       ({ NRF_P0->OUTCLR = 1UL << CTRPIN ;})
#define  BOUART_OFF()      ({ NRF_P0->OUTSET = 1UL << CTRPIN ;})
#else
#define  BOUART_ON()       ({ NRF_P0->OUTSET = 1UL << CTRPIN ;})
#define  BOUART_OFF()      ({ NRF_P0->OUTCLR = 1UL << CTRPIN ;})
#endif


#define  BUSTXD_LO()       ({ NRF_P0->OUTCLR = 1UL << BUSTXD ;})
#define  BUSTXD_HI()       ({ NRF_P0->OUTSET = 1UL << BUSTXD ;})


/* I2C引脚相关定义 */

#ifdef   HARDWARE_V2

#define  HScl                          5
#define  HSda                          7

#define  SScl                          6
#define  SSda                          8

#else

#define  HScl                          2
#define  HSda                          3

#define  SScl                          2
#define  SSda                          3

#endif


#define  SOFT_SCL(a)                   ({    \
      NRF_P0->PIN_CNF [SScl] =               \
         NRF_GPIO_PIN_DIR_OUTPUT   << GPIO_PIN_CNF_DIR_Pos   |\
         NRF_GPIO_PIN_INPUT_CONNECT<< GPIO_PIN_CNF_INPUT_Pos |\
         NRF_GPIO_PIN_NOPULL       << GPIO_PIN_CNF_PULL_Pos  |\
         NRF_GPIO_PIN_S0D1         << GPIO_PIN_CNF_DRIVE_Pos |\
         NRF_GPIO_PIN_NOSENSE      << GPIO_PIN_CNF_SENSE_Pos ;\
      if(a) { NRF_P0->OUTSET = 1UL << SScl ;}\
      else  { NRF_P0->OUTCLR = 1UL << SScl ;}\
      })


#define  _SCL_()                       ({    \
      NRF_P0->IN & (1UL << SScl) ;           \
      })


#define  INPU_SCL()                    ({    \
      NRF_P0->PIN_CNF [SScl] =               \
         NRF_GPIO_PIN_DIR_INPUT    << GPIO_PIN_CNF_DIR_Pos   |\
         NRF_GPIO_PIN_INPUT_CONNECT<< GPIO_PIN_CNF_INPUT_Pos |\
         NRF_GPIO_PIN_NOPULL       << GPIO_PIN_CNF_PULL_Pos  |\
         NRF_GPIO_PIN_S0D1         << GPIO_PIN_CNF_DRIVE_Pos |\
         NRF_GPIO_PIN_NOSENSE      << GPIO_PIN_CNF_SENSE_Pos ;\
      })

#define  INPU_SDA()                    ({    \
      NRF_P0->PIN_CNF [SSda] =               \
         NRF_GPIO_PIN_DIR_INPUT    << GPIO_PIN_CNF_DIR_Pos   |\
         NRF_GPIO_PIN_INPUT_CONNECT<< GPIO_PIN_CNF_INPUT_Pos |\
         NRF_GPIO_PIN_NOPULL       << GPIO_PIN_CNF_PULL_Pos  |\
         NRF_GPIO_PIN_S0D1         << GPIO_PIN_CNF_DRIVE_Pos |\
         NRF_GPIO_PIN_NOSENSE      << GPIO_PIN_CNF_SENSE_Pos ;\
      })


#define  SOFT_SDA(a)                   ({    \
      NRF_P0->PIN_CNF [SSda] =               \
         NRF_GPIO_PIN_DIR_OUTPUT   << GPIO_PIN_CNF_DIR_Pos   |\
         NRF_GPIO_PIN_INPUT_CONNECT<< GPIO_PIN_CNF_INPUT_Pos |\
         NRF_GPIO_PIN_NOPULL       << GPIO_PIN_CNF_PULL_Pos  |\
         NRF_GPIO_PIN_S0D1         << GPIO_PIN_CNF_DRIVE_Pos |\
         NRF_GPIO_PIN_NOSENSE      << GPIO_PIN_CNF_SENSE_Pos ;\
      if(a) { NRF_P0->OUTSET = 1UL << SSda ;}\
      else  { NRF_P0->OUTCLR = 1UL << SSda ;}\
      })


#define  _SDA_()                       ({    \
      NRF_P0->IN & (1UL << SSda) ? 256 : 0 ; \
      })


/* 作为Master的返回状态*/
#define  TWIM_STATUS_OK                0
#define  TWIM_STATUS_BUSY              1
#define  TWIM_STATUS_COMP              2
#define  TWIM_STATUS_NAK               3
#define  TWIM_STATUS_ERR               4


/* I2C协议Header */
#define  I2C_HEAD_LEN                  i2c[0]
#define  I2C_HEAD_INS                  i2c[1]
#define  I2C_HEAD_DEV                  i2c[2]
#define  I2C_HEAD_OPT                  i2c[3]


#define  I2C_DATA_D0                   i2c[4]
#define  I2C_DATA_D1                   i2c[5]
#define  I2C_DATA_D2                   i2c[6]
#define  I2C_DATA_D3                   i2c[7]
#define  I2C_DATA_D4                   i2c[8]
#define  I2C_DATA_D5                   i2c[9]
#define  I2C_DATA_D6                   i2c[10]
#define  I2C_DATA_D7                   i2c[11]


/* I2C Slave Buff长度
 * */
#define  ISLL                          2


/* I2C协议中的INS字段*/
#define  NODE_INS_EVT                  0x0E
#define  NODE_INS_RAW                  0xD0
#define  NODE_INS_RSP                  0xF0



/* 结构定义*/

#define  ALL_CBB                       256

struct callback_block {

   uint16_t tag16 ; /* "CB",B0B1 */
   uint16_t event ; /* node,B2,event,B3*/
   uint16_t tmsav ; /* TMO  */
   uint16_t tmout ; /* TMO  */

   void(*entry)(uint8_t*,int,int);
   uint32_t param ; /* 参数 */

} __attribute__ ((packed)) ;




/*********************************************************************/
/*                                                                   */
/* 系统宏定义,勿修改                                                 */
/*                                                                   */
/*********************************************************************/




#endif /*__config_H__*/


