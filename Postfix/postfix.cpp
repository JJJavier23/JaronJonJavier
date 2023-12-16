#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

bool isOperand(char c);//checking if the char is an operand
int charToInt(char c);//converting the char into the int datatype
bool isOperator(char c);//checking if the char is an operator 
int doMath(int and1, char tor, int and2);//switching between +,-,*,/ depending on the case

int main()
{
  Stack s; //declaring the stack
  string expr;//getting to get expression inputs
  cin >> expr;//input
  cout << endl;
  int len = expr.length();//getting length for the for loop to count each char

  for(int i = 0; i<len; i++){ //to go through each char in the expr
    char c = expr[i];//declaring c as the char of the index i
    if(isOperand(c)){ //checking if operand
      s.push(charToInt(c)); //if operand then pushing in stack
    }else if(isOperator(c)){//checking if operator
      if(s.isEmpty()){//checkin if stack is empty
	cout <<  "Error: Not enough operands." << endl; //if empty then not enough operands to calculate
	i = len; //exiting loop
      }
      int n1 = s.topElem(); //if there's enough operands, setting variable to the value
      charToInt(n1);//converting char to int
      s.pop();//then popping top
      if(s.isEmpty()){//checking to see if the stack is empty
	cout <<  "Error: Not enough operands." << endl;//if empty then not enough operands to calculate
	i = len;//exiting loop
      }
      int n2 = s.topElem();//if enough operands, setting second variable to the value
      s.pop();//popping
      charToInt(n2);//converting char to inr
      s.push(doMath(n1, c, n2));//pushing the calculated value based on the operands and operator
    }else{
      cout << "Error: Invalid item was found."<<endl;//if it was not an operator or operand then it was an invalid item
      return 0;//ending program if invalid
    }
  }
//loop finished getting final result
  int f = s.topElem();//setting variable f to the final result
  s.pop();//popping
  if(!s.isEmpty()){//if there's still value in the stack then there was too many operands
    cout <<  "Error: Too many operands." << endl;
    return 0;//ending program
  }

  cout <<" = " <<f << endl; //displaying the final calculation; the postfix

  return 0; //ending program
}

bool isOperand(char c)
{
  return c>='0' && c<='9'; //if the char is 0-9 then return the char
}

int charToInt(char c)
{
  int i = c - '0'; //c-'0' will give the int value of the char 
  return i;
}

bool isOperator(char c)
{
  return c=='+' || c=='-' || c=='*' || c=='/'; //checking if +,-,*,/ and returning
}

int doMath(int and1, char tor, int and2)
{
  int answer;
  switch(tor){
  case '+':
    answer = and1+and2; //if + then adding 
    break;
  case '-':
    answer = and1-and2;//if - then subtracting
    break;
  case '*':
    answer = and1*and2;//if * then multiplying
    break;
  case '/':
    answer = and1/and2; //if / then diving 
    break;
  }
  return answer; //returning the answer
}
