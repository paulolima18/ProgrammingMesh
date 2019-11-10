//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define MAX 256

int main(int argc,char* argv[])
{
  int fd = open ("a.txt",O_CREAT | O_WRONLY,0600);//0644

  printf("fd=%d\n",fd);

  write(fd,"ola\n",4);

  close(fd);

  fd = open("a.txt",O_RDONLY);

  char data[MAX];

  int n = read(fd,data,MAX);
  data[n] = 0;

  printf("read:%s",data);

  close(fd);

  return 0;
}
