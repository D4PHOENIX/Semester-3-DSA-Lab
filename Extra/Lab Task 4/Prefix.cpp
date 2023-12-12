#include <iostream>
#include <cstdlib>

class PrefixSolver {
public:
    static int solve(const char* expression) {
        int operands[100]; // Assuming a limit on the number of operands
        int top = -1;

        int i = 0;
        while (expression[i] != '\0') {
            while (expression[i] == ' ') {
                i++;
            }

            char token[10]; // Assuming a limit on the length of each token
            int j = 0;
            while (expression[i] != ' ' && expression[i] != '\0') {
                token[j++] = expression[i++];
            }
            token[j] = '\0';

            if (isOperator(token)) {
                int operand2 = operands[top--];
                int operand1 = operands[top--];

                int result = applyOperator(token, operand1, operand2);
                operands[++top] = result;
            } else {
                int operand = atoi(token);
                operands[++top] = operand;
            }
        }

        return operands[top];
    }

private:
    static bool isOperator(const char* token) {
        return token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/';
    }

    static int applyOperator(const char* op, int operand1, int operand2) {
        if (op[0] == '+') {
            return operand1 + operand2;
        } else if (op[0] == '-') {
            return operand1 - operand2;
        } else if (op[0] == '*') {
            return operand1 * operand2;
        } else if (op[0] == '/') {
            return operand1 / operand2;  // Assuming no division by zero
        } else {
            // Handle unsupported operators
            std::cerr << "Unsupported operator: " << op << std::endl;
            return 0;  // Default value, you may choose to handle it differently
        }
    }
};


#include "prefix_solver.h"

int main() {
    const char* expression = "* + 6 9 - 3 1";
    int result = PrefixSolver::solve(expression);

    std::cout << "Result: " << result << std::endl;

    return 0;
}