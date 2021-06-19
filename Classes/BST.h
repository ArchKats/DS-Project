#include<iostream>

#ifndef BST_H
#define BST_H

/* 
    Data structure for a (binary search) tree's Node. Each node object contains a string (Word) and the Frequency of said word.
*/

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

/* 
    A Class that represents a Binary Search Tree (BST)
*/

class BST{

    protected:

    node *root;                                 // Root of the Binary Search Tree
    int   NUM;                                  // Number of the BST's nodes

    public:

    BST();                                      // Blank Constructor for the BST
    BST(char *);                                // Constructor for the BST (Uses a filename as a parameter)
    ~BST();                                     // Destructor for the Binary Search Tree

    // Getters for the attributes of a node
    std::string GetWord(const node*);
    int GetFrequency(const node*);
    int GetNUM();

    bool virtual append(const char*);           // Method that inputs a Word into the BST
    node* search(const char*);                  // Method that searches the BST for a word
    void remove(const char*);                   // Method that removes a word from the BST

    void inorder(node*);                        // Prints the Words and Frequencies of the BST Inorder (recursively)
    void preorder(node*);                      // Prints the Words and Frequencies of the BST Preorder (recursively)
    void postorder(node*);                     // Prints the Words and Frequencies of the BST Postorder (recursively)

    // Each one is a recursive function that is called in one of the previous methods    
    protected:

    bool append(node*, const char*);
    void deleteTree(node*);
    virtual node* remove(node*, const char*);
    node* Ever(const char*, node*);
};

#endif