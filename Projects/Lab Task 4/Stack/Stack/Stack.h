#include <iostream>
using namespace std;

class Stack {
public:
    static const int maxSize = 10;
    int stack[maxSize];
    int top;
    Stack()
    {
        top = -1;
    }

    // push function for the stack to add values
    void push(int v) {
        if (isFull()) {
            cout << "Stack Overflow";
        }
        else {
            top++;
            stack[top] = v;
            cout << v << " pushed into stack\n";
        }
    }

    // pop function for the stack to remove values
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow";
        }
        else {
            cout << "Popped value is " << stack[top] << endl;
            top--;
        }
    }

    // peek function for the stack to return the top value
    int peek() {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            return stack[top];
        }
    }

    bool isEmpty() {
		return (top < 0);
	}

    bool isFull()
    {
    	return (top == maxSize - 1);
    }

    // stackAverage function to return the average of the stack
    double stackAverage(int n) {
        if (n <= 0) {
            cout << "Invalid number of elements for average calculation\n";
            return 0.0;
        }
        else if (n > top + 1) {
            cout << "Not enough elements in the stack for average calculation\n";
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