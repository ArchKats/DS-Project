#ifndef BST_H
#define BST_H

#include<iostream>

struct node{
    // The Values of the node
    std::string Word;
    int Frequency;

    // Pointers to the associate co-trees and parent node
    node *left;
    node *right;
    node *parent;

    int height;
    // Struct Constructors
    node(){ Word = nullptr; left = nullptr; right = nullptr; parent = nullptr;}
    node(const char* Stemp) { Word = Stemp; Frequency = 1; left = nullptr; right = nullptr; parent = nullptr; height = 0;}
};

class BST{

    protected:

    node *root;                                 // Root of the Binary Search Tree
    int   NUM;                                  // Number of the BST's nodes

    public:

    BST();                                      // Blank Constructor for the BST
    BST(char *);                                // Constructor for the BST (Uses a filename as a parameter)
    ~BST();                                     // Destructor for the Binary Search Tree

    bool virtual append(const char*);                   // Method that inputs a Word into the BST
    node* search(const char*);                  // Method that searches the BST for a word
    void remove(const char*);                   // Method that removes a word from the BST

    void print();

    void inorder(node*);                        // Prints the Words and Frequencies of the BST Inorder (recursively)
    void preorder(node*);                      // Prints the Words and Frequencies of the BST Preorder (recursively)
    void postorder(node*);                     // Prints the Words and Frequencies of the BST Postorder (recursively)

    // Recursive functions that I believe should be private
    // Each one is recursive function that is called in one of the previous methods
    protected: bool append(node*, const char*);
    protected: void deleteTree(node*);
    protected: virtual node* remove(node*, const char*);

    protected: node* Ever(const char*, node*);
};

#endif