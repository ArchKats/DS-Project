#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H

#include"Array.h"
#include<iostream>
#include<fstream>

class SortedArray: public Array{
    // The Sorted Array inherits the (Protected) Variables as well as their Getters and 
    // the remove method that contains the virtual Search method that is derived
    public:

    SortedArray():Array(){}              //Empty Constructor
    SortedArray(char*);                 // Constructor for the SortedArray that uses a FileStream as a parameter 
    SortedArray(const Array&);                // Constructor for the SortedArray that uses a Array object as a parameter and pretty much it just sorts the array by using 

    void append(const char*);           // appends a new word into the sorted array by using the Insertion Sort
    int search(const char*, bool);      // Uses binary search to search a word in the sorted array, takes a boolean that if true and the word is not found in the 
    int search(const char* entry);      // Automatically sets the boolean as false


    // Private Recursive Binary Search (Unaccesible from an object)
    private: int BinSearch(int start, int end, const char* entry, bool entry_POS); 
};

#endif
