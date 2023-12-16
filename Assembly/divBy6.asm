.data

quest: .asciiz "How many positive numbers that are divisible by 6 do you want to add?\n"
enter: .asciiz "Enter a number: "
arrow: .asciiz "==> "
is: .asciiz " is divisible by "
error1: .asciiz "**** ERROR: "
error2: .asciiz " is not a positive number. Enter another number.\n"
total: .asciiz "The sum of the positive numbers between 1 and 100 that are divisible by 6 is: "
rng: .asciiz " is not in the range of 1 to 100. Enter another number.\n"
ndiv: .asciiz " is not divisible by 6. Enter another number.\n"
endl: .asciiz "\n"

.text

li $s0, 0
li $s2, 6

li $v0, 4
la $a0, quest
syscall

li $v0, 5
syscall

add $s1, $v0, $zero

Loop: beq $s0, $s1, Stop


li $v0, 4
la $a0, enter
syscall

li $v0, 5
syscall

add $t0, $v0, $zero

blt $t0, $zero, negative
blt $t0, 1, range
bgt $t0, 100, range

div $t0, $s2
mfhi $t1

li $v0, 1
add $a0, $t1, $zero
syscall

bne $t1, $zero, notd

li $v0, 4
la $a0, arrow
syscall

li $v0, 1
add $a0, $t0, $zero
syscall

li $v0, 4
la $a0, is
syscall

li $v0, 1
add $a0, $s2, $zero
syscall

li $v0, 4
la $a0, endl
syscall

add $t2, $t2, $t0

addi $s0, $s0, 1

j Loop

range: li $v0, 4
	la $a0, error1
	syscall
	
	li $v0, 1
	add $a0, $t0, $zero
	syscall

	
	li $v0, 4
	la $a0, rng
	syscall
	
	j Loop
	



notd: li $v0, 4
	la $a0, error1
	syscall
	
	li $v0, 1
	add $a0, $t0, $zero
	syscall

	li $v0, 4
	la $a0, ndiv
	syscall
	
	j Loop
	



negative: li $v0, 4
	la $a0, error1
	syscall
	
	li $v0, 1
	add $a0, $t0, $zero
	syscall
	
	li $v0, 4
	la $a0, error2
	syscall 
	
	j Loop

Stop: li $v0, 4
	la $a0, total
	syscall
	
	li $v0, 1
	add $a0, $t2, $zero
	syscall
	
	li $v0, 10
	syscall
