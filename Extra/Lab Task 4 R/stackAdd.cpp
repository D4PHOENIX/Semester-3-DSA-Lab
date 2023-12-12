#include <iostream>
using namespace std;

class Stack {
public:
    static const int maxsize = 10;
    int stack[maxsize];
    int top;
    Stack()
    {
        top = -1;
    }
    void push(int v) {
        if (isFull()) {
            cout << "Stack is Full";
        }
        else {
            top++;
            stack[top] = v;
            cout << v << " pushed."<< endl;
        }
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Empty";
        }
        else {
            cout << stack[top] << " popped." << endl;
            top--;
        }
    }
    int peek() {
        if (isEmpty())
        {
            cout << "Stack Empty" << endl;
        }
        else
        {
            return stack[top];
        }
    }
    bool isEmpty() {
        return (top == -1);
    }
    bool isFull() {
        return (top == maxsize - 1);
    }
};

void stackAdd(Stack& stack1, Stack& stack2, Stack& stack3)
{
	while (!stack1.isEmpty() && !stack2.isEmpty())
	{
		stack3.push(stack1.peek() + stack2.peek());
		stack1.pop();
		stack2.pop();
	}
}

int main()
{
	Stack s1, s2, s3;
	s1.push(34);
	s1.push(52);
	s1.push(78);
	s2.push(26);
	s2.push(87);
	s2.push(39);
	stackAdd(s1, s2, s3);
	cout << "The resulting stack is: " << s3.peek() << endl;

return 0;
}