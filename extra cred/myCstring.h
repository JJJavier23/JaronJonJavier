#ifndef MYCSTRING_H
#define MYCSTRING_H
#include <iostream>

using namespace std;

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
  //putting \0 at the end
  dest[d] = ' ';
  dest[d+1] = '\0';
}

void myStrcpy(char* dest, const char* source)
{
  int i;
  for(i=0; source[i]!='\0'; i++){
    dest[i] = source[i];
  }
  dest[i]='\0';
}

int myStrlen(const char* cstr)
{
  int i;
  for(i = 0; cstr[i] != '\0'; i++){
    ;
  }

  return i;
}


int myStrcmp(const char* cstr1, const char* cstr2)
{
  for(int i = 0; cstr1[i]!='\0' || cstr2[i]!='\0'; i++){
    if(cstr1[i] != cstr2[i]){
      return cstr1[i]-cstr2[i];
    }
  }

  return 0;
}

int binarySearch(const char** bad, int s, char* key)
{
  int l = 0; //left boudary starts at first index
  int r = s-1; //right boundary starts at last index
  int m; //middle point between left and right.

  //When l and r cross over, search ends. --> key was not found.
  while(l<=r)
    {
      //calculate the middle point between l and r
      m=(l+r)/2;

      if(myStrcmp(bad[m], key)==0) //word was found
        return m;
      else if(myStrcmp(bad[m], key)<0)
        l = m+1;
      else 
	r = m-1;
    }

  return -1; //word was not found
}

#endif
