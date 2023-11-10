#include <iostream>
#include "Node.h"
using namespace std;

class linked_list
{
public:
	Node* first;
	linked_list()
	{
		first = nullptr;
	}

	// insert functions
	//	insert at the end
	void insertNode(int v)
	{
		Node* newNode = new Node();
		newNode->data = v;
		newNode->next = nullptr;
		if (first == nullptr)
		{
			first = newNode;
		}
		else
		{
			Node* temp = first;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
		cout<< "Node "<< v <<" inserted." << endl;
	}
	//	insert at the beginning
	void insertAtBeginning(int v)
	{
		Node* newNode = new Node();
		newNode->data = v;
		newNode->next = first;
		first = newNode;
		cout << "Node "<< v <<" inserted at the beginning." << endl;
	}
	// insert in the middle
	void insertInMiddle(int v)
	{
		Node* newNode = new Node();
		newNode->data = v;
		Node* temp = first;
		int count = 0;
		while (temp != nullptr)
		{
			count++;
			temp = temp->next;
		}
		temp = first;
		for (int i = 0; i < count / 2; i++)
		{
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
		cout << "Node "<< v <<" inserted in the middle" << endl;
	}
	//	insert after a node
	void insertAfterNode(int v, int k)
	{
		Node* newNode = new Node();
		newNode->data = v;
		Node* temp = searchNode(k);
		newNode->next = temp->next;
		temp->next = newNode;
		cout << "Node "<< v <<" inserted after node "<< k << endl;
	}
	// insert in ascending order
	void insertAscending(int v)
	{
		Node* newNode = new Node();
		newNode->data = v;
		newNode->next = nullptr;
		if (first == nullptr || first->data > v)
		{
			newNode->next = first;
			first = newNode;
		}
		else
		{
			Node* temp = first;
			while (temp->next != nullptr && temp->next->data < v)
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		cout<<"Node "<< v <<" inserted in ascending order."<<endl;
	}
	 
	// delete functions
	//delete a specific node
	void deleteNode(int v)
	{
		Node* temp = searchNode(v);
		Node* temp1 = first;
		while (temp1->next != temp)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp->next;
		temp->next = nullptr;
		delete temp;
		cout<<"Successfully deleted node "<<v<<endl;
	}
	// delete from the beginning
	void deleteFromBeginning()
	{
		Node* temp = first;
		first = first->next;
		temp->next = nullptr;
		cout << "Successfully deleted node "<< temp->data << " from the beginning." << endl;
		delete temp;
	}
	// delete from the end
	void deleteFromEnd(){
		Node* temp = first;
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		Node* temp1 = temp->next;
		temp->next = nullptr;
		cout << "Successfully deleted node " << temp1->data << " from the end." << endl;
		delete temp1;
	}
	
	// display function
	void displayList()
	{
		Node* temp = first;
		while (temp != nullptr)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}

	// count function
	void countNodes()
	{
		Node* temp = first;
		int count = 0;
		while (temp != nullptr)
		{
			count++;
			temp = temp->next;
		}
		cout << "Number of nodes in the list are: " << count << endl;
	}

	// search function
	Node* searchNode(int v)
	{
		Node* temp = first;
		while (temp != nullptr)
		{
			if (temp->data == v)
			{
				cout << "Node found" << endl;
				return temp;
			}
			temp = temp->next;
			
		}
		if (temp == nullptr)
		{
			cout << "Node not found" << endl;
			return nullptr;
		}
	}

	// ascending sort function
	void sortAscending()
	{
		Node* temp = first;
		while (temp != nullptr)
		{
			Node* temp1 = temp->next;
			while (temp1 != nullptr)
			{
				if (temp->data > temp1->data)
				{
					int t = temp->data;
					temp->data = temp1->data;
					temp1->data = t;
				}
				temp1 = temp1->next;
			}
			temp = temp->next;
		}
		cout << "List sorted in ascending order." << endl;
	}
};	