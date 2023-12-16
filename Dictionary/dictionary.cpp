#include <iostream>
#include <fstream>
#include "LL.h"
#include "utility.h"
#include <string>

using namespace std;

void buildLL(LL& l, string w);
void removeBadWords(LL& l, string w);
void outputToFile(LL& l);

int main()
{
  ifstream fin, bin;
  fin.open("essay.txt");
  bin.open("bad.txt");
  LL l;
  string word;

  while(fin >> word){
    buildLL(l, word);
  } 

  while(bin >> word){
    removeBadWords(l, word);
  }

  //l.displayAll();

  fin.close();
  bin.close();

  outputToFile(l);

  return 0;
}

/*
First param is for the LL of words, the second param is the word we are putting into ascended order into the LL
*/
void buildLL(LL& l, string w)
{
  string word = stripStr(w);

  if(!l.search(word)){//adding words that aren't in there already
      l.addInOrderAscend(word);
    }
}

/*
First param is the LL we made, the second param is the bad word we want to search for and erase out of the LL
*/
void removeBadWords(LL& l, string w)
{
  if(l.search(w)){ //searching and deleting the bad word in the LL
    l.deleteNode(w);
  }
}

/*
The param is the LL with all the words in it in order to sort them into their own .txt file
*/
void outputToFile(LL& l)
{
  ofstream fout;
  
  while(!l.isEmpty()){
    string s = l.deleteFront();
    char c = s[0];
    string fileName = "./dictionary/ .txt";
    fileName[13] = myToUpper(c);
    fout.open(fileName.c_str());
    fout << s;
    fout.close();
  }
}
