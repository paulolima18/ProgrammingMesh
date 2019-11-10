#include <unistd.h>
#include <fcntl.h>

int main(int argc)
{
  char buffer[argc];
  int n;
  while( (n = read(0,buffer,argc)) > 0)
  {
    write(1,buffer,n);
  }
  return 0;
}
