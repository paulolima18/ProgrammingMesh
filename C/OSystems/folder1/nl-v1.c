#include <unistd.h>   //chamadas ao sistema: defs e decls essenciais
#include <fcntl.h>    //O_RDONLY, O_WRONLY, O_CREAT, O_*
#include "Extras/readlnSonic.h"

int     open(const char*path, int oflag ,...);
ssize_t read(int fildes, void* buf, size_t nbyte);
ssize_t write(int fildes, const void* buf, size_t nbyte);
int     close(int fildes);

//6
int main(int argc,char* argv[])
{
  int i=0,n=1,k=1,line = 1;
  char *lines = (char*) malloc(sizeof(char)*16);
  char *buffer = (char*) malloc(sizeof(char)*256);
  char space[1] = " ";
  char nbar[1] = "\n";

  if(argc > k)
  {
    int fd = open(argv[k],O_RDONLY);

    n = readln(fd,buffer,sizeof(buffer));
    while(n > 0)
    {
      sprintf(lines,"%d",line);
      write(1,lines,sizeof(lines));
      write(1,space,sizeof(space));
      while (i < n)
        write(1,buffer+(i++),1);
      i = 0;
      *buffer = '\n';
      write(1,buffer,1);
      n = readln(fd,buffer,256);
      line++;
    }
    lines = 0;
    k++;
    close(fd);
  }
  else
  {
    while(line)
    {
      n = readln(0,buffer,sizeof(buffer)); // read the input

      sprintf(lines,"%d",line); // print line
      write(1,lines,sizeof(lines));
      write(1,space,sizeof(space));

      write(1,buffer,n); //print input
      write(1,nbar,sizeof(nbar));
      line++;
    }
  }

  return 0;
}
