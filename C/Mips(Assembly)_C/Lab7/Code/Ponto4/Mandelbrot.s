	.data
	
	.text
	.globl	Mandelbrot
	
Mandelbrot:
	addi	$sp,$sp,-12
	sw	$ra,8($sp)
	add	$t0,$0,$a0
	
	lw	$a0,0($t0)
	sw	$a0,0($sp)
	#z0
	lw	$a1,4($t0)
	sw	$a1,4($sp)
	#n
	#jal	func	
	add	$v0,$0,$a0
	lw	$ra,8($sp)
	addi	$sp,$sp,12
	jr	$ra

func:
	#mul	$t1,$a0,$a0
	#z^2
	#add	$t2,$t1,$a0
	#bne	$a1,$0,func
	#addi	$a1,$a1,-1
	add	$v0,$0,$a0	
	jr $ra
