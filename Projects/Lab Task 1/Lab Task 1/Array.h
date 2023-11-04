#include <iostream>
using namespace std;

class Array
{
public:
	int size;
	int array[size];
	// Initialization function
	void arrayInit(int size)
	{
		for (int i = 0; i < size; i++)
		{
			array[i] = 0;
		}
	}
	// Print function
	void arrayPrint(int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << array[i];
		}
		cout << endl;
	}

};