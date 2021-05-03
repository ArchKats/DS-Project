#include<iostream>
#include<fstream>
#include"Funcs.cpp"
#include<cstring>
#include"Array.h"


Array::Array(std::ifstream& file){

    std::string entry; // String Variable that will contain each temporary word of the file
    NUM = 0; // Reseting the size of the array

    while(file >> entry){ // Loop that continues till every word is imported into the array
        entry = better2low(entry.c_str()); // Converting the entry string into lower case for more information check the local function library
        if(NUM==0){ // case for empty Array
            append(entry);
        }
        else{
            if(search(entry)!=-1){ // case for the word being found in the array
                int pos = search(entry);
                FREQ[pos]++; // increasing the frequency of the word
            }
            else{ //if(NUM<2) GARBAGE
                append(entry); // inserting the entry string into the array
            }
        }

    }
    std::cout << "Array's Construction was Successful" << std::endl;
}

Array::~Array(){ 
    delete[] WORDS; 
    delete[] FREQ; 
}

void Array::append(const std::string entry){
    NUM++; // increasing the integer that represents the size of the array
    // Temporary arrays that are copies of the original arrays (WORDS and FREQ)
    std::string* string_temp;
    int* int_temp;
    string_temp = new std::string[NUM-1];
    int_temp = new int[NUM-1];
    for(int i=0; i<NUM-1; i++){
        string_temp[i] = WORDS[i];
        int_temp[i] = FREQ[i];
    }
    
    // Deletion of the previous arrays
    delete[] WORDS;
    delete[] FREQ;
    // Memory Allocation for the new "appended" arrray
    WORDS = new std::string[NUM];
    FREQ = new int[NUM];
    // Copying the temporary arrays into the new ones
    for(int i=0; i<NUM-1; i++){
        WORDS[i] = string_temp[i];
        FREQ[i] = int_temp[i];
    }
    //inserting the entry word into the new array
    WORDS[NUM-1]=entry;
    FREQ[NUM-1]=1;
}

int Array::search(const std::string key){ // Just a linear search of the key string
    for(int i=0;i<NUM;i++){
        if(WORDS[i]==key) return i; // Case in which the key string was found
    }
    return -1; // Case in which the key string wasnt found in the array
}


void Array::print(){
    for(int i=0; i<NUM; i++){
        std::cout<<i<<"."<<WORDS[i]<<" "<<FREQ[i]<<std::endl;
    }
    
}
