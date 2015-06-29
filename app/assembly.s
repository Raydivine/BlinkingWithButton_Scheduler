  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

.global testFunc

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


