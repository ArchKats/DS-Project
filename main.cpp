/* Temporary Placeholder main that is used for testing*/
#include"Classes/Array.h"
#include<iostream>
#include<fstream>

int main(){
    std::ifstream file;
    file.open("test.txt");
    std::cout << "FILE OPEN";


    Array l(file);

    l.print(); 
    
}