#include<iostream>
#include<fstream>
#include<cstring>
#include"Array.h"
#include"../Funcs.h"


Array::Array(){
    WORDS = nullptr;
    FREQ = nullptr;
    NUM = 0;
}

Array::Array(char* filename){
    std::ifstream file = My::ClearFile(filename);       // Creation of a punctuation-free copy of the initial file, This probably at some point will be moved to the main function
    std::string entry;                                  // String Variable that will contain each temporary word of the file
    NUM = 0;                                            // Reseting the size of the array

    // First Entry to the array is out of the loop in order to make the code easier to read and understand
    file >> entry;
    entry = My::better2low(entry.c_str());
    append(entry.c_str());

    while(file >> entry){                               // Loop that continues till every word is imported into the array
        entry = My::better2low(entry.c_str());          // Converting the entry string into lower case for more information check the local function library                                                                    
        append(entry.c_str());                          // inserting the entry string into the array
    }
    std::cout << "Array's Construction was Successful" << std::endl; // Temporary output to sign the Finishing of the Array's construction
    std::remove("Temp.txt");                            // Deletes the temporary file
}

Array::~Array(){ 
    delete[] WORDS; 
    delete[] FREQ; 
}

void Array::append(const char* entry){

    int pos = search(entry);                            // Searches for the entry in the array, if it is found the function returns the position of the word into the integer variable pos, if it was not found it returns the negative value -1 into the pos variable 

    if(pos!=-1){                                        // case for the word being found in the array
        FREQ[pos]++;                                    // increasing the frequency of the word
        return;
    }

    NUM++;                                              // increasing the integer that represents the size of the array

    // Temporary arrays that are copies of the original arrays (WORDS and FREQ)
    std::string* string_temp = new std::string[NUM];
    int* int_temp = new int[NUM];
    for(int i=0; i<NUM-1; i++){
        string_temp[i] = WORDS[i];
        int_temp[i] = FREQ[i];
    }
    string_temp[NUM-1]=entry;
    int_temp[NUM-1]=1;

    
    // Deletion of the previous arrays.
    if(NUM!=1){
    delete[] WORDS;
    delete[] FREQ;
    }
    // Copying the temporary arrays into the new ones

    WORDS = string_temp;
    FREQ = int_temp;
}

void Array::remove(const char* del){

    //Temporary arrays that are diminished-by-one from the size of the original arrays

    int pos = search(My::better2low(del));              // Search for the position of the word

    if(pos!=-1){                                        // Case of the position being found
        NUM--;                                          // diminishing the integer that represents the size of the array
        std::string* string_temp = new std::string[NUM];
        int* int_temp =new int[NUM];
        int i = 0;
        int j = 0;
        while(j<NUM){                                   // loop that inserts in the temporary arrays all Words and Frequencies but those of the ones that are to be removed
            if(i==pos) i++;
            else{
                string_temp[j]=WORDS[i];
                int_temp[j]=FREQ[i];
                j++;
                i++;
            }
        }
        // Deletion of the previous arrays
        delete[] WORDS;
        delete[] FREQ;
        
        // Copying the temporary arrays into the new ones
        WORDS = string_temp;
        FREQ = int_temp;
    }
    else std::cout << "!!! ERROR, WORD WAS NOT FOUND IN ARRAY !!!"<<std::endl; // Error message for the case in which the position of the word was not found
    return;
}

int Array::search(const char* key){                     // Just a linear search of the key string
    for(int i=0;i<NUM;i++){
        if(WORDS[i]==key) return i;                     // Case in which the key string was found
    }
    return -1;                                          // Case in which the key string was not found
}

void Array::print(){ // TEMPORARY
    std::ofstream output("Output.txt");
    for(int i=0; i<NUM; i++){
        output<<i<<"."<<WORDS[i]<<" "<<FREQ[i]<<std::endl;
    }
    output.close();
}

void Array::operator+=(const char* Entry){ append(Entry);}
void Array::operator-=(const char* Rem)  { remove(Rem);  }