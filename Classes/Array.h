#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>
#include<fstream>

class Array{

    private:

    std::string* WORDS; // The words 
    int* FREQ; // Frequency of each word
    int NUM; // Size of the array (amount of words)

    public:

    Array(std::ifstream&); // Constructor for unsorted array (it uses a file as a parameter and each word (and each word's |uses|))
    ~Array(); // Destructor for Unsorted Array Class

    // Getters for the private members of the class //
    int GetNum() const { return NUM;}
    std::string GetName(int i) const { return WORDS[i]; }
    int GetFrequency(int i) const { return FREQ[i]; }
    //                                              //


    void append(const std::string); // Method that increases the size of the array
    void remove(const char*); // Method that removes a string from the array
    int search(const char*); // Function that searches for the parameter string and returns a positive integer which represents the position of the word if it is found or returns the negative integer -1 if the word is not found

    void print(); // Temporary method that prints the array

};



#endif