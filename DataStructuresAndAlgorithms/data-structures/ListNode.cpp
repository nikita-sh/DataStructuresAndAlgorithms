#include "ListNode.h"

ListNode::ListNode() : value(0), next(nullptr) {
}

ListNode::ListNode(int value) : value(value), next(nullptr) {
}

ListNode::ListNode(int value, ListNode* next) : ListNode(value) {
	this->next = next;
}

int ListNode::getValue() {
	return value;
}

void ListNode::setValue(int val) {
	value = val;
}

void ListNode::setNext(ListNode *n) {
	next = n;
}

ListNode *ListNode::getNext() {
	return next;
}

