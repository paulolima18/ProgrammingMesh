#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
  char *progs[4][5] = {{"grep", "-v", "^#", "/etc/passwd", (char *)0},
                      {"cut", "-f7", "-d:", (char *)0},
                      {"uniq", (char *)0},
                      {"wc", "-l", (char *)0}};

  int fd[2];
  int i;
  for(i = 0; i < 3; i++)
  {
      pipe(fd);
      if (fork() == 0)
      {
          dup2(fd[1], 1);
          close(fd[1]);
          execvp(progs[i][0], progs[i]);
          perror("ex5-if");
      }
      else
      {
          close(fd[1]);
          dup2(fd[0], 0);
          close(fd[0]);
      }
  }
  execvp(progs[i][0], progs[i]);
  perror("ex5");
}
