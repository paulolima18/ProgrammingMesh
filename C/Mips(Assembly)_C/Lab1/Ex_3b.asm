.text #Factorial
main:
	li $v0,5 #instruction (call integer)
	syscall
	move $s1,$v0 #place content of $v0 in $s1
	move $t1,$s1 #"               "$s1 in $t1
	li $t2,1 #Puts $t2 with value 1
loop: 
	mul $t2,$t1,$t2 #multiply $t2 by itself and the value of $t1
	addi $t1,$t1,-1 #Decrease by 1 $t1 value
	bne $t1,$0,loop #when different than 0 run the loop
	
print:	
	li $v0,1
	move $a0,$t2
	syscall

