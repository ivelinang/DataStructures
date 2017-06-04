#pragma once
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTHREE_H

struct Node {
	// value of element
	double elem;
	// left Node
	Node* left;
	// right Node
	Node* right;
};

class BinarySearchTree 
{
private:
	Node* topNode;
	int length;

	void destroyRecursive(Node* node);
public:

	// default constructor
	BinarySearchTree();
	// virtual destructor
	virtual ~BinarySearchTree();

	// isEmpty method
	virtual bool isEmty() const;
	// include another Node in the tree
	virtual void include(double value);
	// contains?
	virtual bool contains(double value) const;
	virtual bool containsv2(double value) const;
	virtual bool containHelper(Node* node, double value) const;
	// remove
	virtual void remove(double value);

	// in-order traversal
	virtual void inOrderTraversal(Node* node) const;
	// pre-order traversal
	virtual void preOrderTraversal(Node* node) const;
	// post-order traversal
	virtual void postOrderTraversal(Node* node) const;

	// print
	virtual void print(Node* tree, int indent=0) const;
	virtual void printv2(Node* tree, int indent = 0) const;
	// get top node
	Node* getTopNode() const;

};


#endif // !BINARYSEARCHTREE_H
