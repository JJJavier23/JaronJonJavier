#ifndef LQUEUE_H
#define LQUEUE_H
#include <iostream>
using namespace std;

typedef int el_t;

struct node
{
  el_t elem;
  node* next;
};

class LQueue
{
 private:
  node* front;
  node* rear;
  int count;
  void queueError(string msg);
  void printAllReverse(node* p);

 public:
  LQueue();
  bool isEmpty();
  void addRear(el_t el);
  void displayAll();
  el_t deleteFront();
  ~LQueue();
  void printAllReverse();

};

#endif
