  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

  .global  waitForTaskSwitch
  .global  SysTick_Handler
  .extern taskOneStack
  .extern taskTwoStack

  .section  .text.waitForTaskSwitch
  .type  waitForTaskSwitch, %function
waitForTaskSwitch:
  ldr  r0, =#0x00000000
  ldr  r1, =#0x11111111
  ldr  r2, =#0x22222222
  ldr  r3, =#0x33333333
  ldr  r4, =#0x44444444
  ldr  r5, =#0x55555555
  ldr  r6, =#0x66666666
  ldr  r7, =#0x77777777
  ldr  r8, =#0x88888888
  ldr  r9, =#0x99999999
  ldr  r10, =#0xaaaaaaaa
  ldr  r11, =#0xbbbbbbbb
  ldr  r12, =#0xcccccccc
  ldr   lr, =#0xdeadface
  push  {r0}
  b		.
  
.align 8
.type SysTick_Handler, %function

.equ TCB_NEXT,  0
.equ TCB_NAME,  4
.equ TCB_SP  ,  8

SysTick_Handler:
/*
//First
  	push 	{r4-r11}          //1. push all necessary register
  	ldr 	r0, =mainTcb      //2. load mainTcb
 	movs	r1, #0            //3. save SP into mainTcb.sp
	add		r1, sp            //
	str 	r1, [r0, #TCB_SP] //   (r0 is mainTcb, r1 is sp, and r1 is store into r0.sp)
	ldr 	r0, =taskOneTcb   //4. Load taskOneTcb
	ldr 	sp, [r1, #TCB_SP] //5. Load mainTcb.SP into sp ( because mainTcb.SP == r1 , due to step 3 )
	pop 	{r4-r11}          //6. pop all pushed register
	pop 	{r0-r3}           //
	pop 	{r12}             //
 	bx      lr                //7. return from interrupt
  */
//Second
  	push  {r4-r11}          //1. push all necessary register
  	ldr   r4, =runningTcb   //2. a)load runningTcb into r4
 //   ldr   r4, [r4]          //   b)load r4 into r4
  	str   sp, [r4, #TCB_SP] //3. store SP into runningTcb.sp (r4 is runningTcb)
  	push  {r7, lr}          //4. a) push r7 and lr
 	ldr   r0, =readyQueue   //   b) load readyQueue into r0(readyQueue is LinkedList)
 	bl    removeHead        //   c) removeHead(r0)
 	mov   r5, r0            //   d) r5 = r0  ( r5 is the list )
  	ldr   sp, [r5, #TCB_SP] //5. load R5.sp into sp
  	ldr   r5, =runningTcb   //6. load runningTcb into r5
  	pop   {r7, lr}          //7. a) pop r7 and lr
  	mov   r0, r4            //   b) load r4 to r0
  	bl    addDataToTail     //   c) add r1 to tail ( r1 also equal r4)
  	pop   {r4-r11}          // pop all pushed register
  	bx    lr                // return from interrupt


// extra space
//     XPSR
//     PC
//     LR
//     r12
//     r3
//     r2
//     r1
//     r0
//     r11
//     r10
//     r9
//     r8
//     r7
//     r6
//     r5
//     r4    <-	sp

