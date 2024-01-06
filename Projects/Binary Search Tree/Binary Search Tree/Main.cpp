#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
	Tree tree;
	tree.insert(5);
	tree.insert(6);
	tree.insert(10);
	tree.insert(10);
	tree.insert(2);
	tree.search(2);
	tree.search(6);
	tree.search(5);

return 0;
}