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

    // Struct Constructors
    node(){Word = nullptr; left = nullptr; right = nullptr; parent = nullptr;}
    node(const char* Stemp) { Word = Stemp; Frequency = 1; left = nullptr; right = nullptr; parent = nullptr;}
};

class BST{

    protected:
    node * root;
    int NUM;

    public:

    BST();
    BST(char *);
    ~BST();

    bool append(const char*);
    node* search(const char*);
    void remove(const char*);
    void print();

    void inorder();
    void preorder();
    void postorder();

    private: bool append(node*, const char*);
    private: void deleteTree(node*);
    private: void print(node*);


};

#endif