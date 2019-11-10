#include <unistd.h>

int main()
{
  if (fork())
  {
    execlp("ls","ls","-l",NULL);
  }
  else
  {

  }
  return 0;
}
