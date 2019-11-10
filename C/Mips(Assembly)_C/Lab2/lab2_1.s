.data
li $t0, 0x10010000
li $t1, 0x00ffff00
	
.text


row:
	sw $t1, 0($t0)
	addi $t0,$t0,4

col:
		
exit: 
	li $v0, 10
	syscall	