#ifndef Mutex_H
#define Mutex_H

#include "Task.h"
#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"

typedef struct{
	Tcb *owner;
	int counter;
	LinkedList *blockTcb;
}Mutex;

#endif // Mutex_H
