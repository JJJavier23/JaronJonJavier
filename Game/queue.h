#ifndef QUEUE_H
#define QUEUE_H
#include <string>
using namespace std;

const int QUEUE_SIZE = 10; //max number of elements the queue can hold

enum op{ADD, SUB, MULT, DIVI};

struct expr
{
  int oprd1;
  op oprt;
  int oprd2;
};

typedef expr el_t; //el_t is an alias for char

class Queue
{
 private:
  el_t el[QUEUE_SIZE];
  int count;
  int front;
  int rear;

 public:
  Queue();
  bool isEmpty();
  bool isFull();
  void queueError(string msg);
  void add(el_t e);
  el_t remove();
  el_t getFront();
  void goToBack();
  int getSize();
  void displayAll();
  friend ostream& operator<<(ostream& o, const expr& e);

};
#endif
