#include "LinkedList.h"

#ifndef QUEUE_H
#define QUEUE_H

class Queue {
public:
	LinkedList *container;
	int size;
private:
	Queue();
	~Queue();
	void push(int value);
	int pop();
};

#endif

