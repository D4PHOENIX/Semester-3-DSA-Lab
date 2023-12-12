#include <iostream>
#include "doublyLinkedList.h"
using namespace std;

int main() {
    // creating a doubly linked list object
    doublyLinkedList list;

    // using the insert node function and displaying the list
    list.insertNode(9);
    list.insertNode(69);
    list.insertNode(42);
    list.insertNode(420);
    list.displayList();
    list.count();

    // using the delete node function and displaying the list
    list.deleteNode(69);
    list.deleteNode(420);
    list.displayList();
    list.count();

    // using the insert at head function and displaying the list
	list.insertAtHead(69);
    list.displayList();
    list.count();

return 0;
}
