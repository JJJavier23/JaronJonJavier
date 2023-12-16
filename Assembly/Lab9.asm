.data

myArray: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 
how: .asciiz "How many elements: "
too: .asciiz "Too many elements!!!\n"
low: .asciiz "Not enough elements!!!\n"
colon: .asciiz ":\t"
largest: .asciiz "The largest element is: "

.text

la $s1, myArray
li $t3, 1

Loop: li $v0, 4
	la $a0, how
	syscall
	
	li $v0, 5
	syscall

	add $t0, $v0, $zero
	
	bgt $t0, 10, arrayCountHigh
	blt $t0, 0, arrayCountLow
	
	j Ready1
	

Ready1: beq $t0, $zero, After
	
	li $v0, 1
	add $a0, $t3, $zero
	syscall

	li $v0, 4
	la $a0, colon
	syscall
	
	li $v0, 5
	syscall
	
	sw $v0, 0($s1)
	
	addi $s1, $s1, 4
	
	addi $t0, $t0, -1
	
	addi $t3, $t3, 1
	
	j Ready1
	
After: 	li $t0, 0
	la $s2, myArray
	lw $s3, 0($s2)	
	

	
	j Ready2
	
Ready2: beq $t0, $t4, done
	lw $s4, 0($s2)
	bgt $s4, $s3, replace
	addi $t0, $t0, 1
	addi $s2, $s2, 4
	
	j Ready2



replace: 
	add $s3, $s4,  $zero
	j Ready2

arrayCountHigh: li $v0, 4
		la $a0, too
		syscall
	
		j Loop
		
arrayCountLow: li $v0, 4
		la $a0, low
		syscall
		
		j Loop

done: li $v0, 4
	la $a0, largest
	syscall
	
	li $v0, 1
	add $a0, $s3, $zero
	syscall
	
	li $v0, 10
	syscall
	
		


