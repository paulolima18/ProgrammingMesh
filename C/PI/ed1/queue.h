#include <stdio.h>
#include <stdlib.h>

#define MAX 10

//definition of struct Case
typedef struct queue
{
  int index,size;
  int cap;
  int *elem;
}QUEUE;

//initializing queue
void init(QUEUE *q);

int encheck(QUEUE *q);

void newalloc(QUEUE *q,int cap,int value);

void enqueue(QUEUE *q,int value);

int decheck(QUEUE *q);

void dequeue(QUEUE *q);
