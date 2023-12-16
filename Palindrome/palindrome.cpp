#include <iostream>
#include "LL.h"
#include <string>
using namespace std;

void createLL(const string& s, LL& l); //creating the linked list with chars
char myToLower(char& c); //if theres an upper case changing to lower case
bool palindrome(LL& l); //checking if it's a palindrome
bool isLetter(char& c); //checking if it's a letter or non-letter

int main()
{
  string s;
  LL l;
  cout << "Enter a string: ";

  getline(cin, s); //getting phrase to check if it's a palindrome

  createLL(s, l); //making the string into a Linked list of chars
  
  bool check = palindrome(l); //checking is the string/chars is a palindrome


  if(check){ //if it is it will say it is and vise versa
    cout << '"'  << s << '"' << " is a palindrome" << endl;
  }else{
    cout << '"' << s << '"' << " is not a palindrome" << endl;
  }

}

void createLL(const string& s, LL& l) //putting each char from the string to the LL
{
  for(int i = s.length()-1;i>-1;i--){
    char t = s[i];
    myToLower(t);
    l.addFront(t);
  }
}


char myToLower(char& c) //changing any uppercase to lowercase
{
  if(c>=65 && c<=90){
    c = c+32;
  }

  return c;
}

bool isLetter(char& c) //checking if it's a letter or not
{
  if(c < 65 || c > 122 || c == 32){ //ascii, 65-122 is a letter and 32 is a space
    return false;
  }else{
    return true;
  }
}


bool palindrome(LL& l)
{
  char front, back; //putting the front and back chars of the LL to local variables
  
  while(!l.isEmpty()){ //if not empty 
    front = l.deleteFront(); //front will be the first letter
    while(!isLetter(front) && !l.isEmpty()){ //if front isnt a letter and it's not empty
      front = l.deleteFront(); //changing front until front is a letter or it is empty
    }

    if(!l.isEmpty()){ //if it's not empty back is the last char in the LL
      back = l.deleteRear(); //back is the last char in LL
      if(!isLetter(back) && l.isEmpty()){ // if it's not a letter, but is empty back is front ex: mom
	back = front;
      }
      while(!isLetter(back)){//while back is not a letter change til it gets a letter
	back = l.deleteRear();
	if(l.isEmpty()){
	  back = front; //if it becomes empty back becomes front
	}
      }
    }else if(l.isEmpty()){ //else if it is empty after getting front, back becomes front. ex : a
      back = front; 
    }

    if(!isLetter(back) && l.isEmpty()){ //if back is not a letter and the LL is empty then back becomes front
      back = front;
    }

    if(front != back){ //if front is not the same as back then it is not a palindrome
      return false;
    }
  }

  if(l.isEmpty()){ //if the LL becomes empty then all the letters were the same and the string was a palindrome
    return true;
  }
}
