		.data

		.text
		.globl	programa
programa:

	addi	$sp,$sp,-24
	sw 	$ra,20($sp)
	add	$t0,$0,$a0
	#elem1
	lw	$a0,0($t0)
	sw	$a0,0($sp)
	#elem2
	lw	$a1,4($t0)
	sw	$a1,4($sp)
	#elem3	
	lw	$a2,8($t0)
	sw	$a2,8($sp)
	#elem4	
	lw	$a3,12($t0)
	sw	$a3,12($sp)
	#elem5	
	lw	$t1,16($t0)
	sw	$t1,16($sp)
	jal	policalc
	lw	$ra,20($sp)
	addi	$sp,$sp,24
	jr	$ra


policalc:
	add	$t2,$a0,$a1
	mul	$t2,$t2,5
	#5(x1+x2)
	mul	$t3,$t1,$a3
	mul	$t3,$t3,3
	#(3 x5 x4)
	sub	$t3,$a2,$t3
	#(x2-ans)
	mul	$t2,$t2,$t3
	add	$v0,$0,$t2
	jr	$ra
