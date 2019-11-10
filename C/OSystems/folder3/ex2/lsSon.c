#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char** argv)
{
  if ( fork() == 0)
    execl("/bin/ls","ls","-l",(char *) 0);
  //write(0,"waiting for son\n",16);
  wait(NULL);
  //write(0,"found it\n",9);
  return 0;
}
