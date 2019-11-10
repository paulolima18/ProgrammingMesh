#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>

void ex2()
{
  int fd[2],n;
  char fs[16] = "son to father\n";
  char aux[16];
  pipe(fd);
  if (!fork()) //filho
  {
    close(fd[0]);
    while ((n = read(0, aux, 1024)) > 0)
    {
        write(fd[1], aux, n);
    }
    close(fd[1]);
  }
  else //pai
  {
    close(fd[1]);
    while ((n = read(fd[0], aux, 1024)) > 0)
    {
        write(1, aux, n);
    }
    close(fd[0]);
  }
}

int main()
{
  ex2();
  return 0;
}
