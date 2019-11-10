#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main ()
{

  char **cena = (char**) malloc(sizeof(char)*100);
  cena[1] = "123\n";

  int fd = open ("pass.txt",O_RDONLY);
  dup2 (fd,0);

  char buf[128];
  int n = read (0,buf,128);
  close(fd);

  int r = strcmp(cena[1],buf);

  //printf("li: %s",buf);
  if ( r == 0)
  {
    fd = open ("lol.txt",O_WRONLY);
    dup2(fd,1);
    close(fd);

    printf("Correct Password: %s",cena[1]);
  }
  else
  {
    fd = open ("errors.txt",O_WRONLY);
    dup2 (fd,1);
    close(fd);

    printf("Wrong Password: %s\n",cena[1]);
    fprintf(stderr, "Wrong Password: %s\nRepeat\n",cena[1]);
  }

  return 0;
}
