#ifndef LIST_NODE_H
#define LIST_NODE_H

class ListNode {
public:
	ListNode();
	ListNode(int value);
	ListNode(int value, ListNode* next);
	int getValue();
	void setValue(int val);
	void setNext(ListNode *n);
	ListNode* getNext();
private:
	int value;
	ListNode *next;
};

#endif
