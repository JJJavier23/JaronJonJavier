#ifndef STUDENT_H
#define STUDENT_H
#include "price.h"
#include <string>

using namespace std;

const int MAX = 6;

class Student{

 private:
  string fN;
  string lN;
  char gen;
  int numClasses;
  int stuID;
  int classes[MAX];
  Price balance;

 public:
  Student();
  int addCourse(int crn);
  string getFirstName()const;
  string getLastName()const;
  char getGen()const;
  int getID()const;
  int getNumClasses()const;
  Student(string f, string l, char g, int s);
  void viewAllCourses();
  bool dropCourse(int crn);
  Price getBalance();
  void addFee(int d, int c);
  void reduceFee(int d, int c);
  int getClassof(int c)const;

};

#endif
