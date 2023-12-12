using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(){
		next = nullptr;
	}
	~Node(){
		delete next;
	}
};