#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

volatile int c_time_elapsed = 0;
volatile int c_clicked = 0;

void timeElapased ()
{
  printf("Time elapsed: %ds\n",c_time_elapsed);
  c_clicked++;
}

void timeClicked ()
{
  printf("Clicked: %d times\n",c_clicked);
  exit(0);
}

void print ()
{
  char buf[100] = "working...\n";
  write(1,buf,11);
  alarm(1);
  c_time_elapsed++;
}

void mysleep(int s)
{
  signal(SIGALRM,print);
  alarm(s);
  pause();
}

int main (int argc,char*argv[])
{
  signal(SIGINT,timeElapased);
  signal(SIGQUIT,timeClicked);
  signal(SIGALRM,print);

  alarm(1);
  while (1);

  return 0;
}
