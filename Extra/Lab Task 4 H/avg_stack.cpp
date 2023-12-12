#include <iostream>
using namespace std;
const int max_size = 10;

class Stack {
public:
    int stack[max_size];
    int top;
    Stack()
    {
        top = -1;
    }
    void push(int val) {
        if (top == max_size - 1) {
            cout << "Stack is Full";
        }
        else {
            top++;
            stack[top] = val;
            cout << val << " pushed into the stack\n";
        }
    }
    void pop() {
        if (top == -1) {
            cout << "Stack is Empty";
        }
        else {
            cout << "Popped value: " << stack[top] << endl;
            top--;
        }
    }
    int peek() {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            return stack[top];
        }
    }
    double stackAverage(int n) {
        if (n <= 0 || n > max_size) {
            cout << "Invalid Input\n";
            return 0.0;
        }
        else {
            int sum = 0;
            for (int i = 0; i <= n; i++) {
                sum += stack[i];
            }
            return static_cast<double>(sum) / n;
        }
    }
};

int main() {
    Stack stack;
    int size, val;
    cout << "Enter the size of the stack: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Enter the element: ";
        cin >> val;
        stack.push(val);
    }
    int n;
    cout << "Enter the number of values to be popped: ";
    cin >> n;
    cout << "Average of popped values is " << stack.stackAverage(n) << endl;

return 0;
}