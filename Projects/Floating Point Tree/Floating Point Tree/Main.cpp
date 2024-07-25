#include <iostream>
#include "PointTree.h"
using namespace std;

int main()
{
	// Create a tree object of type PointTree
	PointTree tree;

	// Insert nodes in the tree
	tree.insert(0.69);
	tree.insert(3.69);
	tree.insert(2.69);
	tree.insert(1.69);
	tree.insert(4.69);

	// Search for nodes	in the tree
	tree.search(1.69);
	tree.search(4.69);
	tree.search(5.69);

	// Traverse the tree in in-order
	cout << "In-order traversal: ";
	tree.inOrder();

	// Traverse the tree in pre-order
	cout << "Pre-order traversal: ";
	tree.preOrder();

	// Traverse the tree in post-order
	cout << "Post-order traversal: ";
	tree.postOrder();

return 0;
}