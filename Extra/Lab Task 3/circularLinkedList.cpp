#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() {
        next = nullptr;
        prev = nullptr;
    }
};

class circularLinkedList
{
public:
    Node* head;
    Node* tail;
    circularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // insert node function
    void insertNode(int v) {
        Node* newNode = new Node();
        newNode->data = v;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head;
            head->prev = tail;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            tail->next = head;
            head->prev = tail;
        }
        cout << "Node with value " << v << " inserted." << endl;
    }

    // delete node function
    void deleteNode(int v) {
        Node* temp = searchNode(v);
        if (temp != nullptr) {
            if (temp == head) {
                head = head->next;
                if (head != nullptr) {
                    head->prev = tail;
                }
                tail->next = head;
            }
            else if (temp == tail) {
                tail = tail->prev;
                if (tail != nullptr) {
                    tail->next = head;
                }
                head->prev = tail;
            }
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete temp;
            cout << "Node with value " << v << " deleted." << endl;
        }
        else {
            cout << "Node with value " << v << " not found." << endl;
        }
    }

    // display list function
    void displayList()
    {
    	Node* temp = head;
		if (head == nullptr) {
			cout << "List is empty" << endl;
		}
        else {
            cout << "Values in the list are: " << endl;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            cout<< endl;
        }
    }

    // search node function
    Node* searchNode(int v) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == v) {
                cout << "Node with value " << v << " found." << endl;
                return temp;
            }
            temp = temp->next;
        }
        cout << "Node with value " << v << " not found." << endl;
        return NULL;
    }
};

int main()
{
	// creating an object of circularLinkedList class
	circularLinkedList list;

    // using insertNode function to insert nodes in the list and displaying the list
	list.insertNode(841);
    list.insertNode(56);
    list.insertNode(569);
    list.insertNode(420);
    list.insertNode(69);
    list.displayList();

    // using deleteNode function to delete nodes from the list and displaying the list
    list.deleteNode(420);
    list.deleteNode(56);
    list.displayList();

return 0;
}