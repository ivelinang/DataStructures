//*****************************************************************
//  BinarySearchTree.cpp
//  
//*****************************************************************

#include "BinarySearchTree.h"
#include <iostream>
#include <iomanip>

// default constructor
BinarySearchTree::BinarySearchTree()
{
	topNode = nullptr;
	length = 0;
}

void BinarySearchTree::destroyRecursive(Node* node)
{
	if (node)
	{
		destroyRecursive(node->left);
		destroyRecursive(node->right);
		std::cout << "delete: " << node->elem;
		//std::cin.get();
		delete node;
	}
}

// destructor
BinarySearchTree::~BinarySearchTree()
{
	destroyRecursive(topNode);
	std::cout << "deletion done!";
	std::cin.get();
}

// isEmpty?
bool BinarySearchTree::isEmty() const
{
	return (topNode) ? false : true;
}

// get top node
Node* BinarySearchTree::getTopNode() const
{
	return topNode;
}

// in order traversal
void BinarySearchTree::inOrderTraversal(Node* node) const
{
	if (node)
	{
		inOrderTraversal(node->left);
		std::cout << node->elem << "\n";
		inOrderTraversal(node->right);
	}
}

// pre order traversal
void BinarySearchTree::preOrderTraversal(Node* node) const
{
	if (node)
	{
		std::cout << node->elem << "\n";
		preOrderTraversal(node->left);		
		preOrderTraversal(node->right);
	}
}

// post order traversal
void BinarySearchTree::postOrderTraversal(Node* node) const
{
	if (node)
	{
		
		postOrderTraversal(node->left);
		postOrderTraversal(node->right);
		std::cout << node->elem << "\n";
	}
}

// include another member
void BinarySearchTree::include(double val)
{
	// if empty
	if (!topNode)
	{
		topNode = new Node;
		topNode->elem = val;
		topNode->left = nullptr;
		topNode->right = nullptr;
	}
	// else
	else
	{
		Node* q = topNode;
		
		Node* w = new Node;
		w->elem = val;
		w->left = nullptr;
		w->right = nullptr;

		bool check = true;

		while (check)
		{
			if (val == q->elem)
				throw("no duplicated allowed in binary tree");
			if (val < q->elem)
			{
				if (!q->left)
				{
					q->left = w;
					length++;
					check = false;
				}
													
				q = q->left;
			}
			else
			{
				if (!q->right)
				{
					q->right = w;
					length++;
					check = false;
				}

				q = q->right;
			}

		}
	}

}

// remove element
void BinarySearchTree::remove(double value)
{
	return;
}

// contains element?
bool BinarySearchTree::contains(double value) const
{
	if (!topNode)
		return false;

	Node* q = topNode;

	while (q)
	{
		if (q->elem == value)
			return true;
		else
		{
			if (value < q->elem)
				q = q->left;
			else
				q = q->right;
		}		
	}

	return false;
	
}

// contains Helper
bool BinarySearchTree::containHelper(Node* node, double value) const
{
	if (!node)
		return false;
	else
	{
		if (node->elem == value)
			return true;
		else
		{
			if (value < node->elem)
				containHelper(node->left, value);
			else
				containHelper(node->right, value);
		}
	}

}

// contains v2 - recursive
bool BinarySearchTree::containsv2(double value) const
{
	return containHelper(topNode, value);
}

void BinarySearchTree::print(Node* tree, int indent) const
{
	if (tree)
	{
		if (tree->right)
		{
			print(tree->right, indent + 4);
		}
		if (indent)
			std::cout << std::setw(indent) << ' ';
		if (tree->right) std::cout << "/ \n" << std::setw(indent) << ' ';
		std::cout << tree->elem << "\n";
		if (tree->left)
		{
			std::cout << std::setw(indent) << ' ' << "\ \n";
			print(tree->left, indent + 4);
		}
	}
	std::cin.get();
}

void BinarySearchTree::printv2(Node* tree, int indent) const
{
	if (tree)
	{	
		if (indent)
			std::cout << std::setw(indent) << ' ';
		std::cout << tree->elem << "\n";
		if (tree->left) printv2(tree->left, indent + 4);
		if (tree->right) printv2(tree->right, indent + 4);
		
		

	}
	std::cin.get();
}


