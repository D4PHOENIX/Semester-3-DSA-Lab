#include <iostream>
using namespace std;

int main(){
    // array declaration
    int arrayInit[10];

    // array initialization
    int i = 0, j = 3;
    while(i < 10){
        arrayInit[i] = j;
        i++;
        j += 2;
    }

    // array printing
    for (int i = 0; i < 10; i++){
        cout << arrayInit[i] << endl;
    }

return 0;
}