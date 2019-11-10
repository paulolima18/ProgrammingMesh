#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
  pid_t pid;
  if ((pid = fork()) == 0) //filho
  {
    printf("Filho: %d\nppid: %d\n", getpid(),getppid());
  }
  else //pai
  {
    printf("Pai: %d\nppid: %d\nFilho:%d\n", getpid(),getppid(),pid);
  }
  return 0;
}
