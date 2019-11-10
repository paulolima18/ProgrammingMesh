#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
  int pid,status;
  for (int i =0;i<10;i++)
  {
    if (fork() == 0) //filho
    {
      printf("Filho: %d\nppid: %d\n", getpid(),getppid());
      _exit(i);
    }
    else // pai
    {
      pid = wait(&status);
      if(WEXITSTATUS(status))
      {
        printf("Filho nº%d saiu com %d e pid %d\n", i,WEXITSTATUS(status),pid);
      }
    }
  }
  return 0;
}
