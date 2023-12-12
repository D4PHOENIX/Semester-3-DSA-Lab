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