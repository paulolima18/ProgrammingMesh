#include "../readln/readln.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define MAX 1024

int main(int argc, char*argv[])
{
  int lines=1,n;
  char buffer[MAX];
  char line[32];
  if(argc > 1) //one argument
  {
    int fd = open(argv[1],O_RDONLY);
    while((n = readln(fd, buffer,MAX)) > 0)
    {
      sprintf(line,"%d ",lines);
      write(1, line, strlen(line));
      write(1, buffer, n);
      lines++;
    }
  }
  else
  {
    while((n = read(0, buffer,MAX)) > 0)
    {
      sprintf(line,"%d ",lines);
      write(1, line, strlen(line));
      write(1, buffer, n);
      lines++;
    }
  }
  return 0;
}
// gcc -o nl-v1 nl-v1.c ../readln/readln.c
