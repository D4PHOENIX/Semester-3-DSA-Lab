#include <iostream>
using namespace std;

int main(){
    int array[10];
    int j = 3;
    for (int i = 0; i < 10; i++){
        array[i] = j;
        j+=2;
    }
    for (int i = 0; i < 10; i++){
        cout << array[i] << endl;
    }

return 0;
}