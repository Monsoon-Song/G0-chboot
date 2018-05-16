
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

/* nrf_uart.c -*- mode:C; c-file-style: "eay" -*- */
/*
 * @author Monsoon Song <zhengbin.song@chaihuo.org>
 *
 */



#define  TX_DBG                        29
#define  RX_DBG                        28

#define  TX_MOD                        4
#define  RX_MOD                        5


#define  TXBUFF                        52
#define  RXBUFF                        16



/*********************************************************************
 * @fn      systemUart
 *
 * @brief
 *    UART字符的处理,
 *
 * @return  none
 */

void systemUart (void)
   {

   int  ic ;
   uint8_t *cmd = ucmd , c ,i ;

   if ((ic = rx_byte())!= -1 )
      {


      c = (uint8_t)(ic & 255);


      if (!utm)
         { usm = UARTCMD_STATUS_IDLE ;}


      utm = 32 ; /*320ms 字符间隔*/

      switch (usm)
         {

      case UARTCMD_STATUS_IDLE:

         if ( c >= 4 && c <= 20 )
            {
            CMD_HEAD_LEN = c ;
            usm = UARTCMD_STATUS_LENG ;
            }
         else
            { tx_bytes(&c,1);
            }
         break ;


      case UARTCMD_STATUS_LENG:

         if ( c == CMD_TYPE_TOCORE )
            { CMD_HEAD_TYP = c ;
              usm= UARTCMD_STATUS_TYPE ;
            }

         else if ( c >= 4 && c <= 20 )
            { }
         else
            { usm= UARTCMD_STATUS_IDLE ;}

         break ;


      case UARTCMD_STATUS_TYPE:

         CMD_HEAD_EXE = c ;
         usm = UARTCMD_STATUS_OPTI ;

         break ;


      case UARTCMD_STATUS_OPTI:

         CMD_HEAD_OPT = c ;

         ule = CMD_HEAD_LEN  -  4  ;

         if ( ule )
            { usm = UARTCMD_STATUS_CONT ;
            }
         else
            { usm = UARTCMD_STATUS_IDLE ;
              do_flashcmd (cmd);
            }

         break ;


      case UARTCMD_STATUS_CONT:

         i = CMD_HEAD_LEN - ule-- ;
         cmd[i] = c ;

         if (!ule)
            { usm = UARTCMD_STATUS_IDLE ;
              do_flashcmd (cmd);
            }
         break ;


      default:
         usm = UARTCMD_STATUS_IDLE ;
         break ;

         }
      }
   }



