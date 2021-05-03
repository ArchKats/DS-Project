/* Temporary Placeholder main that is used for testing*/
#include"Classes/Array.h"
#include<iostream>
#include<fstream>

int main(){
    std::ifstream file;
    file.open("Classes/test.txt");


    Array l(file);

    l.print();
    
}