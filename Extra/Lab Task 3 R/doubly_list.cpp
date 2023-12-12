#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;
    Node(){
        next = NULL;
        prev = NULL;
    }
};

class doubly_list {
public:
    Node* head;
    Node* tail;
    doubly_list() {
        head = NULL;
        tail = NULL;
    }
    void insert(int v) {
        Node* new_node = new Node();
        new_node->value = v;
        new_node->next = NULL;
        new_node->prev = NULL;
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        cout << "Node inserted" << endl;
    }
    void insertAtBeginning(int v) {
        Node* new_node = new Node();
        new_node->value = v;
        new_node->next = NULL;
        new_node->prev = NULL;
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        cout << "Node inserted at the beginning" << endl;
    }
    void deleteNode(int v) {
        Node* temp = search(v);
        if (temp != NULL) {
            if (temp == head) {
                head = head->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } else if (temp == tail) {
                tail = tail->prev;
                if (tail != NULL) {
                    tail->next = NULL;
                }
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete temp;
            cout << "Node deleted" << endl;
        } else {
            cout << "Node not found" << endl;
        }
    } 
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    Node* search(int v) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->value == v) {
                cout << v << " Node Found" << endl;
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Node Not Found" << endl;
        }
        return temp;
    }
    void count() {
        Node* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "Number of nodes: " << count << endl;
    }
};

int main() {
    doubly_list list;
    list.insert(45);
    list.insert(23);
    list.insert(49);
    list.insert(88);
    list.insert(67);
    list.display();
    list.count();
    list.search(23);
    list.deleteNode(88);
    list.display();
    list.count();

    return 0;
}
