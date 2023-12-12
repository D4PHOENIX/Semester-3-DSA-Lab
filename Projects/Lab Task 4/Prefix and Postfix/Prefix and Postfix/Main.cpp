#include <iostream>
#include "PrePostSolve.h"
using namespace std;

int main() {
    // making an object of the solution class
    solution s;

    // prefix solution
    string prefixExp = "*+69-31";
    int prefixResult = s.PrefixSol(prefixExp);
    cout << "Prefix expression answer is: " << prefixResult << endl;

    // postfix solution
    string postfixExp = "231*+9-";
    int postfixResult = s.PostfixSol(postfixExp);
    cout << "Postfix expression answer is: " << postfixResult << endl;


    return 0;
}