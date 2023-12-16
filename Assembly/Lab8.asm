.data

MyArray: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 #declaring an array with 5 elements; word for int; same at int myArray[5] = {0, 0, 0, 0, 0}
quest: .asciiz "How many elements would you like to enter?\t"
error1: .asciiz "\nERROR "
error2: .asciiz "not valid. Try again.\n"
space: .asciiz "\n"
enter: .asciiz "Enter number "
colon: .asciiz ":     \t"
reverse: .asciiz "The content of array in reverse order\n"

.text

la $s1, MyArray #storing pointer into register

li $v0, 4
la $a0, quest
syscall

again :li $v0, 5
	syscall

	blt $v0, $zero, range1
	bgt $v0, 10, range1

	add $s0, $v0, $zero
	add $s2, $v0, $zero

	li $t1, 1

inloop:	beq $s0, $zero, next

	li $v0, 4
	la $a0, enter
	syscall
	
	li $v0, 1
	add $a0, $t1, $zero
	syscall
	
	li $v0, 4
	la $a0, colon
	syscall
	
	li $v0, 5
	syscall
	
	blt $v0, $zero, range

	sw $v0, 0($s1)

	addi $s1, $s1, 4 #adding 4 bytes to move the pointer to the next element

	addi $s0, $s0, -1
	
	addi $t1, $t1, 1

	j inloop

next:

li $v0, 4
la $a0, space
syscall

la $a0, reverse
syscall

la $a0, space
syscall

addi $s1, $s1, -4
outloop: beq $s0, $s2, done

	lw $a0, 0($s1)
	li $v0, 1
	syscall
	
	li $v0, 4
	la $a0, space
	syscall
	
	addi $s1, $s1, -4 #adding 4 bytes to move the pointer to the next element

	addi $s0, $s0, 1
	
	j outloop

range1: li $v0, 4
	la $a0, error1
	syscall
	
	li $v0, 4
	la $a0, error2
	syscall
	
	j again
	
range: li $v0, 4
	la $a0, error1
	syscall
	
	li $v0, 4
	la $a0, error2
	syscall
	
	j inloop
	
done: li $v0, 10
	syscall	
