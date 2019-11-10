#include "queue.h"

int main()
{
  QUEUE q;
  int i,j,empty,full,error;

  init(&q);



  //Enqueue into array
  for (i = 0; i < 11; i++)
  {
    if(encheck(&q))
      newalloc(&q,q.cap,i);
    else
      enqueue(&q,i);
  }

  for (j = q.index; j < q.size;j++)
    printf("%d*size = %d\n",j,(q.elem)[j]);


  for (i = q.index; i < MAX; i++)
  {
    if(decheck(&q))
      break;
    else
      dequeue(&q);
  }

  for (j = q.index; j < (q.index+q.size);j++)
    printf("Time: %d\n\t*size = %d\n",j,(q.elem)[j]);

  //Enqueue into array
  for (i = 12; i < 15; i++)
  {
    if(encheck(&q))
      newalloc(&q,q.cap,i);
    else
      enqueue(&q,i);
  }

  for (j = q.index; j < q.cap;j++)
    printf("%d*size = %d\n",j,(q.elem)[j]);

  return 0;
}

//initializing queue
void init(QUEUE *q)
{
  q -> cap = 2;
  q -> index = 0;
  q -> size = 0;
  q -> elem = (int*) malloc((q->cap)*sizeof(int));
}

int encheck(QUEUE *q)
{
  if (q -> size == q -> cap) return 1;
  return 0;
}

void newalloc(QUEUE *q,int cap,int value)
{
  q -> cap = cap * 2;
  int *new = (int*) malloc((q -> cap)*sizeof(int));
  for (int i = 0; i < q -> size; i++)
    new[i] = (q -> elem)[i+q -> index];

  free(q->elem);
  new[q -> size] = value;
  (q -> size)++;
  q -> elem = new;
  q -> index = 0;
}
//Adding elements to queue,(Needs encheck)
void enqueue(QUEUE *q,int value)
{
  (q -> elem)[q -> index + q -> size] = value;
  (q -> size)++;
}

int decheck(QUEUE *q)
{
  if(q -> size == 0) return 1;
  return 0;
}

//Removing elements from queue,(Needs decheck)
void dequeue(QUEUE *q)
{
  q -> index = q -> index + 1;
  (q -> size)--;
}
