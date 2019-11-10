	.data
lab_n:  .word  0x50,0x50, 0x72, 0x6f, 0x67, 0x72, 0x61, 0x6d, 0x61, 0x6e, 0x64, 0x6f, 0x20, 0x6E, 0x6f, 0x20, 0x4d, 0x49, 0x50, 0x53, 0x0d, 0x21
count:	.word 21
msgtexto: .asciiz "Arquitetura de Computadores 2017/2018"
separator: .asciiz "->"
          .text

main:
	la  $a0,msgtexto    # $a0 <- msgtexto
	jal print_string    # print it
	la	$a0,count
	lw	$t0,0($a0)
        
	li  $a0,0x0A       # $a0 <- '\n'
	jal print_char      # print it
        
	li	$t1,0					# to be used as a counter
	la	$a1, lab_n
loop:	

	lw	$t2,4 ($a1)
	move 	$a0,$t2
	jal     print_char      # print corresponding char
    
	 
#	la	$a0, separator
#	jal	print_string
	
		
#	move    $a0,$t2				# $a0 <- lab_n[i]  , i.e. offset=4*i
#	jal     print_int       # print value

#	la	$a0, separator
#	jal	print_string


#	li 	$a0,'('
#	jal     print_char      	
#        	move 	$a0,$t1		# print counter value
#	jal 	print_int			# call function
#	li 	$a0,')'
#	jal     print_char      # print it	
#	li 	$a0,'\n'
#	jal     print_char      # print it	

	addi 	$t1,$t1,1			# decrement counter
	addi	$a1,$a1,4
	blt	$t1,$t0,loop
	
finish:
	li      $v0, 10         # Exit the program
	syscall



# funcoes com chamadas ao sistema para imprimir inteiros, caracteres e strings
# (o argumento de entrada e' colocado em $a0 antes da chamada da funcao)

# print_int(int), $4 = $a0 = integer
print_int:
	li $v0,1
	syscall
	jr $ra

# print_char(char), $4 = $a0 = char
print_char:
	li $v0,11
	syscall
	jr $ra

		
# print_string(char *), $4 = $a0 = string
print_string:
	li $v0,4  
	syscall
	jr $ra

