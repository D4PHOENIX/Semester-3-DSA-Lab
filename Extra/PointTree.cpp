#include <iostream>
using namespace std;

class Node {
public:
	float num;
	Node* right;
	Node* left;
	Node(){ 
		right = NULL;
		left = NULL;
	}	
};

class Floating_Point_Tree {
private:
	Node* root;
public:
	Floating_Point_Tree(){
		root = NULL;
	}
	void insert_node(float v){
		Node* newNode = new Node();
		newNode->num = v;
		if (root == NULL){
			root = newNode;
			cout << "Inserted " << v << endl;
		}
		else{
			Node* current = root;
			while (current){
				if (v < current->num){
					if (current->left){
						current = current->left;
					}
					else{
						current->left = newNode;
						cout << "Inserted " << v << endl;
						break;
					}
				}
				else{
					if (current->right){
						current = current->right;
					}
					else{
						current->right = newNode;
						cout << "Inserted " << v << endl;
						break;
					}
				}
			}
		}
	}
	void search_node(float v){
		Node* current = root;
		while (current){
			if (v == current->num){
				cout << v << " exists." << endl;
				break;
			}
			else if (v < current->num){
				current = current->left;
			}
			else{
				current = current->right;
			}	
		}
		if (current == NULL){
			cout << v << " does not exist." << endl;
		}
	}

	void in_order(Node* node) {
		if (node) {
			in_order(node->left);
			cout << node->num << " ";
			in_order(node->right);
		}
	}

	void pre_order(Node* node) {
		if (node) {
			cout << node->num << " ";
			pre_order(node->left);
			pre_order(node->right);
		}
	}

	void post_order(Node* node) {
		if (node) {
			post_order(node->left);
			post_order(node->right);
			cout << node->num << " ";
		}
	}

	void display_in_order() {
		in_order(root);
		cout << endl;
	}

	void display_pre_order() {
		pre_order(root);
		cout << endl;
	}

	void display_post_order() {
		post_order(root);
		cout << endl;
	}
};

int main(){
	Floating_Point_Tree tree;
	tree.insert_node(0.69);
	tree.insert_node(3.69);
	tree.insert_node(2.69);
	tree.insert_node(1.69);
	tree.insert_node(4.69);
	tree.search_node(1.69);
	tree.search_node(4.69);
	tree.search_node(5.69);
	cout << "In-order traversal: ";
	tree.display_pre_order();
	cout << "Pre-order traversal: ";
	tree.display_pre_order();
	cout << "Post-order traversal: ";
	tree.display_post_order();

return 0;
}