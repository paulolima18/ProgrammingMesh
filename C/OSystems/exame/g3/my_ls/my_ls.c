#include <unistd.h>

int main()
{
  char cmd[] = "ls";
  char* argv[3];
  argv[0] = "ls";
  argv[1] = "-l";
  argv[2] = NULL;

  execvp(cmd,argv);
  return 0;
}
