#include<iostream>
#include<fstream>
#include<cstring>
#include"SortedArray.h"
#include"Array.h"
#include"../Funcs.h"

SortedArray::SortedArray(char* filename){           // Pretty Much a copy of the normal Array Constructor, didn't use derived Constructor because it wouldn't allow the use of the virtual methods, also different Finish Message

    std::ifstream file = My::ClearFile(filename);   // Creation of a punctuation-free copy of the initial file, This probably at some point will be moved to the main function
    std::string entry;                              // String Variable that will contain each temporary word of the file
    NUM = 0;                                        // Reseting the size of the array

    // First Entry to the array is out of the loop in order to make the code easier to read and understand
    file >> entry;
    entry = My::better2low(entry.c_str());
    append(entry.c_str());

    while(file >> entry){                           // Loop that continues till every word is imported into the array
        entry = My::better2low(entry.c_str());      // Converting the entry string into lower case for more information check the local function library
        int pos = search(entry.c_str());            // Searches for the entry in the array, if it is found the function returns the position of the word into the integer variable pos, if it was not found it returns the negative value -1 into the pos variable 
        if(pos!=-1){                                // case for the word being found in the array
            FREQ[pos]++;                            // increasing the frequency of the word
        }
        else{                                       // case for the word not being found in the array and thus appening it into the array
            append(entry.c_str());                  // inserting the entry string into the array
        }
    }
    std::cout << "Sorted Array's Construction was Successful" << std::endl; 
    std::remove("Temp.txt");                        // Deletes the temporary file

}

SortedArray::SortedArray(const Array& Arr){         // Sorts an Array (object) into a SortedArray (object)
    NUM = Arr.GetNum();                             // Copies the Variables from the (Regular) Array (object)
    WORDS = new std::string[NUM];                   // into the Sorted Array (object) 
    FREQ = new int[NUM]; 
    for (int i = 0; i < NUM; i++) { 
        WORDS[i] = Arr.GetWord(i); 
        FREQ[i]= Arr.GetFrequency(i); 
    }

    int int_temp;                                   // Good'ol Bubble Sort
    std::string string_temp;                        // O(n^2) but I don't think it "deserves" a better
    for(int i=0; i < NUM-1; i++){                   // and faster Sorting Algorithm
        for(int j=1; j > NUM-i-1; j++){
            if(WORDS[j]>WORDS[j-1]){
                string_temp = WORDS[j];
                WORDS[j] = WORDS[j-1];
                WORDS[j-1] = string_temp;
                int_temp = FREQ[j];
                FREQ[j] = FREQ[j-1];
                FREQ[j-1] = int_temp;
            }
        }
    } 
}

void SortedArray::append(const char* entry){

    int entrypoint;                                 // Represents the position in which the entry word will enter

    if(NUM!=0){
        entrypoint = search(entry, true)+1;         // Searchs for the position of the right-smaller word in the array and then adds it with 1 to make the Entry position of the entry word
    }
    else entrypoint = 0;                            // first entry will certainly have an entrypoint of 0

    NUM++;                                          // increases the number of entries by 1

    // Create "Increased by 1" Copies of the Arrays in order to enter the entry into the original arrays
    std::string* string_temp = new std::string[NUM]; 
    int* int_temp = new int[NUM];
    // Enters the Words and Frequencies before the Entry Point to the copies
    for(int i=0; i<entrypoint; i++){
        string_temp[i] = WORDS[i];
        int_temp[i] = FREQ[i];
    } 
    // Enters the entry to the Entry Point to the copies
    string_temp[entrypoint] = entry; 
    int_temp[entrypoint] = 1;
    // Enters the Words and Frequencies after the Entry Point to the copies
    for(int i=entrypoint+1; i<NUM; i++){
        string_temp[i] = WORDS[i-1];
        int_temp[i] = FREQ[i-1];
    }

    // Deletion of the previous arrays.
    if(NUM!=1){
    delete[] WORDS;
    delete[] FREQ;
    }
    // Copying the temporary arrays into the new ones

    WORDS = string_temp;
    FREQ = int_temp; 
}

int SortedArray::search(const char* entry, bool Entry_POS_Search){ // Calls the binary search function with the boolean manually entered
    return BinSearch(0, NUM-1, entry, Entry_POS_Search);
}

int SortedArray::search(const char* entry){                         // Calls the binary search function with the boolean automatically entered (false)
    return BinSearch(0, NUM-1, entry, false);
}

int SortedArray::BinSearch(int start, int end, const char* entry, bool entry_POS){ // Just a binary search but with a small twist
    int middle = (start+end)/2;                                     // middle point declaration

    // While start is bigger or equal to end the algorithm recursively tries to find the key word (entry), 
    // in the case of it not being found it will
    // 1.(For entry_POS==true) find the position of the word that right-smaller of entry 
    // 2.(For entry_POS==false) it will return -1

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
    if(entry_POS){  // 1
        if(start>=NUM) return start-1;
        if(WORDS[start]<entry) return start;
        else return start-1;
    }       
    return -1;      // 2
}