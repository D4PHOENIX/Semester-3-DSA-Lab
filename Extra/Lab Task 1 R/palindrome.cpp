#include <iostream>
using namespace std;

int main(){
    int palindrome[6];
    for (int i = 0; i < 6; i++){
        while (palindrome[i] < 0 || palindrome[i] > 9){
            cout << "Enter a value between 0 and 9: ";
            cin >> palindrome[i];
        }
    }
    
    if (palindrome[0] == palindrome[5] && palindrome[1] == palindrome[4] && palindrome[2] == palindrome[3]){
        cout << "\nThis is a Palindrome value." << endl;
    }
    else{
        cout << "\nThis is not a Palindrome value." << endl;
    }

return 0;    
}