#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <string>
using namespace std;

char myToLower(char& c) //changing any uppercase to lowercase
{
  if(c>=65 && c<=90){
    c = c+32;
  }

  return c;
}

char myToUpper(char& c) //changing any uppercase to lowercase
{
  if(c>=97 && c<=122){
    c = c-32;
  }

  return c;
}


bool isLetter(char& c)
{
  if(c < 65 || c > 122 || c == 32){ 
    return false;
  }else{
    return true;
  }
}

string stripStr(const string& wd) 
{ 
  string w = "";
  
  for(int i = 0; i < wd.length(); i++) //go through each character in wd 
    { 
      char t = wd[i];
      if(isLetter(t)){ 
	w += myToLower(t); 
      }
    } 
  return w; 
} 

#endif
