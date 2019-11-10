#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int fd[2];
  char* line = malloc(sizeof(char)*10);
  char* mail = malloc(sizeof(char)*32);

  int file,i,n;

  if ( (file = open("file.txt",O_RDONLY)) == -1)
  {
    perror("file.txt");
    exit(-1);
  }

  for(i =0;i<10 && (n = read(file,line,10));i++)
  {
    pipe(fd);
    if (fork() == 0)
    {
      mail = malloc(sizeof(char)*32);
      strcpy(mail, strtok(line, " "));
      strcat(mail, "@alunos.uminho.pt");

      close(fd[1]);
      dup2(fd[0],0);
      close(fd[0]);
      execlp("mail","mail","-s","Sistemas Operativos",mail,(char * )0);
      _exit(-1);
    }
    else
    {
      close(fd[0]);
      dup2(fd[1],1);
      close(fd[1]);
      write(1,line,10);
    }
    if(i==9)
    {
      wait(NULL);
      i--;
    }
    i = 0;
    line = malloc(sizeof(char)*10);
  }
  close(file);
  return 0;
}
