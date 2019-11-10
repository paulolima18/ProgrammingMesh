#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

volatile int ctrl_c=0;
volatile int tempo=0;

void comandC()
{
  printf("Tempo:%d/s\n",tempo);
  ctrl_c++;
}

void quit()
{
  printf("%d\n",ctrl_c);
  exit(0);
}

void my_alarm()
{
  char buf[16] ="working...\n";
  write(1,buf,12);
  alarm(1);
  tempo++;
}

int main()
{
  signal(SIGINT,comandC);
  signal(SIGQUIT,quit);
  signal(SIGALRM,my_alarm);

  alarm(1); // chamar alarm que responderá 1 segundo depois
  /* pause(); Caso existisse este pause e não o while então o program iria esperar
              que um sinal fosse enviado (por exemplo o alarm(1 segundo depois)
              e depois o programa sairia*/
  while(1){pause();} //loop infinito para poder 'ativar' todos os sinais sem o programa sair

  return 0;
}
