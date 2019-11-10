#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);
int kill(pid_t pid, int sig);
unsigned int alarm(unsigned int seconds);
int pause(void);

void f()
{
  //write(1,"Não.",4);
}
/*
SIGNAL | Function
-----------------
SIGINT  |    f   | ctrl+c
SGTERM  |    f   | "kill"
SIGKILL |    X   | "kill -KILL"
SIGSTOP |    X
SIGCONT |    X
SIGALRM |    f
SIGSEGV |    f   | acesso sgf
SIGCHLD |    f
*/

void mysleep(int s)
{
  signal(SIGALRM,f);
  alarm(s);
  pause();

}

int main(int argc,char* argv[])
{
  int n;
  char buf[100];

  //signal(SIGINT, f); //regista f para tratar SIGINT
  //signal(SIGTERM, f);

  /*signal(SIGALRM, f);
  alarm(5);*/

  /*signal(SIGSEGV, f);
  char*p = NULL;
  *p = 'a';*/

  while((n=read(0,buf,100))>0)
  {
    mysleep(1);
    write(1,buf,n);
  }
}
