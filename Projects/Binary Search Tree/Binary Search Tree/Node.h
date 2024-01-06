class Node {
public:
	int value;
	Node* left;
	Node* right;
	Node(int v): value(v), left(nullptr), right(nullptr) {}
};