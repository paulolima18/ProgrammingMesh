#include <unistd.h>
#include <fcntl.h>

int main(int argc, char*argv[])
{
  int fd = open(argv[1],O_CREAT | O_RDWR,666);
  int count = 0;
  while(count < 1000000)
  {
    write(fd,"aaaaaaaaaa",10);
    count ++;
  }
  close(fd);
  return 0;
}
