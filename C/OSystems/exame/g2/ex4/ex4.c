#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
  int pid,status,i;

  for(i = 0;i<10;i++)
  {
    if(!fork()) break;
  }

  if(i < 10)
  {
    printf("Son - pid : %d\n",getpid());
    printf("Son's Father - pid : %d\n",getppid());
    _exit(i+1);
  }
  else
  {
    for (i=10; i > 0; i--)
    {
      wait(&status);
      printf("EXIT: %d\n",WEXITSTATUS(status));
    }
  }

  return 0;
}
