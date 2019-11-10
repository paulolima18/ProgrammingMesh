#include <unistd.h>     /*chamadas ao sistema: defs e decls essenciais*/
#include <sys/wait.h>   /*chamadas wait*() e macros relacionadas*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

pid_t getpid(void);
pid_t getppid(void);
pid_t fork(void);
void _exit(int status);
pid_t wait(int*status);
pid_t waitpid(pid_t pid, int*status, int options);


int main()
{

  printf("Father: %d\n",getpid());
  fork();
  printf("Son: %d\n",getppid());
  //system("ps");
  //char pid[16];
  //sprintf(pid,getpid());
  //write(1,pid,10);
  return 0;
}
