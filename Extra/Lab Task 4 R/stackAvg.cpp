#include <iostream>
using namespace std;

class Stack {
public:
    static const int maxsize = 10;
    int stack[maxsize];
    int top;
    Stack()
    {
        top = -1;
    }
    void push(int v) {
        if (isFull()) {
            cout << "Stack is Full";
        }
        else {
            top++;
            stack[top] = v;
            cout << v << " pushed."<< endl;
        }
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Empty";
        }
        else {
            cout << stack[top] << " popped." << endl;
            top--;
        }
    }
    int peek() {
        if (isEmpty())
        {
            cout << "Stack Empty" << endl;
        }
        else
        {
            return stack[top];
        }
    }
    bool isEmpty() {
        return (top == -1);
    }
    bool isFull() {
        return (top == maxsize - 1);
    }
    double stackAvg(int n, Stack stack) {
        if (n <= 0 || n > maxsize) {
            cout << "Wrong Input\n";
            return 0.0;
        }
        else {
            double sum = 0;
            for (int i = 0; i < n; i++) {
                sum += stack.peek();
                stack.pop();
            }
            return sum / n;
        }
    }    
};

int main() {
    Stack s;
    int n, element;
    cout << "Number of elements to be pushed: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter the element: ";
        cin >> element;
        s.push(element);
    }
    cout << "Number of elements to be popped: ";
    cin >> n;
    cout << "Average: " << s.stackAvg(n, s) << endl;

return 0;
}