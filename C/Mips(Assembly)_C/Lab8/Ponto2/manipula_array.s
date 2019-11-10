		.data

		.text
		.globl	manipula_array
manipula_array:

	addi	$t0,$0,0
	loop:
		lw	$t1,0($a0)	
		add	$t1,$t1,$t1
		sw	$t1,0($a0)	
		addi	$a0,$a0,4	
		addi	$t0,$t0,1
		bne	$t0,$a1,loop
	
	addi	$sp,$sp,-44
	sw	$ra,44($sp)
	jal	inverte_array
	lw	$ra,44($sp)
	addi	$sp,$sp,44
	jr	$ra
