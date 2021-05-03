#include"Array.h"
#include<iostream>
#include<fstream>

int main(){
    std::ifstream file;
    file.open("test.txt");


    Array l(file);

    l.print();
    
}


