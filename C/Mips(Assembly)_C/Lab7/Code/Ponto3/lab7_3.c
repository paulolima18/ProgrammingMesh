#include <stdio.h>

int programa(int*);

int main()
{
	int vec[5]={4, 2, 10, 1, 6};
	int f;
	
	f=programa(vec);
	
	// Imprimir Resultados Calculados em Assembly e em C
	printf("Resultado Calculado na Funcao Assembly: %d\n",f);
	printf("Resultado Calculado em C: %d\n",5*(vec[0]+vec[1])*(vec[2]-3*vec[3]*vec[4]));
}
