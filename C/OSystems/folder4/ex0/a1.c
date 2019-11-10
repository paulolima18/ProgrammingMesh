#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main (int argc,char** argv)
{
  //printf("ANTES\n");

  char buf[100];
  int n = read (0,buf,100);
  printf("li %s\n",buf);

  int fd = open ("saida.txt",O_RDONLY);//|O_CREAT,0644);
  dup2(fd,0);//1 write, 0 read
  close(fd);

  n = read (0,buf,100);
  buf[n] = 0;
  printf("li %s\n",buf);

  //printf("DEPOIS\n");

  return 0;
}
