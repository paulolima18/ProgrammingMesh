	.data
	
	.text
	.globl	conta_char

conta_char:
	
	addi	$t1,$0,0

	loop:
		lbu	$t0,($a0)
		beq	$t0,$a1,more
		addi	$a0,$a0,1
		beq	$t0,0,end
		jal	loop
	more:
		addi	$t1,$t1,1
		jal	loop
	end:
		add	$v0,$t1,$0	
		jr	$ra
