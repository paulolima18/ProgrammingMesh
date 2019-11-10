#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{

  int fd[2];
  pipe(fd);

  if (fork() == 0)
  {
    close(fd[0]);//doesnt use exit
    for (int i = 0;i<5;i++)
    {
      printf("Working...\n");
      sleep(1);
      printf("Done\n");
      int resultado = i + 1000;
      //enqueue(fila,resultado);
      write(fd[1],&resultado,sizeof(resultado));
    }
    printf("Terminated!\n");
    _exit(0);
  }
  else
  {
    close(fd[1]); // doesnt use entrance
    while (1)
    {
      printf("Reading the result...\n");
      int resultado;
      int n = read(fd[0],&resultado,sizeof(resultado));
      //wait(NULL);
      if (n == 0)
        break;
      printf("N = %d Resultado: %d\n",n,resultado);
    }
  }
}
