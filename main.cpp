#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

void createQ(string* Q, int size, char* file_name);
int main()
{
	srand((unsigned)time(0));
	char file_name[40];
	cin >> file_name;
	ifstream ifs;
	ifs.open(file_name);
	if (ifs.is_open())
	{
		cout << "File opened\n";
	}
	else cout << "File did not open";
	string a;
	 const int size =rand() ;
	string * Q;
	Q = new string[size];	
	createQ(Q, size,file_name);

	for (int i = 0; i <size; i++)
	{
		cout << Q[i]<<" ";
	}
}
void createQ(string* Q, int size,char * file_name)
{
		int i = 0;
		ifstream ifs;
		string a;
		ifs.open(file_name);
		
	while (ifs >> a&& i<size)
	{
		if ((rand()) % 2 == 1)
		{
			Q[i] = a;
			i++;
		}

	}

}