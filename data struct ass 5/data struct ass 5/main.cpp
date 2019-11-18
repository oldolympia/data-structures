//
//  main.cpp
//  data struct ass 5
//
//  Created by Olympia Pyburn on 10/26/19.
//  Copyright © 2019 Olympia Pyburn. All rights reserved.
// used https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/ for help understanding. (supplying information to avoid any plagarism accusation)

#include <iostream>

using namespace std;

class node
{
    public:
    int data;
    node* leftchild;
    node* rightchild;
      
    node(int data)
    {
        this->data = data;
        this->leftchild = NULL;
        this->rightchild = NULL;
    }
};

//question 5
bool checkBinary(node* root, int min, int max){
    
    //if the tree is empty return false (not a binary search tree)
    if(root == NULL){
        return false;
    }
    
    //if the root's data is greater than the max value or less
    //than the  minimum value, return false (not a binary tree)
    if(root->data > max || root->data < min){
        return false;
    }
    
    //check the left child and right child of the root recursively
    //min/max are larger/smaller to make constraints closer
    return checkBinary(root->leftchild, min, root->data - 1)
    && checkBinary(root->rightchild, root->data + 1, max);
   
}

//question 4
int sumTree(node* root){
    
    if (root == NULL){return 0;}
    
    return (root->data + sumTree(root->leftchild) + sumTree(root->rightchild));
}

int main() {
    
    //create binary tree
    node *root = new node(4);
    root->leftchild = new node(2);
    root->rightchild = new node(5);
    root->leftchild->leftchild = new node(1);
    root->leftchild->rightchild = new node(3);
//    root->rightchild->leftchild = new node(11);
//    root->rightchild->rightchild = new node(15);
    
    //vars for min and max values in tree
    int min = 1;
    int max = 5;
    
    //print out sum of tree
    cout << "Sum of binary tree: " << sumTree(root) << endl;
    
    //find whether or not is binary search tree
    bool check = checkBinary(root, min, max);

    //print findings
    cout << "Is binary search tree?: ";

    if (check == false){cout << "No." << endl;}
    else{cout << "Yes." << endl;}
        
    return 0;
}
