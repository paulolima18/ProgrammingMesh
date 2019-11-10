#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
/*
int main (int argc, char* argv[])
{
  int i;
  printf("PID\tCPID\tIND\tIS_EXIT\n");
  for (i = 1; i <= 10; i++)
  {
    pid_t ch = fork();
    if(ch == -1)
      _exit(1);
    else if (ch) // fork() returns 0 if Son process: Execute when son process
    {
      wait(NULL);
      continue;
    }
    else
    {
      printf("%d\t%d\t%d\t%d\n",getpid(), getppid(), i, 0);//Son && Father
      wait(NULL);
      //printf("%d\t%d\t%d\t%d\n",getpid(), ch, i, 1);
      _exit(0);
    }
  }
  return 0;
}*/

int main()
{
  int i;
  printf("Index\tSon\tFather\n");
  for (i = 0;i < 10;i++)
  {
    //printf("%d\t%d\t%d\n",i,getpid(),getppid());
    if ( i == 10) _exit(0);
    pid_t p = fork();
    if (p)
    {
      wait(0);
      break;
    }
  }
  printf("%d\t%d\t%d\n",i,getpid(),getppid());
}
