#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H
#include <string>

using namespace std;

class rNum
{

 private:
  int top;
  int bottom;
  void simplify();

 public:
  rNum();
  rNum(int t, int b);
  friend istream& operator>>(istream& i, rNum& r);
  friend ostream& operator<<(ostream& o, const rNum& r);
  rNum operator+(rNum& r);
  bool operator>(const rNum& r);
  bool operator==(const rNum& r)const;
  rNum operator+=(rNum& r);
 
};

#endif
//define the rNum class here. The data members are top and bottom.
