#include "LinkedList.h"

#ifndef STACK_H
#define STACK_H

class Stack {
private:
	LinkedList *container;
	int size;
public:
	Stack();
	~Stack();
	void push(int value);
	int pop();
};

#endif
