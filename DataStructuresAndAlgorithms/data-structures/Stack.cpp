#include "Stack.h"

Stack::Stack() : container(new LinkedList()), size(0) {
}

Stack::~Stack() {
	delete container;
}

void Stack::push(int value) {
	container->addAt(value, 0);
	size++;
}

int Stack::pop() {
	int result = container->get(0);
	container->deleteAt(0);
	size--;
	return result;
}
