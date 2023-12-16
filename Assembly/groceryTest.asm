.data

FillPrice: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 #array for item prices - at most 20
FillCoupon: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 #array for coupon prices - at most 20

num_item: .asciiz "Please enter the amount of items you're purchasing:\t" #asking user for # of items purchasing

many_items: .asciiz "Sorry! Too many items to purchase!!\n" #too and low used for checking if # of items are less than 2 or greater than 20
low_items: .asciiz "Sorry! Not enough items to purchase!!\n" 

border: .asciiz "=====================================================\n" #self explanitory border

price_items: .asciiz "Please enter the price of item " #asking user to input the price of the items in order
colon: .asciiz ":\t" #use of colong between item number and price of item user inputs 

num_coupons: .asciiz "Please enter the number of coupons that you want to use.\n" #asking user for # of coupons

many_coupons: .asciiz "Too many Coupons!! Please enter the number of coupons that you want to use.\n" #if coupons > items

price_coupon: .asciiz "Please enter the amount of coupon " #loop of coupons counting up
#insert colon here

unacceptable: .asciiz "This coupon is not acceptable\n" #if coupon is more than item price of exceeds $10

total: .asciiz "Your total charge is:\t$"
thankyou: .asciiz "\nThank you for shopping with us."

.text

#pt 1
itemStart: li $v0, 4
      la $a0, num_item
      syscall
       
      li $v0, 5
      syscall
       
      add $t0, $v0, $zero #$t0 stores the number of items the user wants to purchase
      
      blt $t0, 0, lowItems
      bgt $t0, 20, manyItems
      
      add $a1, $t0, $zero #adding to argrument resgister for function purpose
      
      jal FillPriceArray
      
      li $v0, 4
      la $a0, border
      syscall
      
      j couponStart
      
couponStart: li $v0, 4
             la $a0, num_coupons
             syscall
             
             li $v0, 5
             syscall
             
             add $t1, $v0, $zero
             
             bgt $t1, $t0, manyCoupons            
             
             add $a1, $t1, $zero #passing to argument registere to use for function
             
             jal FillCouponArray
             
             j calculate

calculate: sub $t4, $t5, $t6

	   j Total
      

FillPriceArray: la $s0, FillPrice #set $s0 to array
		li $t1, 1 #counting indicator from 1-the user input
		
		li $v0, 4
		la $a0, border
		syscall
		
		j FillPrices
		
FillPrices: beq $a1, $zero, doneItem
	   
	   li $v0, 4
	   la $a0, price_items
	   syscall
	   
	   li $v0, 1
	   add $a0, $t1, $zero
	   syscall
	   
	   li $v0, 4
	   la $a0, colon
	   syscall
	   
	   li $v0, 5
	   syscall
	   
	   sw $v0, 0($s0)
	   
	   add $t5, $t5, $v0
	   
	   addi $s0, $s0, 4 #next indext in array++
	   addi $a1, $a1, -1 #decreasing loop--
	   addi $t1, $t1, 1 #item indicator++
	   
	   j FillPrices

doneItem: jr $ra

FillCouponArray: la $s1, FillCoupon
		 li $t1, 1
		 la $s2, FillPrice
		 
		 j FillCoupons
		 
FillCoupons: beq $a1, $zero, couponDone
	    
	    li $v0, 4
	    la $a0, price_coupon
	    syscall
	    
	    li $v0, 1
	    add $a0, $t1, $zero
	    syscall
	    
	    li $v0, 4
	    la $a0, colon
	    syscall
	    
	    li $v0, 5
	    syscall
	    
	    add $t3, $v0, $zero
	    
	    lw $t2, 0($s2)
	    
	    bgt $t3, 10, toZero
	    bgt $t3, $t2, toZero
	    
	    j storing
	    
storing:    sw $t3, 0($s1)
	    
	    add $t6, $t6, $t3
	    
	    addi $s1, $s1, 4
	    addi $s2, $s2, 4
	    addi $a1, $a1, -1
	    addi $t1, $t1, 1
	    
	    j FillCoupons

toZero: sub $t3, $t3, $t3
	
	li $v0, 4
	la $a0, unacceptable
	syscall
	
	j storing

couponDone: jr $ra

Total: li $v0, 4
       la $a0, border
       syscall

       la $a0, total
       syscall
       
       li $v0, 1
       add $a0, $t4, $zero
       syscall
       
       li $v0, 4
       la $a0, thankyou
       syscall
       
       li $v0, 10
       syscall
	   
manyItems: li $v0, 4
	   la $a0, many_items
	   syscall
	   
	   j itemStart
	   
lowItems:  li $v0, 4
	   la $a0, low_items
	   syscall
	   
	   j itemStart

manyCoupons: li $v0, 4
	     la $a0, many_coupons
	     syscall
	     
	     j couponStart
	   
