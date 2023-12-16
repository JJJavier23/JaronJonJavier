#ifndef LQUEUE_H
#define LQUEUE_H
#include <iostream>
using namespace std;

typedef char el_t;

struct node
{
  el_t elem;
  node* next;
};

class LL
{
 private:
  node* front;
  node* rear;
  int count;
  void queueError(string msg);

 public:
  LL();
  bool isEmpty();
  void addRear(el_t el);
  void displayAll();
  el_t deleteFront();
  ~LL();
  void addFront(el_t el);
  el_t deleteRear();
  LL(const LL& source);
  void deleteNode(el_t e);
  void deleteNodes(el_t e);
  void addInOrderAscend(el_t e);
  bool search(el_t e);
  void addInOrderDescend(el_t e);

};

#endif
