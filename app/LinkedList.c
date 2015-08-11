#include "LinkedList.h"
#include <stdio.h>
#include <malloc.h>
#include "Task.h"


LinkedList *linkListNew(Tcb *data){
  LinkedList *link;// = malloc( sizeof(LinkedList) );
  link->data = data;
  link->next = NULL;

  return link;
}

