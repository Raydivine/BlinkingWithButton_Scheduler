#ifndef LinkedList_H
#define LinkedList_H

typedef struct LinkedList LinkedList;

struct LinkedList{
  void *data;
  LinkedList *next;
};

LinkedList *linkListNew(void *data); 
LinkedList *linkListInit();
void clearLinkList(LinkedList *link); 

#endif // LinkedList_H
