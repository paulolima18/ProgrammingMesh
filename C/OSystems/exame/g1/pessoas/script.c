#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define START 84000
int main(int argc,char*argv[])
{
  int count = 6000+START;
  for (int i = START; i < count; i++)
  {
    char command[32] = "./pessoa -i ";
    char name[32] = "Mr.Mosby";
    char age[3];
    int age_i = i%20;
    char size[8];
    char space[1] = " ";

    sprintf(age," %d",age_i);
    sprintf(size,"%d",i);

    //strcat(name, size);
    strcat(command, size);

    strcat(command, age);
    printf("%s\n",command);


    system(command);
  }
  return 0;
}
