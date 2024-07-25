#include <iostream>
#include "Node.h"
using namespace std;

class PointTree 
{
private:
	Node* root;
	// in-order traversal
	void inOrderTraversal(Node* node) 
	{
		if (node) 
		{
			inOrderTraversal(node->left);
			cout << node->value << " ";
			inOrderTraversal(node->right);
		}
	}

	// pre-order traversal
	void preOrderTraversal(Node* node) 
	{
		if (node) 
		{
			cout << node->value << " ";
			preOrderTraversal(node->left);
			preOrderTraversal(node->right);
		}
	}

	// post-order traversal
	void postOrderTraversal(Node* node) 
	{
		if (node) 
		{
			postOrderTraversal(node->left);
			postOrderTraversal(node->right);
			cout << node->value << " ";
		}
	}
public:
	PointTree():root(nullptr){}
    ~PointTree() 
	{
		delete root; 
	}

	// insert a value into the tree
	void insert(float v)
	{
		Node* newNode = new Node(v);
		// if the tree is empty, set the new node as the root
		if (root == nullptr)
		{
			root = newNode;
			cout << "Inserted " << v << " as the root." << endl;
		}
		else
		{
			Node* current = root;
			while (current)
			{
				if (v < current->value)
				{
					if (current->left)
					{
						current = current->left;
					}
					else
					{
						current->left = newNode;
						cout << "Inserted " << v << " to the left of " << current->value << "." << endl;
						break;
					}
				}
				else
				{
					if (current->right)
					{
						current = current->right;
					}
					else
					{
						current->right = newNode;
						cout << "Inserted " << v << " to the right of " << current->value << "." << endl;
						break;
					}
				}
			}
		}
	}

	// search for a value in the tree
	void search(float v) 
	{
		Node* current = root;
		while (current)
		{
			if (v == current->value)
			{
				cout << v << " found." << endl;
				break;
			}
			else if (v < current->value)
			{
				current = current->left;
			}
			else
			{
				current = current->right;
			}	
		}
		if (current == nullptr)
		{
			cout << v << " not found." << endl;
		}
	}


	// print the tree in in-order
	void inOrder() 
	{
		inOrderTraversal(root);
		cout << endl;
	}

	// print the tree in pre-order
	void preOrder() 
	{
		preOrderTraversal(root);
		cout << endl;
	}

	// print the tree in post-order
	void postOrder() 
	{
		postOrderTraversal(root);
		cout << endl;
	}
};