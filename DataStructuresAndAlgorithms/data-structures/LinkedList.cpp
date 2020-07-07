#include "LinkedList.h"
#include <iostream>
#include <assert.h>

LinkedList::LinkedList() : head(nullptr), tail(nullptr), length(0) {
}

LinkedList::~LinkedList() {
	ListNode* temp = nullptr;
	ListNode* curr = this->getHead();
	while (curr) {
		temp = curr;
		curr = curr->getNext();
		delete temp;
	}
}

ListNode* LinkedList::getHead() {
	return head;
}

ListNode* LinkedList::getTail() {
	return tail;
}

void LinkedList::addNode(int value) {
	ListNode* newNode = new ListNode(value);

	if (!head) {
		head = tail = newNode;
		length = 1;
		return;
	}

	tail->setNext(newNode);
	tail = tail->getNext();
	length++;
}

void LinkedList::deleteLast() {
	if (!head) {
		return;
	}

	ListNode* curr = head, *prev = nullptr;
	while (curr != tail) {
		prev = curr;
		curr = curr->getNext();
	}

	if (curr == head) {
		delete curr;
		head = tail = nullptr;
		length = 0;
		return;
	}

	delete curr;
	prev->setNext(nullptr);
	tail = prev;
	length--;
}


void LinkedList::deleteNode(ListNode* node) {
	if (!head) {
		return;
	} else if (head == node) {
		ListNode* temp = head;
		head = head->getNext();
		delete temp;
		length--;
		return;
	}

	ListNode* prev = nullptr, *curr = head;
	while (curr != node) {
		prev = curr;
		curr = curr->getNext();
	}

	prev->setNext(curr->getNext());
	delete curr;
	length--;
}

void LinkedList::addAt(int value, int position) {
	assert(position <= length);

	int curr_pos = 0;
	ListNode* curr = head;
	ListNode* newNode = new ListNode(value);

	if (position == 0) {
		newNode->setNext(head);
		head = newNode;
	} else if (position == length) {
		tail->setNext(newNode);
		tail = newNode;
	} else {
		while (curr_pos < position - 1) {
			curr_pos++;
			curr = curr->getNext();
		}

		newNode->setNext(curr->getNext());
		curr->setNext(newNode);
	}
	length++;
}

void LinkedList::deleteAt(int position) {
	assert(position < length);

	int curr_pos = 0;
	ListNode* curr = head, *prev = nullptr;

	if (position == 0) {
		head = curr->getNext();
		delete curr;
		length--;
	}
	else if (position == length - 1) {
		deleteLast();
	}
	else {
		while (curr_pos < position) {
			curr_pos++;
			prev = curr;
			curr = curr->getNext();
		}
		prev->setNext(curr->getNext());
		delete curr;
		length--;
	}
}

void LinkedList::printList() {
	ListNode* curr = head;
	while (curr) {
		std::cout << curr->getValue() << " -> ";
		curr = curr->getNext();
	}
	std::cout << "NULL" << std::endl;
}