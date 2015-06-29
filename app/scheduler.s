  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

  .global  taskSwitch
  .global  SysTick_Handler
  .extern taskOneStack
  .extern taskTwoStack

  .section  .text.taskSwitch
  .type  taskSwitch, %function
taskSwitch:
  movs  r0, #0x00000000
  movs	r1, #0x11111111
  movs	r2, #0x22222222
  movs  r3, #0x33333333
  movs  r4, #0x44444444
  movs  r5, #0x55555555
  movs  r6, #0x66666666
  movs  r7, #0x77777777
  movs  r8, #0x88888888
  movs  r9, #0x99999999
  movs  r10, #0xaaaaaaaa
  movs  r11, #0xbbbbbbbb
  movs  r12, #0xcccccccc
  ldr   lr, =#0xdeadface
  push  {r0}
  b		.
  .align 8
  .type SysTick_Handler, %function

SysTick_Handler:
    push	{r4-r11}
    b       .


  //write code here
  //push the rest of the registers...

  //push {r7, lr}
  //add r7, sp, #0
  //bl     HAL_IncTick;
  //pop {r7, pc}

