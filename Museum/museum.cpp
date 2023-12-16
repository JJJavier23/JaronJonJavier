#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "array.h"
#include "/cs/slott/cs211/checkInput.h"

using namespace std;

char showMenu();
int getVisitorInfo(int a[], double t[], string c[], int& count);
bool checkPassword();
void showStatistic(int a[], double t[], string c[], int count);
void filetxt(ofstream& file, int a[], double t[], string c[], int count);

const int MAX=100; // up to 100 visitors

int main(){
  int counter = 0; // visitor counter
  int age[MAX]; //visitor age info
  double time[MAX];//visitor time spent
  string country[MAX];//visitor country from
  char menu;//menu variable to go to menu
  bool access = false;//bool for password check
  char yn;//to get y or n into Y or N

  cout << setfill('=') << setw(50) << '=' << endl;

  while(menu != '2'){//To always show menu unless chosen as a staff member and closes museum
    menu = showMenu();
    if(menu == '1'){ //when a visitor calls the getVisitor function
      getVisitorInfo(age, time, country, counter);
    } else if(menu=='2'){ // selecting to be the staff member
      access = checkPassword();
      if(access == false){ //if password was incorrect, brought back to menu of choice
	menu = 1;
      }else if(access ==true){
	if(counter > 0){ //only shows stats when there is more than 0  visitors
	  cout <<endl << "The total number of visitors is " << counter << endl << endl;
	  showStatistic(age, time, country, counter);
	  cout << "Do you want to close the Museum? Y or N: ";
	  yn = getYN("Invalid answer. Enter Y or N: ");
	 
	}else if (counter ==0){//if there is no visitors
	  cout << endl <<"Do you want to close the Museum? Y or N: ";
	  yn = getYN("Invalid answer. Enter Y or N: ");
	}
	if(yn == 'Y'){ // if wanting to close calls the txt funtion in order to transfer the summary
	  ofstream fout;
	  string date;
	  string filename;
	  cout << "Enter today's date: ";
	  cin >> date;
	  filename = date + ".txt";
	  fout.open(filename.c_str());
	  filetxt(fout, age, time, country, counter);
	  break;
	  fout.close();
       	} 
	else if(yn == 'N'){
	  menu = showMenu();
	}
      }
    }
  }

  return 0;
}

//gives the user the menu choice to choose between the visitor or staff member
char showMenu(){

  char choice;

  cout <<"1. Visitor" << endl << "2. Museum Staff" << endl << "Enter your choice: ";

  choice = getData('1', '2', "Invalid choice. Enter 1 or 2: ");
  cout << endl;

  return choice;
}


//getting each visitors information within the museum, a = age, t = time and c = country arrays
int getVisitorInfo(int a[], double t[], string c[], int& count){

  string country;
  int age;
  double time;

  cout << "Enter your country: ";
  cin >> country;
  c[count] = country;
  
  cout << "Enter your age : ";  
  age = getData(0, 200, "The age has to be between 0 and 200. Enter again: ");
  a[count] = age;

  cout << "Enter the number of hours you explored: ";
  time = getData(0.0, 10.0, "The number of hours has to be between 0 and 10.0. Enter again: ");
  t[count] = time;

  cout << endl << setw(50) << '=' << endl;

  count++;

  return count;
}


//Checking if the password given by the user is correct through a bool, no parameters needed
bool checkPassword(){
  string password;
  cout << "Enter the password: ";
  cin >> password;
  if(password == "5678"){
    return true;
  }else{
    cout << "The password is wrong. " << endl << endl << endl << setw(50) << '=' << endl;
    return false;
  }
}


//to show the needed stats based on the array and output it
void showStatistic(int a[], double t[], string c[], int count){
  int uniqcount;
  string uniqC[count];
  int low, high;
  double avg;

  cout << setw(6)<< '=' << "The names of the countries of visitors" << setw(6)<<'=' << endl;

  uniqcount = unique(c, uniqC, count);

  print(uniqC, count);

  cout << endl;

  low =  getLowest(a, count);
  cout << "The age of the youngest visitor: " << a[low] << endl;

  high = getHighest(a, count);
  cout << "The age of the oldeest visitor: " << a[high] << endl;

  avg = getAvg(a, count);
  cout << "The average age of the visitors: " << avg << endl;

  cout << endl;

  low = getLowest(t, count);
  cout << "The shortest visit hours: " << t[low]<< endl;

  high = getHighest(t, count);
  cout << "The longest visit hours: " << t[high] << endl;

  avg = getAvg(t, count);
  cout << "The average visit hours: " << avg << endl;

  cout << endl;
}


//To transfer the summary into a .txt file
void filetxt(ofstream& file, int a[], double t[], string c[], int count){
  file <<setfill('=') <<setw(6) << '=' << "The names of the countries of visitors" << setw(6)<<'=' << endl;
  string uq[count];
  int uqc;
  uqc = unique(c, uq, count);
  for(int i=0; i<uqc;i++){
    file << uq[i] << ' ';
  }
  file << endl << endl;
  file <<"The age of the youngest visitor: "<<a[getLowest(a, count)]<< endl << "The age of the oldest visitor: " << a[getHighest(a, count)]<< endl << "The average age of the visitors: " <<getAvg(a, count)<< endl<< endl << "The shortest visit hours: " << t[getLowest(t, count)]<<endl <<"The longest visit hours: " << t[getHighest(t, count)]<< endl << "The average visit gours: " << getAvg(t, count)<< endl << endl;
}
