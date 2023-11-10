#include <iostream>
#include "linked_list.h"
using namespace std;

void clearScreen()
{
	cout << "\n Press any key to continue...";
	getchar();
	system("cls");
}

int main()
{
	// creating a choice for the user to select the program
	int choice;
	cout << " Press 1 for Program 1 and 2 for Program 2: " << endl;
	cin >> choice;
	clearScreen();

	// creating an object of the class linked_list
	linked_list list;

	// creating a switch case to select the program
	switch (choice)
	{
	case 1:
		// code related to the program 1 of Lab Task 2

		// inserting nodes
		list.insertNode(69);
		list.insertNode(42);
		list.insertNode(888);
		list.insertNode(420);
		list.insertNode(45);
		list.insertNode(67);
		list.insertNode(98);
		// displaying original list
		clearScreen();
		cout << "\n Original List: " << endl;
		list.displayList();
		clearScreen();

		// inserting node at the beginning and after a node
		list.insertAtBeginning(169);
		list.insertAfterNode(420, 42);
		// displaying list after inserting new nodes
		clearScreen();
		cout << "\n Updated List after new insertions: " << endl;
		list.displayList();
		clearScreen();

		//inserting in the middle
		list.insertInMiddle(53);
		// displaying list after inserting node in the middle
		clearScreen();
		cout << "\n Updated List after inserting in the middle: " << endl;
		list.displayList();
		clearScreen();

		//counting nodes in the current version of the list
		list.countNodes();
		clearScreen();

		//deleting some nodes
		list.deleteNode(420);
		list.deleteNode(53);
		//displaying list after deleting nodes
		clearScreen();
		cout << "\n Updated List after Deletions: " << endl;
		list.displayList();
		clearScreen();

		//deleting from beginning and end
		list.deleteFromBeginning();
		list.deleteFromEnd();
		//displaying list after deleting nodes
		clearScreen();
		cout << "\n Updated List after Deletions: " << endl;
		list.displayList();
		clearScreen();

		break;

	case 2:
		// code related to program 2 of Lab Task 2
		//inserting nodes
		list.insertAscending(3);
		list.insertAscending(2);
		list.insertAscending(1);
		list.insertAscending(4);
		list.insertAscending(6);
		list.insertAscending(5);

		//displaying list
		cout << "\nList in Ascending Order: " << endl;
		list.displayList();
		clearScreen();

		break;
	default:
		cout << "\n Invalid Choice!" << endl;
		break;
	}

return 0;
}