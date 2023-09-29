#include "heap.h"

// @brief gets the maximum value in the heap
// @return the highest value integer in the heap
int Heap::getMax() const {
    if (count == 0)
        return -1;
    return heaparray[0];
}


// @brief default constructor. Construct an empty heap with initial capacity
Heap::Heap(int size) {
    capacity = size;
    heaparray = new int[size];
    count = 0;
}

// @brief destructor
Heap::~Heap() {
    delete[] heaparray;
}

/**
 * @brief constructor to build a heap from an array of values
 * @param values array of values to be added to the heap
 * @param length the size of the array
 */
Heap::Heap(int *values, int length) {
    this->capacity = length;
    this->heaparray = values;
    this->count = length;
}

/**
 * @brief Copy constructor to build a heap from another heap
 * @param the heap to be copied
 */
Heap::Heap(const Heap& heap) {
    capacity = heap.capacity;
    for (int i = 1; i <= heap.count; i++)
    {
        heaparray[i - 1] = heap.heaparray[i - 1];
    }
    count = heap.count;
}

/**
  * @brief assignment operator to set one heap to another
  * @param the heap that you want to set your heap to
  */
Heap& Heap::operator = (const Heap& heap)
{
    if (this != &heap)
    {
        capacity = heap.capacity;
        for (int i = 1; i <= heap.count; i++)
        {
            heaparray[i - 1] = heap.heaparray[i - 1];
        }
        count = heap.count;
    }
    return *this;
}

/**
 * @brief   organizes the values in the heap to satisfy heap property.
 */
void Heap::heapify() {
    // TODO: Organize the heap values by percolating through the heap
    for(int i = count/2 - 1;i>=0;i--){
        percolateDown(i);
    }
}

/**
 * @brief  Runs percolate down on the heap for the node stored in index.
 */
void Heap::percolateDown(int index) {

    // TODO: check the values at index in the heap and decide whether they need to be swapped.
    // Run recursively until the current node is bigger than its children
    int l = leftChild(index);
    int r = rightChild(index);
    int largest = index;

    if(l < count && heaparray[l]>heaparray[largest]){
        largest = l;
    }

    if(r < count && heaparray[r]>heaparray[largest]){
        largest = r;
    }

    if(largest!=index){
        swap(index,largest);
        percolateDown(largest);
    }
}

/**
 * @brief  Runs percolate up on the heap for the node stored in index.
 */
void Heap::percolateUp( int index) {

    // TODO: check the value of the parents of index in the heap and swap them if they are smaller
    // run recursively until the current node is small than its parent
    int p = (index-1)/2;

    if(index > 0 && heaparray[index] > heaparray[p]){
        swap(index,p);
        percolateUp(p);
    }

}

/**
 * @brief  inserts a value into the heap
 *
 */
void Heap::insert(int value) {
    // TODO: resize the Heap array if neccessary and insert the value into the heap.
    // TODO: percolate the Heap to rearange after the value is inserted

    if(count == capacity){
        int* t = new int[2*capacity];
        for(int i = 0;i < capacity;i++){
            t[i] = heaparray[i];
        }
        delete[] heaparray;
        heaparray = t;
        capacity *=2;
    }

    heaparray[count] = value;
    count++;
    percolateUp(count-1);
}

/**
 * @brief  Removes the max value from the heap
 * @return the value that was removed
 */
int Heap::removeMax() {
    // TODO: remove the max value from the heap and then percolate the heap to rearrange values
    if(count == 0){
        return -1;
    }

    int max = heaparray[0];
    heaparray[0] = heaparray[count-1];
    count--;
    percolateDown(0);

    return max;
}

/**
 * @brief  Prints the values in the heap
 */
void Heap::printHeap() {
    int i;
    cout << "[ ";
    for (i = 0; i < count; i++)
        cout << heaparray[i] << " ";
    cout << "]\n";
}

/**
 * @brief  Prints the values in an array
 */
void printArray(int values[], int length) {
    int i;
    cout << "[ ";
    for (i = 0; i < length; i++) {
        cout << values[i] << " ";
    }
    cout << "]\n";
}

/**
 * @brief  Swaps the values in the heap at index1 and index2
 */
void Heap::swap(int index1, int index2) {
    int temp = heaparray[index1];
    heaparray[index1] = heaparray[index2];
    heaparray[index2] = temp;
}

/**
 * @brief  Sorts the values of an array by using the heap
 */
void Heap::heapSort(int values[], int length) {
    cout << "Array Before Sorting: \n";
    printArray(values, length);

    // TODO Create a heap from the array and then remove them from the heap into the array in order 
    Heap heap(values, length);
    
    for(int i = length/2-1;i>=0;i--){
        heap.heapify();
    }

    for(int i = length-1;i>0;i--){
        swap(values[0], values[i]);
        heap.heapify();
    }

    cout << "Array After Sorting: \n";
    printArray(values, length);

    return;
}

/**
     * @brief Change the key of the element at position i to the new value.
     *        It maintains the heap property.
     * @param i the position of the element to be decreased
     * @param value the new value
     */
void Heap::changeKey(int i, int new_val) {
    if (i < capacity) {
        heaparray[i] = new_val;
        percolateDown(0);
    }
}
