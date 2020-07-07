#ifndef BST_NODE_H
#define BST_NODE_H

class BSTNode {
private:
	int value;
	BSTNode *left;
	BSTNode *right;

public:
	BSTNode();
	BSTNode(int value);
	int getValue();
	void setValue(int value);
	BSTNode *getLeft();
	BSTNode *getRight();
	void setRight(BSTNode *node);
	void setLeft(BSTNode *node);
};

#endif
