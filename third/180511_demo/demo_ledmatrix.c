
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

/* demo_ledmatrix.c -*- mode:C; c-file-style: "eay" -*- */
/*
 * @author Monsoon Song <zhengbin.song@chaihuo.org>
 *
 */


#ifndef  __demo_ledmatrix_C__
#define  __demo_ledmatrix_C__



void ledmatrix_off (uint8_t ins)
   {


   uint8_t  i2c[8] ;


   I2C_HEAD_LEN = 0x40 + 4 ;
   I2C_HEAD_INS =  ins/*0x96*/ ;
   I2C_HEAD_DEV = 0x07 ;
   I2C_HEAD_OPT = 0x00 ;

   _co_putCmd (i2c, 4 );

   }



void ledmatrix_bar (uint8_t ins , uint16_t bar , uint16_t tmo)
   {


   uint8_t  i2c[8] ;


   I2C_HEAD_LEN = 0x40 + 7 ;
   I2C_HEAD_INS =  ins/*0x91*/ ;
   I2C_HEAD_DEV = 0x07 ;
   I2C_HEAD_OPT = 0x00 ;

   I2C_DATA_D0  = bar%19 ;
   mmcpy (&I2C_DATA_D1 , &tmo , 2 ); /*time*/

   _co_putCmd (i2c, 7 );

   }



void ledmatrix_emoji (uint8_t ins , uint16_t emoji , uint16_t tmo)
   {


   uint8_t  i2c[8] ;


   I2C_HEAD_LEN = 0x40 + 8 ;
   I2C_HEAD_INS =  ins/*0x92*/ ;
   I2C_HEAD_DEV = 0x07 ;
   I2C_HEAD_OPT = 0x00 ;

   I2C_DATA_D0  = emoji%5 ;
   mmcpy (&I2C_DATA_D1 , &tmo , 2 ); /*time*/
   I2C_DATA_D3  = 0x00 ; /*direction*/

   _co_putCmd (i2c, 8 );

   }



void ledmatrix_uppercase (uint8_t ins , uint16_t c , uint16_t tmo)
   {


   uint8_t  i2c[9] ;


   I2C_HEAD_LEN = 0x40 + 9 ;
   I2C_HEAD_INS =  ins/*0x94*/ ;
   I2C_HEAD_DEV = 0x07 ;
   I2C_HEAD_OPT = 0x00 ;

   I2C_DATA_D0  = 0x00 ;
   mmcpy (&I2C_DATA_D1 , &tmo , 2 ); /*time*/
   I2C_DATA_D3  = 0x00 ; /*direction*/
   I2C_DATA_D4  = 0x41 + c%26;

   _co_putCmd (i2c, 9 );

   }



void ledmatrix_lowercase (uint8_t ins , uint16_t c , uint16_t tmo)
   {


   uint8_t  i2c[9] ;


   I2C_HEAD_LEN = 0x40 + 9 ;
   I2C_HEAD_INS =  ins/*0x94*/ ;
   I2C_HEAD_DEV = 0x07 ;
   I2C_HEAD_OPT = 0x00 ;

   I2C_DATA_D0  = 0x00 ;
   mmcpy (&I2C_DATA_D1 , &tmo , 2 ); /*time*/
   I2C_DATA_D3  = 0x00 ; /*direction*/
   I2C_DATA_D4  = 0x61 + c%26;

   _co_putCmd (i2c, 9 );

   }


#endif  /*__demo_ledmatrix_C__*/


