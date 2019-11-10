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
    char resultado[1024];
    for (int i = 0;i<5;i++)
    {
      printf("Writting the result...\n");
      //enqueue(fila,resultado);
      write(fd[1],&resultado,1024);
    }
    printf("Terminated!\n");
    _exit(0);
  }
  else
  {
    close(fd[1]); // doesnt use entrance
    int i = 0;
    while (1)
    {
      printf("Working...\n");
      sleep(1);
      printf("Done\n");
      char resultado[1024];
      int n = read(fd[0],&resultado,1024);
      //wait(NULL);
      if (n == 0)
        break;
      printf("N = %d Resultado: %d\n",n,i);
    }
  }
}
