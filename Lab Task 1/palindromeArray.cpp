#include <iostream>
using namespace std;

int main(){
    // array declaration
    int array[6];

    // array initialization
    for (int i = 0; i < 6; i++){
        while (array[i] < 0 || array[i] > 9){
            cout << "Enter a value between 0 and 9: ";
            cin >> array[i];
        }
    }
    cout << "\n\n";

    // array printing
    for (int i = 0; i < 6; i++){
        cout << array[i];
    }

    // palindrome check
    if (array[0] == array[5] && array[1] == array[4] && array[2] == array[3]){
        cout << " is a Palindrome value." << endl;
    }
    else{
        cout << " is not a Palindrome value." << endl;
    }

return 0;    
}