#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>

void paifilho()
{
  int fd[2],n;
  char fs[16] = "father to son\n";
  char aux[16];
  pipe(fd);
  if (!fork()) //filho
  {
    close(fd[1]);
    n = read(fd[0],aux,strlen(fs));
    close(fd[0]);
    write(1,aux,n);
  }
  else //pai
  {
    close(fd[0]);
    write(fd[1],fs,strlen(fs));
    close(fd[1]);
  }
}

void filhopai()
{
  int fd[2],n;
  char fs[16] = "son to father\n";
  char aux[16];
  pipe(fd);
  if (!fork()) //filho
  {
    close(fd[0]);
    write(fd[1],fs,strlen(fs));
    close(fd[1]);
  }
  else //pai
  {
    wait(0);
    close(fd[1]);
    n = read(fd[0],aux,strlen(fs));
    close(fd[0]);
    write(1,aux,n);
  }
}

int main()
{
  filhopai();
  return 0;
}
