#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
  int fifo,n;
  char buf[128];
  mkfifo("tmp/fifo",0666);
  if((fifo = open("tmp/fifo",O_WRONLY)) == -1)
  {
    perror("tmp/fifo[CLIENTE]");
    exit(-1);
  }
  while((n = read(0,buf,128)) > 0)
  {
    write(fifo,buf,n);
  }

  return 0;
}
