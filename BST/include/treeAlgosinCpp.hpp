/*
 * treeAlgosinCpp.hpp
 *
 *  Created on: 26-Jun-2017
 *      Author: baliyan
 */
#include <climits>
#include <stack>
#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

const int INF=INT_MAX;
struct node{
	int value;
	node* left_child;
	node* right_child;
};

node* getNode();

class BinarySearchTree{
private:
	node* root;
	void removeCurrentNode(node* current, node* parent);
	void preorderTraverseHelper(node* tree);
	void inorderTraversalHelper(node* tree);
	void postorderTraversalHelper(node* tree);
public:
	BinarySearchTree();
	bool insert(int);
	bool remove(int);
	bool search(int);
	void inorderRecursive();
	void preorderrecursive();
	void postorderrecursive();
};


#endif
