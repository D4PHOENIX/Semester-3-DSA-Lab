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
    void insert_ascending(int v)
    {
        Node* newNode = new Node();
        newNode->data = v;
        newNode->next = nullptr;
        if (head == nullptr || head->data > v)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while (temp->next != nullptr && temp->next->data < v)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        cout<<"Node inserted in ascending order."<<endl;
    }
};

int main(){
    linked_list l;
    l.insert_ascending(5);
    l.insert_ascending(3);
    l.insert_ascending(4);
    l.insert_ascending(1);
    l.insert_ascending(2);
    l.insert_ascending(6);
    l.insert_ascending(7);
    l.insert_ascending(9);
    l.insert_ascending(8);
    l.insert_ascending(10);
    Node* temp = l.head;
    while (temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

return 0;
}