#include "readln.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
int main(int argc,char* argv[])
{
  int i;
  char id[16],life[16];

  for (i = 0;i < 1000;i++)
  {
    char string[128] = "Mr.Simpson";
    char file[32]="./person ";
    int age = i%65;

    sprintf(id,"%d",i);
    strcat(string,id);

    sprintf(life," %d",age);

    strcat(file,"-i ");
    strcat(file,string);
    strcat(file,life);
    printf("%s\n",file);
    
    system(file);
  }

  return 0;
}
