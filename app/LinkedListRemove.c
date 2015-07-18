#include "LinkedList.h"
#include "LinkedListRemove.h"
#include <string.h>
#include <stdio.h>

void removeDataFromList(LinkedList **list, void *removeData){
  LinkedList *current = *list;
    
  if(current ){
    if(current->data == removeData){
      freeAndJump(&current);
      *list = current;
      return;  
    }
    while(current->next ){ 
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
   
  tail = current->next;
  current = tail;
  *list = current;
}
