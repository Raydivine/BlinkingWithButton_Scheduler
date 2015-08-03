#ifndef MailBox_H
#define MailBox_H

#include "Mutex.h"
#include "Semaphore.h"

typedef struct{
	int *buufer;
	int size;
	Semaphore sloatAvailbale;
	Semaphore slotsUsed;
	int writeIndex;
	int readiIndex;
	Mutex mutexForBuffer;
}MailBox;

void mailBoxInit( MailBox *mainlBox, int size);
void mailBoxSendMessage(MailBox *milBox, int message);
int mailBoxGetMessage(MailBox *mailBox);

#endif // MailBox_H
