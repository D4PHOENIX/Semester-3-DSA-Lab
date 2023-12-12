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

int prefix_cal(string exp) {
    Stack stack;    
    int length = exp.length();
    for (int i = length - 1; i >= 0; i--) {
        if (exp[i] >= '0' && exp[i] <= '9') {
            stack.push(exp[i] - '0');
        }
        else {
            int op1 = stack.peek();
            stack.pop();
            int op2 = stack.peek();
            stack.pop();
            switch (exp[i]) {
            case '+':
                stack.push(op1 + op2);
                break;
            case '-':
                stack.push(op1 - op2);
                break;
            case '*':
                stack.push(op1 * op2);
                break;
            case '/':
                stack.push(op1 / op2);
                break;
            default:
                return stack.peek();
                break;
            }
        }
    }
    return stack.peek();
}

int main() {
    string prefixExpression = "*+69-31";
    int result = prefix_cal(prefixExpression);
    cout << "Prefix expression answer is: " << result << endl;

    return 0;
}    