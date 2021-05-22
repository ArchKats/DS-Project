#include<iostream>
#include<fstream>
#include<cstring>
#include"SortedArray.h"
#include"Array.h"
#include"../Funcs.h"

SortedArray::SortedArray(char* filename){

    std::ifstream file = My::ClearFile(filename); // Creation of a punctuation-free copy of the initial file, This probably at some point will be moved to the main function
    std::string entry; // String Variable that will contain each temporary word of the file
    NUM = 0; // Reseting the size of the array

    // First Entry to the array is out of the loop in order to make the code easier to read and understand
    file >> entry;
    entry = My::better2low(entry.c_str());
    append(entry.c_str());

    while(file >> entry){ // Loop that continues till every word is imported into the array
        entry = My::better2low(entry.c_str()); // Converting the entry string into lower case for more information check the local function library
        int pos = search(entry.c_str()); // Searches for the entry in the array, if it is found the function returns the position of the word into the integer variable pos, if it was not found it returns the negative value -1 into the pos variable 
        if(pos!=-1){ // case for the word being found in the array
            FREQ[pos]++; // increasing the frequency of the word
        }
        else{ // case for the word not being found in the array and thus appening it into the array
            append(entry.c_str()); // inserting the entry string into the array
        }
    }
    std::cout << "Array's Construction was Successful" << std::endl; // Temporary output to sign the Finishing of the Array's construction
    std::remove("Temp.txt"); // Deletes the temporary file

}

void SortedArray::append(const char* entry){

    int entrypoint;

    if(NUM!=0){
        entrypoint = search(entry, true)+1;
    }
    else entrypoint = 0;

    NUM++;

    std::string* string_temp = new std::string[NUM];
    int* int_temp = new int[NUM];
    for(int i=0; i<entrypoint; i++){
        string_temp[i] = WORDS[i];
        int_temp[i] = FREQ[i];
    } 
    string_temp[entrypoint] = entry;
    int_temp[entrypoint] = 1;
    for(int i=entrypoint+1; i<NUM; i++){
        string_temp[i] = WORDS[i-1];
        string_temp[i] = FREQ[i-1];
    }

    if(NUM!=1){
    delete[] WORDS;
    delete[] FREQ;
    }

    


    WORDS = string_temp;
    FREQ = int_temp;

    for(int i=0; i<NUM; i++){
        std::cout<<WORDS[i]<<" "<<FREQ[i]<<std::endl;
    }
    std::cout<<"BRRR\n";
}

int SortedArray::search(const char* entry, bool Entry_POS_Search){
    return BinSearch(0, NUM-1, entry, Entry_POS_Search);
}

int SortedArray::search(const char* entry){
    return BinSearch(0, NUM-1, entry, false);
}

int SortedArray::BinSearch(int start, int end, const char* entry, bool entry_POS){
    int middle = (start+end)/2;
    if(start<=end){
        
        if(WORDS[middle]==entry){
            return middle;
        }

        if(WORDS[middle]>=entry){
            return BinSearch(start, middle-1, entry, entry_POS);
        }

        if(WORDS[middle]<=entry){
            return BinSearch(middle+1, end, entry, entry_POS);
        }
    }
    if(entry_POS){
        std::cout<<start<<" "<<end;
        if(WORDS[start]>entry) {std::cout<<"BEEP"; return start;}
        if(WORDS[end]>entry)   {std::cout<<"BOOP"; return end;}
    }
    return -1;
}