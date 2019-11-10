#include <unistd.h>   /*chamadas ao sistema: defs e decls essenciais*/
#include <fcntl.h>    /*O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <string.h>
#include "readlnSonic.h"

int     open(const char*path, int oflag ,...);
ssize_t read(int fildes, void* buf, size_t nbyte);
ssize_t write(int fildes, const void* buf, size_t nbyte);
int     close(int fildes);

ssize_t readln (int fildes, char* buf, size_t nbyte)
{
  int i=0;
  if( read(fildes,buf,nbyte) > 0)
  {
    while (buf[i] != '\n')
      i++;
  }
  buf[i] = '\0';


  return i;
}
