
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

/* flashcmd.c -*- mode:C; c-file-style: "eay" -*- */
/*
 * @author Monsoon Song <zhengbin.song@chaihuo.org>
 *
 */



/*********************************************************************
 * @fn      _fbitchk_
 *
 * @brief
 *    检查blk是否存在(已收到)
 *
 *    参数: blk,块号
 *
 * @return  1,Yes,0,NO
 */

int __attribute__((section(".mlib"))) _fbitchk_ (uint16_t blk)
   {

   int  i = ( blk >> 5 )& 7 , j = blk & 31 ;

   return  ( fbitmap[i] & (1UL << j )) ? 1 : 0;

   }



/*********************************************************************
 * @fn      _fbitset_
 *
 * @brief
 *    设置blk的bitmap
 *
 *    参数: blk,块号
 *
 * @return  none
 */

void __attribute__((section(".mlib"))) _fbitset_ (uint8_t blk)
   {

   int  i = (blk >> 5 ) & 7 , j = blk & 31 ;

   fbitmap[i] |= 1UL << j ;

   }



/*********************************************************************
 * @fn      do_flashcmd
 *
 * @brief
 *    解析执行HOST命令
 *
 * @return  none
 */

void do_flashcmd (uint8_t *p )
   {


   uint8_t *cmd = p ;


   switch (CMD_HEAD_EXE)
      {


/* 切换串口烧写节点,OPT(节点地址),*/
   case CMD_EXEC_UART:

      if (!boflag && !(CMD_HEAD_OPT & 0x80) && CMD_HEAD_LEN == 4 )
         { boflag  =  1 ;

           NRF_P0->PIN_CNF [CTRPIN] =
              NRF_GPIO_PIN_DIR_OUTPUT   << GPIO_PIN_CNF_DIR_Pos   |
              NRF_GPIO_PIN_INPUT_DISCONNECT<< GPIO_PIN_CNF_INPUT_Pos |
              NRF_GPIO_PIN_NOPULL       << GPIO_PIN_CNF_PULL_Pos  |
              NRF_GPIO_PIN_S0S1         << GPIO_PIN_CNF_DRIVE_Pos |
              NRF_GPIO_PIN_NOSENSE      << GPIO_PIN_CNF_SENSE_Pos ;

           BOUART_ON  ();
         }
      break ;


/* 主控reboot*/
   case CMD_EXEC_BOOT:

      if (CMD_HEAD_LEN == 20)
         {

         uint32_t s[4] ;
         mmcpy (  s , CMD_HEAD_DAT , 16 );

         if ( s[0] == 0xDEADBEEF && s[1] == 0xDEADBEEF &&
              s[2] == 0xDEADBEEF && s[3] == 0xDEADBEEF )
            { sreset(2) ;}
         }
      break ;


/* 编程开始,指定Flash地址*/
   case CMD_EXEC_FSTA:

      if ( !boflag && CMD_HEAD_LEN == 8 )
         {

         mmcpy (&_fstart_, CMD_HEAD_DAT , 4 );

         if (_fstart_>= LTABLE_ADDR && _fstart_<FLASH_END)
            {

            /* OPT为FF时,才需擦除,否则不擦除
             * */
            if (CMD_HEAD_OPT == 0xFF)
               {sd_flash_page_erase (_fstart_ >> 12 ) ;}

            ursp[0] =  4 ; /*LEN*/
            ursp[1] = CMD_TYPE_FRCORE ;
            ursp[2] = CMD_EXEC_FSTA;
            ursp[3] = CMD_HEAD_OPT ; /*OPT*/
            tx_bytes (ursp , 4 );
            }
         }
      break ;


/* 编程数据*/
   case CMD_EXEC_FDAT:

      if ( !boflag &&_fstart_>= LTABLE_ADDR && _fstart_<FLASH_END)
         {

         uint8_t   b = CMD_HEAD_OPT ;

         mmcpy ( _fd_ , CMD_HEAD_DAT , CMD_HEAD_LEN-4 );

         sd_flash_write (
               (uint32_t*)(_fstart_ + ((uint32_t)b << 4)) ,
               _fd_, (CMD_HEAD_LEN-4) >> 2 );
         _fbitset_ (b);

         }
      break ;


/* 编程结束*/
   case CMD_EXEC_FFIN:

      if ( !boflag && CMD_HEAD_LEN == 8 )
         {

         uint32_t s , m , e = CMD_HEAD_OPT ? CMD_HEAD_OPT : 0x100 ;

         mmcpy ( &s , CMD_HEAD_DAT , 4 );


         m  = checksum((uint32_t*)_fstart_ , e<<2);
         m += s;
         if ( m == 0x00000000 )
            { e =  0x00 ;}
         else
            { e =  0xFF ;}

         ursp[0] =  4 ; /*LEN*/
         ursp[1] = CMD_TYPE_FRCORE ;
         ursp[2] = CMD_EXEC_FFIN ;
         ursp[3] =  e ; /*OPT*/

         tx_bytes (ursp , 4 );

         }
      break ;


/* 编程数据检查*/
   case CMD_EXEC_FCHK:

      if ( !boflag && CMD_HEAD_LEN == 8 )
         {

         uint16_t b = CMD_HEAD_OPT , e = 0 ;

         if (!b)
            { b = 256 ;}

         for(uint16_t i = 0 ; i < b ; ++ i)
            {

            if (!_fbitchk_(i))
               {

               ursp[4+e++] = (uint8_t) i ;

               if ( e == 16 )
                  {break ;}
               }

            }

         ursp[0] = e+4; /*LEN*/
         ursp[1] = CMD_TYPE_FRCORE ;
         ursp[2] = CMD_EXEC_FCHK ;
         ursp[3] = e  ; /*OPT*/

         tx_bytes (ursp , e+4);

         }
      break ;


/* 读Flash数据*/
   case CMD_EXEC_FRED:

      if ( !boflag && CMD_HEAD_LEN == 8 )
         {

         uint32_t d ;
         mmcpy ( &d , CMD_HEAD_DAT , 4 );


         mmcpy (&ursp[4] ,
               (uint8_t*)( d+((uint32_t)CMD_HEAD_OPT<<4)) , 16);

         ursp[0] = 20; /*LEN*/
         ursp[1] = CMD_TYPE_FRCORE ;
         ursp[2] = CMD_EXEC_FRED ;
         ursp[3] = 0 ; /*OPT*/

         tx_bytes (ursp , 20);
         }
      break ;


/* 指定配置表入口点*/
   case CMD_EXEC_FENT:

      if ( !boflag && CMD_HEAD_LEN == 20 )
         {

         entrypoint ( CMD_HEAD_DAT );

         ursp[0] = 4; /*LEN*/
         ursp[1] = CMD_TYPE_FRCORE ;
         ursp[2] = CMD_EXEC_FENT;
         ursp[3] = 0x00 ; /*OPT*/
         tx_bytes (ursp , 4);
         }
      break ;

   default:
      break ;
      }

   return ;

   }


