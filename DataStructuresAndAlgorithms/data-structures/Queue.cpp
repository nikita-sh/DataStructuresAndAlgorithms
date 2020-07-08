#include "Queue.h"

Queue::Queue() : container(new LinkedList), size(0) {
}

Queue::~Queue() {
	delete container;
}

void Queue::push(int value) {
	container->addToEnd(value);
	size++;
}

int Queue::pop() {
	int result = container->get(0);
	container->deleteAt(0);
	size--;
	return result;
}
