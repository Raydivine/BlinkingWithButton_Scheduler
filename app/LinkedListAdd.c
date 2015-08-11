#include "LinkedList.h"
#include "LinkedListAdd.h"
#include "LinkedListERR.h"
#include <stdio.h>
#include <malloc.h>
#include "Task.h"

void addDataToTail(LinkedList **list, Tcb *data){
  LinkedList *current = *list;
  
  if(current == NULL){
    current = linkListNew(data);
    *list = current;
  }
  else{
    while (current->next != NULL){
      current = current->next;
    }
    current->next = linkListNew(data);
  }
}

void addDataToHead(LinkedList **list, Tcb *data){
  LinkedList *current = *list, *newHead;
  
  newHead = linkListNew(data);
  newHead->next = current;
  *list = newHead;
}

void addDataToMid(LinkedList **list, Tcb *data, Tcb *addAfterThis){
  LinkedList *current = *list, *mid, *tail;

  while(current != NULL){ 
    if(current->data == addAfterThis){
      tail = current->next;
      mid = linkListNew(data);
      mid->next = tail;
      current->next = mid;
      return; 
    }
    current = current->next;     
  }
}
