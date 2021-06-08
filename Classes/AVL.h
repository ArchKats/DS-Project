#ifndef AVL_H
#define AVL_H

#include<iostream>
#include"BST.h"

class AVL: public BST{
    
    public: 
    
    AVL():BST(){}
    AVL(char* fname);

    bool append(const char*);
    //void remove(const char*);

    private:

    node* append(node*, const char*,node*);
    

    node* leftRotate(node*);
    node* rightRotate(node*);

    node* Balancing(node*);

    int getHeight(node*);

    int getBalance(node*);

    int RefreshHeight(node*);

    node* remove(node*, const char*);



    
};

#endif

