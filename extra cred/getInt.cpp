#include <iostream>
#include "myCstring.h"

using namespace std;

int isInt(char* c);
int decimal(char* c);
int cstr_i(char* c);

int main()
{
  bool check;
  char user[10] = "";
  int n = 0;

do
  {
    check = false;
    cout << "Enter an integer: ";
    cin >> user;

    try{
      n = cstr_i(user);
    }

    catch(string e){
      cout << e << endl << endl;
      check = true;
    }

  }while(check == true);

 cout << "After catch" << endl;
 cout << "Num = " << n << endl;

}

int isInt(char* c)
{
  int n = 0, v1 = 0, v2 = 1;
  int result;

  for(int i = myStrlen(c) - 1; i >= 0; i--)
    {
      if(c[i] >= 'A' && c[i] <= 'z'){
	return 0;
      }else{
	n = c[i];
	n = n - 48;
	v1 = v1 + (n * v2);
	v2 = v2 * 10;
      }
    }
  result = v1;
  return result;
}

int decimal(char* c)
{
  int i;
  for(i = 0; c[i] != '.' && i < myStrlen(c); i++);
  if(c[i] =='.'){
    return i;
  }else{
    return 0;
  }
}

int cstr_i(char* c)
{
  int result;

  if(isInt(c) == 0 || decimal(c) != 0){
      string error = "Not an integer number";
      throw error;
  }else{
    result = isInt(c);
    return result;
  }
}
