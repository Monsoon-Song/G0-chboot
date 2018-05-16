
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

/* demo_twinButton.c -*- mode:C; c-file-style: "eay" -*- */
/*
 * @author Monsoon Song <zhengbin.song@chaihuo.org>
 *
 */


#ifndef  __demo_twinButton_C__
#define  __demo_twinButton_C__


#include "demo_buzzer.c"
#include "demo_ledmatrix.c"
#include "demo_rgbled.c"
#include "demo_servo.c"



uint16_t  singleClickCnt ;
uint16_t  doubleClickCnt ;



/*************************************************************
 *
 * onClickA, Click A,(单击)
 *
 * Parameter: NA
 *
 * Return:
 *
 *************************************************************
 * */
void onClickA (void)
   {


   -- singleClickCnt ;


#if 1
/* Buzzer,08,Previous Tone */
   buzzer_tone (0x00 , singleClickCnt);
#endif

#if 1
/* LED Matrix,07,Previous */
   switch (doubleClickCnt & 3)
      {

   case 0:
      ledmatrix_bar (0x01 , singleClickCnt , 2000);
      break;
   case 1:
      ledmatrix_uppercase (0x04 , singleClickCnt , 2000);
      break;
   case 2:
      ledmatrix_lowercase (0x04 , singleClickCnt , 2000);
      break;
   case 3:
      ledmatrix_emoji (0x02 , singleClickCnt , 2000);
      break;

      }
#endif

#if 1
/* RGB LED,0B,Previous color*/
   rgbled_index (0x00 , singleClickCnt);


/* Servo,24,Previous(0/45/90/135/180) */
   servo_play (singleClickCnt);
#endif
   }



/*************************************************************
 *
 * onClickB, Click B,(单击)
 *
 * Parameter: NA
 *
 * Return:
 *
 *************************************************************
 * */
void onClickB (void)
   {


   ++ singleClickCnt ;

#if 1
/* Buzzer,08,Next Tone */
   buzzer_tone (0x00 , singleClickCnt);
#endif


#if 1
/* LED Matrix,07,Next */

   switch (doubleClickCnt & 3)
      {

   case 0:
      ledmatrix_bar (0x01 , singleClickCnt , 2000);
      break;
   case 1:
      ledmatrix_uppercase (0x04 , singleClickCnt , 2000);
      break;
   case 2:
      ledmatrix_lowercase (0x04 , singleClickCnt , 2000);
      break;
   case 3:
      ledmatrix_emoji (0x02 , singleClickCnt , 2000);
      break;

      }
#endif


#if 1
/* RGB LED,0B,Next color*/
   rgbled_index (0x00 , singleClickCnt);


/* Servo,24,Next(0/45/90/135/180) */
   servo_play (singleClickCnt);
#endif
   }



/*************************************************************
 *
 * onDoubleClickA, Double Click A,(双击)
 *
 * Parameter: NA
 *
 * Return:
 *
 *************************************************************
 * */
void onDoubleClickA (void)
   {


   -- doubleClickCnt ;


#if 1
/* Buzzer,08,Decrease BPM by 60 */
   buzzer_bpm (0x05 , 0 );
#endif

/* LED Matrix,07,Previous Category*/
   switch (doubleClickCnt & 3)
      {

   case 0:
      ledmatrix_bar (0x01 , singleClickCnt , 2000);
      break;
   case 1:
      ledmatrix_uppercase (0x04 , singleClickCnt , 2000);
      break;
   case 2:
      ledmatrix_lowercase (0x04 , singleClickCnt , 2000);
      break;
   case 3:
      ledmatrix_emoji (0x02 , singleClickCnt , 2000);
      break;

      }

/* RGB LED,0B,Previous color*/

   }



/*************************************************************
 *
 * onDoubleClickB, Double Click B,(双击)
 *
 * Parameter: NA
 *
 * Return:
 *
 *************************************************************
 * */
void onDoubleClickB (void)
   {


   ++ doubleClickCnt ;


#if 1
/* Buzzer,08,Increase BPM by 60 */
   buzzer_bpm (0x05 , 1 );
#endif

/* LED Matrix,07,Next */
   switch (doubleClickCnt & 3)
      {

   case 0:
      ledmatrix_bar (0x01 , singleClickCnt , 2000);
      break;
   case 1:
      ledmatrix_uppercase (0x04 , singleClickCnt , 2000);
      break;
   case 2:
      ledmatrix_lowercase (0x04 , singleClickCnt , 2000);
      break;
   case 3:
      ledmatrix_emoji (0x02 , singleClickCnt , 2000);
      break;

      }

/* RGB LED,0B,Next color*/

   }


#endif  /*__demo_twinButton_C__*/


