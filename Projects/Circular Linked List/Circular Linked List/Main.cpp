#include <iostream>
#include "circularLinkedList.h"
using namespace std;

int main()
{
	// creating an object of circularLinkedList class
	circularLinkedList list;

    // using insertNode function to insert nodes in the list and displaying the list
	list.insertNode(841);
    list.insertNode(56);
    list.insertNode(569);
    list.insertNode(420);
    list.insertNode(69);
    list.displayList();

    // using deleteNode function to delete nodes from the list and displaying the list
    list.deleteNode(420);
    list.deleteNode(56);
    list.displayList();

return 0;
}