#include <stdio.h>
#include <stdlib.h>
//Collatz Conjecture in C
int main()
{
    collatz();
    return 0;
}
void collatz(){
    int num , i=0 ;
    printf("Collatz Conjecture\n");
    printf("Number: ");
    scanf("%d",&num);
    while(num!=1){
        if (num%2 == 0){
            num = num/2;
            printf("%d\n",num);
            i++;
        }
        else if (num%2 != 0){
            num = (3*num) +1;
            printf("%d\n",num);
            i++;
        }
    }
    printf("Steps: %d",i);
    return 0;
}
