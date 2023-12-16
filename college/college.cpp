#include <iostream>
#include <cstdlib> //for atoi() <-- you might not use this
using namespace std;
#include "/cs/slott/cs211/checkInput.h"
#include "array.h"
#include "student.h"
#include "price.h"
#include <fstream>
#include <iomanip>

const int SIZE = 100; //size of the array
const int START = 100000;//student id starts at 100000
const int PASSWORD = 123; //password for admission's office 
const int PRIME1 = 31; //used to calculate a student's password
const int PRIME2 = 5;

int showMenu();
int showAdmMenu();
int showStuMenu();
void addStu(Student ar[], int& i, int& c);
void showStuInfo(Student& s);
void allStuInfo(Student ar[], int& c);
bool operator==(const Student& s, int id);
void removeStu(Student ar[], int& c, int i);
void addCourse(Student& s);
void dropCourse(Student& s);
void makePayment(Student& s);
bool checkPassword();
bool checkStuPassword(int i);
int findStu(Student ar[], int c);


int main()
{
  int count = 0; //the number of students in the array
  int curID = START; //curID is the student id used for the next student you are creating
  Student ar[SIZE];
  ifstream fin;
  Student s;
  int ID;  
  int mm = 0;
  int am = 0;
  int sm = 0;

  while(mm!=3){
    mm = showMenu();

    if(mm == 1){
      bool c;
      c = checkPassword();

      if(c){
	am = showAdmMenu();
	if(am == 1){
	  addStu(ar, curID, count);
	}else if(am == 2){

	}else if(am == 3){
	  cout << "Enter the student ID: ";
	  cin >> ID;
	  removeStu(ar, count, ID);
	}else if(am == 4){
	  cout << "Enter the sudent ID: ";
	  cin >> ID;
	  int f = find(ar, count, ID);
	  cout << f << endl;
	  if(f !=-1){
	    showStuInfo(ar[f]);
	  }else{
	    cout << "No student with ID " << ID << endl;
	  }
	}else if(am == 5){
	  allStuInfo(ar, count);
	}else{
	  //goes back to menu
	}
      }
    }else if(mm == 2){
      bool d;
      cout << "Enter student ID: ";
      cin >> ID;
      int stud = find(ar, count, ID); 

      if(stud != -1){
	d = checkStuPassword(ID);
      }else{
	cout << "No student with ID " << ID << endl;
      }

      if(d){
	sm = showStuMenu();
      }


      if(sm == 1){
	cout << stud << endl;
	addCourse(ar[stud]);
      }else if(sm == 2){
	dropCourse(ar[stud]);
      }else if(sm == 3){
	makePayment(ar[stud]);
      }else if(sm == 4){
	showStuInfo(ar[stud]);
      }else{
	//goes back
      }	  	
    }
  }





  //phase 1 test
  /*
  cout << "-------- adding the first student --------" << endl;
  addStu(ar, curID, count);
  cout << "-------- showing the first student --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- adding student 2, 3, and 4 --------" << endl;
  addStu(ar, curID, count);
  addStu(ar, curID, count);
  addStu(ar, curID, count);
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(ar, count);
  cout << "-------- removing stu 2 --------" << endl;
  cout << "Enter the student id: ";
  cin >> ID;
  removeStu(ar, count, ID);
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(ar, count);
  cout << "-------- removing the last student --------" << endl;
  cout << "Enter the student id: ";
  cin >> ID;
  removeStu(ar, count, ID);
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(ar, count);
  */

  //phase 2 test
  /*
  cout << "-------- adding the first student --------" << endl;
  addStu(ar, curID, count);
  cout << "-------- showing the first student --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- addiing 111 to a student --------" << endl;
  addCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- addiing 222 to a student --------" << endl;
  addCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- addiing 222 again to a student ==> error ----\
----" << endl;
  addCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- removing 222 --------" << endl;
  dropCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- removing 333 ==> error --------" << endl;
  dropCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "######################################################\
##################################" << endl;
  cout << "If you didn't work on bonus feature, enter 20 0. If yo\
u did, enter 20" << endl;
  cout << "######################################################\
##################################" << endl;
  cout << "-------- making a payment --------" << endl;
  makePayment(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "######################################################\
##################################" << endl;
  cout << "If you didn't work on bonus feature, enter 10 14. If y\
ou did, enter 10.14" << endl;
  cout << "######################################################\
##################################" << endl;
  cout << "-------- making a payment --------" << endl;
  makePayment(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "######################################################\
##################################" << endl;
  cout << "Did you work on the bonus feature where you reject an \
over payment? Enter Y or N:";
  char ans;
  cin >> ans;
  if(ans == 'Y' || ans == 'y')
    {
  cout << "-------- For bonus, making an overpayment ==> show\
\
 error and won't be processed --------" << endl;
  makePayment(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
}
  else
    cout << "You didn't work on the bonus feather for overpayment\
\
" << endl;
*/  




  return 0;
}



// ************************  PHASE 1  ****************************

void addStu(Student ar[], int& i, int& c)
{
//case 1 of admission
  string f, l;
  char g;
  cout << "Enter the first name: ";
  cin >> f;

  cout << "Enter the last name: ";
  cin >> l;

  cout << "Enter the gender: ";
  cin >> g;

  /*create a student object. The first student created is given a stu id, 100000 (coming from const START).
The second student gets 100001, the third student gets 100002, etc (notice curID in main).

copy the info from the stu obj into the array at the appropriate slot*/

  Student s(f, l, g, i);
  ar[c++] = s;
  i++;
  cout << endl;

}

                                                                                                                                             
void showStuInfo(Student& s)            
{                                                                                                                                             
//*********************************************************************
//DO NOT send the entire array to this function. BIG deduction if you do.
//SEND only ONE student object as a parameter. If you don't know how, check
//lab1-struct.cpp.
//********************************************************************** 


  cout << "--------------------" << endl;                                                         
                                                                                                                                             
  cout << "first name: " << s.getFirstName()  << endl;                                                                                                 
 
  cout << "last name: " << s.getLastName()  << endl;                                                                                                  
 
  cout << "gender: " << s.getGen() << endl;                                                                                                      
 
  cout << "stu id: " << s.getID() << endl;                                                                                                      
 
  cout << "num classes: " << s.getNumClasses()  << endl;                                                                                                  
 
                                                                                                                                            
  cout << "Courses: ";                                                                                                                        
 
  for(int i = 0; i < s.getNumClasses() ; i++)  //Don't use showAllCourses() but show each course at a time. Which memeber function shows one course?      
    cout << s.getClassof(i)  << ", ";                                                                                                                 
 
                                                                                                                                              
  cout << "\nAmount owed $" << s.getBalance()  << endl;  
//You have an operator overloading function to show a price object at once                   
 
  cout << endl;                                                                                                                               
 
  }


void allStuInfo(Student ar[], int& c)
{
//Case 5 of Admission and case 4 of student
//Call showStuInfo()
//******************************************
//YOU MUST call showStuInfo() to show each student.
//*******************************************

  for(int i=0;i<c && i < SIZE;i++){
    showStuInfo(ar[i]);
  }

}

bool operator==(const Student& s, int id) 
{
  if(s.getID()==id){
    return true;
  }else{
    return false;
  }
}


void removeStu(Student ar[], int& c, int i)
{
//Case 3 of Admission
  int n = find(ar, c, i);
  Student s = ar[n];
  bool tf = remove(ar, c, i);
//2 different messages
  if(!tf){
    cout <<"student with id" << s.getID() << "doesn't exist" << endl;
  }else{
    cout <<s.getFirstName()<< ' '<<s.getLastName()<< " has been removed" << endl;
    c--;
  }
     //"student with id " << id << " doesn't exist" << endl;
     // f << " " << l << " has been removed." << endl;


}


// addStuFromFile()

//Case 2 of admission







//*******************  PHASE 2 ****************************


void addCourse(Student& s)
{
//case 1 of student
//FYI, I am passing one student to this function not the array.
  int crn; 
  cout << "Enter the course number you want to add : ";
  cin >> crn;

  int c = s.addCourse(crn);
//3 different messages to show

  if(c == 1){
    s.addFee(50,14);
    cout << crn <<" has been added successfully" << endl;
  }else if(c == 0){
    cout << crn <<" was not added because you have " << crn << " already." <<  endl;
  }else if(c == -1){
    cout << crn  << " was not added because your schedule is full." <<  endl;
  }

}


void dropCourse(Student& s)
{
//case 2 of admission
//FYI, I am passing one student to this function not the array. 
  int crn;
  cout << "Enter the cource number you want to drop: ";
  cin >> crn;

//2 different messages
  if(!s.dropCourse(crn)){
    cout<< crn << " wasn't dropped from " << s.getFirstName() << " because " << crn << " doesn't exist" << endl;
    }else{
      s.reduceFee(50,14);
      cout<< crn <<" has been dropped successfully." << endl;
    }
}


void makePayment(Student& s)
{
//case 3 of student
//FYI, I am passing one student to this function not the array.  
  int d;
  int c;

  cout << "Amount owed : " << s.getBalance() << endl;
  cout << "Enter payment : ";
  cin >> d >> c;
  s.reduceFee(d, c);
}






//******************** PHASE 3 ****************************

bool checkStuPassword(int i)
{
//I am using this function to check a password for both the admission's office and student
//FYI, I am passing the correct password as a parameter and returning true/false.
//The correct password for a student is  student_id % (PRIME1 * PRIME2)

  int realpw = i%(PRIME1*PRIME2);
  int user;
  cout << "Enter Student Password : ";
  cin >> user;
  if(realpw == user){
    return true;
  }else{
    return false;
  }
}


int findStu(Student ar[], int c)
{
//Small function. You may choose not to use this function. That is OK.

//Ask for the student id
//call find() to find the student id
//return what find() returned which is index where it was found or -1
  int ID;
  cout << "Enter student ID: ";
  cin >> ID;
  int f = find(ar, c, ID);

  return f;

}
/*

void viewStuInfo()
{
//Case 4 of admission
//Ask for the student id
//If the student doesn't exist, show an error message.
//If it exists, call showStuInfo to show the student
}


 verifyStu()
{
//You may decide not to use this function. If so, that is OK.

//When the user is a student, select 2 in the top menu. He/she enters hi/her student id.
//Make sure the stuent id exists in the array. If not, I am showing an error message.
//FYI, I am returning the index where the student was found or -1 if not found.
}

*/

int showMenu()
{
  int choice;
  cout << "========================================================" << endl;
  cout << "1: Admission's Office" << endl;
  cout << "2: Student" << endl;
  cout << "3: End program" << endl;
  cout << "========================================================" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 3, "\tInvalid choice. Enter only 1, 2 or 3: ");

  return choice;
}


int showStuMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a course" << endl;
  cout << "2: drop a course" << endl;
  cout << "3: Make a payment" << endl;
  cout << "4: View my information" << endl;
  cout << "5: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 5, "\tInvalid choice. Enter only 1 through 5: ");

  return choice;
}

int showAdmMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a new student" << endl;
  cout << "2: Add new students from a file" << endl;
  cout << "3: drop a student" << endl;
  cout << "4: View one student info" << endl;
  cout << "5: View all students' info" << endl;
  cout << "6: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 6, "\tInvalid choice. Enter only 1 through 6: ");

  return choice;
}

bool checkPassword(){
  int password;
  cout << "Enter the password: ";
  cin >> password;
  if(password == PASSWORD){
    return true;
  }else{
    cout << "The password is wrong. " << endl << endl << endl << setw(50) << '=' << endl;
    return false;
  }
}
