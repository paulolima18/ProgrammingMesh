#include <unistd.h>
#include <fcntl.h>    //O_RDONLY, O_WRONLY, O_CREAT, O_*
#include "readln.h"
#include <sys/wait.h>
#include <string.h>

int my_system(char* cmd)
{/*
  if(fork() == 0)
  {
    char* args[] = {"ls","-l","-a",(char *)0};
    execvp(argv,args);
    perror(argv);
    _exit(1);
  }
  else
    wait(NULL);
  return 0;}*/

  char* args[100];
  int i = 0;
  args[i] = strtok(cmd, "\n\t");
  while (args[i] != NULL)
    args[++i] = strtok (NULL,"\n\t");
  if (fork() == 0)
  {
    execvp (args[0], args);
    perror (args[0]);
    _exit (1);
  }
  else
  {
    wait (NULL);
  }
  return 0;
}


int main(int argc,char** argv) // exit or cd test
{
  int size_t;
  char* cmd = (char*) malloc(sizeof(char)*100);
  while(1)
  {
    write (1,"$",2);
    readln(0,cmd,size_t);
    my_system(cmd);
  }

  return 0;
}
