		.data

		.text
		.globl	inverte_array
inverte_array:
	li	$t3,0
	addi	$t4,$a1,-1
	mul	$t4,$t4,-4
	srl	$t5,$a1,1
	loop:
		addi	$a0,$a0,-4
		lw	$t1,0($a0)

		add	$a0,$a0,$t4
		lw	$t2,0($a0)
		sw	$t1,0($a0)

		mul	$t4,$t4,-1
		add	$a0,$a0,$t4
		sw	$t2,0($a0)

		mul	$t4,$t4,-1
		addi	$t4,$t4,8
		addi	$t3,$t3,1		
		bne	$t3,$t5,loop		

	jr	$ra
