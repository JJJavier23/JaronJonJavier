#ifndef STACK_H
#define STACK_H
#include <string>

using namespace std;

typedef char el_t;
const int MAX = 5;

class Stack
{

 private:
  el_t el[MAX];
  int top;
  void stackError(string msg)const;

 public:
  Stack();
  bool isEmpty()const;
  bool isFull()const;
  void push(el_t e);
  el_t pop();
  int topElem()const;
  void displayAll()const;
  void clearIt();

};
#endif
