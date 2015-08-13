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
  	push  {r4-r11}          //1. push all necessary register
  	ldr   r4, =runningTcb   //2. a)load runningTcb to r4
    ldr   r4, [r4]          //   b)point r4 address to running Tcb
  	str   sp, [r4, #TCB_SP] //3. store current SP into runningTCB.sp
  	push  {lr}         		//4. save current register
 	ldr   r0, =readyQueue   //5. a)load readyQueue into r0
 	bl    returnHead        //   b)returnHead from readyQueue, which is TaskOne
 	mov   r5, r0            //   c)mov tasKOne into r5
  	ldr	  r1, =runningTcb	//6. a)load runningTcb to r1
    str	  r0, [r1]		    //   b)point the runningTcb addres to TaskOne
    mov	  r1, r4		    //7. a)r4 contained runningTcb
    bl	  addDataToTail     //   b)store mainTcb into readyQueue
    pop	  {lr}              //8. get back the register
    ldr	  sp, [r5, #TCB.SP]	//9. load current  to taskOneTcb.sp
    pop   {r4-r11}          //10. pop all  register
    bx    lr                //11. return from interrupt




