#include <iostream>
using namespace std;

class Student_Data {
public:
    int reg_no;
    string student_name;
    float cgpa;
    Student_Data(int reg_no, const string& name, float cgpa) : reg_no(reg_no), student_name(name), cgpa(cgpa) {}
    void display() {
        cout << "Reg No: " << reg_no << ", Name: " << student_name << ", CGPA: " << cgpa << endl;
    }
};

class Node {
public:
    Student_Data student;
    Node* left;
    Node* right;
    Node(const Student_Data& v) : student(v), left(NULL), right(NULL) {}
};

class Student_Tree {
public:
    Node* root;
    Student_Tree() : root(NULL){}
    void insert_data(const Student_Data& s) {
        Node* newNode = new Node(s);
        if (root == NULL) {
            root = newNode;
        }
        else {
            Node* current = root;
            while (true) {
                if (s.reg_no < current->student.reg_no) {
                    if (current->left) {
                        current = current->left;
                    }
                    else {
                        current->left = newNode;
                        break;
                    }
                }
                else if (s.reg_no > current->student.reg_no) {
                    if (current->right) {
                        current = current->right;
                    }
                    else {
                        current->right = newNode;
                        break;
                    }
                }
                else {
                    cout << "Registraton Number already exists." << endl;
                    break;
                }
            }
        }
    }
        void search(int reg) {
        Node* current = root;
        while (current) {
            if (reg == current->student.reg_no) {
                cout << "Student exists: ";
                current->student.display();
                return;
            }
            else if (reg < current->student.reg_no) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        cout << "Reg No " << reg << " does not exist." << endl;
    }
    void pre_order(Node* node) {
        if (node != NULL) {
            node->student.display();
            pre_order(node->left);
            pre_order(node->right);
        }
    }
    void post_order(Node* node) {
        if (node != NULL) {
            post_order(node->left);
            post_order(node->right);
            node->student.display();
        }
    }
    void in_order(Node* node) {
        if (node != NULL) {
            in_order(node->left);
            node->student.display();
            in_order(node->right);
        }
    }
    void displayPreOrder() {
        pre_order(root);
    }
    void displayPostOrder() {
        post_order(root);
    }
    void displayInOrder() {
        in_order(root);
    }

};

int main() {
    Student_Tree studentData;
    int reg;
    string name;
    float cgpa;
    int num ;
    cout << "Enter number of students: ";
    cin >> num;
    for (int i = 0; i < num; i++) {
        cout << "Enter ID: ";
        cin >> reg;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter CGPA: ";
        cin >> cgpa;
        studentData.insert_data(Student_Data(reg, name, cgpa));
    }
    cout<<"Enter number of students to search: ";
    cin>>num;
    for (int i = 0; i < num; i++) {
        cout << "Enter ID to search: ";
        cin >> reg;
        studentData.search(reg);
    }
    cout << "In Order Display: " << endl;
    studentData.displayInOrder();
    cout << "Pre Order Display: " << endl;
    studentData.displayPreOrder();
    cout << "Post Order Display: " << endl;
    studentData.displayPostOrder();

return 0;
}