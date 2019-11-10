#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc,char* argv[])
{
  if(fork() == 0) // filho
  {
    printf("Filho: pid = %d\nppid = %d\n", getpid(), getppid());
  }
  else //pai
  {
    printf("Pai: pid = %d\nppid = %d\n", getpid(), getppid());
  }
  return 0;
}
