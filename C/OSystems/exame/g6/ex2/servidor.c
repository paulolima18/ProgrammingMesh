#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int fifo,n,logs;
  char buf[128];

  if((fifo = open("tmp/fifo",O_RDONLY)) == -1)
  {
    perror("tmp/fifo[SERVIDOR]");
    exit(-1);
  }

  if((logs = open("tmp/logs",O_CREAT | O_WRONLY | O_APPEND,0666)) == -1)
  {
    perror("tmp/logs[SERVIDOR]");
    exit(-1);
  }
  while((n = read(fifo,buf,128)) > 0)
  {
    write(logs,buf,n);
  }

  return 0;
}
