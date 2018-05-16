
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

/* startup.c -*- mode:C; c-file-style: "eay" -*- */
/*
 * @author Monsoon Song <zhengbin.song@chaihuo.org>
 *
 */


#include <stdint.h>
#include <string.h>


#include "config.h"



#define  EASYLOGIC_DEMO_MOBLE



void startup  (void);

void demo_init(void);


static uint32_t /* 4 Words */
g_TAG_third [] __attribute__ ((section(".vector"),used)) =
   {
   0x74666544,       /* TAG "Deft"     */
   0x00000000,       /* B7-6,Ver,B5-4,Length,Unit 4B */
(uint32_t)startup,   /* Entry Point,   */
   0x00000000,       /* 32bit CheckSum */
   } ;



#include "easylogic_demo.c"



/**@brief Function for application entry.
 */
void startup (void)
   {


   uint32_t *s , *d ;

   extern uint32_t __bss_start__ , __bss_end__;
   extern uint32_t __etext , __data_start__  , __data_end__;



   s = (uint32_t *) &__etext , d = (uint32_t *) &__data_start__;

   while ((uint32_t) d < (uint32_t) &__data_end__)
      { *d++ = *s++ ;}


   d = (uint32_t *) &__bss_start__;

   while ((uint32_t) d < (uint32_t) &__bss_end__ )
      { *d++ =   0  ;}


/*********************************************************************/
/*                                                                   */
/*                                                                   */
/*********************************************************************/

   printd ( "C" );

   demo_init();


   }


