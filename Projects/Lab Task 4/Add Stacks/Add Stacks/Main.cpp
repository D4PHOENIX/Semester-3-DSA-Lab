#include <iostream>
#include "Stack.h"
using namespace std;

// addStack function to add the values of two stacks
Stack addStack(Stack& stack1, Stack& stack2, Stack& result)
{
	Stack temp1 = stack1;
	Stack temp2 = stack2;
	while (!temp1.isEmpty() && !temp2.isEmpty())
	{
		result.push(temp1.peek() + temp2.peek());
		temp1.pop();
		temp2.pop();
	}
	return result;
}

int main()
{
	// create two stacks and a result stack
	Stack stack1, stack2, result;

	// push values into the stacks
	stack1.push(50);
	stack1.push(38);
	stack1.push(24);
	stack2.push(19);
	stack2.push(38);
	stack2.push(45);

	// call the addStack function
	addStack(stack1, stack2, result);

	// display the result
	cout << "The result is: " << result.peek() << endl;

return 0;
}