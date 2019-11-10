	.data
	.text
	.globl	manipula_array

manipula_array:
	
	addi	$t0,$zero,-1
	addi	$t2,$zero,2
	loop:

		addi	$t0,$t0,1
		beq	$t0,$a1,end
		
		lw	$t1,0($a0)
		addi	$t3,$t1,0
		div	$t3,$t2
		mfhi	$t3
		beq	$t3,$zero,next
		

		addi	$t1,$zero,1
		sw	$t1,0($a0)
		addi	$a0,$a0,4
		j	loop	
		next:
			sw	$zero,0($a0)
			addi	$a0,$a0,4
			j	loop
									


	
end:
	jr	$ra
