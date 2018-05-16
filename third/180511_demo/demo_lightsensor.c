
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

/* demo_lightsensor.c -*- mode:C; c-file-style: "eay" -*- */
/*
 * @author Monsoon Song <zhengbin.song@chaihuo.org>
 *
 */


#ifndef  __demo_lightsensor_C__
#define  __demo_lightsensor_C__


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
void onLightsensorLight (void)
   {


/* Buzzer, */
   buzzer_tone (0x00 , 21);


/* LED Matrix, Off */
   ledmatrix_off (0x06);


/* RGB LED,0B,Rainbow OFF*/
   rgbled_rainbow_off (0x07);


/* Servo,24,Previous(0/45/90/135/180) */
   servo_play (0);

   }



/*************************************************************
 *
 * onLightsensorDark, 事件 Dark
 *
 * Parameter: NA
 *
 * Return:
 *
 *************************************************************
 * */
void onLightsensorDark (void)
   {


/* Buzzer, */


/* LED Matrix, On */
   ledmatrix_bar (0x01 , 18 , 2000);


/* RGB LED,0B,Rainbow On*/
   rgbled_rainbow_on (0x03 , 2000 );


/* Servo,24,Previous(0/45/90/135/180) */
   servo_play (4);

   }


#endif  /*__demo_lightsensor_C__*/


