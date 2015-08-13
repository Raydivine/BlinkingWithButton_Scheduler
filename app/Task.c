#include "Task.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"

uint8_t taskOneStack[1028];
uint8_t taskTwoStack[1028];

Tcb mainTcb;
Tcb taskOneTcb;
Tcb taskTwoTcb;
Tcb *runningTcb;
Tcb *readyQueue;

void taskOne(void){
  volatile int counter = 0;
  while(1){
    counter++;
  }
}

void taskTwo(void){
  volatile int counter = 0xFFFFFFFF;
  while(1){
    counter--;
  }
}

void initTcb(){

	mainTcb.name = "main_thread";
	mainTcb.sp = 0;
	taskOneTcb.name = "thread #1";
	taskOneTcb.sp = (uint32_t)&taskOneStack[1028];
	CpuContext *cc = (CpuContext*)(((uint32_t)&taskOneStack[1028]) - sizeof(CpuContext));
	taskOneTcb.sp = (uint32_t)cc;


	cc->R4 =0x4444;
	cc->R5 =0x5555;
	cc->R6 =0x6666;
	cc->R7 =0x7777;
	cc->R8 =0x8888;
	cc->R9 =0x9999;
	cc->R10 =0xAAAA;
	cc->R11 =0xBBBB;
	cc->R1 =0x1111;
	cc->R2 =0x2222;
	cc->R3 =0x3333;
	cc->R12 =0xCCCC;
	cc->LR =0x1000;
	cc->PC =(uint32_t)taskOne;
	cc->xPSR =0x1200;

	runningTcb = &mainTcb;   //mainTCb is on Running Task
	readyQueue = &taskOneTcb; //TaskOne is in readyQueue prepare task switchinh
}
