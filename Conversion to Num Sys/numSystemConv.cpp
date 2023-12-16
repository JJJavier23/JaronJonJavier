#include <iostream>
#include <string>
#include "stack.h"
#include "/cs/slott/cs211/checkInput.h"

using namespace std;

char convertToChar(int n);
void convertRec(int n, int b);
int getBase();
void convertStack(int n, int b);

int main()
{
  int dec, base;
  cout << "Enter a number in base 10: ";
  dec = getData(1, 999999, "Enter a number between 1 and 999999.");
  base = getBase();
  cout << "---------- Using Recursion ----------" << endl;
  convertRec(dec, base);
  cout << endl;
  cout << "---------- Using Stack ----------" << endl;
  convertStack(dec, base);
  cout << endl;

  return 0;
}

//This function asks for a number system to which a decimal number is converted, either 2, 8 or 16. It rejects bad inputs other than 2, 8 or 16. It returns either 2, 8 or 16.
int getBase()
{
  int b;
  cout <<"Enter a base to convert the base 10 number to: ";
  cin >> b;
  if(b != 2 && b != 8 && b!= 16){
    do{
	cout << b << " is invalid. Enter 2, 8 or 16 only: ";
	cin >> b;
    }while(b != 2 && b != 8 && b!= 16);
  }
  return b;
}

//This is a recursive function to convert a decimal number to a different number system and print it. 
void convertRec(int n, int b)
{
  if(b == 2){
    if(n==0){
      return;
    }else{
      convertRec(n/b, b);
      cout << n%b;
    }
  }else if(b == 8){
    if(n==0){
      return;
    }else{
      convertRec(n/b, b);
      cout << n%b;
    }
  }else if(b == 16){
    if(n==0){
      return;
    }else{
      convertRec(n/b, b);
      cout << convertToChar(n%b);
    }
  }
}

//This function uses a stack to convert a decimal number to a different number system and prints it. This is not a recursive function. 
void convertStack(int n, int b)
{
  Stack s;
  if(b==2){
    while(n!=0){
      s.push(n%b);
      n = n/b;
    }
  }else if(b==8){
    while(n!=0){
      s.push(n%b);
      n = n/b;
    }
  }else if(b==16){
    while(n!=0){
      s.push(convertToChar(n%b));
      n = n/b;
    }
  }
  while(!s.isEmpty()){
    int e = s.topElem();
    convertToChar(e);
    cout << e;
    s.pop();  
  }
}

//This function receives an integer between 0 and 15 and returns the character.
char convertToChar(int n)
{
  if(n%16 > 9){
    return char(n%16+55);
  }else{
    return char(n+55);
  }
}
