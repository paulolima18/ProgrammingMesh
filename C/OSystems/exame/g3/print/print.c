#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
  int i = 1;
  char newLine[1] = "\n";
  while (i < argc)
  {
    write(1,argv[i],strlen(argv[i]));
    write(1,newLine,1);
    i++;
  }
  return 0;
}
