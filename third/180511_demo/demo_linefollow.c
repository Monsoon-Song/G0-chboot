
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

/* demo_linefollow.c -*- mode:C; c-file-style: "eay" -*- */
/*
 * @author Monsoon Song <zhengbin.song@chaihuo.org>
 *
 */


#ifndef  __demo_linefollow_C__
#define  __demo_linefollow_C__



#define  LINEFOLLOW_COLOR_WHITE        5
#define  LINEFOLLOW_COLOR_BLACK        1
#define  LINEFOLLOW_COLOR_RED          2
#define  LINEFOLLOW_COLOR_GREEN        3
#define  LINEFOLLOW_COLOR_BLUE         4


#define  LINEFOLLOW_LINE_ONLINE        1
#define  LINEFOLLOW_LINE_NOLINE        2
#define  LINEFOLLOW_LINE_RIGHT1        3
#define  LINEFOLLOW_LINE_RIGHT2        4
#define  LINEFOLLOW_LINE_LEFT1         5
#define  LINEFOLLOW_LINE_LEFT2         6


/*注意,左右是反的*/
#define  MOBILE_RUN_STOP               0
#define  MOBILE_RUN_FORWARD            1
#define  MOBILE_RUN_RIGHT1             3
#define  MOBILE_RUN_RIGHT2             4
#define  MOBILE_RUN_LEFT1              5
#define  MOBILE_RUN_LEFT2              6
#define  MOBILE_RUN_LEFTCIRCLE         2
#define  MOBILE_RUN_RIGHTCIRCLE        7


#define  MOBILE_STATUS_STOP            0
#define  MOBILE_STATUS_RUN             0
#define  MOBILE_STATUS_FIND            0


#include "demo_mobile.c"
#include "demo_rgbled.c"


uint8_t  line_turnleft , line_tmo , line_active ;



/*************************************************************
 *
 * onLineFollow, RAW data
 *
 * Parameter: NA
 *
 * Return:
 *
 *************************************************************
 * */
void onLineFollow (uint8_t *p )
   {


   uint8_t *i2c = p ;


   if (!p)
      {

      if (!line_active )
         { line_active = 6 ; /*600ms*/
           _co_ctrlRaw_ (0xD027 , 1 , 50 );
         }
      else
         { line_active -- ;}


      if ( line_tmo )
         { line_tmo -- ;}

      }

   else
      {


      line_active = 6 ; /*600ms*/


/* Mobile */
      if (!line_tmo )
         {

         switch (I2C_DATA_D0) /* Color*/
            {

         case LINEFOLLOW_COLOR_RED :
            line_turnleft = MOBILE_RUN_STOP;
            mobile_move  (MOBILE_RUN_STOP);
            break;

         case LINEFOLLOW_COLOR_GREEN:
            line_tmo = 6 ;
            line_turnleft = MOBILE_RUN_RIGHTCIRCLE;
            mobile_move  (MOBILE_RUN_RIGHT2);
            break;
         case LINEFOLLOW_COLOR_BLUE:
            line_tmo = 6 ;
            line_turnleft = MOBILE_RUN_LEFTCIRCLE ;
            mobile_move  (MOBILE_RUN_LEFT2);
            break;

         default:
            switch (I2C_DATA_D1) /* Line*/
               {

            case LINEFOLLOW_LINE_RIGHT1:
            case LINEFOLLOW_LINE_RIGHT2:
               line_turnleft = MOBILE_RUN_RIGHTCIRCLE;
               mobile_move(I2C_DATA_D1);
               break;

            case LINEFOLLOW_LINE_LEFT1 :
            case LINEFOLLOW_LINE_LEFT2 :
               line_turnleft = MOBILE_RUN_LEFTCIRCLE;
               mobile_move(I2C_DATA_D1);
               break;

            case LINEFOLLOW_LINE_ONLINE:
               line_turnleft = MOBILE_RUN_RIGHTCIRCLE;
               mobile_move(I2C_DATA_D1);
               break;

            case LINEFOLLOW_LINE_NOLINE:
               mobile_move(line_turnleft);
               break;
               }
            break;
            }

         }


/* RGB LED,0B,*/
      rgbled_color (0x90 , I2C_DATA_D2, I2C_DATA_D3, I2C_DATA_D4 );

      }


   }


#endif  /*__demo_linefollow_C__*/


