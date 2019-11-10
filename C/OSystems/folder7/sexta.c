#include <signal.h>
#include <stdio.h>
#include <unistd.h>

volatile int segundos;
volatile int vezes;
volatile int fim = 0;

void sigint_handler (int s)
{
  vezes += 1;
  char buf[100];
  int n = sprintf(buf,"Elapsed %d seconds\n",segundos);
  write(1, buf, n);
}

void sigquit_handler (int s)
{
  fim = 1;
}

void sigarlm_handler (int s)
{
  segundos += 1;
  alarm(1);
}

int main()
{
  signal(SIGINT, sigint_handler);
  signal(SIGQUIT, sigquit_handler);
  signal(SIGALRM, sigarlm_handler);
  alarm(1);

  while (!fim)
  {
    pause();
  }
  printf("Carregou %d vezes\n",vezes);
}
