#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 128

void ms(char* buf)
{
  int i = 0,size=0;
  for(int j = 0;buf[j];j++)
  {
    if (buf[j] == ' ') size ++;
  }
  char* argv[size];
  argv[i++] = strtok(buf, " ");

  while((argv[i++] = strtok(NULL, " ")) != NULL) {}

  if(!fork()) execvp(argv[0],argv);
}

int main(int argc, char*argv[])
{
  int n;
  char buf[MAX];

  while((n = read(0,buf,MAX)) > 0)
  {
    buf[n-1] = '\0';
    ms(buf);
  }

  return 0;
}
