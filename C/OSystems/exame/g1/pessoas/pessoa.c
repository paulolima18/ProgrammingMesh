#include "../readln/readln.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#define MAX 1024

void comand(char flag[], char name[], char age[])
{
  int fd;
  char newline[1] = "\n",space[1] = " ";
  int n;

  if(strcmp(flag,"-i") == 0)
  {
    fd = open("file.bin",O_CREAT|O_RDWR|O_APPEND,0666);
    write(fd,name,strlen(name));
    write(fd,space,1);
    write(fd,age,strlen(age));
    write(fd,newline,1);
  }
  else if (strcmp(flag,"-u") == 0)
  {
    char buffer[64];
    fd = open("file.bin",O_RDWR);
    while((n = readln(fd, buffer,MAX)) > 0)
    {
      strtok(buffer," ");
      if (strcmp(buffer,name) == 0)
      {
        close(fd);
        fd = open("file.bin",O_WRONLY);
        write(fd,name,strlen(name));
        write(fd,space,1);
        write(fd,age,strlen(age));
        write(fd,newline,1);
        break;
      }
    }
  }
  close(fd);
}

int main(int argc,char* argv[])
{
  comand(argv[1],argv[2],argv[3]);
  return 0;
}
