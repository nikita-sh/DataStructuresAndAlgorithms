#include "BSTNode.h"

BSTNode::BSTNode() : value(0), left(nullptr), right(nullptr) {
}

BSTNode::BSTNode(int value) : value(value), left(nullptr), right(nullptr) {
}

void BSTNode::setValue(int value) {
	this->value = value;
}

int BSTNode::getValue() {
	return value;
}

void BSTNode::setLeft(BSTNode *node) {
	left = node;
}

BSTNode *BSTNode::getLeft() {
	return left;
}

void BSTNode::setRight(BSTNode *node) {
	right = node;
}

BSTNode *BSTNode::getRight() {
	return right;
}