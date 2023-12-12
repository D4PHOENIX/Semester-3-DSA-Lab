#include <iostream>
#include "PrePostSolve.h"
using namespace std;

int main() {
    // making an object of the solution class
    solution s;

	string prefixExpression = "*+69-31";
    int preResult = s.PrefixSol(prefixExpression);
    cout << "Prefix expression answer is: " << preResult << endl;

    string postfixExpression = "231*+9-";
    int postResult = s.PostfixSol(postfixExpression);
    cout << "Postfix expression answer is: " << postResult << endl;


return 0;
}