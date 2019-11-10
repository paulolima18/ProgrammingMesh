#include <unistd.h>   /*chamadas ao sistema: defs e decls essenciais*/
#include <fcntl.h>    /*O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdio.h>

int     open(const char*path, int oflag ,...);
ssize_t read(int fildes, void* buf, size_t nbyte);
ssize_t write(int fildes, const void* buf, size_t nbyte);
int     close(int fildes);

int main(int argc,char *argv[])
{
  int fd,i;
  char buf[10] = "aaaaaaaaaa";
  int Mb = 1024*1024;

  fd = open(argv[1],O_WRONLY | O_CREAT);// | O_APPEND);
  printf("%d\n",fd);
  while(i < Mb)
  {
    write(fd,buf,10);
    //printf("%d\n",i);
    i++;
  }
  close(fd);
  return 0;
}
