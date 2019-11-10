#include <stdio.h>
#include <stdlib.h>

typedef struct btree
{
  int value;
  struct btree *left,*right;
}Node,*Btree;

int size(Btree a)
{
  int r = 1;
  if(a == NULL)
    r = 0;
  else
  {
    r = r + size(a->left);
    r = r + size(a->right);
  }
  return r;
}

int altura(Btree a)
{
  int r = 0;
  int size = size(a);
  for (int i = 0; size > (2^i);i++)
    r++;

  return r;
}
void main()
{
  Btree a,b,c;
  a = malloc(sizeof(struct btree));
  a -> value = 11;
  b = malloc(sizeof(struct btree));
  a -> value = 10;
  c = malloc(sizeof(struct btree));
  a -> value = 30;

  a -> left = b;
  a -> right = c;

  int x = size(a);
  printf("%d\n",x);
}
