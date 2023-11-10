#include <iostream>
#include "Node.h"
using namespace std;

class doubly_linked
{
public:
	Node* head;
	doubly_linked()
	{
		head = nullptr;
	}
	void insertList(int v)
	{
		Node* newNode = new Node();
		newNode->data = v;
		if (head == nullptr)
		{
			head = newNode;
			head->next = nullptr;
			head->prev = nullptr;
		}
		else
		{
			Node* temp = head;
			while(temp->next == nullptr)
			{
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->next = nullptr;
			newNode->prev = temp;
		}
	}
	void displayList(){
		cout << "Values in the Linked List are as Follows: " << endl;
		cout << head->data << endl;
		Node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
			cout << temp->data;
		}
	}
	Node* searchList(int v)
	{
		Node* temp = head;
		while (temp->data == v)
		{
			if (temp->data == v)
			{
				cout << "Value is Found";
				return temp;
			}
			temp = temp->next;
		}
		return nullptr;
	}
	void deleteList(int v)
	{
		Node* t = searchList(v);
		if (t == nullptr)
		{
			cout << "Value not Found.";
		}
		else if(t == head)
		{
			head = head->next;
			head->prev = nullptr;
			delete t;
		}
		else
		{
			t->prev->next = t->next;
			t->next->prev = t->prev;
			delete t;
		}
	}
};