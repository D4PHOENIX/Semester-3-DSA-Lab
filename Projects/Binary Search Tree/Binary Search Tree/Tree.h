#include <iostream>
#include "Node.h"
using namespace std;

class Tree
{
public:
	Node* root;
	Tree(): root(nullptr) {}

	// search for a node
	Node* search(int v)
	{
		Node* current = root;
		while(current){
			if (current->value == v) {
				cout << "Found " << v << endl;
				return current;
			}
			else if(current->value > v)
				current = current->left;
			else
				current = current->right;
		}
		return nullptr;
	}

	// insert a node
	void insert(int v)
	{
		Node* newNode = new Node(v);
		if (root == nullptr) 
			root = newNode;
		else {
			Node* current = root;
			while (current) {
				if (current->value > v)
				{
					if (current->left)
						current = current->left;
					else {
						current->left = newNode;
						break;
					}
					cout << v << " inserted." << endl;
				}
				else if (current->value < v) {
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

	// delete a node
	void deleteNode(int v)
	{
		Node* current = root;
		Node* parent = nullptr;
		while (current) {
			if (current->value == v) {
				if (current->left == nullptr && current->right == nullptr) {
					if (parent->left == current)
						parent->left = nullptr;
					else
						parent->right = nullptr;
					delete current;
					cout << v << " deleted." << endl;
					break;
				}
				else if (current->left == nullptr) {
					if (parent->left == current)
						parent->left = current->right;
					else
						parent->right = current->right;
					delete current;
					cout << v << " deleted." << endl;
					break;
				}
				else if (current->right == nullptr) {
					if (parent->left == current)
						parent->left = current->left;
					else
						parent->right = current->left;
					delete current;
					cout << v << " deleted." << endl;
					break;
				}
				else {
					Node* temp = current->right;
					while (temp->left)
						temp = temp->left;
					current->value = temp->value;
					delete temp;
					cout << v << " deleted." << endl;
					break;
				}
			}
			else if (current->value > v) {
				parent = current;
				current = current->left;
			}
			else {
				parent = current;
				current = current->right;
			}
		}
	}

	void preorder(Node* current)
	{
		if (current) {
			cout << current->value << " ";
			preorder(current->left);
			preorder(current->right);
		}
	}
	void inorder(Node* current)
	{
		if (current) {
			inorder(current->left);
			cout << current->value << " ";
			inorder(current->right);
		}
	}
	void postorder(Node* current)
	{
		if (current) {
			postorder(current->left);
			postorder(current->right);
			cout << current->value << " ";
		}
	}
};