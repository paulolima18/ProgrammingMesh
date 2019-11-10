#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 10

typedef struct list *LInt;

struct list
{
  int value;
  LInt prox;
};

typedef struct lista
{
  int value;
  struct lista *prox;
}*AInt;

LInt addS(LInt a,int x)
{
  LInt new = malloc(sizeof (struct list));
  if(new!=NULL)
  {
    new -> value = x;
    new -> prox = a;
  }
  return new;
}

LInt addE(LInt a,int x)
{
  LInt new = malloc(sizeof(struct list));
  while(a -> prox != NULL) a = a-> prox;
  if(new != NULL)
  {
    a -> prox = new;
    new -> prox = NULL;
    new -> value = x;
  }
}
void printALL(LInt array)
{
  LInt fake = array;
  while(fake != NULL)
  {
    printf("%d\n",fake->value );
    fake = fake -> prox;
  }
  printf("over\n");
  free(fake);
}

LInt reverse(LInt a)
{
  LInt r,pt;

  if (a == NULL || a-> prox == NULL)
    r = a;
  else
  {
    r = pt = reverse(a->prox);

    while(pt -> prox != NULL)
      pt = pt -> prox;
    pt -> prox = a;
    a -> prox = NULL;
  }
  free(pt);
  return r;
}

void main()
{
  int i = 3;
  LInt a,b;
  b = addS(NULL,10);
  a = addS(b,1);
  printALL(a);
  reverse(a);
  printALL(b);
}
