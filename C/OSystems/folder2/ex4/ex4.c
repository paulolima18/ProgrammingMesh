#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc,char* argv[])
{
  int i;

  for (i = 0; i < 10; i++)
    if (!fork())
      break; // if different from parent

  if (i < 10)
  {
    printf("Son - pid : %d\n",getpid());
    printf("Son's Father - pid : %d\n",getppid());
    _exit(i+1);
  }
  else
  {
    int s,active_proc;
    for (active_proc = 10;active_proc > 0; active_proc--)
    {
      wait(&s);
      printf("Exit: %d\n",WEXITSTATUS(s));
    }
  }

  return 0;
}
