#include "ListNode.h"

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList {
private:
	ListNode* head;
	ListNode* tail;
	int length;
public:
	LinkedList();
	~LinkedList();
	ListNode* getHead();
	ListNode* getTail();
	void addNode(int value);
	void deleteLast();
	void deleteNode(ListNode* node);
	void addAt(int value, int position);
	void deleteAt(int position);
	void printList();
};

#endif
