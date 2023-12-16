#include "rationalNumber.h"
#include "array.h"
#include <iostream>
using namespace std;


//default constructor: set top to 0 and bottom to 1
rNum::rNum(){
  top = 0;
  bottom = 1;
}

//non-default constructor: we won't be using it in the client, but we might as well make it.
rNum::rNum(int t,int b){
  top = t;
  bottom = b;
}

//Create all operator overloaded functions here. You need to figure out what you need by reading the client. 
istream& operator>>(istream& i, rNum& r)
{
  cout << "Enter the top number: "; 
  i >> r.top; 
  cout << "Enter the bottom number: "; 
  i >> r.bottom; 
  return i; 
}

ostream& operator<<(ostream& o,const rNum& r)
{
  o<<r.top<<"/"<<r.bottom;
  return o;
}

rNum rNum::operator+(rNum& r)
{
  int newt, newb;

  if (this->bottom!=r.bottom){
    newb=this->bottom*r.bottom;
    newt=(this->top*r.bottom)+(r.top*this->bottom);
  }else{
    newb=this->bottom;
    newt=this->top+r.top;
  }

  rNum r1(newt,newb);
  r1.simplify();

  return r1;
}

bool rNum::operator>(const rNum& r)
{
  bool c=this->top>r.top;

  if (this->bottom!=r.bottom){
    c=(this->top*r.bottom)>(r.top*this->bottom);
  }

  return c;
}

bool rNum::operator==(const rNum& r)const
{
  if (this->bottom==r.bottom && this->top==r.top){
    return true;
  }else{
    return false;
  }
}

rNum rNum::operator+=(rNum& r)
{
  int newt, newb;

  if (this->bottom!=r.bottom){
    newb=this->bottom*r.bottom;
    newt=(this->top*r.bottom)+(r.top*this->bottom);
  }else{
    newb=this->bottom;
    newt=this->top+r.top;
  }

  this->top = newt;
  this->bottom = newb;

  simplify();

  return *this;
}


//This is not an operator overloaded function.. This function will simplify a rational number to the simplest form.

void rNum::simplify()
{
  int counter=1;
  int gcf=1;
  while (1){
    if (counter>this->top ||  counter>this->bottom){
      break; 
    }
    if ((this->top%counter==0) && (this->bottom%counter==0)){
      gcf=counter;
    }
    counter++;
  }
  this->top=top/gcf;
  this->bottom=bottom/gcf;
}
