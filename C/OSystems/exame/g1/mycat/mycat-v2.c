#include <unistd.h>
#include <fcntl.h>
#define MAX 1024

int main(int argc,char* argv[])
{
  char buffer[MAX];
  int n,fd;
  for(int i = 1; i <= argc;i++)
  {
    int fd;
    if (argc == 1)
    {
      fd = 0;
    }
    else
    {
      fd = open(argv[i],O_RDONLY);
    }
    while( (n = read(fd,buffer,MAX)) > 0)
    {
      write(1,buffer,n);
    }
    close(fd);
  }
  return 0;
}
// time ./mycat-v2 < ../10mb/file.txt > /tmp/lixo
