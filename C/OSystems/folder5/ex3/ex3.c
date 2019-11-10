#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
  int fd[2];
  pipe(fd);
  char* args[] = {"wc",(char *)0};

  if ( fork() == 0 )
  {
    dup2(fd[0],0);
    close(fd[0]);
    close(fd[1]);
    execvp(args[0],args);
  }
  else
  {
    close(fd[0]);

    char* text = malloc(sizeof(char)*100);
      while (1)
      {
        read(0,text,100);
        if(text[0]=='1')
          break;
      }

    write(fd[1],text,strlen(text));
    close(fd[1]);
    wait(NULL);
  }

  return 0;
}
