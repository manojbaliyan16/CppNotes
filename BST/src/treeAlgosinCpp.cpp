/*
 * treeAlgosinCpp.cpp
 *
 *  Created on: 26-Jun-2017
 *      Author: baliyan
 */
#include <iostream>
#include <stack>
#include "../include/treeAlgosinCpp.hpp"
using namespace std;

node* getNode() {

	node* newnode = new node();
	newnode->left_child = NULL;
	newnode->right_child = NULL;

	return newnode;
}

BinarySearchTree::BinarySearchTree() {
	root = getNode();
	root->value = INF;
}

bool BinarySearchTree::insert(int value) {

	if (root->value == INF) {
		root->value = value;
		return true;
	}
	node* current = root;
	node* newNode = getNode();
	if (newNode == NULL) {
		cout << "memory is not allocate to node" << endl;
		return false;
	}
	while (true) {
		if (value <= current->value) {
			if (current->left_child == NULL) {
				current->left_child = newNode;
				current->left_child->value = value;
				return true;
			} else {
				current = current->left_child;
			}
		} else {
			if (current->right_child == NULL) {
				current->right_child = newNode;
				current->right_child->value = value;
				return true;
			} else {
				current = current->right_child;
			}
		}
	}

}
/*
 Remove: It remove that node by value
 */
bool BinarySearchTree::remove(int value) {
	if (root->value == INF) {
		return false;
	}
	node* current = root;
	node* parent = NULL;
	while (true) {
		if (value == current->value) {
			removeCurrentNode(current, parent);
		} else {
			parent = current;
			if (value <= current->value) {
				current = current->left_child;
			} else {
				current = current->right_child;
			}
		}
		if (current == NULL) {
			return false;
		}
	}
}
void BinarySearchTree::removeCurrentNode(node* current, node* parent) {
	node* toBeDeleted;
	node* successor;
	node* successorParent = NULL;
// if current node has no child
	if (current->left_child == NULL and current->right_child == NULL) {
		if (parent == NULL) {
			current->value = INF;
		} else {
			if (parent->left_child == current) {
				parent->left_child = NULL;
			} else {
				parent->right_child = NULL;
			}
			delete current;
		}

	} else if (current->right_child == NULL) {
		toBeDeleted = current->left_child;
		current->left_child->value = current->value;
		current->right_child = current->left_child->right_child;
		current->left_child = current->left_child->left_child;
		delete toBeDeleted;
	} else {
		successor = current->right_child;
		successorParent = NULL;
		while (successor->left_child != NULL) {
			successorParent = successor;
			successor = successor->left_child;
		}
		if (successorParent == NULL) {
			current->right_child = successor->right_child;
		} else {
			successorParent->left_child = successor->right_child;
		}
		current->value = successor->value;
		delete successor;
	}

}
bool BinarySearchTree::search(int value) {
	node* current = root;
	while (true) {
		if (value < current->value) {
			if (current->left_child == NULL) {
				return false;
			} else {
				current = current->left_child;
			}
		} else if (value > current->value) {
			if (current->right_child == NULL) {
				return false;
			} else {
				current = current->right_child;
			}
		} else {
			return true;
		}
	}
}
void BinarySearchTree::inorderTraversalHelper(node* tree) {
	if (tree == NULL or tree->value == INF) {
		return;
	}
	inorderTraversalHelper(tree->left_child);
	cout << tree->value << endl;
	inorderTraversalHelper(tree->right_child);
}
void BinarySearchTree::inorderRecursive() {
	inorderTraversalHelper(root);
}
void BinarySearchTree::preorderTraverseHelper(node* tree) {
	if (tree == NULL or tree->value == INF) {
		return;
	}
	cout << tree->value << endl;
	preorderTraverseHelper(tree->left_child);
	preorderTraverseHelper(tree->right_child);
}
void BinarySearchTree::preorderrecursive() {
	preorderTraverseHelper(root);
}
void BinarySearchTree::postorderTraversalHelper(node *tree) {
	if (tree == NULL or tree->value == INF) {
		return;
	}
	postorderTraversalHelper(tree->left_child);
	postorderTraversalHelper(tree->right_child);
	cout << tree->value << endl;
}

void BinarySearchTree::postorderrecursive() {
	postorderTraversalHelper(root);
}

int main() {
	cout << "Insert the node in to BST" << endl;
	BinarySearchTree tree;
	tree.insert(10);
	tree.insert(14);
	tree.insert(12);
	tree.insert(5);
	cout << "In Order Traversal: \n";
	tree.inorderRecursive();

	cout << "Pre Order Traversal: \n";
	tree.preorderrecursive();

	cout << "Post Order Traversal: \n";
	tree.postorderrecursive();

	cout << "Searching 10 : ";
	if (tree.search(10))
		cout << "Found!\n";
	else
		cout << "Not found!\n";

	cout << "Removing 10\n";
	tree.remove(10);
	cout << "Searching 10 : ";
	if (tree.search(10))
		cout << "Found!\n";
	else
		cout << "Not found!\n";
	return 0;

}
