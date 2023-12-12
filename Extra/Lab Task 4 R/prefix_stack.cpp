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
};

int prefix_cal(string exp) {
    Stack result;    
    int expLength = exp.length();
    for (int i = expLength - 1; i >= 0; i--) {
        if (exp[i] >= '0' && exp[i] <= '9') {
            result.push(exp[i] - '0');
        }
        else {
            int op1 = result.peek();
            result.pop();
            int op2 = result.peek();
            result.pop();
            switch (exp[i]) {
            case '+':
                result.push(op1 + op2);
                break;
            case '-':
                result.push(op1 - op2);
                break;
            case '*':
                result.push(op1 * op2);
                break;
            case '/':
                result.push(op1 / op2);
                break;
            default:
                return result.peek();
                break;
            }
        }
    }
    return result.peek();
}

int main() {
    string expression = "*+69-31";
    int answer = prefix_cal(expression);
    cout << "Answer is: " << answer << endl;

    return 0;
}    