class Node {
public:
	float value;
	Node* right;
	Node* left;
	Node(float v): value(v), right(nullptr), left(nullptr) {};
	~Node()
	{
		delete right;
		delete left;
	}
};