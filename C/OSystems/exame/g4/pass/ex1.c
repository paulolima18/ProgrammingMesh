#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#define MAX 128

int main()
{
  int n;
  char buffer[MAX];

  int stdin  = open("pass.txt",O_CREAT | O_APPEND | O_RDWR,0666);
  int stdout = open("saida.txt",O_CREAT | O_APPEND | O_RDWR,0666);
  int stderr = open("erros.txt",O_CREAT | O_APPEND | O_RDWR,0666);

  dup2(stdin,0);
  dup2(stdout,1);
  dup2(stderr,2);

  close(stdin);
  close(stdout);
  close(stderr);

  //execlp("wc","wc",(char *) 0);
  //exercicio 3
  if(!fork())
  {
    while ((n = read(0,buffer,MAX)) > 0)
    {
      write(1,buffer,n);
    }

    if(n<0)
    {
      write(2,buffer,n);
    }
  }
  else
  {
    wait(0);
  }
}
