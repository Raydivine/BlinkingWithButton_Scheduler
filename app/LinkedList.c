#include "LinkedList.h"
#include <string.h>

LinkedList *linkListNew(void *data){
  LinkedList *link ;//= sizeof(LinkedList);
  link->data = data;


  return link;
}

LinkedList *linkListInit(){
  LinkedList *link ;

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
