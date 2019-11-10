#include <unistd.h>
#include <fcntl.h>
#include "readlnSonic.h"

int main(int argc,char* argv[])
{
  int n,fd,lines,i,j;
  char* buffer = (char*) malloc(sizeof(char)*4096);
  char slash[1] = "\n";
  char left[4] = "==> ",right[4] = " <==";

  argv[1]++;
  lines = atoi(argv[1]);

  if (argc == 2)
  {
    for (j = 0; j < lines; j++)
    {
      if ((n = readln(0,buffer,sizeof(buffer))) > 0)
        write(1,buffer,n);
      else
        break;
      write(1,slash,1);
    }
  }
  else
  {
    for (i = 0; i < (argc-2); i++)
    {
      fd = open(argv[i+2],O_RDONLY);
      write(1,left,sizeof(left));
      write(1,argv[i+2],sizeof(argv[i+2]));
      write(1,right,sizeof(right));
      write(1,slash,1);

      for (j = 0; j < lines; j++)
      {
        if ((n = readln(fd,buffer,sizeof(buffer))) > 0)
          write(1,buffer,n);
        else
          break;
        write(1,slash,1);
      }
      close(fd);
    }
  }

  return 0;
}
