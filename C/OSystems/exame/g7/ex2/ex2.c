#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void sigcont()
{

}

void sigstop()
{

}

void sigalarm()
{

}

void sigchld()
{

}

int main(int argc, char*argv[])
{
  signal(SIGCONT,sigcont);
  signal(SIGSTOP,sigstop);
  signal(SIGCHLD,sigchld);

  
  return 0;
}
