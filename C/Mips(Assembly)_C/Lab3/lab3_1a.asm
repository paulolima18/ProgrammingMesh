.data
end1: .word 0xffff0010

.text

main:
	la $s0,end1
	lw $s0,0($s0)
	li $s1,256

reset:
	li $t1,1
loop:
	beq $t1,$s1,reset
	sw $t1,0($s0)
	sll $t1,$t1,1
	j loop