#include <stdio.h>

void manipula_array(int *ptr, int dim);

int main()
{
	int i;	
	int dim=10;
	int array[]={1,2,3,4,5,6,7,8,9,10}; 

	printf("Array original: ");
	for(i=0;i<9;i++){
		printf("%d -> ",array[i]);
	}
	printf("%d \n",array[9]);
	
	manipula_array(array,dim);
	
	printf("Array manipulado e invertido: ");
	for(i=0;i<9;i++){
		printf("%d -> ",array[i]);
	}
	printf("%d",array[9]);
	printf("\n");
return 0;
}
/*
		.data

		.text
		.globl	inverte_array
inverte_array:
	li	$t3,0
	addi	$t4,$a1,-1
	mul	$t4,$t4,-4
	srl	$t5,$a1,1
	loop:
		addi	$a0,$a0,-4
		lw	$t1,0($a0)

		add	$a0,$a0,$t4
		lw	$t2,0($a0)
		sw	$t1,0($a0)

		mul	$t4,$t4,-1
		add	$a0,$a0,$t4
		sw	$t2,0($a0)

		mul	$t4,$t4,-1
		addi	$t4,$t4,8
		addi	$t3,$t3,1		
		bne	$t3,$t5,loop		

	jr	$ra*/
