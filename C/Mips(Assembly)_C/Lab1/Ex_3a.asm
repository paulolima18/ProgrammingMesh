.text
main:
	li $v0,5
	syscall
	move $s1,$v0
	mul $s1,$s1,3
	li $t1,1
	
loop: 
	li $v0,1
	move $a0,$t1
	syscall
	addi $t1,$t1,1
	
	blt $t1,$s1,loop
	syscall
		

