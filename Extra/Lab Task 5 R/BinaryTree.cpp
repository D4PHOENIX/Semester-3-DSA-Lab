#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(){
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree{
public:
    Node* root;
    BinaryTree(){
        root = nullptr;
    }
    void insert(int v){
        Node* newNode = new Node();
        newNode->data = v;
        if (root == nullptr) 
            root = newNode;
        else {
            Node* current = root;
            while (current) {
                if (current->data > v)
                {
                    if (current->left)
                        current = current->left;
                    else {
                        current->left = newNode;
                        break;
                    }
                    cout << v << " inserted." << endl;
                }
                else if (current->data < v) {
                    if (current->right)
                        current = current->right;
                    else {
                        current->right = newNode;
                        break;
                    }
                    cout << v << " inserted." << endl; 
                }
                else {
                    cout << v << " already exists." << endl;
                    break;
                }
            }
        }
    }
    Node* search(int v){
        Node* current = root;
        while(current){
            if (current->data == v) {
                cout << "Found " << v << endl;
                return current;
            }
            else if(current->data > v)
                current = current->left;
            else
                current = current->right;
        }
        return nullptr;
    }
    Node* deleteNode(Node* root, int v) {
    if (root == nullptr) {
        return root;
    }

    if (v < root->data) {
        root->left = deleteNode(root->left, v);
    } else if (v > root->data) {
        root->right = deleteNode(root->right, v);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

void preorder(Node* current)
{
	if (current) {
		cout << current->data << " ";
		preorder(current->left);
		preorder(current->right);
	}
}
void inorder(Node* current)
{
	if (current) {
		inorder(current->left);
		cout << current->data << " ";
		inorder(current->right);
	}
}
void postorder(Node* current)
{
	if (current) {
		postorder(current->left);
		postorder(current->right);
		cout << current->data << " ";
	}
}
};