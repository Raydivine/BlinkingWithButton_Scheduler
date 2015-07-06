#include "LinkedList.h"
#include "LinkedListAdd.h"
#include <string.h>

void addDataToTail(LinkedList **list, void *data){
  LinkedList *current = *list;
  
  if(current == NULL){
    current = linkListNew(data);
    *list = current;
    return;
  }
  
  while (current->next != NULL){
    current = current->next;
  }
  current->next = linkListNew(data);
}

void addDataToHead(LinkedList **list, void *data){
  LinkedList *current = *list, *newHead;
  
  newHead = linkListNew(data);
  newHead->next = current;
  *list = newHead;
}

void addDataToMid(LinkedList **list, void *data, void *addAfterThis){
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
