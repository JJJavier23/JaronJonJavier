#include "student.h"
#include "array.h"
using namespace std;

Student::Student()
{

  fN = "unknown";
  lN = "unknown";
  gen = 'X';
  numClasses = 0;
  stuID = -1;

}

string Student::getFirstName()const{
  return fN;
}

string Student::getLastName()const{
  return lN;
}

char Student::getGen()const{
  return gen;
}

int Student::getID()const{
  return stuID;
}

int Student::getNumClasses()const{
  return numClasses;
}

Student::Student(string f, string l, char g, int s){
  fN=f;
  lN=l;
  gen=g;
  stuID=s;
}


int Student::addCourse(int crn){
  int check;
  check = find(classes, MAX, crn);
  
  if(check!=-1){
    // cout << crn  << " already exists" << endl;
    return 0;
  }else  if(numClasses==MAX){
    // cout << crn << " can't be added because the schedule is full" << endl;
    return -1;
  }else{
    classes[numClasses]=crn;
    // cout << crn  << " has been added" << endl;
    numClasses++;
    return 1;
  }
}

void Student::viewAllCourses(){
  print(classes, numClasses);
}

bool Student::dropCourse(int crn){
  bool check;
  check = remove(classes, numClasses, crn);
  if(check){
    numClasses--;
    // cout << crn << " has been dropped" << endl;
  }else{
    // cout << "The student is not taking " << crn << endl;
  }
  return check;
}

Price Student::getBalance()
{
  return balance;
}

void Student::addFee(int d, int c)
{
  Price p(d, c);
  balance = balance + p;
}

void Student::reduceFee(int d, int c)
{
  Price p(d, c);
  balance = balance - p;
}

int Student::getClassof(int c)const
{
  return classes[c]; 
}
