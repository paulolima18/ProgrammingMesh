#include <unistd.h>
#include <sys/wait.h>

int main ()
{
  int fd[2];
  pipe(fd);

  if (fork() != 0)
  {
    write(0,"Working...\n",12);
    sleep(5);
    char resultado[16] = "this sentece\n";
    write(fd[1],&resultado,16);
    write(0,"Done!\n",7);
    _exit(0);
  }
  else
  {
    close(fd[1]);
    char resultado[16];
    int n = read(fd[0],resultado,16);

    write(0,resultado,16);
  }
}
