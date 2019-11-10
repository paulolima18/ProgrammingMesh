#include <unistd.h>
#define MAX 1024

int main()
{
  int fd[2],n;
  char str[MAX];
  pipe(fd);

  if (fork() == 0)
  {
    dup2(fd[0],0);
    close(fd[1]);
    close(fd[0]);
    execlp("wc","wc",(char * )0);
  }
  else
  {
    close(fd[0]);
    while((n = read(0,str,MAX)) > 0)
    {
      write(fd[1],str,n);
    }
    close(fd[1]);
  }
  return 0;
}
