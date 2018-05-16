
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

/* demo_rgbled.c -*- mode:C; c-file-style: "eay" -*- */
/*
 * @author Monsoon Song <zhengbin.song@chaihuo.org>
 *
 */


#ifndef  __demo_rgbled_C__
#define  __demo_rgbled_C__


/* red, orange, yellow, green, cyan, blue,deeppink, purple, */
const uint32_t COLOR_PICKER[] = {
   0xff0000, 0xffa500, 0xffff00, 0x00ff00,
   0x0fffff, 0x0000ff, 0x800080, 0xff1493
};


void rgbled_index (uint8_t ins , uint16_t color)
   {


   uint8_t  i2c[9] ;


   I2C_HEAD_LEN = 0x40 + 9 ;
   I2C_HEAD_INS =  ins/*0x90*/ ;
   I2C_HEAD_DEV = 0x0B ;
   I2C_HEAD_OPT = 0x00 ;

   mmcpy(&I2C_DATA_D0 , (void*)&COLOR_PICKER[color&7] , 4);

   I2C_DATA_D4  = 0x00 ;

   _co_putCmd (i2c, 9 );

   }



void rgbled_rainbow_off (uint8_t ins)
   {


   uint8_t  i2c[8] ;


   I2C_HEAD_LEN = 0x40 + 4 ;
   I2C_HEAD_INS =  ins/*0x97*/ ;
   I2C_HEAD_DEV = 0x0B ;
   I2C_HEAD_OPT = 0x00 ;

   _co_putCmd (i2c, 4 );

   }


void rgbled_rainbow_on (uint8_t ins , uint16_t tmo)
   {


   uint8_t  i2c[8] ;


   I2C_HEAD_LEN = 0x40 + 8 ;
   I2C_HEAD_INS =  ins/*0x93*/ ;
   I2C_HEAD_DEV = 0x0B ;
   I2C_HEAD_OPT = 0x00 ;

   I2C_DATA_D0  = 0x14 ;
   I2C_DATA_D1  = 0x00 ;
   mmcpy (&I2C_DATA_D2 , &tmo , 2 ); /*time*/

   _co_putCmd (i2c, 8 );

   }


void rgbled_bright (uint8_t ins , uint8_t bri)
   {


   uint8_t  i2c[8] ;


   I2C_HEAD_LEN = 0x40 + 5 ;
   I2C_HEAD_INS =  ins/*0x96*/ ;
   I2C_HEAD_DEV = 0x0B ;
   I2C_HEAD_OPT = 0x00 ;

   I2C_DATA_D0  =  bri ;

   _co_putCmd (i2c, 5 );

   }


void rgbled_color (uint8_t ins ,
     uint8_t r , uint8_t g , uint8_t b )
   {


   uint8_t  i2c[9] ;


   I2C_HEAD_LEN = 0x40 + 9 ;
   I2C_HEAD_INS =  ins/*0x90*/ ;
   I2C_HEAD_DEV = 0x0B ;
   I2C_HEAD_OPT = 0x00 ;


   I2C_DATA_D0  =  r ;
   I2C_DATA_D1  =  g ;
   I2C_DATA_D2  =  b ;
   I2C_DATA_D3  = 0x00 ;
   I2C_DATA_D4  = 0x00 ;

   _co_putCmd (i2c, 9 );

   }


#endif  /*__demo_rgbled_C__*/


