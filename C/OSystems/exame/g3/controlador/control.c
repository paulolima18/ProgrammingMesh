#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int ms(char* buf)
{
  int i = 0,size=0;
  for(int j = 0;buf[j];j++)
  {
    if (buf[j] == ' ') size ++;
  }
  char* argv[size];
  argv[i++] = strtok(buf, " ");

  while((argv[i++] = strtok(NULL, " ")) != NULL) {}

  if(!fork()) execvp(argv[0],argv);
  else wait(0);
  return 1;
}

int main(int argc, char* argv[])
{
    int i, count;
    printf("i\texit\n");
    for(i = 1; i < argc; i++)
    {
        count = 0;
        if (fork() == 0)
        {
            while(ms(argv[i])!= 0)
            {
                count++;
                sleep(1);
            }
            _exit(count);
        }
    }
    for(i = 1; i < argc; i++)
    {
        int status;
        wait(&status);
        if (WIFEXITED(status))
        {
            printf("%s\t%d\n", argv[i], WEXITSTATUS(status));
        }
    }
  return 0;
}
