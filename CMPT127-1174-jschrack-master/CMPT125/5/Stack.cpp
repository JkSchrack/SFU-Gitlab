#include <cstdlib>
#include <math.h>
#include "Stack.h"
#include "LinkedList.h"

Stack::Stack()
{
	data = NULL;
	size = 0;
}

int Stack::empty()
{
	if(data == NULL) // Checks if stack is empty
	{
		return 1;
	}
	return 0;
}
// Checks if empty and returns 1 if empty and 0 otherwise 
void Stack::push(int val)
{
	data[size] = val;
	append(val);
	size++;
	// inserts its single integer parameter on the stack
}
// Appends val and returns 1 if failed and 0 otherwise
int Stack::pop(int *i)
{
	*i = removeTail();
	size--;
	return *i;
}
//Removes and return highest index variable and returns 1 if failed and 0 otherwise
