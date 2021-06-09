#include<iostream>
#include"BST.h"

#ifndef AVL_H
#define AVL_H

/*
    A class that represents an AVL tree. It inherits from the BST tree and constructs a binary tree in order to be balanced.
    After each time a new word is inserted or removed from the tree, the "Balancing" method checks if the tree is correctly balanced,
    if it is not it proceeds in balancing it.
*/

class AVL: public BST{
    
    public: 
    
    AVL():BST(){}                                   // Empty Constructor
    AVL(char* fname);                               // Constructor using a filename to insert all of the file's words inside the AVL tree

    bool append(const char*);                       // Public Method that starts the append operation (it appends a string into the AVL tree)

    // The Getters are inherited from the BST class

    private:

    // Each one is a recursive function that is called in one of the previous methods
    node* append(node*, const char*,node*);
    node* remove(node*, const char*);

    // The rotation methods in order for the tree to be balenced
    node* leftRotate(node*);
    node* rightRotate(node*);

    // Getters for the height and the Balance of each node
    int getHeight(node*);
    int getBalance(node*);

    // The method that checks balances the tree after every time a word is inserted (appended) or removed
    node* Balancing(node*);

    // Method that changes every nodes Height after every time the tree is balanced
    int RefreshHeight(node*);
};

#endif

