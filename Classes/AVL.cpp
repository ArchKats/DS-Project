#include<iostream>
#include<fstream>
#include"../Funcs.h"
#include"AVL.h"
#include"BST.h"

AVL::AVL(char* fname){
    std::ifstream file = My::ClearFile(fname);                                      // Tl;dr : Creates a temporary file of the (Temp.txt) of the file whose name is a parameter
    std::string entry;                                                              //         that removes all punctuation, after that for each word of the (temporary) file 
    NUM = 0;                                                                        //         it appends it in the BST correctly (inorder) and at the end of the construction it
    file >> entry;                                                                  //         it prints a message and deletes the Temporary file 
    entry = My::better2low(entry.c_str());
    root = new node(entry.c_str());
    NUM++;

    while(file >> entry){
        entry = My::better2low(entry.c_str());
        append(entry.c_str());
    }
    std::cout << "AVL Tree's Construction was Successful" << std::endl;
    std::remove("Temp.txt");
}

bool AVL::append(const char* entry){
    root = append(root, entry, nullptr);
    return true;
}

node* AVL::append(node* r, const char* entry, node* papa){

    if(r==nullptr){
        r = new node(entry);
        r->parent = papa;
        NUM++;
        return r;
    }
    if(r->Word==entry) {r->Frequency++; return r;}

    if(entry > r->Word){
        r->right=append(r->right, entry, r);
    }
    else if (entry < r->Word){
        r->left=append(r->left, entry, r);
    }
    

    return Balancing(r);
}

node* AVL::remove(node* tree, const char* key)
{
    if (tree == nullptr)                                                            // Case in which the subtree is empty 
        return tree;


    if (key < tree->Word)                                                           // Recursively correctly removes a node from the tree
        tree->left = remove(tree->left, key);                                       // By correctly, meaning that it moves its children nodes to its original position 
 

    else if (key > tree->Word)
        tree->right = remove(tree->right, key);
 

    else {
        if (tree->left == nullptr) {
            struct node* temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right == nullptr) {
            struct node* temp = tree->left;
            free(tree);
            return temp;
        }
        else{
            node* temp = Ever("last", tree->right);
            tree->Word = temp->Word;
            tree->right = remove(tree->right, temp->Word.c_str());
        }
    }
    Balancing(tree);
    return tree;
}

node* AVL::Balancing(node* r){
    
    r->height = 1 + My::max<int>(getHeight(r->left), getHeight(r->right));

    if(getBalance(r)>1 && getBalance(r->left)==1){
        r=rightRotate(r);
    }
    else if(getBalance(r)<-1 && getBalance(r->right)==-1){
        r=leftRotate(r);
    }
    else if(getBalance(r)<-1 && getBalance(r->right)==1){
        r->right = rightRotate(r->right);
        r = leftRotate(r);
    }
    else if(getBalance(r)>1 && getBalance(r->left)==-1){
        r->left = leftRotate(r->left);
        r = rightRotate(r);
    }   
    return r;   
}

node* AVL::leftRotate(node* x){
    node* y = x->right;
    node * t=y->left;
    

    y->left = x;
    x->right = t;

    y->parent = x->parent;
    x->parent = y;

    RefreshHeight(y);

    return y;
}

node* AVL::rightRotate(node* y){
    node* x = y->left;
    node* t = x->right;

    x->right = y;
    y->left = t;

    x->parent = y->parent;
    y->parent = x;

    RefreshHeight(x);

    return x;
}

int AVL::getHeight(node* r){
    if(r==nullptr) return -1;
    else return r->height;
}

int AVL::getBalance(node* r){
    int lh = getHeight(r->left);
    int rh = getHeight(r->right);
    return lh-rh;
}

int AVL::RefreshHeight(node* r){
    if(r==nullptr) return -1;
    else r->height = 1+My::max<int>(RefreshHeight(r->left), RefreshHeight(r->right));
    return r->height;
}
