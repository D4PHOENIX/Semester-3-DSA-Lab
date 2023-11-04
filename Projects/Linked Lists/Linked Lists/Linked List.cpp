#include <iostream>
#include "linked_list.h"
using namespace std;

int main() {
	linked_list l;
	l.insertList(78);
	l.insertList(69);
	l.insertList(53);
	l.insertList(85);
	l.displayList();
	l.deleteList(53);
	l.displayList();

return 0;
}