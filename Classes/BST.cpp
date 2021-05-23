#include<iostream>
#include"../Funcs.h"
#include<cstring>
#include<fstream>

#include"BST.h"

BST::BST(char* fname){
    std::ifstream file = My::ClearFile(fname);
    std::string entry;
    NUM = 0;

    file >> entry;
    entry = My::better2low(entry.c_str());
    append(entry.c_str());

    while(file >> entry){
        entry = My::better2low(entry.c_str());
        append(entry.c_str());
    }
    std::cout << "Binary Search Tree's Construction was Successful" << std::endl;
    std::remove("Temp.txt");
}

BST::~BST(){
    deleteTree(root);
}

void BST::deleteTree(node* r){
    if(r!=nullptr){
        deleteTree(r->left);
        deleteTree(r->right);
        delete(r);
    }

}

bool BST::append(const char* entry){
    if(root == nullptr){
        root = new node(entry);
        return true;
    }
    return append(root, entry);
}

bool BST::append(node* ND, const char* entry){
    if(entry == ND->Word){
        ND->Frequency++;
        return false;
    }
    if(entry > ND->Word){
        if(ND->right==nullptr){
            ND->right = new node(entry);
            ND->right->parent = ND;
            return true;
        }
        return append(ND->right, entry);
    }
    else{
        if(ND->left==nullptr){
            ND->left = new node(entry);
            ND->left->parent = ND;
            return true;
        }
        return append(ND->left, entry);
    }
}

/*
node* BST::search(const char* entry){

    node *p;

    if(root == nullptr){
        std::cout << "!!!Search of Empty BST was attempted!!!";
        p = new node();
        return p;
    }

    p = root;
    while (p != nullptr && entry != p->Word){
        
        if (entry>p->Word) {p = p->right;}
        else               {p = p->left;}
    }
    return p;
}
*/

void BST::print(){
    print(root);
}

void BST::print(node* r){
    if(r==nullptr) return;

    print(r->left);
    std::cout<< r->Word << std::endl;
    print(r->right);
}

