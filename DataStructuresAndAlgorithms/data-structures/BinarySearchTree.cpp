#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() : root(nullptr), size(0) {
}

BinarySearchTree::BinarySearchTree(int initial_value) : BinarySearchTree() {
	BSTNode *newNode = new BSTNode(initial_value);
	root = newNode;
}

BinarySearchTree::~BinarySearchTree() {
	freeTree(root);
}

void freeTree(BSTNode *root) {
	if (!root) {
		return;
	} else if (root->getLeft() == nullptr && root->getRight() == nullptr) {
		delete root;
	} else if (root->getLeft() != nullptr && root->getRight() == nullptr) {
		freeTree(root->getLeft());
		delete root;
	} else if (root->getLeft() == nullptr && root->getRight() != nullptr) {
		freeTree(root->getRight());
		delete root;
	} else {
		freeTree(root->getRight());
		freeTree(root->getLeft());
		delete root;
	}
}

BSTNode *BinarySearchTree::find(int value) {
	return findHelper(root, value);
}

BSTNode *findHelper(BSTNode *root, int value) {
	if (!root) {
		return nullptr;
	}

	if (root->getValue() == value) {
		return root;
	} else if (value < root->getValue()) {
		return findHelper(root->getLeft(), value);
	} else {
		return findHelper(root->getRight(), value);
	}
}

void BinarySearchTree::insert(int value) {
	if (!root) {
		root = new BSTNode(value);
		size = 1;
		return;
	}

	insertHelper(root, value);
	size++;
}

void insertHelper(BSTNode *root, int value) {
	BSTNode *newNode = new BSTNode(value);

	if (value <= root->getValue()) {
		if (!root->getLeft()) {
			root->setLeft(newNode);
		} else {
			insertHelper(root->getLeft(), value);
		}
	} else {
		if (!root->getRight()) {
			root->setRight(newNode);
		} else {
			insertHelper(root->getRight(), value);
		}
	}
}

void BinarySearchTree::remove(int value) {
	root = removeHelper(root, value);
	size--;
}

BSTNode *removeHelper(BSTNode *root, int value) {
	BSTNode *temp;

	if (!root) {
		return nullptr;
	} else if (value < root->getValue()) {
		root->setLeft(removeHelper(root->getLeft(), value));
	} else if (value > root->getValue()) {
		root->setRight(removeHelper(root->getRight(), value));
	} else if (root->getLeft() && root->getRight()) {
		temp = findMin(root->getRight());
		root->setValue(temp->getValue());
		root->setRight(removeHelper(root->getRight(), root->getValue()));
	} else {
		temp = root;
		if (!root->getLeft()) {
			root = root->getRight();
		} else {
			root = root->getLeft();
		}
		delete temp;
	}
	return root;
}

BSTNode *findMin(BSTNode *root) {
	while (root->getLeft()) {
		root = root->getLeft();
	}
	return root;
}

BSTNode *findMax(BSTNode *root) {
	while (root->getRight()) {
		root = root->getRight();
	}
	return root;
}

void printInorder(BSTNode *root) {
	if (!root) {
		return;
	}
	printInorder(root->getLeft());
	std::cout << root->getValue() << " ";
	printInorder(root->getRight());
}

void BinarySearchTree::print() {
	printInorder(root);
	std::cout << std::endl;
}