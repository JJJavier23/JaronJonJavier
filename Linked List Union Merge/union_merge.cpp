/**
 * @brief Implementation of unionLinkedList and mergeLinkedList functions
 */
//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.
#include <iostream>
#include "linkedlist.h"
using namespace std;

/**
    * @brief Assume two linked lists that represent Set A and Set B respectively.
    * Compute the union A U B and return the result as a new linked list.
    *
    * @param LA Input linkedlist A as a set (no duplicated element)
    * @param LB Input linkedlist B as a set (no duplicated element)
    * @return LinkedList return the unioned linkedlist 
    */
LinkedList unionLinkedList(const LinkedList& LA, const LinkedList& LB) {
    // TODO: Add your implementation here
    
    LinkedList LC(LA);

    Node *temp = LB.front;
    while(temp != nullptr){
        if(LC.search(temp->val) == -1){
            LC.addRear(temp->val);
        }
        temp = temp->next;
    }

    return LC;
}

/**
     * @brief Assume two input linked lists, LA and LB, whose elements are both in the non-descending order.
     * This function merges LA and LB into a new linked list (as the return value).
     * The elements in the new list should still be in the non-descending order.
     *
     * @param LA
     * @param LB
     * @return LinkedList
     */
LinkedList mergeLinkedList(const LinkedList& LA, const LinkedList& LB) {
    // TODO: Add your implementation here
    LinkedList LC;

    Node *fir = LA.front;
    Node *sec = LB.front;

    while(fir != nullptr && sec != nullptr){

            if(fir->val <= sec->val){
                LC.addRear(fir->val);
                fir = fir->next;
            } else if(fir->val > sec->val){
                LC.addRear(sec->val);
                sec = sec->next;
            }
    }

    while(fir != nullptr){
        LC.addRear(fir->val);
        fir = fir->next;
    }

    while(sec !=nullptr){
        LC.addRear(sec->val);
        sec = sec->next;
    }

    return LC;
}