#include "queue.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

Queue::Queue()
{
  count = 0;
  front = 0;
  rear = -1;
}

bool Queue::isEmpty()
{
  return (count == 0)? true : false;
}

bool Queue::isFull()
{
  return (count == QUEUE_SIZE)? true : false;
}

void Queue::queueError(string msg)
{
  cout << msg << endl << endl;
}

void Queue::add(el_t e)
{
  if(!isFull()){
    int check = (rear+1)%QUEUE_SIZE;
    if(check != 0){
      rear++;
      el[rear]=e;
      count++;
    }else{
      rear = 0;
      el[rear]=e;
      count++;
    }
  }else{
    queueError("Queue is full");
  }
}

ostream& operator<<(ostream& o, const expr& e)
{
  char opr;
  switch(e.oprt){
  case ADD: opr='+';
    break;
  case SUB: opr='-';
    break;
  case MULT: opr='*';
    break;
  case DIVI: opr='/';
    break;
  }

  o << e.oprd1 << e.oprt << e.oprd2 << endl;
  return o;
}

el_t Queue::remove()
{
  int t;
  if(!isEmpty()){
    t = front;
    front = (front+1)%QUEUE_SIZE;
    count--;
  }else{
    queueError("Queue is empty");
  }

  return el[t];
}

el_t Queue::getFront()
{
  if(!isEmpty()){
    cout << "The front of the queue is " << el[front] << endl;
  }else{
    queueError("The queue is empty");
  }
}

void Queue::goToBack()
{
  if(isEmpty()){
    queueError("Queue is empty");
  }else if(count == 1){
    return;
  }else{
    rear++;
    el[rear]=el[front];
    front++;
  }
}

int Queue::getSize()
{
  return count;
}

void Queue::displayAll()
{
  if(front < rear && count !=0){
    for(int i = front; i < rear+1;i++){
      cout << el[i] << " ";
    } 
  }else if(front > rear && count !=0){
    for(int i = front; i < QUEUE_SIZE; i++){
      cout << el[i] << " ";
    }
    for(int j = 0; j < rear+1; j++){
      cout << el[j]<< " ";
    }
  }else if(count == 1){
    cout << el[front];
  }else if(count == 0){
    cout << "Empty";
  }
  cout << endl << endl;
}


