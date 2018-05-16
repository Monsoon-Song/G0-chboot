
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

/* demo_servo.c -*- mode:C; c-file-style: "eay" -*- */
/*
 * @author Monsoon Song <zhengbin.song@chaihuo.org>
 *
 */


#ifndef  __demo_servo_C__
#define  __demo_servo_C__


uint8_t  servo_angle [] = { 0 , 45 , 90 , 135 , 180 };


void servo_play (uint16_t ang)
   {


   uint8_t  i2c[8] ;


   I2C_HEAD_LEN = 0x40 + 5 ;
   I2C_HEAD_INS = 0x90 ;
   I2C_HEAD_DEV = 0x24 ;
   I2C_HEAD_OPT = 0x00 ;

   I2C_DATA_D0  = servo_angle[ ang%5 ];

   _co_putCmd (i2c, 5 );

   }


#endif  /*__demo_servo_C__*/


