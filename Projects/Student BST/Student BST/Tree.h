#include <iostream>
#include "StudentData.h"
using namespace std;

// Student Tree Class
class Tree {
private:
	Node* root;
    // pre-order traversal function
    void preOrderTraversal(Node* node) {
        if (node != nullptr) {
            node->data.display();
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }
    // post-order traversal function
    void postOrderTraversal(Node* node) {
        if (node != nullptr) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            node->data.display();
        }
    }
    // in-order traversal function
    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            node->data.display();
            inOrderTraversal(node->right);
        }
    }

public:
    // constructor for the tree
	Tree() : root(nullptr){}
	// insert function for the tree
    void insert(const Student& s) {
        Node* newNode = new Node(s);
        int regNo = s.getRegNo();
        string studentName = s.getStudentName();
        float cgpa = s.getCGPA();
        if (root == nullptr) {
            root = newNode;
        }
        else {
            Node* current = root;
            while (true) {
                if (regNo < current->data.getRegNo()) {
                    if (current->left) {
                        current = current->left;
                    }
                    else {
                        current->left = newNode;
                        break;
                    }
                }
                else if (regNo > current->data.getRegNo()) {
                    if (current->right) {
                        current = current->right;
                    }
                    else {
                        current->right = newNode;
                        break;
                    }
                }
                else {
                    cout << "Duplicate Registraton Number." << endl;
                    break;
                }
            }
        }
    }
    
    // search function for the tree
    void search(int regNo) {
        Node* current = root;
        while (current) {
            if (regNo == current->data.getRegNo()) {
                cout << "Student Found: ";
                current->data.display();
                return;
            }
            else if (regNo < current->data.getRegNo()) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        cout << "Student with Reg No " << regNo << " not found." << endl;
    }

    // display functions for different traversals
    // Function to display the tree in pre-order
    void displayPreOrder() {
        preOrderTraversal(root);
    }
    // Function to display the tree in post-order
    void displayPostOrder() {
        postOrderTraversal(root);
    }
    // Function to display the tree in in-order
    void displayInOrder() {
        inOrderTraversal(root);
    }
};