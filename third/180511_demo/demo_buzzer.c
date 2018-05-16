
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

/* demo_buzzer.c -*- mode:C; c-file-style: "eay" -*- */
/*
 * @author Monsoon Song <zhengbin.song@chaihuo.org>
 *
 */


#ifndef  __demo_buzzer_C__
#define  __demo_buzzer_C__



void buzzer_tone (uint8_t ins , uint16_t tone)
   {


   uint8_t  i2c[8] ;


   I2C_HEAD_LEN = 0x40 + 6 ;
   I2C_HEAD_INS =  ins/*0x90*/ ;
   I2C_HEAD_DEV = 0x08 ;
   I2C_HEAD_OPT = 0x00 ;

   I2C_DATA_D0  = tone%21+1;
   I2C_DATA_D1  = 0x01 ; /*1-8*/

   _co_putCmd (i2c, 6 );

   }



void buzzer_bpm (uint8_t ins , uint8_t dir )
   {


   uint8_t  i2c[8] ;


   I2C_HEAD_LEN = 0x40 + 7 ;
   I2C_HEAD_INS =  ins/*0x95*/ ;
   I2C_HEAD_DEV = 0x08 ;
   I2C_HEAD_OPT = 0x00 ;

   I2C_DATA_D0  =  dir ;
   I2C_DATA_D1  = 0x3C ;
   I2C_DATA_D2  = 0x00 ;

   _co_putCmd (i2c, 7 );

   }


#endif  /*__demo_buzzer_C__*/


