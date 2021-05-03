#include<cstring>

char* better2low(const char* line){

    char* temp = new char[strlen(line) + 1];
    strcpy(temp, line);
    for(int i=0; i<strlen(line); i++){
        if(line[i]>64&&line[i]<91) temp[i] = char(line[i]+32);
    }
    return temp;
    
}