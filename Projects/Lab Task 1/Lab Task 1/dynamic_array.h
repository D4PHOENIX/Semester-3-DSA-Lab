#include <iostream>
using namespace std;

const int maxSize = 20;

class dynamic_array{
public:
    int size;
    int item[maxSize];
	dynamic_array()
    {
        size = 0;
    }

	void count()
    {
        cout << "Values in List are " << size << endl;

    }

	void add(int value)
    {
        if (size < 20)
        {
            item[size] = value;
            size++;
        }
    }

	void insert(int value, int pos)
    {
        if (size < 20 && pos >= 0 && pos <= size)
        {
            for (int i = size - 1; i >= pos; i--)
                item[i + 1] = item[i];
            item[pos] = value;
            size++;
        }
    }

	void retrieve(int pos)
    {
        if (pos >= 0 && pos < size)
        {
            cout << "Value on position " << pos << "is " << item[pos] << endl;
        }
        else
            cout << "Position not found" << endl;
    }

	void display()
    {
        cout << "Values in List are following ";
        for (int i = 0; i < size; i++)
            cout << item[i] << " ";
    }
};