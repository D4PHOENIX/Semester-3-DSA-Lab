#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node() {
        next = NULL;
        prev = NULL;
    }
};

class circular_list {
public:
    Node* head;
    Node* tail;
    circular_list() {
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
            tail->next = head;
            head->prev = tail;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
            tail->next = head;
            head->prev = tail;
        }
        cout << "Node inserted" << endl;
    }
    void deleteNode(int v) {
        Node* temp = search(v);
        if (temp != NULL) {
            if (temp == head) {
                head = head->next;
                if (head != NULL) {
                    head->prev = tail;
                }
                tail->next = head;
            } else if (temp == tail) {
                tail = tail->prev;
                if (tail != NULL) {
                    tail->next = head;
                }
                head->prev = tail;
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
    Node* search(int v) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->value == v) {
                cout << "Node found" << endl;
                return temp;
            }
            temp = temp->next;
        }
        cout << "Node not found" << endl;
        return NULL;
    }
};

int main() {
    circular_list list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.deleteNode(1);
    list.deleteNode(5);
    list.deleteNode(3);
    list.search(2);
    list.search(4);
    list.search(6);

    return 0;
}
