#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include "Classes/Array.h"
#include "Classes/SortedArray.h"
#include "Classes/BST.h"
#include "Classes/AVL.h"
#include "Classes/HashTable.h"
#include "Funcs.h"

using namespace std;

void createQ(string* Q, int size, char* file_name);

template<typename T> string PrintTime(T&, const char*);

int main()
{
	srand((unsigned)time(0));

	char* file_name;
	ifstream ifs;
	bool FILE_EXIST=true;

	file_name = (char*)"test.txt"; // name of the file
	
	/* Reads the name of the file from the keyboard
	cout<<"Insert File Name:";
	do{
		if(!FILE_EXIST) cout<<"File Name does not exist\nEnter File Name that exists:";
		cin >> file_name;
		ifs.open(file_name);
		FILE_EXIST = ifs.good();
	}while(!FILE_EXIST);
	*/

	cout<<"Program has started\nConstruction of the Data Structures may take a while \n";

	Array a(file_name);
	SortedArray b(file_name);
	BST c(file_name);
	AVL d(file_name);
	HashTable e(file_name);

	const int size =rand() % a.GetNum() % 10001;

	string * Q;
	Q = new string[size];	
	
	createQ(Q, size,file_name);
	

	ofstream ofs("OUT.txt");
	for(int i=0; i<size; i++){
		ofs << "++++++++++++"<<Q[i]<<"++++++++++++\n";
		ofs << "     Array  : "<<PrintTime(a, Q[i].c_str());
		ofs << "     S.Array: "<<PrintTime(b, Q[i].c_str());
		ofs << "     BST    : "<<PrintTime(c, Q[i].c_str());
		ofs << "     AVLTree: "<<PrintTime(d, Q[i].c_str());
		ofs << "   HashTable: "<<PrintTime(e, Q[i].c_str());
		ofs<<"\n\n";
	}
	ofs.close();
	cout<<"The procedure was successful. Check the OUT.txt file to see the results.\n";
}

void createQ(string* Q, int size,char * file_name)
{
		int i = 0;
		ifstream ifs = My::ClearFile(file_name);
		string a;
		
	while (ifs >> a&& i<size)
	{
		if ((rand()) % 5 == 1)
		{
			Q[i] = My::better2low(a.c_str());
			i++;
		}

	}
	ifs.close();
	remove("Temp.txt");

} 

template<typename T>
string PrintTime(T& a, const char* keyword){

    string OUT;                                        		// Output String

    auto start = chrono::high_resolution_clock::now(); 		// Start Time

    auto i = a.search(keyword);

    auto end = chrono::high_resolution_clock::now();   		// End Time

    chrono::duration<double, milli> fp_ms = end - start; 	// Duration (End - Start)
    double time = fp_ms.count();                            // Duration to double (milliseconds)

    int Fz = a.GetFrequency(i);                             // Frequency

    
    OUT = to_string(time) + " milliseconds ||| Frequency:" + to_string(Fz) + '\n'; // Example: "0.006 milliseconds Frequency: 9"
    return OUT.c_str();
}