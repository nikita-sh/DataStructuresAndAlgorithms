#include "BSTNode.h"

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

class BinarySearchTree {
private:
	BSTNode *root;
	int size;

public:
	BinarySearchTree();
	BinarySearchTree(int initial_value);
	~BinarySearchTree();
	BSTNode *find(int value);
	void insert(int value);
	void remove(int value);
	void print();
};

void freeTree(BSTNode *root);
BSTNode *findHelper(BSTNode *root, int value);
void insertHelper(BSTNode *root, int value);
BSTNode *removeHelper(BSTNode *root, int value);
BSTNode *findMin(BSTNode *root);
BSTNode *findMax(BSTNode *root);
void printInorder(BSTNode *root);

#endif
