#include "LinkedList.h"

class Stack{
private:
	int data[];
	// Holds integers
	int size;
	// size of array

public:
	Stack();
	// Creates empty stack
	int empty();
	// Checks if empty and returns 1 if empty and 0 otherwise 
	void push(int val);
	// Appends val and returns 1 if failed and 0 otherwise
	int pop(int *i);
	//Removes and return highest index variable and returns 1 if failed and 0 otherwise
};