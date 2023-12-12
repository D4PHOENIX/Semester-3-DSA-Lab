
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

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow";
        }
        else {
            cout << "Popped value is " << stack[top] << endl;
            top--;
        }
    }

    int peek() {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            return stack[top];
        }
    }
};

class solution
{
    public:
    int PrefixSol(string exp) {
        Stack stack;
        int len = exp.length();

        // Traverse the expression in reverse order
        for (int i = len - 1; i >= 0; i--) {
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
    //int PostfixSol(string exp)
    //{
    //    Stack stack;
    //    int len = exp.length();
    //    for (int i = 0; i < len; i++)
    //    {
    //        if (exp[i] >= '0' && exp[i] <= '9')
    //            stack.push(exp[i] - '0');
    //        else
    //        {
    //            int op1 = stack.top();
    //            stack.pop();
    //            int op2 = stack.top();
    //            stack.pop();

    //            switch (exp[i])
    //            {
    //            case '+': // addition
    //                stack.push(op1 + op2);
    //                break;
    //            case '-': // subtraction
    //                stack.push(op1 - op2);
    //                break;
    //            case '*': // multiplication
    //                stack.push(op1 * op2);
    //                break;
    //            case '/': // division
    //                stack.push(op1 / op2);
    //                break;
    //            default:
    //                return stack.top();
    //                break;
    //            }
    //        }
    //    }
    //    return stack.top();
    //}
};


int main() {
    solution s;
	string prefixExpression = "*+69-31";
    
    int result = s.PrefixSol(prefixExpression);
    cout << "Prefix expression answer is: " << result << endl;

    return 0;
}