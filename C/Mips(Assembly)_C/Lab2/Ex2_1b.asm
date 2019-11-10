.data
ind:	.word 0x10010000 #adress
.text
la $t0,ind #place address in register $t0
li $t3,0 #Starts $t3 with value 0 (col)
li $t4,0 #Starts $t4 with value 0 (row)
li $s0,64 #Starts $s0 with value 64(width)
li $s1,32 #Starts $s1 with value 32(height)
#1111 1111 | 1111 1111 | 1111 1111 | 1111 1111
col:
	sll $t6,$t3,10 #Place the value of $t6 in the hexadecimal equivalent for green
	sll $t5,$t4,18 #Place the value of $t5 in the hexadecimal equivalent for red
	add $t1,$t5,$t6 #"same"
	sw $t1,0($t0) #store value of $t1 inside $t0(puts the value(color) inside the adress of the pointer)
	addi $t3,$t3,1 #counter of col
	addi $t0,$t0,4 #pointer placement
	slt $t2,$t3,$s0 #condition (if $t3<$s0 then $t2 = 1)
	bne $t2,$0,col #if $t2!=0 goto:col
	
row:
	li $t3,0 #load $t3(col) at zero (reset)
	addi $t4,$t4,1 #counter for rows
	slt $t2,$t4,$s1 #condition (if $t4<$s1 then $t2 = 1)
	bne $t2,$0,col #if $t2!=0 goto:col


exit:
	li $v0,10
	syscall
