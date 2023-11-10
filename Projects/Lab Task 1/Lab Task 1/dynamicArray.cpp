#include <iostream>
#include "dynamic_array.h"
using namespace std;

int main()
{
    dynamic_array list;
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.count();
    list.display();
    list.retrieve(3);
    list.insert(60, 2);
    list.display();
    list.add(50);
    list.display();
    // is.itemdelete(2);
    cout << "After del the value" << endl;
    list.display();
    list.count();

}
