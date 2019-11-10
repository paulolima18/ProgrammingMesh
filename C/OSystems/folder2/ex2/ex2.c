#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
  pid_t pid;

  if ( (pid = fork()) == 0 )
  {
    //sleep(1);
    printf("Son - pid : %d\n",getpid());
    printf("Son's Father - pid : %d\n",getppid());
    _exit(0);
  }
  else
  {
    //sleep(100);
    printf("Father - pid: %d\n", getpid());
    printf("Father - pid Father: %d\n", getppid());
    printf("Father - pid Son: %d\n", pid);
  }
  return 0;
}
