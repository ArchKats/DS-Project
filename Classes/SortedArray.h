#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H

#include"Array.h"
#include<iostream>
#include<fstream>

class SortedArray: public Array{
    /*private:

    std::string* WORDS;
    int* FREQ;
    int NUM;
    */
    public:

    SortedArray():Array(){}      //Empty Constructor
    SortedArray(char*); // Constructor for the SortedArray that uses a FileStream as a parameter 
    SortedArray(Array&);         // Constructor for the SortedArray that uses a Array object as a parameter and pretty much it just sorts the array by using 

    /* The Sorted Array Class Inherints the Getters of the Normal Array*/
    /*int GetNum() const { return NUM;}
    std::string GetName(int i) const { return WORDS[i]; }
    int GetFrequency(int i) const { return FREQ[i]; }*/
    //                                 //

    void append(const char*); // appends a new word into the sorted array by using the Insertion Sort
    //void remove(const char*); // removes a word from the sorted array
    int search(const char*, bool);  // Uses binary search to search a word in the sorted array
    int search(const char* entry);

    private: int BinSearch(int start, int end, const char* entry, bool entry_POS); 

    

};

#endif
