#ifndef LinkedListAdd_H
#define LinkedListAdd_H
#include "LinkedList.h"
#include "Task.h"

void addDataToTail(LinkedList **list, Tcb *data);
void addDataToHead(LinkedList **list, Tcb *data);
void addDataToMid (LinkedList **list, Tcb *data, Tcb *addAfterThis);

#endif // LinkedListAdd_H
