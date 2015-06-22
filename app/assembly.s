  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

.global  testFunc
.extern dummy

  .section  .text.testFunc
  .type  testFunc, %function
testFunc:
  movs	r0, #0x12
  movs	r1, #0x34
  movs	r2, #0x56
  ldr	r3, = #0x1234face
  push	{r0, r1}
  pop   {r0, r1}
  //push	{r1, r0}
 // pop   {r1, r0}
  stmdb SP!,{r1,r2,r3}
  stmdb SP!,{r4,r5,r6}
  ldmia SP!,{r1,r2,r3}
 // stmda SP!,{r1,r2,r3}
 // ltmda SP!,{r1,r2,r3}

  movw.w	r4, 0xface
  movt.w	r4, 0x1234

 // push	{R0, R1, R2} | stmdb sp! {r0, r1, r2}
  bx	lr		//branch exchange => go back to whr it call this func
