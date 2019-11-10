#include <unistd.h>
#include <stdio.h>

int main (int argc,char** argv)
{
  *argv++;
  while (*argv != NULL)
  {
    execl("/bin/bin",(char * ) 0);
  }
  return 0;
}
