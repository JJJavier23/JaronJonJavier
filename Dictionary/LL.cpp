#include "LL.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

LL::LL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

bool LL::isEmpty()
{
  return (front == NULL && rear == NULL && count == 0)? true : false;
}

void LL::addRear(el_t el)
{
  node* n = new node;
  n->elem = el;
  n->next = NULL;
  if(isEmpty()){
    front = n;
    rear = n;
  }else{
    rear->next = n;
    rear = rear->next;
  }
  count++;
}

void LL::displayAll()
{
  if(isEmpty()){
    cout << "[Empty]" << endl;
  }else{
    node* p = front;
    while(p!=NULL){
      cout << (*p).elem;
      if((*p).next!=NULL){
	cout << ',';
      }
      p = (*p).next;
    }
    cout << endl;
  }
}

void LL::queueError(string msg)
{
  cout << msg << endl;
  exit(1);
}

el_t LL::deleteFront()
{
  el_t e;
  if(isEmpty()){
    queueError("Underflow");
  }else{
    if(count == 1){
      rear = NULL;
    }
    node* next = (*front).next;
    e = (*front).elem;
    delete front;
    front = next;
    count--;
    return e;
  }
}

LL::~LL()
{
  while(!isEmpty()){
    deleteFront();
  }
}

void LL::addFront(el_t el)
{
  if(isEmpty()){
    front = new node;
    rear = front;
    rear->next = NULL;
    rear->elem = el;
  }else{
    node* p = new node;
    p->elem = el;
    p->next = front;
    front = p;  
  }
  count++;
}

el_t LL::deleteRear()
{
  if(isEmpty()){
    queueError("Error: Queue is Empty");
  }else if(count == 1){
    el_t p = (*rear).elem;
    delete rear;
    front = rear = NULL;
    count--;
    return p;
  }else{
    node* p;
    for(p=front;p->next!= rear;p=p->next)
      ;
    el_t t = (*rear).elem;
    delete rear;
    rear = p;
    rear->next = NULL;
    count--;
    return t;
  }
}

LL::LL(const LL& source)
{
  this->front = this->rear = NULL;
  this->count = 0;
  node* p = source.front;
  while(p!=NULL){
    this->addRear(p->elem);
    p=p->next;
  }
}

void LL::deleteNode(el_t e)
{
  node* pre;
  node* del;
  if(isEmpty()){
    return;
  }
  for(pre = front, del = front->next; del != NULL && del->elem != e; pre = del, del = del->next)
    ;
  if(del != NULL){
    pre->next = pre->next->next;
    delete del;
    count--;
  }else if(pre == front || front->elem == e){
    deleteFront();
  }else{
    return;
  }
}

void LL::deleteNodes(el_t e)
{
  node* p = front;
  if(!isEmpty()){
    while(p->elem==e){
      deleteFront();
    }

    if(count!=0){
      p = front;
    }

    while(p->next!=NULL){
      if(p->next->elem==e){
	node* t = p->next;
    
	if(t==rear){
	  rear=p;
	}
	p->next = p->next->next;
	delete t;
	count--;
      }else{
	p=p->next;
      }
    }
  }
}

void LL::addInOrderAscend(el_t e)
{
  node* p = front;
  if(isEmpty()){
    front = rear = new node;
    front->elem = e;
    rear->next = NULL;
    count++;
  }else{
    if(e < front->elem){
      addFront(e);
    }else if(e > rear->elem){
      addRear(e);
    }else{
      node* newN = new node;
      newN->elem = e;
      while(p->next != NULL && p->next->elem < e){
	p = p->next;
      }
      newN->next = p->next;
      p->next = newN;
      count++;
    }
  }
}

bool LL::search(el_t e)
{
  bool check = false;
  int count = 0;
  node* t = front;
  while(!check && t != NULL){
    count++;
    if(t->elem == e){
      check = true;
    }else{
      t = t->next;
      check = false;
    }
  }
  
  //cout << count << " nodes checked" << endl;

  if(check){
    return true;
  }else{
    return false;
  }

}

void LL::addInOrderDescend(el_t e)
{
  node* p = front;
  if(isEmpty()){
    front = rear = new node;
    front->elem = e;
    rear->next = NULL;
    count++;
  }else{
    if(e > front->elem){
      addFront(e);
    }else if(e < rear->elem){
      addRear(e);
    }else{
      node* newN = new node;
      newN->elem = e;
      while(p->next != NULL && p->next->elem > e){
        p = p->next;
      }
      newN->next = p->next;
      p->next = newN;
      count++;
    }
  }
}
