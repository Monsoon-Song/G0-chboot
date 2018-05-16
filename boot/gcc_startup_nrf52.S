
   .syntax unified
   .arch   armv7e-m


   .section .isr_vector

   .align 2
   .globl __isr_vector

__isr_vector:
   .long   0x20010000                  /* Top of Stack */
   .long   Reset_Handler


   .size __isr_vector, . - __isr_vector


/* Reset Handler */

   .text

   .thumb
   .thumb_func

   .align 1
   .globl Reset_Handler
   .type  Reset_Handler, %function


Reset_Handler:


/* Loop to copy data from read only memory to RAM.
 * All addresses must be aligned to 4 bytes boundary.
 */
   ldr  r1, =__etext
   ldr  r2, =__data_start__
   ldr  r3, =__bss_start__

   subs r3, r2
   ble .L_loop1_done

.L_loop1:
   subs r3, #4
   ldr  r0, [r1,r3]
   str  r0, [r2,r3]
   bgt .L_loop1

.L_loop1_done:


/* CLEAR_BSS */
   ldr  r1, =__bss_start__
   ldr  r2, =__bss_end__

   movs r0, 0

   subs r2, r1
   ble .L_loop3_done

.L_loop3:
   subs r2, #4
   str  r0, [r1, r2]
   bgt .L_loop3

.L_loop3_done:

   ldr  r0, =0x20001CD0

   ldr  r1, =0x20010000
   str  r1, [r0, #0]

   ldr  r1, =Reset_Handler
   str  r1, [r0, #4]

   ldr  r1, =0x17C41 #_systickIrq_
   str  r1, [r0, #60]

   ldr  r1, =0x17B49 #UARTE0_UART0_IRQHandler
   str  r1, [r0, #72]

   ldr  r1, =0x17951 #RTC1_IRQHandler
   str  r1, [r0, #132]


/* Execute SystemInit function.
 * */
   ldr  r1, =0x17CDD #SystemInit

/* bl _start */
   bl main


  .end



