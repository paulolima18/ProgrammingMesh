#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char*argv[] )
{
  int n;
  char buf[128];
  int fd[2],fd0[2];

  pipe(fd0);
  for(int i = 0;i<8;i++)
  {
    pipe(fd);
    if(!fork())
    {
      close(fd[1]);
      dup2(fd[0],0);
      close(fd[0]);

      close(fd0[0]);
      dup2(fd0[1],1);
      close(fd0[1]);
      execlp("patgrep","patgrep",argv[1],(char *)0);
    }
    while (n=read(0,buf,128))
    {
      close(fd[0]);
      dup2(fd[1],1);
      close(fd[1]);
      write(1,buf,n);
    }
    // if(i == 7)
    // {
    //   wait(NULL);
    //   i--;
    // }
  }

  for(n=0;read(fd0[0],buf,1);n++);
  close(fd0[0]);
  close(fd0[1]);
  printf("%d\n",n);
  return 0;
}
