#include "readln.h"

ssize_t readln(int fildes, char *buf, size_t nbyte)
{
  int i = 0;
  while(read(fildes,buf+i,1) > 0)
  {
    if(buf[i] == '\n')
    {
      buf[i++] = '\n';
      break;
    }
    i++;
  }
  return i;
}
