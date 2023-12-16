#include <iostream>
#include <string>
#include "lqueue.h"

using namespace std;

void createReverseLL(LQueue& l, const string& s);
void addLLs(LQueue& f, LQueue& s, LQueue& t);

int main()
{

  string n1, n2;

  cout << "Enter the first number: ";
  cin >> n1;
  cout << "Enter the second number: ";
  cin >> n2;

  LQueue l1, l2, total;
  createReverseLL(l1, n1);
  createReverseLL(l2, n2);
  addLLs(l1,l2,total);
  
  cout << n1 << '+' << n2 << '=';
  total.printAllReverse();
  cout << endl;
  cout << n1 << '+' << n2 << '=';
  total.displayAll();




  return 0;
}

void createReverseLL(LQueue& l, const string& s)
{
  node* e = new node; //new node to hold ints
  int t; //variable to hold the converted char to int
  for(int i = s.length()-1; i>-1;i--){ //converting char to int
    t = s[i] - '0';
    e->elem = t;
    l.addRear(t); //adding the int to rear
  }
}

void addLLs(LQueue& f, LQueue& s, LQueue& t)
{
  int sum; 
  int carry = 0;
  while(!f.isEmpty() && !s.isEmpty()){ //checking if both aren't empty to add them
    sum = f.deleteFront() + s.deleteFront() + carry; // getting the sum
    if(sum > 10){ 
      if(f.isEmpty() && s.isEmpty()){ //if it's empty then adding the last digits to the rear
	t.addRear(sum%10);
	t.addRear(sum/10);
      }else{ //if not empty then it carries over and adding the previous digit place into the queue
	carry = sum/10;
	t.addRear(sum%10);
      }
    }else{ //if one still has in queue
      if(carry>=10){ //if carry is over or equal to 10 then new carry for next int
	carry = carry/10;
	t.addRear(sum);
      }else if(carry < 10){ //if carry not over 10 then carry is 0
	carry = 0;
	t.addRear(sum);
      }
    }
  }
  if(!f.isEmpty()){ //if there is more place holders in the first then second then keep emptying the appropriate number
    while(!f.isEmpty()){ //going to clear the queue until none left
      int i = f.deleteFront()+carry;//getting the int value
    
      if(carry>0&&carry<=9){ //if carry is less than 10 then no more carry;
	carry = 0;
      }else if(carry>9){ //there is carry over
	carry = i/10;
	i = i + carry;
      }

      if(i<10){ //if the front value is less than 10 then add it right away
	t.addRear(i);
      }else if(f.isEmpty() && i==10){ //if 10 is the last value then add 0 and 1 to the queue
	t.addRear(0);
	t.addRear(1); 
      }else if(i==10){ //if it's 10 then add 0 and carry is 1;
	t.addRear(0);
	carry = 1;
      }else if(i>10){ //if it's greater than 10 then adding the mod of 10 and the it divided by 10
	t.addRear(i%10);
	t.addRear(i/10);
      }
    }
  }else if(!s.isEmpty()){ //if there is more place holders in the first then second then keep emptying the appropriate number
    while(!s.isEmpty()){ //same exact thing but if the second queue has more than the first
      int i = s.deleteFront()+carry;

      if(carry>0&&carry<=9){
        carry = 0;
      }else if(carry>9){
        carry = i/10;
        i = i + carry;
      }

      if(i<10){
        t.addRear(i);
      }else if(s.isEmpty() && i==10){
        t.addRear(0);
        t.addRear(1);
      }else if(i==10){
        t.addRear(0);
        carry = 1;
      }else if(i>10){
        t.addRear(i%10);
        t.addRear(i/10);
      }
    }    
  }
}
