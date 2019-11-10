#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
int main(int argc,char** argv)
{
  if(fork() == 0)
  {
    char* args[] = {"ls","-l","-a",(char *)0};
    execvp(argv[1],args);
    perror(argv[1]);
    _exit(1);
  }
  else
    wait(NULL);
  return 0;
}
