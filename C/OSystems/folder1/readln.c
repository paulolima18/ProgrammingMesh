#include <unistd.h>   //chamadas ao sistema: defs e decls essenciais
#include <fcntl.h>    //O_RDONLY, O_WRONLY, O_CREAT, O_*
#include "readln.h"

ssize_t readln(int fildes, char* buf, size_t nbyte)
{
  int i=0,n;
  while((n = read(fildes,buf+i,1)) > 0)
  {
    if(buf[i] == '\n')
      break;
    i++;
  }
  buf[i] = '\0';

  if (n<=0 && i == 0)
    i = n;

  return i;
}
