.data
inputnum: .space 2
title: .asciiz "Arquitetura De Computadores 2017/2018\n"

.text
main:
	la $a0,title
	jal print_string
	
	la $a0, inputnum
	li $a1, 2
	li $v0,8
	syscall
	
	li $t0,0
	
	la $a0,print_string
	jal print_string
	
	la $a0,finish
	jal finish
	
	
	
finish:
	li $v0,10
	syscall
	
print_int:
	la $v0, 1
	syscall
	jr $ra

print_string:
	la $v0, 4
	syscall
	jr $ra
