#include <iostream>
#include <fstream>

using namespace std;

void DisplayArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << *(a+i) << ", ";
	cout << endl;
}


int main()
{
	int x[] = { 12,43,2,65,76 };
	int n = size(x);
	// Display the content of the array on the console.
	DisplayArray(x, n);
	// Write the number of array elements and the content of the array 
	// into a text file. Each number has to be written into a new line.
	ofstream fout;
	// Open file for text output.
	fout.open("data.txt", ios::ate);
	if (!fout.is_open())
	{
		cerr << "File couldn't be opened!";
		exit(-1);
	}
	fout << n << endl;
	for (auto i = 0; i < n; i++)
		fout << x[i] << endl;
	fout.close();
	// Open file for text input.	
	ifstream fin("data.txt");
	if (!fin.is_open())
	{
		cerr << "File couldn't be opened!";
		exit(-1);
	}
	// Read the number of array elements from the file.
	fin >> n;
	// Allocate memory for the array dinamically.
	int* t = new int[n];
	if(t==nullptr)
	{
		cerr << "Unsuccessful memory allocation!";
		exit(-2);
	}
	// Read the numbers from the file into the array. 
	for (auto i = 0; i < n; i++)
		fin >> t[i];
	fin.close();
	// Display the content of the array on the console.
	DisplayArray(t, n);	
	delete []t;
	return 0;
}