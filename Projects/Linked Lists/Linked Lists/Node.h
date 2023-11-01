#include <cstddef>

class Node {
public:
	int value;
	Node* next;
	Node() {
		next = NULL;
	}
	~Node() {
		delete next;
	}
};
