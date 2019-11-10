#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char*argv[])
{
  int i = 0,size=0;
  argv[1][strlen(argv[1])] = '\0';
  for(int j = 0;argv[1][j];j++)
  {
    if (argv[1][j] == ' ') size ++;
  }
  char* arg[size];
  arg[i++] = strtok(argv[1], " ");

  while((arg[i++] = strtok(NULL, " ")) != NULL) {}

  if(!fork()) execvp(arg[0],arg);
  else {wait(0);}
}
