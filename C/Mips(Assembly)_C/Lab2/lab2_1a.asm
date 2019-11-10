#Yellow Square
.text
main:
	li $t0, 0x10010000 #load adress to $t0
	li $t1, 0x00ffff00 #load color yellow to $t1
	li $t3, 0 #load 0 to register $t3 (rows)
	li $t4, 0 #load 0 to register $t4 (col)
	li $s0, 30 #size rows
	li $s1, 20 #size col 
col:	
	sw $t1, 0($t0) #store yellow at $t0 adress
	addi $t0,$t0,4 #add 4(size of pixel)
	addi $t3,$t3,1 #counter of rows
	slt $t2,$t3,$s0 
	bne $t2,$0,col #if $t2!=0 goto:row
	
row:
	addi $t0,$t0,136 #move 128 pixels(next line)
	addi $t4,$t4,1
	li $t3,0
	slt $t2,$t4,$s1
	bne $t2,$0,col
			
exit: 
	li $v0, 10
	syscall	
