#include <unistd.h>

int main()
{
  int fd[2];
  pipe(fd);

  if (!fork())//filho
  {
    close(fd[1]);
    dup2(fd[0],0);
    close(fd[0]);
    execlp("wc","wc","-l",(char *) 0);
  }
  else
  {
    close(fd[0]);
    dup2(fd[1],1);
    close(fd[1]);
    execlp("ls","ls","/etc",(char *) 0);
  }

  return 0;
}
