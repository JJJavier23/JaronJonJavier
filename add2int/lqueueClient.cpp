#include "lqueue.h"
#include <iostream>

using namespace std;

int main()
{
  LQueue l;
  if(l.isEmpty()){
    cout << "The queue is empty" << endl;
  }
  l.displayAll();
  l.addRear(1);
  l.displayAll();
  l.addRear(2);
  l.addRear(3);
  l.addRear(4);
  l.displayAll();
  for(int i = 0; i<3;i++){
    cout << l.deleteFront() << ' ';
  }
  cout << endl;
  l.displayAll();
  if(!l.isEmpty()){
    cout << "The queue is not empty" << endl;
  }
  cout << l.deleteFront() << endl;
  if(l.isEmpty()){
    cout << "The queue is empty" << endl;
  }
  l.displayAll();
  return 0;
}
