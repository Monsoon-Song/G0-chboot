
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

/* easylogic_demo.c -*- mode:C; c-file-style: "eay" -*- */
/*
 * @author Monsoon Song <zhengbin.song@chaihuo.org>
 *
 */



#include "demo_twinButton.c"
#include "demo_lightsensor.c"
#include "demo_soundsensor.c"
#include "demo_linefollow.c"



/*************************************************************
 *
 * demo_init, 给初始化函数
 *
 * Parameter: NA
 *
 * Return:
 *
 *************************************************************
 * */
void demo_init (void)
   {


   /* ClickA,Double ClickA,... */
   _co_registerCB_(0x0102 , (uint32_t)onClickA,0,0);
   _co_registerCB_(0x0402 , (uint32_t)onClickB,0,0);
   _co_registerCB_(0x0202 , (uint32_t)onDoubleClickA,0,0);
   _co_registerCB_(0x0502 , (uint32_t)onDoubleClickB,0,0);


   /* 加了拨码开关,有多种地址,其中有 0x1A,0x12 */
   _co_registerCB_(0x011A , (uint32_t)onClickA,0,0);
   _co_registerCB_(0x041A , (uint32_t)onClickB,0,0);
   _co_registerCB_(0x021A , (uint32_t)onDoubleClickA,0,0);
   _co_registerCB_(0x051A , (uint32_t)onDoubleClickB,0,0);

   _co_registerCB_(0x0112 , (uint32_t)onClickA,0,0);
   _co_registerCB_(0x0412 , (uint32_t)onClickB,0,0);
   _co_registerCB_(0x0212 , (uint32_t)onDoubleClickA,0,0);
   _co_registerCB_(0x0512 , (uint32_t)onDoubleClickB,0,0);


   /* Lightsensor,Light,Dark,... */
   _co_registerCB_(0x0305 , (uint32_t)onLightsensorLight,0,0);
   _co_registerCB_(0x0105 , (uint32_t)onLightsensorDark ,0,0);


#if 1
   /* Soundsensor,,... */
   _co_registerCB_(0xD006 , (uint32_t)onSoundsensor,0,60);


#ifdef  EASYLOGIC_DEMO_MOBLE

   /* Linefollow,,... */
   _co_registerCB_(0xD027 , (uint32_t)onLineFollow,0,10);

#endif

#endif
   }


