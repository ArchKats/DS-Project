#include"Array.h"
#include<iostream>
#include<fstream>

#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H

/* A Class that represents a Sorted Array. It inherits from the (unsorted) Array class. It is an array that is Sorted alphabetically 
    according to each item's word. It can be constructed manually or simillary like the (unsorted) array's constructor with the filename
    parameter as well as it can be constructed by sorting an object of the (Unosrted) array class.
*/

class SortedArray: public Array{
    // The Sorted Array inherits the (Protected) Variables as well as their Getters and 
    // the remove method that contains the virtual Search method that is derived
    public:

    SortedArray():Array(){}              //Empty Constructor
    SortedArray(char*);                  // Constructor for the SortedArray that uses a FileStream as a parameter 
    SortedArray(const Array&);           // Constructor for the SortedArray that uses a Array object as a parameter and pretty much it just sorts the array by using 

    void append(const char*);           // appends a new word into the sorted array by using the Insertion Sort
    int search(const char* entry);      // Automatically sets the boolean as false

    private:
    int search(const char*, bool);      // Uses binary search to search a word in the sorted array, takes a boolean that if true and the word is not found in the                             
    int BinSearch(int start, int end, const char* entry, bool entry_POS);  // Private Recursive Binary Search (Unaccesible from an object)
};

#endif
