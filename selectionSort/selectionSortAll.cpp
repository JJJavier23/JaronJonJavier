/****************************************************
Template written by Kazumi Slott
CS211
selection sort lab

This program has 4 different selection sort functions.
*****************************************************/
#include <iostream>
#include <cstdlib>
#include "array.h"
using namespace std;
//??????? include your array.h

void selectionSort1(int array[], int N);
void selectionSort2(int array[], int N);
void selectionSort3(int array[], int N);
void selectionSort4(int array[], int N);
void fill(int array[], int N);
void test(int code);

int main()
{
  srand(time(0));
  cout << "------ testing selectionSort1: Ascending moving largest to end  ------" << endl;
  test(1);

  cout << "\n------ testing selectionSort2: Descending moving smallest to end  ------" << endl;
  test(2);

  cout << "\n------ testing selectionSort3: Ascending moving smallest to beginning  ------" << endl;
  test(3);

  cout << "\n------ testing selectionSort4: Descending moving largest to beginning  ------" << endl;
  test(4);

  return 0;
}

//This function fills the array with random numbers between 1 and 100
void fill(int array[], int N)
{
  for(int i=0;i<N;i++){
    array[i] = rand() % 100 + 1;
  }
}



//code = 1 for selectionSort1
//       2 for selectionSort2
//       3 for selectionSort3
//       4 for selectionSort4

void test(int code)
{
  //make a constant SIZE set to 10
  const int SIZE = 10; 
  //declare an integer array using SIZE  
  int ar[SIZE];
  //fill the array by calling fill()
  fill(ar, SIZE);
  //print the array by calling print() in array.h
  print(ar, SIZE);
  //create a switch statement here to call a different sort function depending on the code.
  //?????
  switch(code){
  case 1:
    selectionSort1(ar, SIZE);
    break;
  case 2:
    selectionSort2(ar, SIZE);
    break;
  case 3:
    selectionSort3(ar, SIZE);
    break;
  case 4:
    selectionSort4(ar, SIZE);
    break;
  }
  //print the array - hopefully the numbers are sorted correctly
  print(ar, SIZE);
}



//this function sorts the numbers in ascending order by moving the largest to the end: smallest to largest
void selectionSort1(int array[], int N) 
{
  int lrgIndx; //the index of the largest value
  int temp; //temporary variable that holds the largest value

  //last is the last index in unsorted part
  for(int last = N-1; last >= 1; last--) 
    {
      lrgIndx = 0; //assume the first item is the largest
      //find the largest in unsorted part ([0..last])
      for(int i = 1; i <= last; i++) 
	{
	  if(array[i] > array[lrgIndx]) //The current item is larger 
	    lrgIndx = i;
	}

      //swap the largest with the last item in the unsorted part
      temp = array[lrgIndx]; 
      array[lrgIndx] = array[last]; 
      array[last] = temp;
    } 
}



//Change this function so it sorts the numbers in descending order by moving the smallest to the end: largest to smallest                                                                    
//You can change the variable names to suit their purposes. 
//The structure of this code shouldn't change.
void selectionSort2(int array[], int N)
{
  int smallIndx; //index of the smallest value                                                                                                                     
  int temp; //temporary variable that holds the smallest value
                                                                                                                                  
  //last is the last index in unsorted part                                                                                                       
  for(int last = N-1; last >= 1; last--)
    {
      smallIndx = 0; //assuming the first index is the smallest                        
      //find the smallest in unsorted part([0..last])                                 
      for(int i = 1; i <= last; i++)
        {
          if(array[i] <  array[smallIndx]) //The current item is smaller                                                                                                                          
            smallIndx = i;
        }

      //??????? swap the smallest with the last item in the unsorted part                                                                                                                           
      temp = array[smallIndx];
      array[smallIndx] = array[last];
      array[last] = temp;
    }
}




//Change this function so it sorts the numbers in ascending order by moving the smallest to the beginning: smallest to largest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.
void selectionSort3(int array[], int N)
{
  int smallIndx; //the index of the smallest value                                                                                                                                                         
  int temp; //temporary variable that holds the smallest value                                                                                                                                                                           
  //first is the first index in unsorted part                                                                                                
  for(int first =0 ; first <= 9; first++)
    {
      smallIndx = 9; //assume the last item is the smallest                                                                                                          
      //find the smallest in the unsorted part ([first...9])                                                                                                                                                                 
      for(int i = 9; i >= first; i--)
        {
          if(array[i] < array[smallIndx]) //The current item is smaller
            smallIndx = i;
        }

      //swap the smallest with the first item in the unsorted part
      temp = array[smallIndx];
      array[smallIndx] = array[first];
      array[first] = temp;
    }
}


/*
//Change this function so it sorts the numbers in descending order by moving the largest to the beginning: largest to smallest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.
*/
void selectionSort4(int array[], int N)
{
  int lrgIndx; //The index of the largest value
  int temp; //temporary variable that holds the smallest value
  //first is the first index in the unsorted part
  for(int first = 0;first <= 9; first++)
    {
      lrgIndx = 9; //assume last item is the largest                                                                                                                                        
      //find the largest in the unsorted part([first...9])                                                                                                                                            
      for(int i = 9; i >= first;i--)
        {
          if(array[i] > array[lrgIndx]) //The current item is larger                                                                                                                          
            lrgIndx = i;
        }

      //swap the largest with the first item in the unsorted part                                                                                                                             
      temp = array[lrgIndx];
      array[lrgIndx] = array[first];
      array[first]= temp;
    }
}












