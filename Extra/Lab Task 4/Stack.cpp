#include <iostream>
using namespace std;

class Stack {
public:
    static const int maxSize = 10;
    int stack[maxSize];
    int top;
    Stack() : top(-1) {}

    void push(int v) {
        if (top == maxSize - 1) {
            cout << "Stack Overflow";
        }
        else {
            top++;
            stack[top] = v;
            cout << v << " pushed into stack\n";
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow";
            return 0;
        }
        else {
            int poppedValue = stack[top];
            top--;
            return poppedValue;
        }
    }

    int peek() {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
        {
            return stack[top];
        }
    }

    bool isEmpty() {
        return (top < 0);
    }
};

void addStacks(Stack &stack1, Stack &stack2, Stack &stack3) {
    while (!stack1.isEmpty() && !stack2.isEmpty()) {
        int sum = stack1.pop() + stack2.pop();
        stack3.push(sum);
    }
}

int main() {
    Stack stack1, stack2, stack3;
    stack1.push(1);
    stack1.push(2);
    stack2.push(3);
    stack2.push(4);
    addStacks(stack1, stack2, stack3);
    cout << "Top of Stack 3: " << stack3.peek() << endl;
    return 0;
}