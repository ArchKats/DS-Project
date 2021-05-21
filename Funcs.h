#ifndef FUNCS_H
#define FUNCS_H

#include<cstring>
#include<iostream>
#include<algorithm>
#include<fstream>

/* Better2low is a function that transofrms the Uppercase letters of a string into lower case */
namespace My{

static char* better2low(const char* line){

    char* temp = new char[strlen(line) + 1];
    strcpy(temp, line);
    for(int i=0; i<strlen(line); i++)
        if(line[i]>64&&line[i]<91) temp[i] = char(line[i]+32);
    return temp;
    
}


/* ClearFile Creates a temporary copy of the initial file that is edited to have all punctuation removed */
static std::ifstream ClearFile(const char* filename) {
    std::ifstream file(filename);
    std::string line;
    std::ofstream temp("Temp.txt",std::ios::in|std::ios::trunc);

    while(std::getline(file, line)){
        std::replace_if(line.begin() , line.end() , [] (const char& c) { return std::ispunct(c) ;},' ');
        temp << line << std::endl;
    }
    file.close();
    temp.close();
    std::ifstream rtn("Temp.txt");
    return rtn;
    
} 

}

#endif
