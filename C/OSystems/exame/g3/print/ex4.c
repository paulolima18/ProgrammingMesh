#include <unistd.h>

int main(int argc, char* argv[])
{
  execvp("./print",argv);
  return 0;
}
