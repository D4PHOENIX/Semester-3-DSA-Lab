#include <iostream>
using namespace std;

class dynamicArray
{
public:
    int *array;
    int size;
    dynamicArray(int size)
    {
        this->size = size;
        array = new int[size];
    }
    ~dynamicArray()
    {
        delete[] array;
    }

    // input function for array
    void input()
    {
        for (int i = 0; i < size; i++)
        {
            int inputNum;
            do {
                cout << "Enter value for index " << i << " (0-12): ";
                cin >> inputNum;
            } while (inputNum < 0 || inputNum > 12);
            *(array + i) = inputNum;
        }
    }

    // calculating average
    double average()
    {
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += array[i];
        }
        return sum / size;
    }

    // calculating factorial
    int factorial(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            return n * factorial(n - 1);
        }
    }

    // printing factorials
    void displayFactorials()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Factorial of " << array[i] << " is " << factorial(array[i]) << endl;
        }
    }
};

int main()
{
    // taking size of array from user
    int size;
    cout << "Enter size of array (1-20): ";
    cin >> size;
    // checking if size is valid
    if (size < 1 || size > 20)
    {
        cout << "Invalid size entered. Program terminated." << endl;
    }
    else
    {
    // creating dynamic array    
    dynamicArray array(size);
    // taking input from user
    array.input();
    // displaying factorials
    cout<<"\n Factorials of all elements: "<<endl;
    array.displayFactorials();
    // displaying average
    cout << "\nAverage of all elements: " << array.average() << endl;
    }

return 0;
}
