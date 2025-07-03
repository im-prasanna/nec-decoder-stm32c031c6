.syntax unified
.cpu cortex-m0plus
.fpu softvfp
.thumb
.global g_pfnVectors

.word _sidata
.word _sdata
.word _edata
.word _sbss
.word _ebss

  .section .text.Reset_Handler
  .weak Reset_Handler
  .type Reset_Handler, %function
Reset_Handler:
  ldr   r0, =_estack 
  mov   sp, r0          /* set stack pointer */

  bl Reset_Continue

LoopForever:
  b LoopForever

  .size Reset_Handler, .-Reset_Handler
