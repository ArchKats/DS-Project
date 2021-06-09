#include<iostream>
#include"../Funcs.h"
#include<cstring>
#include<fstream>

#include"BST.h"

BST::BST(){                                                                         // Empty Constructor that sets the root of the tree as null
    NUM=0;
    root = nullptr;
}

BST::BST(char* fname){                                                              // Once again a constructor that is based on the one of the Array Constructor
    std::ifstream file = My::ClearFile(fname);                                      // Tl;dr : Creates a temporary file of the (Temp.txt) of the file whose name is a parameter
    std::string entry;                                                              //         that removes all punctuation, after that for each word of the (temporary) file 
    NUM = 0;                                                                        //         it appends it in the BST correctly (inorder) and at the end of the construction it
    file >> entry;                                                                  //         it prints a message and deletes the Temporary file 
    entry = My::better2low(entry.c_str());
    root = new node(entry.c_str());
    NUM++;

    while(file >> entry){
        entry = My::better2low(entry.c_str());
        if(append(entry.c_str())) NUM++;
    }
    std::cout << "Binary Search Tree's Construction was Successful" << std::endl;
    std::remove("Temp.txt");
}

BST::~BST(){
    deleteTree(root);                                                               // Uses the recursive function deleteTree to delete the entire tree (More on that down) 
}

std::string BST::GetWord(const node* r){
    return r->Word;
}

int BST::GetFrequency(const node* r){
    return r->Frequency;
}

int BST::GetNUM(){
    return NUM;
}

void BST::deleteTree(node* r){
    if(r!=nullptr){                                                                 // Recursively deletes each node of the tree in Postorder
        deleteTree(r->left);
        deleteTree(r->right);
        delete(r);
    }

}

bool BST::append(const char* entry){                                                // The append method returns the boolean value true if the entry was Successfully inserted into the BST 
    if(root == nullptr){                                                           // or false if the entry was not succesfull
        root = new node(entry);                                                     // the Append method checks if the tree is empty (no root), if
        return true;                                                                // it finds that there is no root it appends the entry as the root
    }
    return append(root, entry);                                                     // if the tree isnt empty it uses the recursive version of the
}                                                                                   // append method to find where to put and to put the entry into the correct node of the tree

bool BST::append(node* ND, const char* entry){
    if(entry == ND->Word){                                                          // if the entry is found in a node it just increases the Frequency of the node and returns false 
        ND->Frequency++;
        return false;
    }                                                                               // From here on out it searches for the correct node to put it in (inorder)
    if(entry > ND->Word){                                                           // It searches for each node if it's value (the word ) is bigger or smaller than the entry                                            
        if(ND->right==nullptr){                                                     // It does that untill it finds the right (empty) in which point it enters the entry word and the appending method concludes
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


node* BST::search(const char* entry){                                              // Searches the whole tree for a (key) word 

    node *p;

    if(root == nullptr){                                                            // in the case of the root BST being empty it prints out a warning message and then stops the search
        std::cout << "!!!Search of Empty BST was attempted!!!";
        p = new node();
        return p;
    }

    p = root;
    while (p != nullptr && entry != p->Word){                                       // Loop that continues till the keyword is found, it does that by 
        
        if (entry>p->Word) p = p->right;                                            // moves the temporary node from the parent node to the right node because the word is (alphabetically) bigger
        else               p = p->left;                                             // moves the temporary node from the parent node to the left node because the word is (alphabetically) smaller
    }
    return p;
}


void BST::print(){                                                                  // TEMPORARY FUNCTIONS
    inorder(root);
}

void BST::remove(const char* key){                                                  // Calls the recursive remove function from the root
    root = remove(root, key);
}

node* BST::remove(node* tree, const char* key)
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
            tree->Frequency = temp->Frequency;
            tree->right = remove(tree->right, temp->Word.c_str());

        }
 
    }
    return tree;
}

// They all print the Words and Frequencies that are contained in the Nodes of the BST

// Inorder left -> parent -> right
void BST::inorder(node* tree){ 
    if(tree==nullptr) return;                                                         

    inorder(tree->left);
    std::cout<< tree->Word <<" "<< tree->Frequency<< std::endl;
    inorder(tree->right);
}

// Preorder parent -> left -> right
void BST::preorder(node* tree){
    if(tree==nullptr) return;

    std::cout<< tree->Word <<" "<< tree->Frequency<< std::endl;
    preorder(tree->left);
    preorder(tree->right);
}

// Preorder left -> right -> parent
void BST::postorder(node* tree){
    if(tree==nullptr) return;

    postorder(tree->left);
    postorder(tree->right);
    std::cout<< tree->Word <<" "<< tree->Frequency<< std::endl;
}

node* BST::Ever(const char* Dir, node* r){
    if(r==nullptr) return r;
    node* temp = r;

    if(Dir==(char*)"last"){
        while(temp && temp->left) temp = temp->left;
    }
    else if(Dir==(char*)"first"){
        while(temp && temp->right) temp = temp->right;
    }
    return temp;
}