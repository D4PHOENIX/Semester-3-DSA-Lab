#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    // making a stack
    Stack stack;

    // pushing elements into the stack
    int n, value;
    cout << "Enter the number of elements to be pushed: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter the element: ";
        cin >> value;
        stack.push(value);
    }

    // printing the average of the elements
    cout << "Enter the number of elements to be popped: ";
    cin >> n;
    cout << "Average of popped elements: " << stack.stackAverage(n) << endl;

return 0;
}