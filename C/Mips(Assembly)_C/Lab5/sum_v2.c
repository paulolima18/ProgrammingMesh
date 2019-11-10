#include <stdio.h>

int soma(int a, int b){
  return a+b;
};

int main(){
  int a,b,c;

  printf("Enter the first number: ");
  scanf("%d",&a);
  printf("Enter the second number: ");
  scanf("%d",&b);

  c=soma(a,b);

  printf("The sum of %d with %d is %d \n",a,b,c);
}
