
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

/* demo_mobile.c -*- mode:C; c-file-style: "eay" -*- */
/*
 * @author Monsoon Song <zhengbin.song@chaihuo.org>
 *
 */


#ifndef  __demo_mobile_C__
#define  __demo_mobile_C__


/* STOP, 前进, */
const uint16_t MOBILE_ACT[] = {
   0x0000, 0x0103, 0x0503, 0x0302,
   0x0303, 0x0402, 0x0403, 0x0603,
};


void mobile_move (uint8_t idx)
   {


   uint8_t  i2c[8] ;


   if ( idx > 7 )
      { return ;}

   I2C_HEAD_LEN = 0x40 + 8 ;
   I2C_HEAD_INS = !idx ? 0x90 : 0x91 ;
   I2C_HEAD_DEV = 0x28 ;
   I2C_HEAD_OPT = 0x00 ;

   mmcpy(&I2C_DATA_D0 , (void*)&MOBILE_ACT[idx] , 2 );

   I2C_DATA_D2  = 0x00 ;
   I2C_DATA_D3  = 0x00 ;

   _co_putCmd (i2c, 8 );

   }


#endif  /*__demo_mobile_C__*/


