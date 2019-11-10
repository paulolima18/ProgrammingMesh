	.file	1 "bin_img_c.c"
	.section .mdebug.abi32
	.previous
	.gnu_attribute 4, 1
	.abicalls
	.option	pic0
	.text
	.align	2
	.globl	bin_img_c
	.set	nomips16
	.ent	bin_img_asm
	.type	bin_img_asm, @function
bin_img_asm:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	blez	$6,$L17
	move	$9,$4

	move	$11,$0
	move	$2,$0
	move	$7,$0
	addiu	$10,$5,-1
$L3:
	blez	$5,$L6
	nop

	move	$3,$0
$L4:
	addu	$8,$9,$3
	lbu	$8,0($8)
	addiu	$3,$3,1
	bne	$3,$5,$L4
	addu	$7,$7,$8

	addiu	$2,$2,1
	addu	$2,$2,$10
$L6:
	addiu	$11,$11,1
	bne	$11,$6,$L3
	addu	$9,$9,$5

	div	$0,$7,$2
	teq	$2,$0,7
	move	$2,$0
	mflo	$10
$L7:
	blez	$5,$L10
	nop

	move	$3,$4
	move	$7,$0
$L9:
	lbu	$9,0($3)
	slt	$9,$9,$10
	bne	$9,$0,$L8
	move	$8,$0

	li	$8,255			# 0xff
$L8:
	addiu	$7,$7,1
	sb	$8,0($3)
	bne	$7,$5,$L9
	addiu	$3,$3,1

$L10:
	addiu	$2,$2,1
	bne	$2,$6,$L7
	addu	$4,$4,$5

$L17:
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	bin_img_c
	.size	bin_img_c, .-bin_img_c
	.ident	"GCC: (Debian 4.6.3-14) 4.6.3"
