#include <stdlib.h>
#include <stdio.h>

int minusculas (char s[])
{
  int r,i,a='a',Z='Z',A='A';
  int diff = A-a;
  while (*s)
  {
    if (*s >= A && *s <= Z)
      *s = *s - diff;
    s++;
  }

  return r;
}

int main(int argc, char const *argv[])
{
  char string[11] = "ABCDGEIRTH\0";
  minusculas(string);
  printf("%s\n",string);
  return 0;
}
