#include "LinkedList.h"
#include "LinkedListRemove.h"
#include <string.h>
#include <stdio.h>

void removeDataFromList(LinkedList **list, void *removeData){
  LinkedList *current = *list;
    
  if(current ){
    if(current->data == removeData){
      removeHead(&current);
      *list = current;
      return;  
    }
    while(current->next ){ 
      if(current->next->data == removeData){
        removeHead( &(current->next) );
        return;
      }
      current = current->next;    
    }
  }
  
}

void removeHead(LinkedList **list){
  LinkedList *current = *list, *tail;
   
  tail = current->next;
  current = tail;
  *list = current;
}

LinkedList *returnHead(LinkedList **list){
  LinkedList *current = *list, *tail;

  tail = current->next;
  *list = tail;

  current->next = NULL;
  return current;
}
