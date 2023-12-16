#ifndef PRICE_H
#define PRICE_H
#include <string>

using namespace std;

class Price{
  friend ostream& operator<<(ostream &o,const Price& p);

 private:
  int dollar;
  int cent;

 public:
  Price();
  Price(int d, int c);
  Price operator+(Price p);
  Price operator-(Price p);
  void operator=(Price p);

};

#endif
