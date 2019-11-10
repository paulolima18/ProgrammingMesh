#include "ex.h"

void swapM (int *x, int *y)
{
  int t;
  t = *x;
  *x = *y;
  *y = t;
}

void swap(int v[],int i,int j)
{
  int t;
  t = v[i];
  v[i] = v[j];
  v[j] = t;
}

int sum (int v[], int N)
{
  int sum = 0,i;
  for (i = 0;i<N;i++)
    sum += v[i];

  return sum;
}

int maximum (int v[], int N, int *m)
{
  int i,max=v[0];

  for (i = 0;i < N;i++)
    if (v[i] > max)
      max = v[i];
  *m = max;
  return 0;
}

void squares (int q[], int N)
{
  int i;
  for (i = 0;i < N;i++)
    q[i] = i*i;
}

int fatorial (int N)
{
  return N*factorial(N-1);
}

void pascal (int v[], int N)
{
  if(N==1)
    v[0] = 1;
  else
  {
    v[0] = 1;
    int i;
    for (i = 1; i < N; i++)
    {
      v[factorial(N-1)] = 1;
      
      v[factorial(N)-1] = 1;
    }
  }

}
