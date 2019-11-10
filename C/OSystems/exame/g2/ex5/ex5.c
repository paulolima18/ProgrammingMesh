#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void ex5(int rep,int n)
{
  if (rep == 0) return;
  if(fork() == 0)
  {
    printf("Filho %d: %d\nppid: %d\n",n-rep,getpid(),getppid());
    ex5(rep-1,n);
    _exit(n-rep);
  }
  else
  {
    int pid,status;
    pid = wait(&status);
    if(WEXITSTATUS(status))
    {
      printf("SAIU:%d\npid: %d\n",WEXITSTATUS(status), pid);
    }
  }
}

int main()
{
  ex5(10,10);
  return 0;
}
