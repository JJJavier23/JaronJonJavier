#include <iostream>
#include "myCstring.h"

using namespace std;

void showResult(const char* l, const char* s, const char* all);

int main()
{
  const char* badAr[4] = {"funky", "idiot", "stinky", "stupid"};
  char wd[10];
  char all[111] = "";
  char longest[100] = "";
  char shortest[] = "xxxxxxxxxxxxxxxxxxxx";
  int len, l = 0, s = 1000;

  for(int i = 0; i < 10 ;i++){
    cout << "Enter a word: ";
    cin >> wd;
    
    if(binarySearch(badAr, 4, wd) == -1){
      myStrcat(all, wd);
    }

    len = myStrlen(wd);
    if(len > l){
      l = len;
      myStrcpy(longest, wd);
    }

    if(len < s){
      s = len;
      myStrcpy(shortest, wd);
    }

 }

  showResult(longest, shortest, all);

  return 0;
}

void showResult(const char* l, const char* s, const char* all)
{
  cout << "The longest word: " << l << endl;
  cout << "The shortest word: " << s << endl;
  cout << "All words minus bad words: " << all << endl;
}
