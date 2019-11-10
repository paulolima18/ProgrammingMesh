.data
end: .word 0xffff0010
chr: .word 0x3f, 0x06, 0x5b, 0x4f,  0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71
.text
main:
	la $s0,end
	lw $s0,0($s0)
	li $s1,16 #number of running numbers
	
reset:
	sw $zero,0($s0) 
	la $s2,chr
	lw $s3,0($s2)
	li $t1,0
	
loop:
	beq $t1,$s1,reset
	sw $s3,0($s0)
	addi $t1,$t1,1
	addi $s2,$s2,4
	lw $s3,0($s2)
	j loop