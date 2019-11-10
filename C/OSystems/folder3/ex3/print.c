#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc,char** argv)
{
  *argv++;
  while(*argv != NULL)
  {
    int this = strlen(*argv);
    write(0,*argv,this);
    write(0,"\n",1);
    *argv++;
  }
  return 0;
}
