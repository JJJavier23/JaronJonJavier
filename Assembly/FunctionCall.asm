.data

base: .asciiz "What would you like the base number to be? "
ex: .asciiz "What would you like the power exponent to be? "
total: .asciiz "\n\nThe total is "
error1: .asciiz "\n***ERROR "
error2: .asciiz " is not valid.\n"

.text

li $t6, 1
prep:   li $v0, 4
	la $a0, base
	syscall

	li $v0, 5
	syscall
	
	blt $v0, 0, range
	bgt $v0, 12, range
	
	add $s0, $v0, $0
	
	li $v0, 4
	la $a0, ex
	syscall
	
	li $v0, 5
	syscall	
		
	blt $v0, 0, range
	bgt $v0, 12, range
	
	add $s1, $v0, $0
	
	j before

before: add $a1, $s0, $0
	add $a2, $s1, $0
	
	jal function
	
	j exit

function:add $t3, $a1, $0
	add $t5, $a1, $0
	 add $t2, $a2, $0
	 j expon
	 
expon: beq $t6, $t2, done
	
	mult $t3, $t5
	mflo $t1
	
	li $t3, 0
	add $t3, $t1, $t0
	
	addi $t6, $t6, 1
	
	j expon
	
done: 	add $v1, $t3, $0
	jr $ra

exit: add $s2, $v1, $0

	li $v0, 4
	la $a0, total
	syscall
	
	li $v0, 1
	add $a0, $s2, $0
	syscall

	li $v0, 10
	syscall

range: li $v0, 4
	la $a0, error1
	syscall
	
	li $v0, 1
	add $a0, $v0, $zero
	syscall
	
	li $v0, 4
	la $a0, error2
	syscall
	
	j prep