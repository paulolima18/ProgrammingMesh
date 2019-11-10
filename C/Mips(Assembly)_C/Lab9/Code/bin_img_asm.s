# O cabeçalho da função bin_img_asm em C é
#
# void bin_img_asm(unsigned char *ptr, int w, int h);

#$a0 = ptr
#$a1 = w
#$a2 = h
	
	.data
	
	.text
	.globl	bin_img_asm
	.set 	noreorder
	
bin_img_asm:

	mult	$a1,$a2
	mflo	$t5
	lui 	$s0,0
	lui	$t4,0
	lui	$t0,0	#representa $t0=i i=0	
	loopa:
		slt	$t2,$t0,$t5		#i<h
		addi	$t0,$t0,1
		addiu	$t4,$t4,1

		lbu	$t3,0($a0)
		add	$s0,$s0,$t3		
		beq	$t2,1,loopa
		addi	$a0,$a0,1

	
	li	$t0,-1			#representa $t0=i i=0	
	addi	$t5,$zero,1
	sll	$t5,$t5,8
	addi	$t5,$t5,-1	
	divu	$s0,$s0,$t4
	mult	$t4,$t0
	mflo	$t4
	add	$a0,$a0,$t4
	#addi	$a0,$a0,-1


	loopi:

		addi	$t0,$t0,1
		slt	$t2,$t0,$a2	#i<h
		bne	$t2,1,fim
		lui	$t1,0		#representa $t1=j j=0

		loopj:

			slt	$t3,$t1,$a1
			lbu	$t4,0($a0)
			bne	$t3,1,loopi
			addi	$t1,$t1,1					

			slt	$t3,$t4,$s0
			beq	$t3,$zero,cond

			sb	$zero,0($a0)
			beq	$zero,$zero,loopj
			addi	$a0,$a0,1

			cond:
				sb	$t5,0($a0)
				beq	$zero,$zero,loopj
				addi	$a0,$a0,1

fim:
		jr	$ra
		sll	$zero,$zero,0	
