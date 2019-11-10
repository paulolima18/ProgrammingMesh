.text
main: 
	li $v0,5
	syscall
	move $t9,$v0
	
	li $v0,5
	syscall
	move $k0,$v0
	
	move $s1,$t9
	move $s2,$k0
	
	sub $s3,$s1,$s2
	add $s4,$s2,$s3
	sub $s5,$s3,$s4
	add $s6,$s4,$s5
	sub $s7,$s5,$s6
	add $t8,$s6,$s7
 	