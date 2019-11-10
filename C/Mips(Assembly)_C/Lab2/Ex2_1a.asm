.data 
ind: .word 0x10010000 #static data
.text
main:
	la $t0,ind 
	li $t1,0x00ffff00 #amarelo
	li $t2,0 #col
	li $t3,0 #rows
	li $s0,30
	li $s1,20

col:
	sw $t1,0($t0)
	addi $t0,$t0,4
	addi $t2,$t2,1
	slt $t4,$t2,$s0
	bne $t4,$0,col

row:
	li $t2,0
	addi $t0,$t0,136
	addi $t3,$t3,1
	slt $t4,$t3,$s1
	bne $t4,$0,col