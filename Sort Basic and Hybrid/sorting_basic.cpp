/**
 * Implemention of selected sorting algorithms
 * @file sorting.cpp
 */

#include "sorting.h"
#include <iostream>
using namespace std;

/**
 * Implement the insertionSort algorithm correctly
 */
void insertionSort(int array[], int lowindex, int highindex, bool reversed) {
    if (!reversed) {
    for (int i = lowindex+1;i <= highindex;i++) {
      int curindex = i;
      while (curindex > 0 && (array[curindex] < array[curindex - 1])) {
        int temp = array[curindex];
        array[curindex] = array[curindex - 1];
        array[curindex - 1] = temp;
        curindex--;
      }
    }
  }
  else {
    for (int i = lowindex+1;i <= highindex;i++) {
      int curindex = i;
      while (curindex > 0 && (array[curindex] > array[curindex - 1])) {
        int temp = array[curindex];
        array[curindex] = array[curindex - 1];
        array[curindex - 1] = temp;
        curindex--;
      }
    }
  }
}

/**
 * @brief Implementation of the partition function used by quick sort
 * 
 */
int partition(int array[], int lowindex, int highindex, bool reversed) {
    // TODO: Add your code here
  
  if(!reversed){
    
    int pivot = array[highindex], i = (lowindex - 1),j;
    for(j = lowindex;j<highindex;j++){
      
      if(array[j]<=pivot){
        i++;
        swap(array[i],array[j]);
      }
      
    }
    
    swap(array[i+1], array[highindex]);
    
    return(i+1);
    
  }else if(reversed){
    
    int pivot = array[highindex], i = (lowindex-1),j;
    
    for(j=lowindex;j<highindex;j++){
      
      if(array[j]>=pivot){
        i++;
        swap(array[i],array[j]);
      }
      
    }
    
    swap(array[i+1],array[highindex]);
    
    return (i+1);
  }
}

/**
 * Implement the quickSort algorithm correctly
 */
void quickSort(int array[], int lowindex, int highindex, bool reversed) {
    // TODO: Add your code here
 
  if(lowindex >= highindex){
    return;
  }
  int p = partition(array, lowindex, highindex, reversed);
  quickSort(array, lowindex, p-1, reversed);
  quickSort(array, p+1, highindex, reversed);
  
}


