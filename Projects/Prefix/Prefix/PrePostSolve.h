#include "Stack.h"
using namespace std;

class solution
{
    public:
    int PrefixSol(string exp) {
        Stack stack;
        long len = exp.length();

        // Traverse the expression in reverse order
        for (int i = len - 1; i >= 0; i--) {
            // Push operand to stack
            if (exp[i] >= '0' && exp[i] <= '9') {
                stack.push(exp[i] - '0');
            }
            // Pop two operands and perform the operation
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
    int PostfixSol(string exp)
    {
        Stack stack;
        int len = exp.length();
        // Traverse the expression
    	for (int i = 0; i < len; i++)
        {
            // Push operand to stack
            if (exp[i] >= '0' && exp[i] <= '9'){
                stack.push(exp[i] - '0');
			}
            // Pop two operands and perform the operation
            else
            {
                int op1 = stack.peek();
                stack.pop();
                int op2 = stack.peek();
                stack.pop();
                switch (exp[i])
                {
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
};



