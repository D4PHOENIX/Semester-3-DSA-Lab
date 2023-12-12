#include <iostream>
using namespace std;

void message(int time){
        cout<< "Message calling with "<< time <<" in times.\n";
    if (time > 0){
        cout<< "How you doin'?\n";
        message(time - 1);
    }
        cout<< "Message returning with "<< time <<" in times.\n";
}

int main(){
    message(2);
    
return 0;    
}