#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(){
        next = NULL;
    }
};

class linked_list
{
public:
	Node* head;
	linked_list()
	{
		head = NULL;
	}

	void insert(int v)
	{
		Node* new_node = new Node();
		new_node->data = v;
		new_node->next = NULL;
		if (head == NULL)
		{
			head = new_node;
		}
		else
		{
			Node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
		}
		cout<< "Node inserted." << endl;
	}
	void insert_at_start(int v)
	{
		Node* new_node = new Node();
		new_node->data = v;
		new_node->next = head;
		head = new_node;
		cout << "Node inserted at the start of list." << endl;
	}
	void insert_at_middle(int v)
	{
		Node* new_node = new Node();
		new_node->data = v;
		Node* temp = head;
		int count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		temp = head;
		for (int i = 0; i < count / 2; i++)
		{
			temp = temp->next;
		}
		new_node->next = temp->next;
		temp->next = new_node;
		cout << "Node inserted in the middle of list." << endl;
	}
	void insert_after_node(int v, int n)
	{
		Node* new_node = new Node();
		new_node->data = v;
		Node* temp = search(n);
		new_node->next = temp->next;
		temp->next = new_node;
		cout << "Node inserted after a node "<< endl;
	}
	void delete_node(int v)
	{
		Node* temp = search(v);
		Node* temp1 = head;
		while (temp1->next != temp)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp->next;
		temp->next = NULL;
		delete temp;
		cout<<"Successfully deleted node "<<endl;
	}
	void delete_from_start()
	{
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
		cout << "Successfully deleted node from the start of list." << endl;
		delete temp;
	}
	void delete_from_end(){
		Node* temp = head;
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		Node* temp1 = temp->next;
		temp->next = NULL;
		cout << "Successfully deleted node from the end of list." << endl;
		delete temp1;
	}
	void display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}
	Node* search(int v)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == v)
			{
				cout << "Node found" << endl;
				return temp;
			}
			temp = temp->next;
		}
		if (temp == NULL)
		{
			cout << "Node not found" << endl;
			return NULL;
		}
    }
	void count()
	{
		Node* temp = head;
		int count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		cout << "Number of nodes are: " << count << endl;
	}
};

int main()
{
    linked_list l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert_at_start(0);
    l.insert_at_middle(6);
    l.insert_after_node(7, 6);
    l.display();
    l.delete_node(7);
    l.delete_from_start();
    l.delete_from_end();
    l.display();
    l.count();
    l.search(4);
    l.search(10);
    
return 0;
}