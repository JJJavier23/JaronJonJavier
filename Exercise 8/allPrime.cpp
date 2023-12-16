#include <iostream>
#include <iomanip>

using namespace std;

bool isPrime(int n);

int main(){
  int counter=0;
  int start = 2;
  int end = 1000;

  for(int i = start; i <=end;i++){
    if (isPrime(i)==true){
      cout << i << ' ';
      counter++;
      if (counter % 10 ==0){
	cout << endl;
      }
    }
  }

  cout << endl << endl << "There are " << counter << " Prime Numbers between 2 and 1000.";

  return 0;
}

bool isPrime(int n){
  for (int d = 2; d < n; d++){
    if(n%d==0){
      return false;
    }
  }
  return true;
}
