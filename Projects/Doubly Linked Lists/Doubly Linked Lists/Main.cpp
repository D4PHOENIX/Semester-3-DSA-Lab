#include <iostream>
#include "doubly_linked.h"
using namespace std;

int main()
{
	doubly_linked list;
	list.insertList(9);
	list.insertList(69);
	list.insertList(42);
	list.insertList(420);
	list.deleteList(9);
	list.displayList();

return 0;
}