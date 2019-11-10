#include<stdio.h>

int conta_char(char *ptr, char letra);

int main ( )
{
	char str[]="Arquitetura de Computadores0";
	char letra='u';
	
	printf("O caracter %c aparece %d vezes \n",letra,conta_char(str,letra));
}

/*
int conta_char(char *ptr,char letra){
	int i  = 0,sum=0;	
	while(*(ptr+i) != '\0'){
		if(letra == *(ptr+i)) sum++;		
		i++;
	}
	return sum;
}*/
