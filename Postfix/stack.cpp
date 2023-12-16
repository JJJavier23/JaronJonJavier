#include "stack.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Stack::Stack()//declaring top -1 meaning there's nothing in the stack yet
{
  top = -1;
}

bool Stack::isEmpty()const //if top is -1 then stack is empty;return true else false
{
  return (top == -1)? true : false;
}

bool Stack::isFull()const//if top is MAX-1 then stack is full;return true else false
{
  return (top == MAX-1)? true : false;
}

void Stack::stackError(string msg)const//stack error is pushing when it's full or popping when it's empty
{
  cout << msg << endl;
  exit(1);
}


void Stack::push(el_t e)//adding a value to the stack
{
  if(isFull()){
    stackError("Error:Expression is too long.");
  }
  else{
    el[top+1] = e;
    top++;
  }
}

el_t Stack::pop()//removing a value in stack
{
  if(isEmpty()){
    stackError("Stack underflow");
  }else {
    top--;
    return el[top-1];
  }
}

int Stack::topElem()const//showing the top of the stack
{
  return el[top];
}

void Stack::displayAll()const//showing all of the stack from top to bottom
{
    for(int i = top; i > -1; i--){
      cout << el[i] << endl;
    }
}

void Stack::clearIt() //clearing the stack
{
    top = -1; 
}
