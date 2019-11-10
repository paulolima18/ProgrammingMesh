#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main (int argc,char** argv)
{

  while (*argv != NULL)
  {
    int size_t = strlen(*argv);
    write(0,*argv,size_t);
    write(0,"\n",1);
    *argv++;
  }
  return 0;
}
