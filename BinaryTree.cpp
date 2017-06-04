#include "BinaryTree.h"

//*****************************************************************
//  BinaryTreeEmpty.cpp
//  
//*****************************************************************

BinaryTreeEmpty::BinaryTreeEmpty():
	BinaryTree()
{}

bool BinaryTreeEmpty::isEmty() const
{
	return true;
}

bool BinaryTreeEmpty::contains(double val) const
{
	return false;
}

void BinaryTreeEmpty::include(double val)
{
	return;
}

void BinaryTreeEmpty::remove(double val)
{
	return;
}

//*****************************************************************
//  BinaryTreeNonEmpty.cpp
//  
//*****************************************************************

BinaryTreeNonEmpty::BinaryTreeNonEmpty(double elem_) :
	BinaryTree(), elem(elem_)
{
	left = new BinaryTreeEmpty;
	right = new BinaryTreeEmpty;
}

BinaryTreeNonEmpty::~BinaryTreeNonEmpty()
{}

bool BinaryTreeNonEmpty::isEmty() const
{
	return false;
}

bool BinaryTreeNonEmpty::contains(double val) const
{
	return false;
}

void BinaryTreeNonEmpty::include(double val)
{
	return;
}

void BinaryTreeNonEmpty::remove(double val)
{
	return;
}

