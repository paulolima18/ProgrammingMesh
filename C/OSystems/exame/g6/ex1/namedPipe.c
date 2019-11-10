#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int main()
{
  mkfifo("tmp/FIFO",0666);
  return 0;
}
