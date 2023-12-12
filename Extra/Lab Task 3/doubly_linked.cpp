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

    ~Node() {
        // No need to delete next in the destructor
        // Set it to nullptr to avoid recursive deletion
        next = nullptr;
    }
};

class doubly_linked {
public:
    Node* head;
    Node* tail;

    doubly_linked() {
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
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Node with value " << v << " inserted." << endl;
    }

    // insert at beginning function
    void insertAtBeginning(int v) {
        Node* newNode = new Node();
        newNode->data = v;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Node with value " << v << " inserted at the beginning." << endl;
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
            } else if (temp == tail) {
                tail = tail->prev;
                if (tail != nullptr) {
                    tail->next = nullptr;
                }
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete temp;
            cout << "Node with value " << v << " deleted." << endl;
        } else {
            cout << "Node with value " << v << " not found." << endl;
        }
    }

    // display list function
    void displayList() {
        Node* temp = head;
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

int main() {
    doubly_linked list;
    list.insertNode(9);
    list.insertNode(69);
    list.insertNode(42);
    list.insertNode(420);
    list.displayList();
    list.deleteNode(42);
    list.displayList();

    return 0;
}
