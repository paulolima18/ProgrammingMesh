#include <unistd.h>   //chamadas ao sistema: defs e decls essenciais
#include <fcntl.h>    //O_RDONLY, O_WRONLY, O_CREAT, O_*
#define SIZE 1024

//1/100/1024/
int     open(const char*path, int oflag ,...);
ssize_t read(int fildes, void* buf, size_t nbyte);
ssize_t write(int fildes, const void* buf, size_t nbyte);
int     close(int fildes);

int main(int argc,char *argv[])
{
  int fd,n;
  char buffer[SIZE];
  for (int i = 1; i < argc; i++)
  {
    fd = open(argv[i],O_RDONLY);
    while((n=read(fd,buffer,SIZE))>0)
      write(1,buffer,n);
  }
  close(fd);
  return 0;
}

//REAL
//Size 1 -> 2.109s/2.104s
//   100 -> 0.237s/0.232s
//  1024 -> 0.245s/0.196s
