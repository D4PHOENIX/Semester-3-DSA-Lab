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
	// display function
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
	// delete function
	void deleteList(int v) {
		Node* temp = searchList(v);
		if (temp == NULL){
			cout << "List is Empty!";
		}
		else if (temp != NULL){
			Node* temp1 = temp;
			Node* temp2 = first;
			if (temp1->next!=NULL){
				first = first->next;
				delete temp1;
				return 0;
			}
			else if (temp1->next !=temp){
				temp2 = temp2->next;
			}
			else if(temp1->next == temp){
				temp2->next = temp1->next;
				delete temp1;
				return 0;
			}
			else
			{
				while (temp1->next != temp){
					temp1 = temp1->next;
				}
				if (temp1->next == temp){
					temp1->next = temp->next;
					delete temp;
					return 0;
				}
			}
		}
	}
	void deleteList(int v) {
		if (first == NULL) {
			cout << "List is Empty!" << endl;
			return;
		}
		if (first->value == v) {
			Node* temp = first;
			first = first->next;
			delete temp;
			return;
		}
		Node* temp1 = first;
		while (temp1->next != NULL) {
			if (temp1->next->value == v) {
				Node* temp2 = temp1->next;
				temp1->next = temp2->next;
				delete temp2;
				return;
			}
			temp1 = temp1->next;
		}
	}
private:
	// search function
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
};