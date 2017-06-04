//*****************************************************************
//  BinaryTree.h
//  Implementation of BinarySearchTree
//	All elements on the left are lower than elements on the right
//  
//
//  
//*****************************************************************


#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H

//*****************************************************************
// Binary Tree.
// Abstract Class.
// Can have two nodes - Empty and NonEmpty
// Empty, NonEmpty are derived classes
//*****************************************************************
class BinaryTree 
{


public:
	// default constructor
	BinaryTree() {};
	// virtual destructor
	virtual ~BinaryTree() {};

	// isEmpty method
	virtual bool isEmty() const = 0;
	// include another Node in the tree
	virtual void include(double value) = 0;
	// contains?
	virtual bool contains(double value) const = 0;
	// remove
	virtual void remove(double value) = 0;



};

class BinaryTreeEmpty : public BinaryTree
{
public:
	// default constructor
	BinaryTreeEmpty();
	// virtual destructor
	virtual ~BinaryTreeEmpty() {};

	// isEmpty method
	virtual bool isEmty() const ;
	// include another Node in the tree
	virtual void include(double value) ;
	// contains?
	virtual bool contains(double value) const ;
	// remove
	virtual void remove(double value) ;
};

class BinaryTreeNonEmpty : public BinaryTree
{
public:
	// default constructor
	BinaryTreeNonEmpty(double elem_);
	// virtual destructor
	virtual ~BinaryTreeNonEmpty();

	// isEmpty method
	virtual bool isEmty() const;
	// include another Node in the tree
	virtual void include(double value);
	// contains?
	virtual bool contains(double value) const;
	// remove
	virtual void remove(double value);

private:
	// value of element
	double elem;
	// left Node
	BinaryTree* left;
	// right Node
	BinaryTree* right;
};


#endif // !BINARYTREE_H


