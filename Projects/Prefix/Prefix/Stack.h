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

    // isEmpty function for the stack to check if it is empty
    bool isEmpty() {
        return (top < 0);
    }

    // isFull function for the stack to check if it is full
    bool isFull()
    {
        return (top == maxSize - 1);
    }
};