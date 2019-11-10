#include <unistd.h>   /*chamadas ao sistema: defs e decls essenciais*/
#include <fcntl.h>    /*O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdio.h>
#include <string.h>
#include "readln.h"

int     open(const char*path, int oflag ,...);
ssize_t read(int fildes, void* buf, size_t nbyte);
ssize_t write(int fildes, const void* buf, size_t nbyte);
int     close(int fildes);

int manager(char instruction[],char name[],char age[])
{
  int fp,n;
  char argv[16] = "new.bin";
  char *buf = (char*) malloc(sizeof(char)*256);
  char slash[1] = "\n";
  char space[1] = " ";
  //i=1;

  if(instruction[1] == 'i')
  {
    fp = open(argv,O_CREAT|O_WRONLY|O_APPEND,0600);//O_CREAT|O_WRONLY|O_APPEND|

    write(fp,name,strlen(name));
    write(fp,space,1);
    write(fp,age,strlen(age));
    write(fp,slash,1);

    close(fp);
  }
  else if (instruction[1] == 'u')
  {
    fp = open(argv,O_RDONLY,0600);
    while((n = readln(fp,buf,sizeof(buf))) > 0)
    {
      printf("%s\n",buf);
      if (strcmp(strtok(buf," "),name) == 0)
      {
        close(fp);

        fp = open(argv,O_WRONLY,0600);
        write(fp,name,strlen(name));
        write(fp,space,1);
        write(fp,age,strlen(age));
        write(fp,slash,1);
        close(fp);
        break;
      }
      //printf("printf2:%s\n",strtok(NULL," "));
    }

  }

  return 0;
}

int main(int argc,char* argv[])
{
  //argv[1] "-i" or "-u"
  //argv[2] "Mr.Smith"(Example)
  //argv[3] age-Ex: 50
  //"new.txt"(Example)

  manager(argv[1],argv[2],argv[3]);
  return 0;
}
