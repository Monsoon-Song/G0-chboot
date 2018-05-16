
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

/* demo_soundsensor.c -*- mode:C; c-file-style: "eay" -*- */
/*
 * @author Monsoon Song <zhengbin.song@chaihuo.org>
 *
 */


#ifndef  __demo_soundsensor_C__
#define  __demo_soundsensor_C__


#include "demo_buzzer.c"
#include "demo_ledmatrix.c"
#include "demo_rgbled.c"
#include "demo_servo.c"



/*************************************************************
 *
 * onLightsensorLight, 事件 Light
 *
 * Parameter: NA
 *
 * Return:
 *
 *************************************************************
 * */

uint16_t  sndsensor_old , sndsensor_cnt , sndsensor_active ;


void onSoundsensor (uint8_t *p )
   {


   uint8_t  *i2c = p ;
   uint32_t  snd = 0 ;


   if (!p)
      {

      if (!sndsensor_active )
         { sndsensor_active = 1 ; /*600ms*/
           _co_ctrlRaw_ (0xD006 , 1 , 30 );
         }
      else
         { sndsensor_active -- ;}

      }
   else
      {


      mmcpy (&snd , &I2C_DATA_D0 , 2 );

      if ( sndsensor_old <= snd || !sndsensor_cnt)
         { sndsensor_old  = snd ;
           sndsensor_cnt  =  2  ;
         }
      else
         {

         if ( sndsensor_cnt )
            { sndsensor_cnt  -- ;}
         snd= sndsensor_old ;
         }

/* Buzzer, */
      if (snd < 100)
         { }
      else
         { buzzer_tone  ( 0x90 , (uint16_t)((snd-100) * 21 / (1023-100) ) );}


/* LED Matrix,  */
      ledmatrix_bar( 0x91 , (uint16_t)(snd * 19 >> 10) , 2000);


/* RGB LED,0B,*/
      rgbled_bright( 0x96 , (uint8_t )(snd >> 2) );
      }


   }


#endif  /*__demo_soundsensor_C__*/


