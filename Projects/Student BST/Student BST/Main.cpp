#include <iostream>
#include "Tree.h"
using namespace std;

// function to clear screen
void clearScreen()
{
	cout << "\n Press any key to continue...";
	getchar();
	system("cls");
}

int main() {
	// creating object of Tree class
	Tree studentData;
	
	// taking input
	bool flag1 = true;
	while (flag1) {
		int id;
		string name;
		double cgpa;
		cout << "Enter ID: ";
		cin >> id;
		cout << "Enter Name: ";
		cin >> name;
		cout << "Enter CGPA: ";
		cin >> cgpa;
		studentData.insert(Student(id, name, cgpa));
		cout << "Do you want to enter more data? (1/0): ";
		cin >> flag1;
	}
	// clearing screen after taking input
	clearScreen();
	
	// searching data
	bool flag2 = true;
	while (flag2){
		int id;
		cout << "Enter ID to search: ";
		cin >> id;
		studentData.search(id);
		cout << "Do you want to search more data? (1/0): ";
		cin >> flag2;
	}
	// clearing screen after searching data
	clearScreen();

	// displaying data in different orders
	cout<< "Displaying data in different orders: \n";
	// displaying data in in-order
	cout<< "\nIn-Order: \n";
	studentData.displayInOrder();
	// displaying data in pre-order
	cout << "\nPre-Order: \n";
	studentData.displayPreOrder();
	// displaying data in post-order
	cout<< "\nPost-Order: \n";
	studentData.displayPostOrder();
	// clearing screen after displaying data
	clearScreen();

return 0;
}