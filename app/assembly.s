  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

.global testFunc
.global taskSwitch
//.global SysTick_Handler

.extern taskOneStack
.extern tasTwoStack



 	.section  .text.testFunc
 	.type  testFunc, %function

testFunc:
  movs	r0, #0x10
  movs	r1, #0x20
  movs	r2, #0x30
  movs  r3, #0x40
  movs  r12,#0x50
  movs  lr, #0x60

  push {r0-r1-r2-r3-r12}
  push {lr}
  bx	lr

  .section  .text.scheduler
  .type  taskSwitch, %function

taskSwitch:
  ldr	r0, =#0x00000000
  ldr	r1, =#0x11111111
  ldr	r2, =#0x22222222
  ldr	r3, =#0x33333333
  ldr   r4, =#0x44444444
  ldr   r5, =#0x55555555
  ldr   r6, =#0x66666666
  ldr   r7, =#0x77777777
  ldr   r8, =#0x88888888
  ldr   r9, =#0x99999999
  ldr  r10, =#0xaaaaaaaa
  ldr  r11, =#0xbbbbbbbb
  ldr  r12, =#0xcccccccc
  ldr  lr, =#0x1515
  push {r0}
  b		.

/*
 .align 8
 .type SysTick_Handler, %function

SysTick_Handler:
	push {lr};
	push {r12};
	push {r3};
	push {r2};
	push {r4};
	push {r11};
	push {r10};
	push {r8};
	push {r7};
	push {r6};
	push {r5};
	push {r4};*/
///push the rest of register


// push	{r1,lr}
// add	r7,sp,#0
//bl		HAL_IncTick
// pop	{r7,pc}
// bx	lr		//branch exchange => go back to whr it call this func

/*
  movs	r0, #0x12
  movs	r1, #0x34
  movs	r2, #0x56
  ldr	r3, = #0x1234face
  push	{r0, r1}
  pop   {r0, r1}
  stmdb SP!,{r1,r2,r3}
  stmdb SP!,{r4,r5,r6}
  ldmia SP!,{r1,r2,r3}
  movw.w	r4, 0xface
  movt.w	r4, 0x1234
*/
// push	{R0, R1, R2} | stmdb sp! {r0, r1, r2}

