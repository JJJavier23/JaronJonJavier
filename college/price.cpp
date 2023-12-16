#include "price.h"
#include <iostream>

using namespace std;

Price::Price()
{
  dollar = 0;
  cent = 0;
}

Price::Price(int d, int c)
{

 this->dollar = d;
 this->cent = c;

}

Price Price::operator+(Price p)
{

  int addCents = p.cent +this->cent;
  int carryover = addCents/100;
  int newCents = addCents%100;

  Price total;
  total.cent = newCents;
  total.dollar = (this->dollar + carryover + p.dollar);

  return total;
}


Price Price::operator-(Price p)
{

  Price total;

  total.cent = this->cent - p.cent;
  total.dollar = this->dollar - p.dollar;

  if(total.cent < 0){
    total.cent = 100 + total.cent;
    total.dollar--;
  }
  return total;
}

void Price::operator=(Price p)
{

  this->dollar = p.dollar;
  this->cent = p.cent;

}

ostream& operator<<(ostream &o,const Price& p)
{

  o << p.dollar << ".";
  if(p.cent < 10){
    o << "0";
  }

  o << p.cent;

  return o;
}
