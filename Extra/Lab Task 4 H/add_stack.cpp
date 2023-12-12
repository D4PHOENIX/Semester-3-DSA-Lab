#include <iostream>
using namespace std;
const int max_size = 10;

class Stack {
public:
    int stack[max_size];
    int top;
    Stack()
    {
        top = -1;
    }
    void push(int val) {
        if (top == max_size - 1) {
            cout << "Stack is Full";
        }
        else {
            top++;
            stack[top] = val;
            cout << val << " pushed into the stack\n";
        }
    }
    void pop() {
        if (top == -1) {
            cout << "Stack is Empty";
        }
        else {
            cout << "Popped value: " << stack[top] << endl;
            top--;
        }
    }
    int peek() {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            return stack[top];
        }
    }
    bool isEmpty() {
		return (top == -1);
	}
    double stackAverage(int n) {
        if (n <= 0 || n > max_size) {
            cout << "Invalid Input\n";
            return 0.0;
        }
        else {
            int sum = 0;
            for (int i = 0; i <= n; i++) {
                sum += stack[i];
            }
            return static_cast<double>(sum) / n;
        }
    }
};

void add_stack(Stack& stack1, Stack& stack2, Stack& stack3)
{
	while (!stack1.isEmpty() && !stack2.isEmpty())
	{
        int sum = stack1.peek() + stack2.peek();
		stack3.push(sum);
		stack1.pop();
		stack2.pop();
	}
}

int main()
{
	Stack stack1, stack2, stack3;
	stack1.push(11);
	stack1.push(33);
	stack1.push(55);
	stack2.push(22);
	stack2.push(44);
	stack2.push(66);
	add_stack(stack1, stack2, stack3);
	cout << "The resulting stack is: " << stack3.peek() << endl;

return 0;
}