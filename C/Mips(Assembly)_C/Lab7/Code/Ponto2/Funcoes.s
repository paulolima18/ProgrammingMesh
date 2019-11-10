	.data
	
	.text
	.globl	max
	.globl	min
	

max:
	slt $t1,$a0,$a1 #a0 > a1 == 0
	bne $t1,$0,m1
	add $v0,$0,$a0
	slt $t1,$v0,$a2
	bne $t1,$0,m2
	slt $t1,$v0,$a3
	bne $t1,$0,m3
	jr $ra	
	j min
		s1:
			slt $t1,$v0,$a2
			bne $t1,$0,m2
		s2:
			slt $t1,$v0,$a3
			bne $t1,$0,m3
		s3:
			jr $ra

min:
	slt $t1,$a0,$a1 #a0 > a1 == 0
	beq $t1,$0,m4
	add $v0,$0,$a0
	slt $t1,$v0,$a2
	beq $t1,$0,m5
	slt $t1,$v0,$a3
	beq $t1,$0,m6
	jr $ra
	j end
		s4:
			slt $t1,$v0,$a2
			beq $t1,$0,m5
		s5:
			slt $t1,$v0,$a3
			beq $t1,$0,m6
		s6:
			jr  $ra
	j end

m1:
	add $v0,$0,$a1
	j s1
m2:
	add $v0,$0,$a2
	j s2
m3:
	add $v0,$0,$a3
	j s3
m4:
	add $v0,$0,$a1
	j s4
m5:
	add $v0,$0,$a2
	j s5
m6:
	add $v0,$0,$a3
	j s6
end:
