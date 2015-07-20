#ifndef Semaphore_H
#define Semaphore_H

#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListRemove.h"

typedef struct{
	int counter;
	int size;
	LinkedList *blockTcb;
}Semaphore;

#endif // Semaphore_H
