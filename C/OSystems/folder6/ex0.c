#include <unistd.h>
#include <sys/wait.h>

int main()
{
  int pfd[2];
  mkfifo("omeupipe",0600);

  if (fork() == 0)
  {
    pfd[0] = open("omeupipe",O_RDONLY);
    printf("filho: tenho a saida\n");

    int v = 0;
    read(pfd[0],&v,sizeof(v));
    close(pfd[0]);

    printf("recebi: %d\n",v);

    _exit(0);
  }
  else
  {
    sleep(5);
    pfd[1] = open("omeupipe",O_WRONLY);
    int v = 12345;
    printf("pai: tenho a entrada\n");
    write(pfd[1],&v,sizeof(v))
  }
  return 0;
}
