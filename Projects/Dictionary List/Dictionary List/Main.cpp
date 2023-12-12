#include <iostream>
#include <cstdlib>
#include "Linked List.h"
using namespace std;

// Function to clear the screen
void clearScreen()
{
	cout << "\n Press any key to go back...";
	getchar();
	system("cls");
}

// main function which calls the program in the form of a menu
int main() {
	// Create a linked list object
    AlphabetLinkedList alphabetList;

	// Create a menu for the user to interact with the program
	int choice; // variable to store the choice
	bool exit = false; // flag to exit the menu
	string word; // variable to store the word
	while (!exit) // loop until the user exits the menu
	{
		cout << "1. Insert a word" << endl;
		cout << "2. Delete a word" << endl;
		cout << "3. Display all words" << endl;
		cout << "4. Display statistics" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		clearScreen();
		switch (choice)
		{
		case 1: // insert a word
			cout << "Enter words (type 'exit' to stop):" << endl;
			while (true) //
			{
				cout << "Enter a word to insert: ";
				cin >> word;
				if (word == "exit") 
				{
					break;
				}
				alphabetList.insertWord(word);
			}
			clearScreen();
			break;
		case 2: // delete a word
			cout << "Enter words (type 'exit' to stop):" << endl;
			while (true) 
			{
				cout << "Enter a word to delete: ";
				cin >> word;
				if (word == "exit") 
				{
					break;
				}
				alphabetList.deleteWord(word);
			}
			clearScreen();
			break;
		case 3:	// display all words
			alphabetList.displayWords();
			clearScreen();
			break;
		case 4: // display statistics
			alphabetList.displayStats();
			clearScreen();
			break;
		case 5: // exit
			exit = true;
			clearScreen();
			break;
		default:
			cout << "Invalid choice" << endl;
			clearScreen();
		}
	}

return 0;
}