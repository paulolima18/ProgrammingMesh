#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
  int i,s;
  for (i = 0; i < 10; i++)
  {
    if (!fork())
    {
      printf("Son - pid : %d\n",getpid());
      printf("Son's Father - pid : %d\n",getppid());
      _exit(i);
    }
    else
    {
      wait(&s);
      printf("Exit : %d\n",WEXITSTATUS(s));
    }
  }

  return 0;
}
