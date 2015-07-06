#include "LinkedList.h"
#include "LinkedListRemove.h"
#include <string.h>
#include <stdio.h>

void removeDataFromList(LinkedList **list, void *removeData){
  LinkedList *current = *list;
    
  if(current != NULL){
    if(current->data == removeData){
      freeAndJump(&current);
      *list = current;
      return;  
    }
    while(current->next != NULL){ 
      if(current->next->data == removeData){
        freeAndJump( &(current->next) );
        return;
      }
      current = current->next;    
    }
  }
  
}

void freeAndJump(LinkedList **list){
  LinkedList *current = *list, *tail;
  
  if(current == NULL)
    return;
  
  tail = current->next;
  free(current);
  current = tail;
  *list = current;
}
