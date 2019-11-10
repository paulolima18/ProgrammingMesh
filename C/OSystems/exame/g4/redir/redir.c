#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
  int entrada,saida;
  int x = 1,y = 1,start=1;
  if (strcmp(argv[1],"-i") == 0)
  {
    x = 2;
    start = x+1;
    if (strcmp(argv[3],"-o") == 0)
    {
      y = 4;
      start = y+1;
    }
  }
  else if ((strcmp(argv[1],"-o")) == 0)
  {
    y = 2;
    start = y+1;
    if (strcmp(argv[3],"-i") == 0)
    {
      x = 4;
      start = x+1;
    }
  }
  if (x > 1)
  {
    entrada = open(argv[x],O_CREAT | O_RDONLY,0666);
    dup2(entrada,0);
    close(entrada);
  }
  if (y > 1)
  {
    saida = open(argv[y],O_CREAT | O_APPEND | O_WRONLY,0666);
    dup2(saida,1);
    close(saida);
  }
  execvp(argv[start],argv+start);
  perror("redir");
}


// |^^^^^^^^|
// <-------->
// |________|
//   ( || )
//    )  (
//   (O)(O)
//   \\  //
//     \/
//     ||
//     ||
//     ||
//     ||
//     ||
