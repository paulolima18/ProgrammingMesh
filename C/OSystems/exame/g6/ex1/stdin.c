#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
  int fifo,n;
  char buf[128];
  
  if ( (fifo = open("tmp/FIFO",O_WRONLY)) == -1)
  {
    perror("tmp/FIFO");
    exit(-1);
  }

  while((n=read(0,buf,128)) > 0)
  {
    write(fifo,buf,n);
  }
  close(fifo);
  return 0;
}
