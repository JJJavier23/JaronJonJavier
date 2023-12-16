.data

base: .asciiz "What would you like the base number to be? "
ex: .asciiz "What would you like the power exponent to be? "
total: .asciiz "\n\nThe total is "
error1: .asciiz "\n***ERROR "
error2: .asciiz " is not valid.\n"


.text

top: li $s0, 1

	li $v0, 4
	la $a0, base
	syscall

	li $v0, 5
	syscall
	
	blt $v0, 0, range
	bgt $v0, 12, range

	add $t2, $v0, $zero
	add $t4, $v0, $zero

	li $v0, 4
	la $a0, ex
	syscall

	li $v0, 5
	syscall

	blt $v0, 0, range
	bgt $v0, 12, range

	add $t3, $v0, $zero
	
	j expo

range: li $v0, 4
	la $a0, error1
	syscall
	
	li $v0, 1
	add $a0, $v0, $zero
	syscall
	
	li $v0, 4
	la $a0, error2
	syscall
	
	j top

expo: beq $t3, $zero, expo2
	beq $s0, $t3, exit
	mult $t2, $t4
	mflo $t1
	li $t2, 0
	add $t2, $t1, $zero
	
	addi $s0, $s0, 1
	
	j expo

expo2: li $t2, 1
	j exit

exit: li $v0, 4
	la $a0, total
	syscall
	
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	
	li $v0, 10
	syscall
	



