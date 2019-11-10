#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
  for (int i = 1; i < argc; i++)
  {
    if (fork() == 0)
    {
      execlp(argv[i],argv[i],NULL);
    }
  }

  for (int i = 1; i < argc; i++)
  {
    wait(0);
  }
  return 0;
}
