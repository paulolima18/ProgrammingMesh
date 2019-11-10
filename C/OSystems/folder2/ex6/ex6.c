#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int procuraRow(int v,int col,int l[col])
{
  int i,result=0;
  for (i = 0;!result && i < col;i++)
  {
    if (l[i] == v)
      result = 1;
  }
  return result;
}

int procura(int v,int row,int col,int m[row][col])
{
  int i,result = 0;
  for (i = 0; !result && i < row; i++)
  {
    if (!fork())
      _exit(procuraRow(v,col,m[i]));
  }
  for (i = 0; !result && i < row; i++)
  {
    int status;
    wait(&status);
    /*if (!WIFEXITED(status))
      result = -1;
      assert(WIFEXITED(status))*/
    if (WEXITSTATUS(status))
      result = 1;
  }
  return result;
}

int main(int argc,char* argv[])
{
  int m[2][2] = {{1,2},{10,3}};

  if (!procura(1,2,2,m))
    printf("0\n");
  else
    printf("1\n");

  return 0;
}
