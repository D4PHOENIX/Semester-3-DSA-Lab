#include <iostream>
#include "Node.h"
using namespace std;

class doublyLinkedList {
public:
    Node* head;
    Node* tail;

    doublyLinkedList() {
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
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Node with value " << v << " inserted." << endl;
    }

    // insert at Head function
    void insertAtHead(int v) {
        Node* newNode = new Node();
        newNode->data = v;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Node with value " << v << " inserted at the Head." << endl;
    }

    // delete node function
    void deleteNode(int v) {
        Node* temp = searchNode(v);
        if (temp != nullptr) {
            if (temp == head) {
                head = head->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
            }
            else if (temp == tail) {
                tail = tail->prev;
                if (tail != nullptr) {
                    tail->next = nullptr;
                }
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
    void displayList() {
        Node* temp = head;
        cout << "Values in the list are: " << endl;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // search node function
    Node* searchNode(int v) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == v) {
                cout << "Node with value " << v << " found." << endl;
                break;
            }
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node with value " << v << " not found." << endl;
        }
        return temp;
    }

    // count function
    void count() {
        Node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "Number of nodes in the list are: " << count << endl;
    }
};