.data
ind:	.word 0x10010000 

.text
	la $t0,ind #pointer
	li $t1,0x000000ff #blue color
	li $t2,0x00ff00ff #fuchsia color
	li $t3,0 #counter cols
	li $t4,0 #counter rows
	li $s0,64 #row size
	li $s1,32 #col size
	li $s2,28 #min bloack width
	li $s3,12 #min block height
	li $s4,36 #max block width
	li $s5,20 #max block height

very: 
	slt $t7,$t3,$s2 # want 0
	slt $t6,$t3,$s4 # want 1
	slt $t8,$t7,$t6 #will be 1
	
	slt $t5,$t4,$s3 #want 0
	slt $t6,$t4,$s5 #want 1
	slt $t9,$t5,$t6 #will be 1
	
	#bne $t8,$0,next
	and $t8,$t8,$t9
	beq $t8,1,colf
	#bne $t9,$0,colf


colb:
	sw $t1,0($t0)
	j draw
	#addi $t3,$t3,1
	#addi $t0,$t0,4
	#slt $t7,$t3,$s0
	#bne $t7,$0,very

row:
	addi $t4,$t4,1
	slt $t7,$t4,$s1
	bne $t7,$0,very

colf:
	sw $t2,0($t0)
	j draw
	#addi $t3,$t3,1
	#addi $t0,$t0,4
	#slt $t7,$t3,$s4
	#bne $t7,$0,colf
	#beq $t7,$0,colb

draw:
	addi $t3,$t3,1
	addi $t0,$t0,4
	slt $t7,$t3,$s0
	bne $t7,$0,very
	li $t3,0
	beq $t3,$0,row


	
