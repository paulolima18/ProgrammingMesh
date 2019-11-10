#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int procura_row(int col, int look, int row[])
{
  int result = 0;
  for (int i = 0; i < col; i++)
  {
    if(row[i] == look)
    {
      result = 1;
      break;
    }
  }
  return result;
}

void procura_matriz(int row, int col, int look, int matriz[row][col])
{
  int i;
  for(i = 0;i<row;i++)
  {
    if(!fork())
    {
      _exit(procura_row(col, look, matriz[i]));
    }
  }
  for ( i = 0; i < row; i++)
  {
    int pid,status;
    pid = wait(&status);
    if(WEXITSTATUS(status))
    {
      printf("Row:%d | Status: %d\n",i,WEXITSTATUS(status));
    }
  }
}

int main(int argc, char*argv[])
{
  int row = 2, col = 2;
  int m[2][2] = {{1,1},{10,1}};
  procura_matriz(row, col, atoi(argv[1]), m);
  return 0;
}
