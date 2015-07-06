#include "LinkedList.h"

LinkedList *linkListNew(void *data){
  LinkedList *link ;//= sizeof(LinkedList);
  link->data = data;
 // link->next = NULL;

  return link;
}

/*
void clearLinkList(LinkedList *link){
  LinkedList *tmp;
  
  while (link != null){
    tmp = link;
    link = link->next;
    free(tmp);
  }
}*/
