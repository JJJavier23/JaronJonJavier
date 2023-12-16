.data

prog: .asciiz "Program Description:\tPrint Output using Loop\n"
author: .asciiz "Author:\t\tJJ Javier\n"
date: .asciiz "Date:\t\t2/14/2023\n\n"
quest: .asciiz "How many numbers would you like to add together? "
sum: .asciiz "The sum of the numbers is "

.text

li $s0, 0 #implementing the start of the loop "int i = 0"
li $s2, 0 #the "sum "variable 

li $v0, 4
la $a0, prog
syscall
la $a0, author
syscall
la $a0, date
syscall
la $a0, quest
syscall

li $v0, 5
syscall

add $s1, $v0, $zero


loopDecision: beq $s0, $s1, exit #loop counter if 0 == 5 then go to exit

	li $v0, 5
	syscall #getting input 
	
	add $t0, $v0, $zero #adding input value to variable 
	
	blt $t0, $zero, loopDecision #checking if the int is negative, if negative go back to loop
	
	addi $s0, $s0, 1 #i++
	
	add $s2, $s2, $t0 #adding to the sum total

	j loopDecision #jumping back to the top of the loop

exit:  
	li $v0, 4 #when loop is done exit starts
	la $a0, sum 
	syscall
	
	li $v0, 1
	add $a0, $s2, $zero #outputting the total sum from the loop
	syscall
	
	li $v0, 10 #program end
	syscall
	



