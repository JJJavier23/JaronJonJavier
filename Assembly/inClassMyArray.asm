.data

MyArray: .word 0, 0, 0, 0, 0 #declaring an array with 5 elements; word for int; same at int myArray[5] = {0, 0, 0, 0, 0}

.text

la $s1, MyArray #storing pointer into register
li $s0, 5

inloop:	beq $s0, $zero, next

	li $v0, 5
	syscall

	sw $v0, 0($s1)

	addi $s1, $s1, 4 #adding 4 bytes to move the pointer to the next element

	addi $s0, $s0, -1

	j inloop

next:



la $s1, MyArray #reset pointer
li $s0, 5 #update loop counter

outloop: beq $s0, $zero, done
	lw $a0, 0($s1)
	li $v0, 1
	syscall
	
	addi $s1, $s1, 4 #adding 4 bytes to move the pointer to the next element

	addi $s0, $s0, -1
	
	j outloop
	
done: li $v0, 10
	syscall	