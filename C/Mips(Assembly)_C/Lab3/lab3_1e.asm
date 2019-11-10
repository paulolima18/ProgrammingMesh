.data
end1:  .word 0xffff0010
end2:  .word 0xffff0011
chr:   .word 0x3f, 0x06, 0x5b, 0x4f,  0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71
chr1:   .word 0x06, 0x5b, 0x4f,  0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71

.text

main:
	la $s0,end1
	lw $s0,0($s0)
	la $s1,end2
	lw $s1,($s1)
	
	li $s2,10 #limit in the first
	
resetg:
	li $t0,0 #counter second
	la $t2,chr1
	lw $s5,0($t2)
	
reset1:
	sw $zero,0($s0)
	la $s6,chr
	lw $s4,0($s6)
	li $t1,0 #counter first 
loopr:
	beq $t1,$s2,loopl
	#beq $t0,$s2,resetg	
	
	sw $s4,0($s0)
	#sb $s5,0($s1)
	#addi $t0,$t0,1
	addi $t1,$t1,1
	addi $s6,$s6,4
	lw $s4,0($s6)
	#lb $s5,0($t2)
	j loopr
loopl:
	beq $t0,$s2,resetg
	sb $s5,0($s1)
	addi $t0,$t0,1
	lb $s5,0($t2)
	addi $t2,$t2,4
	j reset1