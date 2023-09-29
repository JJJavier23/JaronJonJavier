/**
 * Implementation of BST class.
 */
//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.
//You should always comments to each function to describe its PURPOSE and PARAMETERS

// =======================================================
// Your name: ??? (TODO: Add your name)
// Compiler:  g++
// File type: cpp file BST.cpp
// @brief This class implements a BST search tree
//=======================================================

#include "BST.h"
#include <vector>
#include <iostream>
using namespace std;
/**
 * Implement the BST constructor
 */
BST::BST() {
    /* TODO: YOUR CODE HERE */
    root = nullptr;
    numElements = 0;
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    /* TODO: YOUR CODE HERE */
    // Must release memory correctly to avoid memory leaks
    destroy(root);
}

void BST::destroy(Node* node){
    if(node !=nullptr){
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
    /* TODO: YOUR CODE HERE */
    return sizeFind(root);
}

unsigned int BST::sizeFind(Node* node)const{
    if(node == nullptr){
        return 0;
    }else{
        return 1 + sizeFind(node->left) + sizeFind(node->right);
    }
}

/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
    /* TODO: YOUR CODE HERE */
    clearer(root);
    root = nullptr;
}

void BST::clearer(Node* node){
    if(node !=nullptr){
        clearer(node->left);
        clearer(node->right);
        delete node;
    }
}

/**
 * Implement insert() correctly
 */
bool BST::insert(T element) {
    /* TODO: YOUR CODE HERE */
    if(root == nullptr){
        root = new Node(element);
        return true;
    }else{
        return insterer(root, element);
    }
}

bool BST::insterer(Node* node, T element){
    if(element < node->data){
        if(node->left == nullptr){
            node->left = new Node(element);
            return true;
        }else{
            return insterer(node->left, element);
        }
    }else if(element > node->data){
        if(node->right == nullptr){
            node->right = new Node(element);
            return true;
        }else{
            return insterer(node->right, element);
        }
    }else{
        return false;
    }
}

/**
 * Implement find() correctly
 */
bool BST::find(const T &query) const {
    /* TODO: YOUR CODE HERE */
    return finder(root, query);
}

bool BST::finder(const Node* node, const T &query)const{
    if(node == nullptr){
        return false;
    }else if(query == node->data){
        return true;
    }else if(query < node->data){
        return finder(node->left, query);
    }else{
        return finder(node->right, query);
    }
}

/**
 * Implement the height() function correctly
 */
int BST::height() const {
    // TODO: Add your code here
    return heightfind(root);
}

int BST::heightfind(const Node* node)const{
    if(node == nullptr){
        return -1;
    }else{
        int left = heightfind(node->left);
        int right = heightfind(node->right);
        return 1 + std::max(left,right);
    }
}

/**
 * Implement the getRoot() function correctly
 */
BST::Node* BST::getRoot() {
    // TODO: Add your code here
    return root;
}

/**
 * @brief Print the subtree at node using inorder traversal
 * @param node a pointer to node in BST
 */
void BST::printInorder(Node* node) {
    // TODO: Add your code here
    if(node == nullptr){
        return;
    }
    printInorder(node->left);
    cout << node->data << ' ';
    printInorder(node->right);
}

/**
* @brief Print the subtree at node using preorder traversal
* @param node a pointer to node in BST
*/
void BST::printPreorder(Node* node) {
    // TODO: Add your code here
    if(node == nullptr){
        return;
    }
    cout << node->data << ' ';
    printPreorder(node->left);
    printPreorder(node->right);
}

/**
* @brief Print the subtree at node using postorder traversal
* @param node a pointer to node in BST
*/
void BST::printPostorder(Node* node) {
    // TODO: Add your code here
    if(node == nullptr){
        return;
    }
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << ' ';
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node *BST::getLeftMostNode() {
    /* TODO: YOUR CODE HERE */
    Node* curr = root;
    while(curr && curr->left != nullptr){
        curr = curr->left;
    }
    return curr;
}

/**
 * Implement the BST successor function correctly
 */
BST::Node *BST::successor(Node *node) {
    /* TODO: YOUR CODE HERE */
    if(node == nullptr){
        return nullptr;
    }
    if(node->right !=nullptr){
        Node* curr = node->right;
        while(curr->left !=nullptr){
            curr = curr->right;
        }
        return curr;
    }else{
        Node* curr = node;
        Node* parent = node->parent;
        while(parent!=nullptr&&curr==parent->right){
            curr = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

