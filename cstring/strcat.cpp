#include <iostream> 
using namespace std; 
 
void myStrcat(char* dest, const char* source); 
 
int main() 
{ 
  char str2[80] = "Dave "; 
  myStrcat(str2, "Smith"); 
  cout << str2 << endl; //Dave Smith 
 
  return 0; 
} 
 
void myStrcat(char* dest, const char* source) 
{ 
  int d; 
 
  //Move d to the end of dest ('\0') 
  for(d=0;dest[d]!='\0';d++){
    ;
  }
  //copy each character from source to dest 
  for(int i = 0; source[i]!='\0';i++){
    dest[d] = source[i];
    d++;
  }  
  //place '\0' at the end of dest 
  dest[d] = '\0';
} 
