.data

prog : .asciiz "This program program written to mimic a very basic calculator\n\n"
author : .asciiz "JJ Javier\n\n"
date : .asciiz "02/07/23\n\n"
border : .asciiz "===========================================\n\n"
question: .asciiz "Input two numbers\n\n"

prod: .asciiz "\nThe product is:\t\t"
quo: .asciiz "\nThe quotient is:\t"
remain: .asciiz "\nThe remainder is:\t"

.text

li $v0, 4
la $a0, border
syscall
la $a0, prog
syscall
la $a0, author
syscall
la $a0, date
syscall
la $a0, border
syscall
la $a0, question
syscall

li $v0, 5
syscall

add $s0, $v0, $zero

li $v0, 5
syscall

add $s1, $v0, $zero

mult $s0, $s1
mflo $t0
li $v0, 4
la $a0, prod
syscall

li $v0, 1
add $a0,$t0, $zero
syscall

div $s0, $s1
mfhi $t0
mflo $t1
li $v0, 4
la $a0, quo
syscall

li $v0, 1
add $a0, $t1, $zero
syscall

li $v0, 4
la $a0, remain
syscall

li $v0, 1
add $a0, $t0, $zero
syscall




