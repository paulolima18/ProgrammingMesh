#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct list
{
  int values[MAX];
  int size;
}Queue;

void bubbleUp()
{

}

void initQueue(Queue *q)
{
  q->size = 0;
}

int isEmpty(Queue *q)
{
  return (q->size == 0);
}

int add(Queue *q,int x)
{
  int r = 0;//good
  if(q->size == MAX)
    r = 1;//fail
  else
  {
    q->values[q->size] = x;
    bubbleUp(q->values,q->size);
    q->size++;
  }
  return r;
}

int remove(Queue *q,int *x)
{
  int r = 0;
  if(isEmpty(q)) r = 1;
  else
  {
    *x = q->values[q->size];
    q->values[0] = q->values[--q->size]
    bubbleDown(q->values,q->size,0)
  }

}

void main()
{

}
