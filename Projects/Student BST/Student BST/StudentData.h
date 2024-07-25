#include <iostream>
using namespace std;

// A class to store a student's details
class Student {
private:
    // privately declared student attributes
    int regNo;
    string studentName;
    float cgpa;
public:
    // Constructor to initialize the student object
    Student(int reg, const string& name, float cgpa) : regNo(reg), studentName(name), cgpa(cgpa) {}
    
    // Function to display student details
    void display() const {
        cout << "Reg No: " << regNo << ", Name: " << studentName << ", CGPA: " << cgpa << endl;
    }
    
    // Getter for registration number
    int getRegNo() const {
        return regNo;
    }
    // Getter for student name
    const string& getStudentName() const {
        return studentName;
    }
    // Getter for CGPA
    float getCGPA() const {
        return cgpa;
    }
};

// A class which creates nodes of the BST
class Node {
public:
    Student data;
    Node* left;
    Node* right;
    Node(const Student& v) : data(v), left(nullptr), right(nullptr) {}
};