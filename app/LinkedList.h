#ifndef LinkedList_H
#define LinkedList_H
#include "Task.h"

typedef struct LinkedList LinkedList;

struct LinkedList{
  Tcb *data;
  LinkedList *next;
};

LinkedList *linkListNew(Tcb *data);
void clearLinkList(LinkedList *link); 

#endif // LinkedList_H
