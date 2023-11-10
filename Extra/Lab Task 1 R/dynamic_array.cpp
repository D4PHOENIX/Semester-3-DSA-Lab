#include <iostream>
using namespace std;
    
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


int main()
{
    int *array;
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    array = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter value for array between 0 and 12: ";
        cin >> array[i];
    }
    for (int i = 0; i < size; i++)
        {
            cout << "Factorial of " << array[i] << " is " << factorial(array[i]) << endl;
        }
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    cout << "Average of array is " << sum / size << endl;

return 0;
}
