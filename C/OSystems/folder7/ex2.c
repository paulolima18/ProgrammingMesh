#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

void noCode(){}

void mysleep(int s)
{
  signal(SIGALRM,noCode);
  alarm(1);
  signal (SIGSTOP,noCode);
  signal (SIGCONT,noCode);
  signal (SIGCHLD,noCode);
  pause();
}

int main (int argc,char* argv[])
{
  /*exec(argv[0],argv);
  "/bin/pwd"
  execl("sh", "sh", "-c", foo, NULL);*/

  fork();
  mysleep(1);
  argv++;
  char string[16] = "/bin/";
  strcat(string,*argv);
  execl (string, *argv, NULL);

  return 0;
}
