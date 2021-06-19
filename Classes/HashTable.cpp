#include<iostream>
#include<fstream>
#include<cstring>
#include"HashTable.h"
#include"../Funcs.h"

int prime(int i);

HashTable::HashTable(){
    NUM=0;
    MAX_SIZE = 0;
}

HashTable::HashTable(char* fname){
    std::ifstream file = My::ClearFile(fname);
    std::string entry;                                                              
    NUM = 0;
    MAX_SIZE = 0;
    while(file >> entry){
        append(entry.c_str());
    }
    std::cout << "Hash Table's Construction was Successful" << std::endl;
    std::remove("Temp.txt");
}


HashTable::~HashTable(){
    delete[] Table;
}


bool HashTable::append(const char* entry){

    if(MAX_SIZE-NUM<=100){
        SizeIncrease();
    }

    int key = search(entry);
    

    if(key!=-1){
        Table[key]->Frequency++;
        return false;
    }

    bool entered = false;
    int modif=0;

    while(!entered){
        key = hash(entry, modif);
        if(!Table[key]){
            Table[key] = new hash_item(key, entry);
            entered=true;
            //std::cout<<Table[key]->Word<<" "<<key<<std::endl;
        }
        modif++;
    }
    NUM++;
    return true;
}


void HashTable::SizeIncrease(){
    MAX_SIZE += 100;

    hash_item** temp = new hash_item*[MAX_SIZE];
    for(int i=0; i<MAX_SIZE; i++) temp[i] = nullptr;

    for(int i=0; i<MAX_SIZE-100; i++){
        if(Table[i]){
            bool found = false;
            int modif=0;
            int key;

            while(!found){
                key = hash(Table[i]->Word.c_str(), modif);
                if(!temp[key]){
                    temp[key] = Table[i];
                    temp[key]->Key = key;
                    found = true;
                }
                modif++;
            }
        }
    }
    if(MAX_SIZE!=100) delete[] Table;

    Table = temp;
}


int HashTable::search(const char* KeyWord){
    int key = -1;
    int temp;
    int modif = 0;
    bool found = false;

    while(!found){
        temp = hash(KeyWord, modif);
        if(Table[temp]){
        if(Table[temp]->Word==KeyWord){
            key = temp;
            found = true;
        }
        }
        else return -1;
        modif++;     
    }
    return key;
}


int HashTable::hash(const char* entry, int j){
    unsigned long int P = 7;
    //std::cout<<j%20<<std::endl;std::cin.ignore();
    int modif = prime(j%20);

    for(int i=0; i<strlen(entry); i++){
        P = P*modif + (int)entry[i];
    }
    return (P+j) % MAX_SIZE;
}


int prime(int i){
    int p[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43 ,47, 53, 59, 61 ,67 ,71};
    return p[i];
}
