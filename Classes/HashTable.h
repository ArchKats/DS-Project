#include<iostream>

#ifndef HASH_H
#define HASH_H

/* 
    Class for a hash table's items. Each item contains a String (Word), the frequency of the word as well as the key of the item.  
*/
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

/*
    A Class that represents a Hash Table. Creates a dynamic array of hash_item objects with the variable MAX_SIZE showing the array's current
    maximum size. The Size is increased by 100 objects when there are less than 100 empty objects.
*/

class HashTable{
    
    public:

    hash_item** Table;                                          // The Array (Table) that contains the objects of the hash_item class
    int MAX_SIZE;                                               // The Current Maximum Size of the Table
    int NUM;                                                    // Number of non-empty objects

    public:

    HashTable();                                                // Empty Constructor
    HashTable(char*);                                           // Constructor that uses a filename as a parameter and inserts every word of the file inside the hashing table
    ~HashTable();                                               // Destructor for the Hash Table

    int GetFrequency(int i) const { return Table[i]->Frequency; }
    int GetNum()                  {return NUM;}

    int search(const char*);                                    // Search method that searches through the hash method if the word is present in the hash table, if it is present it returns the key of the object if it isnt it returns -1
    bool append(const char*);                                   // Appends a word into the hash table


    private: 

    int hash(const char*, int);                                 // The hashing algorithm that turns a string into a integer key, it also takes an integer as a parameter that acts as a modifier for the algorithm in the case the key is used and collision was attempted 
    void SizeIncrease();                                        // Method that increases the size of the hash table when there are less than 100 empty objects in the hash table

};

#endif