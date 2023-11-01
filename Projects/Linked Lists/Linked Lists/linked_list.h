#include <iostream>
#include <cstddef>
#include "Node.h"
using namespace std;

class linked_list {
public:
	Node* first;
	linked_list() {
		first = NULL;
	}
	// insert function
	void insertList(int v) {
		if (first == NULL) {
			Node* temp = new Node();
			temp->value = v;
			temp->next = NULL;
			first = temp;
		}
		else {
			Node* temp = first;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = new Node();
			temp = temp->next;
			temp->value = v;
			temp->next = NULL;
		}

	}
	void displayList() {
		cout << "Values are: " << endl;
		cout << first->value << endl;
		Node* temp = first;
		while (temp->next != NULL)
		{
			temp = temp->next;
			cout << temp->value;
		}
	}
	void searchList(int v) {
		Node* temp = first;
		while (temp != NULL) {
			if (temp->value == v) {
				cout << "Value found" << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "Value not found" << endl;

	}

	void deleteList() {
		Node* temp = first;
		while (temp != NULL)
		{
			Node* temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
		first = NULL;
	}

};
