#ifndef HASH_H
#define HASH_H

#include<iostream>


class hash_item{
    public:

    int Key;
    std::string Word;
    int Frequency;

    hash_item(int key, const char* Word){
        this->Key = key;
        this->Word = Word;
        Frequency = 1;
    }

    void operator=(hash_item b){
        this->Key = b.Key;
        this->Word = b.Word;
        this->Frequency = b.Frequency;
    }

};

class HashTable{
    
    public:

    hash_item** Table;
    int MAX_SIZE;
    int NUM;

    public:

    HashTable();
    HashTable(char*);
    ~HashTable();

    int search(const char*);
    bool append(const char*);
    void print();

    private: 

    int hash(const char*, int);
    void SizeIncrease();

    
};



#endif