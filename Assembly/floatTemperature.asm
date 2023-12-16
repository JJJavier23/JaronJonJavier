.data 

input: .asciiz "Please input a temperature in Celcius\n=> "

newTemp: .asciiz "The temperature in Fahrenheit is\n=> "

num: .float 0
num1: .float 9.0
num2: .float 5.0
num3: .float 32.0

.text

li $v0, 4
la $a0, input
syscall

li $v0, 6
syscall

l.s $f1, num1
l.s $f2, num2
l.s $f4, num3

div.s $f3, $f1, $f2

mul.s $f1, $f3, $f0,

add.s $f12, $f1, $f4

li $v0, 4
la $a0, newTemp
syscall

li $v0, 2
syscall