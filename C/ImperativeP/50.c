#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct list
{
  int value;
  int *next;
}*List;

//ex1
void scanMax()
{
  int value,max;
  scanf("%d",&value);
  for(max = value; value != 0;scanf("%d",&value))
    if(value > max)
      max = value;
  printf("%d\n",max);
}
//ex2
void scanMed()
{
  int value,med;
  int count = 0;
  scanf("%d",&value);
  for(med = 0; value != 0;scanf("%d",&value))
  {
    med = med + value;
    count++;
  }
  printf("%f\n",((float)med/(float)count));
}
//ex3
int maxi(int array[],int x)
{
  int max = array[0];
  for(int i = 0; array[i] != 0;i++)
  {
    if(max < array[i] && array[i] != x)
      max = array[i];
    else if(max == x)
      max = array[i];
  }
  return max;
}
void scan2Max()
{
  int value,i;
  int max[MAX];
  scanf("%d",&value);
  for (i = 0; value != 0;scanf("%d",&value),i++)
    max[i] = value;

  max[i] = 0;
  i = -1;
  value = maxi(max,i);
  printf("Max:%d\n",value);
  value = maxi(max,value);
  printf("Second:%d\n",value);
}
//ex4
int bitsUm (unsigned int n)
{
  int mod = 0;
  while (n)
  {
    mod += n%2;
    n = n/2;
  }
  return mod;
}
//ex5
int trailingZ (unsigned int n)
{
  int value = 0;
  while (n)
  {
    if (n%2 == 0)
      value++;
    else
      break;
    n /= 2;
  }
  return value;
}
//ex6
int qDig (unsigned int n)
{
  int dig = 0;
  while (n)
  {
    dig++;
    n/=10;
  }
  return dig;
}
//ex7
char *mystrcat(char s1[], char s2[])
{
  char *s0 = s1;
  while (*s1)
    s1++;

  while(*s2)
   *s1++ = *s2++;

  *s1 = '\0';
  return s0;
}
//ex8
  char *mystrcpy(char s1[], const char s2[])
  {
    char *s0 = s1;
    while(*s2)
      *s1++ = *s2++;

    *s1='\0';
    return s0;
  }
//ex9
int mystrcmp (char s1[], char s2[])
{
  int r=0;
  while (*s1 && *s2 && r == 0)
  {
    if (*s1 < *s2)
      r = -1;
    else if(*s1 > *s2)
      r = 1;
    *s1++;
    *s2++;
  }
  if (*s2 && r == 0)
    r = -1;
  else if (*s1 && r == 0)
    r = 1;

  return r;
}
//ex10(Not done)
#include <string.h>

char *mystrstr (char s1[], char s2[])
{
  int i,j,z,k=-1;
  for (i = 0; s1[i] && k == -1; i++)
  {
    if (s1[i] == s2[0])
    {
      for (j = 0; s2[j] && k == -1; j++)
      {
        if (s1[i+j] != s2[j])
          break;
        z = j+1;
      }
      if(s2[z])
        j=0;
      else
        k = i;
    }
  }
  if(k>=0)
  {
    while(k)
    {
      *s1++;
      k--;
    }
    return s1;
  }
  else if(s1 == s2)
    return s1;
  else
    return NULL;
}
//ex11
void strrev (char s[]) //Inverts a string
{
  char s1[100];
  int n = 0,i=0;
  while(*s)
  {
    *s++;
    n++;
  }
  *s--;
  while(i<n)
  {
    s1[i] = *s--;
    i++;
  }
  *s++;
  i=0;
  while(i<n)
  {
    *s++=s1[i];
    i++;
  }
}
//ex12
void strnoV (char s[]) //Removes all vogals from a string
{
  char this[100];
  char *s0 = s;
  int i=0;
  while(*s)
  {
    if((*s != 'a') && (*s != 'e') && (*s != 'i') && (*s != 'o') && (*s != 'u') && (*s != 'A') && (*s != 'E') && (*s != 'I') && (*s != 'O') && (*s != 'U'))
    {
      this[i++] = *s;
    }
    *s++;
  }
  i--;
  while (i >= 0)
  {
    s[i] = this[i];
    i--;
  }
  s = s0;
  s = mystrcpy(s,this);
}
//ex13
void truncW (char t[], int n)
{
  int i = 0;
  char *s = t;
  while(*s)
  {
    if (*s == ' ')
    {
      *t++;
      *s++;
      i = 0;
    }
    else if (i < n)
    {
      *t++ = *s++;
      i++;
    }
    else
      *s++;
  }
  *t = '\0';
}
//ex14
char moreFreqChar (char s[])
{
  char w[1];
  int max,current=0,i,j;
  w[0]=s[0];
  for (i = 0; s[i]; i++)
  {
    for (j = 0; s[j]; j++)
    {
      if(s[i]==s[j])
        current++;
    }
    if(current > max)
    {
      w[0] = s[i];
      max = current;
    }
    current = 0;
  }
  return w[0];
}
//ex15
int consecutiveEquals (char s[])
{
  int r = 0,i,max = 0;
  for (i = 1; s[i] && s[i+1]; i++)
  {
    if (max < r)
      max = r;
    if (s[i] == s[i+1])
      r++;
    else
      r = 1;
  }
  return max;
}
//ex16
int consecutiveDif (char s[])
{
  int r = 0,i,max = 0;
  for (i = 0;s[i] && s[i+1]; i++)
  {
    if (max < r)
      max = r;
    if (s[i] != s[i+1])
      r++;
    else
      r = 1;
  }
  return max;
}
//ex17
int maiorPrefixo(char s1[],char s2[])
{
  int r=0,i,j;
  for (i = 0; s1[i]; i++)
  {
    for j = 0; s2[j]; j++)
    {
      if (s1[i+j] == s2[j])
        r++;
      else
      {
        r = 0;
        break;
      }
    }
  }
  return r;
}
//ex18

void main(void)
{
  char var[200] = "caAbaaaoaiu lol man";
  //strnoV (var);
  truncW(var,2);
  printf("%s\n",var);
}
