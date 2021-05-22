#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>

class Array{

    protected:

    std::string* WORDS; // The words 
    int* FREQ; // Frequency of each word
    int NUM; // Size of the array (amount of words)

    public:

    Array();    // Blank Constructor
    Array(char*); // Constructor for unsorted array (Uses a filename as a parameter)
    ~Array(); // Destructor for Unsorted Array Class.

    // Getters for the private members of the class //
    int GetNum() const                  { return NUM;     }
    std::string GetWord(int i) const    { return WORDS[i];}
    int GetFrequency(int i) const       { return FREQ[i]; }
    //                                              //


    virtual void append(const char*); // Method that increases the size of the array
    void remove(const char*); // Method that removes a string from the array
    virtual int search(const char*); // Function that searches for the parameter string and returns a positive integer which represents the position of the word if it is found or returns the negative integer -1 if the word is not found

    void print(); // Temporary method that prints the array in a file

    //Overload of some operators to represent some of the upper methods
    void operator=(char * Fname){ 
        Array temp(Fname); 
        NUM = temp.GetNum(); 
        WORDS = new std::string[NUM]; 
        FREQ = new int[NUM]; 
        for (int i = 0; i < NUM; i++) { WORDS[i] = temp.GetWord(i); FREQ[i]= temp.GetFrequency(i); }
    }
    void operator+=(const char* Entry)    { append(Entry);}
    void operator-=(const char* Rem)      { remove(Rem);  } 


};



#endif