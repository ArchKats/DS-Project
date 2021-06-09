#include<iostream>

#ifndef ARRAY_H
#define ARRAY_H

/* A Class that represents an (unsorted) Array that contains for each item contains a String (Word) and the Frequency 
   (Times this word was inserted in the array). The Array can either be constructed manually or by declaring the object
    with a filename as a parameter (More information about it on the implimentation file).                          
*/

class Array{

    protected:

    std::string* WORDS;                     // The words 
    int* FREQ;                              // Frequency of each word
    int NUM;                                // Size of the array (amount of words)

    public:

    Array();                                // Blank Constructor
    Array(char*);                           // Constructor for unsorted array (Uses a filename as a parameter)
    ~Array();                               // Destructor for Unsorted Array Class.

    // Getters for the protected members of the class //
    int GetNum()               const    { return NUM;     }
    std::string GetWord(int i) const    { return WORDS[i];}
    int GetFrequency(int i)    const    { return FREQ[i]; }
    //                                              //


    virtual void append(const char*);       // Method that increases the size of the array
    void remove(const char*);               // Method that removes a string from the array
    virtual int search(const char*);        // Function that searches for the parameter string and returns a positive integer which represents the position of the word if it is found or returns the negative integer -1 if the word is not found

    void print();                           // Temporary method that prints the array in a file

    //Overload of some operators to represent some of the upper methods
    void operator+=(const char* Word);
    void operator-=(const char* Word);
};

#endif