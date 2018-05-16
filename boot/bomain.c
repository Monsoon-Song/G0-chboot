
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

/* main.c -*- mode:C; c-file-style: "eay" -*- */
/*
 * @author Monsoon Song <zhengbin.song@chaihuo.org>
 *
 */


#include <stdint.h>
#include <string.h>

#include "nordic_common.h"
#include "ble.h"

#include "nrf.h"
#include "nrf52.h"
#include "nrf_rtc.h"
#include "nrf_gpio.h"
#include "nrf_twis.h"
#include "nrf_uart.h"
#include "nrf_nvic.h"
#include "nrf_sdh.h"
#include "nrf_sdm.h"
#include "nrf_sdh_ble.h"
#include "nrf_ble_gatt.h"


#include "config.h"



/* BootLoader不定义全局变量
 * */



void systemUart  (void);


void do_flashcmd (uint8_t*);



/*********************************************************************
 * @fn      status_led
 *
 * @brief
 *       逻辑是DEBUG_RST按键被按下时亮灯,但超过3s,开始按BOOT模式闪灯 ;
 *       BOOT模式,200ms-600ms ; 正常运行模式,400ms-1200ms
 *          1, OFF, 0,ON
 *
 * @return  none
 */

void txrx_counter (void)
   {

   trx_tmo += 4 ;
   if (trx_tmo > 50 ) /*最多500ms*/
      {trx_tmo = 50;}
   }


void dbgpin (void)
   {

/* DEBUG_RST pin input */
   NRF_P0->PIN_CNF [DBGPIN] =
      NRF_GPIO_PIN_DIR_INPUT    << GPIO_PIN_CNF_DIR_Pos   |
      NRF_GPIO_PIN_INPUT_CONNECT<< GPIO_PIN_CNF_INPUT_Pos |
      NRF_GPIO_PIN_NOPULL       << GPIO_PIN_CNF_PULL_Pos  |
      NRF_GPIO_PIN_S0S1         << GPIO_PIN_CNF_DRIVE_Pos |
      NRF_GPIO_PIN_NOSENSE      << GPIO_PIN_CNF_SENSE_Pos ;

/* STATUS led */
   NRF_P0->PIN_CNF [LEDPIN] =
      NRF_GPIO_PIN_DIR_OUTPUT   << GPIO_PIN_CNF_DIR_Pos   |
      NRF_GPIO_PIN_INPUT_DISCONNECT<< GPIO_PIN_CNF_INPUT_Pos |
      NRF_GPIO_PIN_NOPULL       << GPIO_PIN_CNF_PULL_Pos  |
      NRF_GPIO_PIN_H0S1         << GPIO_PIN_CNF_DRIVE_Pos |
      NRF_GPIO_PIN_NOSENSE      << GPIO_PIN_CNF_SENSE_Pos ;

/* TX/RX led */
   NRF_P0->PIN_CNF [TRXPIN] =
      NRF_GPIO_PIN_DIR_OUTPUT   << GPIO_PIN_CNF_DIR_Pos   |
      NRF_GPIO_PIN_INPUT_DISCONNECT<< GPIO_PIN_CNF_INPUT_Pos |
      NRF_GPIO_PIN_NOPULL       << GPIO_PIN_CNF_PULL_Pos  |
      NRF_GPIO_PIN_H0S1         << GPIO_PIN_CNF_DRIVE_Pos |
      NRF_GPIO_PIN_NOSENSE      << GPIO_PIN_CNF_SENSE_Pos ;


/* Connector TXD */
   NRF_P0->PIN_CNF [BUSTXD] =
      NRF_GPIO_PIN_DIR_OUTPUT   << GPIO_PIN_CNF_DIR_Pos   |
      NRF_GPIO_PIN_INPUT_DISCONNECT<< GPIO_PIN_CNF_INPUT_Pos |
      NRF_GPIO_PIN_NOPULL       << GPIO_PIN_CNF_PULL_Pos  |
      NRF_GPIO_PIN_S0S1         << GPIO_PIN_CNF_DRIVE_Pos |
      NRF_GPIO_PIN_NOSENSE      << GPIO_PIN_CNF_SENSE_Pos ;


#ifdef   HARDWARE_V2
/* Boot uart control */

   NRF_P0->PIN_CNF [CTRPIN] =
      NRF_GPIO_PIN_DIR_INPUT    << GPIO_PIN_CNF_DIR_Pos   |
      NRF_GPIO_PIN_INPUT_CONNECT<< GPIO_PIN_CNF_INPUT_Pos |
      NRF_GPIO_PIN_NOPULL       << GPIO_PIN_CNF_PULL_Pos  |
      NRF_GPIO_PIN_S0S1         << GPIO_PIN_CNF_DRIVE_Pos |
      NRF_GPIO_PIN_NOSENSE      << GPIO_PIN_CNF_SENSE_Pos ;

#endif
   }



#include "../lib/stdlib.c"
#include "../lib/configtable.c"

#include "nrf_uart.c"
#include "flashcmd.c"



/**@brief Function for application main entry.
 */
int main (void)
   {


   sd_softdevice_vector_table_base_set (VECT_RAM_ADDR);


/* 注意自己指定内存地址的变量,也要自己初始化
 * */
   txHead = txTail = 0 ;
   rxHead = rxTail = 0 ;

   evtHead=evtTail = 0 ;
   rtcHead=rtcTail = 0 ;

   tikHead = tikTail = 0 ;

   usm = ule = utm = 0 ;
   _fstart_=  0 ;
   led_tmo = dbg_tmo = trx_tmo = 0 ;
   mmset ( fbitmap , 0 , 32 );

/* I2C Master出错计数 */
   merr = 0;
   offline = LINEMODE_OFF;

   boflag  = 0 ;


   uart_init ();


   dbgpin();

   BUSTXD_HI ();


   tickdown ();

/* DEBUG_RST为高,直接跳入正常代码
 * */
   if (_DBG_())
      {

      if ( ! validate_entry((uint32_t*)LEVEL2_ADDR) )
         {((void(*)(void)) ((uint32_t*)LEVEL2_ADDR)[2])() ;}
      }


   tickup (64000*10-1); /*10ms,*/


   for(;;)
      {


      systemUart();


      /* 按键状态
       * */
      if (tikTail!= tikHead)
         {tikTail = tikHead;

      /* 串口命令超时,不能大于1s*/
         if (utm)
            {utm -- ;}


         if (!_DBG_())
            {

      /* 10ms的Tick,超过3秒进入BOOT
       * */
            if (dbg_tmo < 400 ) /*4.0s,方便闪灯而以*/
               {dbg_tmo ++ ;  }
            else
               {dbg_tmo = 300;}

            }
         else
            {

            if (dbg_tmo >=300 )
               {dbg_tmo  = 0 ;}
            else if ( dbg_tmo )
               { sreset(2) ;}

            }


         if (!dbg_tmo)
            {

            if (led_tmo < 100)
               {led_tmo ++ ;
               if (led_tmo == 80 ) RUNLED_ON();
               }
            else
               {led_tmo = 0 ;
                RUNLED_OFF();
               }
            }
         else if (dbg_tmo == 300 )
            {RUNLED_OFF();}
         else if (dbg_tmo == 320 )
            {RUNLED_ON ();}


         if (!trx_tmo)
            { TRXLED_OFF();}
         else
            { TRXLED_ON (); trx_tmo -- ;
            }
         }


      sd_app_evt_wait ();

      }
   }


