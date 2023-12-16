#include <iostream>
#include <string>
#include <cstdlib>//for rand()
#include <fstream>

using namespace std;

typedef int el_t;

class Node
{
  friend class BST;
private:
  el_t elem;
  Node* right;
  Node* left;
public:
  Node(el_t e){elem = e;right=NULL;left=NULL;}; //implement the constructor inside the class definition
};

class BST
{
private:
  Node* root;
  void insertNode(Node*& p, el_t);
  void destroy(Node* p);
  void inOrderPrint(Node* p);
  void preOrderPrint(Node* p);
  void postOrderPrint(Node* p);
  int getNumNodesBetween(Node* p, int n, int x);
  void printNodesBetween(Node* p, int n, int x);

public:
  BST();
  void insertNode(el_t e);
  bool search(el_t e);
  //~BST();
  void inOrderPrint();
  void preOrderPrint();
  void postOrderPrint();
  int getNumNodesBetween(int n, int x);
  void printNodesBetween(int n, int x);

};

BST::BST()
{
  root = NULL;
}

/*
BST::~BST()
{
  destroy(root);
}
*/

void BST::destroy(Node* p)
{
  if(p==NULL){
    return;
  }
  destroy(p->left);
  destroy(p->right);
  cout << p->elem << "-->";
  delete p;
}


void BST::preOrderPrint(Node* p)
{
  if(p==NULL){
    return;
  }
  cout << p->elem << "-->";
  preOrderPrint(p->left);
  preOrderPrint(p->right);
}

void BST::preOrderPrint()
{
  preOrderPrint(root);
}

void BST::inOrderPrint()
{
  inOrderPrint(root);
}

void BST::inOrderPrint(Node* p)
{
  if(p==NULL){
    return;
  }
  inOrderPrint(p->left);
  cout << p->elem << "-->";
  inOrderPrint(p->right);
}

void BST::insertNode(el_t e)
{
  insertNode(root, e);
}

void BST::insertNode(Node*& p, el_t e)
{
  if(p == NULL)
    p = new Node(e);
  else if(e < p->elem)
    insertNode(p->left, e);
  else
    insertNode(p->right, e);
}
 
bool BST::search(el_t e)
{
  //Don't use recursion. Use a loop.
  //You want to know how many times it loops to find e.
  //declare a counter. 
  Node* t = root;
  int count = 0;
  bool check = false;
  while(!check && t!=NULL){
    count++;
    if(t->elem == e){
      check = true;
    }else if(t->elem > e){
      t = t->left;
    }else if(t->elem <= e){
      t = t->right;
    }
  }

  //display the counter
  cout << count << " nodes checked"  << endl;
  if(check == true){
    return true;
  }else{
    return false;
  }

}

void BST::postOrderPrint()
{
  postOrderPrint(root);
}

void BST::postOrderPrint(Node* p)
{
  if(p==NULL){
    return;
  }
  postOrderPrint(p->left);
  postOrderPrint(p->right);
cout << p->elem << "-->";
}

int BST::getNumNodesBetween(int n, int x)
{
  int t;
  t = getNumNodesBetween(root, n, x);
  return t;
}

int BST::getNumNodesBetween(Node* p, int n, int x)
{
  if(p==NULL){
    return 0;
  }
  if(p->elem >= n && p->elem <= x){
    return 1 + getNumNodesBetween(p->left, n, x) + getNumNodesBetween(p->right, n, x);
  }else if(p->elem < n){
    return getNumNodesBetween(p->right, n, x);
  }else{
    return getNumNodesBetween(p->left, n, x);
  }
}

void BST::printNodesBetween(int n, int x)
{
  printNodesBetween(root, n, x);
}

void BST::printNodesBetween(Node* p, int n, int x)
{
  if(p==NULL){
    return;
  }
  if(n < p->elem){
    printNodesBetween(p->left, n, x);
  }
  if(n <=p->elem && x >= p->elem){
    cout << p->elem << "-->";
  }

  printNodesBetween(p->right, n, x);
}

int main()
{
  //LAB 1

  /*
  srand(time(0)); //you need to include cstdlib

  bool check;
  BST b;
  LL l;

  int const SIZE = 10000;
  int ar[SIZE];

  for(int i = 0; i<10000;i++){
    ar[i]= rand()%10000+1;
    l.addRear(ar[i]);
    b.insertNode(ar[i]);
  }

  int key;
  cout << "What number do you want to search for? ";
  cin >> key;


  cout << "BST *************************" << endl;
 
  check = b.search(key);
  if(!check){
    cout << "NOT found" << endl;
  }else{
    cout << "Found" << endl;
  }

  cout << "LL************************" << endl;
  
  check = l.search(key);
  if(!check){
    cout << "NOT found" << endl;
  }else{
    cout << "Found" << endl;
  }
  */

  //LAB 2
  /*
  BST b;

  b.insertNode(5);
  b.insertNode(8);
  b.insertNode(3);
  b.insertNode(9);
  b.insertNode(6);
  b.insertNode(1);
  b.insertNode(0);
  b.insertNode(4);
  b.insertNode(7);
  b.insertNode(20);


  cout << "---- Print all elements using the in-order traversal -----" << endl;  

  b.inOrderPrint();

  cout << endl << "---- Print all elements using the pre-order traversal -----" << endl;  

  b.preOrderPrint();

  cout << endl <<"---- Print all elements using the post-order traversal -----" << endl;  

b.postOrderPrint();

  cout << "\n--- destructor gets called when b goes out of scope here ---" << endl;  
  */

  ifstream fin;
  fin.open("bst.dat");
  BST b;  
  int i, min, max;

  while(fin >> i){
    b.insertNode(i);
  }

  cout << "Enter min: ";
  cin >> min;
  cout << "Enter max: ";
  cin >> max;

  cout << "The number of nodes between 40 and 60 is " <<b.getNumNodesBetween(min, max) << endl;

  b.printNodesBetween(min, max);  

  return 0;
}
