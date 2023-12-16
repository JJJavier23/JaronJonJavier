.data

array: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
error1: .asciiz "\n***ERROR "
error2: .asciiz " is not valid.\n"
how: .asciiz "How many elements would you like to fill? "
total: .asciiz "The total is : "

.text

la $s0, array #$s0 holds the array

top: li $v0, 4
	la $a0, how
	syscall
	
	li $v0, 5
	syscall
	
	blt $v0, 2, range
	bgt $v0, 10, range
	
	add $a1, $v0, $0
	add $a2, $s0, $0
	
	jal fillArraySetup
	
	li $v0, 4
	la $a0, total
	syscall
	
	li $v0, 1
	add $a0, $t4, $0
	syscall

fillArraySetup: add $t1, $a2, $0 #array
		add $t2, $a1, $0 #n
		add $t3, $a1, $0, #extra n variable
		
		j fillArray
		
fillArray: beq $t2, $0, doneFill
	   
	   li $v0, 5
	   syscall
	   
	   sw $v0, 0($t1)
	   
	   addi $t1, $t1, 4
	   addi $t2, $t2, -1
	   
	   j fillArray
	   
doneFill: addi $sp, $sp, -4
      sw $ra, 0($sp)
      
      add $a1, $s0, $0
      add $a2, $t3, $0
      
      jal AddElementsSetup
      
      lw $ra, 0($sp)
      addi $sp, $sp, 4
      
      jr $ra

AddElementsSetup: add $t1, $a1, $0 #array
		  add $t2, $a2, $0 #n 
		  li $t4, 0
		  j AddElements

AddElements: beq $t2, $t0, done
	     
	     lw $t3, 0($t1)
	     
	     add $t4, $t4, $t3
	     
	     addi $t1, $t1, 4
	     addi $t2, $t2, -1
	     
	     j AddElements

done: jr $ra
	     
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