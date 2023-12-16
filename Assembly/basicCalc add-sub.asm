.data

prog : .asciiz "This program program written to mimic a very basic calculator\n\n"
author : .asciiz "JJ Javier\n\n"
date : .asciiz "02/07/23\n\n"
border : .asciiz "===========================================\n\n"
question : .asciiz "Input two numbers?\n\n"
sum : .asciiz "\nSum is:\t\t"
differ : .asciiz "\nDifference is:\t"

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

add $t0, $v0, $zero

li $v0, 5
syscall

add $t1, $v0, $zero

add $s1, $t0, $t1
sub $s2, $t0, $t1

li $v0, 4
la $a0, sum
syscall

li $v0, 1
add $a0, $s1, $zero
syscall

li $v0, 4
la $a0, differ
syscall

li $v0, 1
add $a0, $s2, $zero
syscall

li $v0, 10
syscall



