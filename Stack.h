#pragma once
//*****************************************************************
//  Stack.h
//  
//
//  
//
//  This header file contains the Stack class declaration.//  
//*****************************************************************


#ifndef STACK_H
#define STACK_H

#include <iostream>

//*****************************************************************
// Stack stores a variable number of items.
//*****************************************************************

template <class T>
class Stack
{
private:
	// Struct with data member<T> and a pointer to the next Node
	struct Node {
		T data;
		Node* next;
	};
	// Pointer to the top Node
	Node* topNode;

	// Size of the stack
	int length;

public:
	//implementation is here as well

	// Constructor
	Stack()
	{
		topNode = nullptr;
		length = 0;
	}

	// Push new data to the top of the stack
	void push(T value)
	{
		
		Node* newTop = new Node;
		newTop->data = value;
		newTop->next = topNode;

		topNode = newTop;

		length++;			
	}

	// Return the value of the top Node
	T top()
	{
		if (!topNode)
		{
			std::cout << "stack is empty";
			std::cin.get();
			throw("stack is empty!");
		}			
		else
			return topNode->data;
	}

	// Return the top value + remove it
	T pop()
	{
		if (!topNode)
		{
			std::cout << "stack is empty";
			std::cin.get();				
			throw("stack is empty!");			
		}
		else
		{
			Node *temp = topNode;
			topNode = topNode->next;

			T value = temp->data;
			delete temp;
			length--;

			return value;
		}
	}

	// print data
	void printData()
	{
		if (length == 0)
		{
			std::cout << "\n{ }\n";
			return;
		}
		Node* p = topNode;
		Node* q = topNode;

		std::cout << "\n{ ";

		while (q)
		{
			p = q;
			
			std::cout << p->data;
			if (p->next) std::cout << ", ";
			else std::cout << " ";
			
			q = p->next;
		}
		std::cout << "}\n";
		std::cin.get();
	
	}

	// destructor
	~Stack()
	{
		if (!topNode)
			return;
		else
		{
			Node* p = topNode;
			Node* q = topNode;

			while (q)
			{
				p = q;
				q = p->next;
				delete p;
			}
		}
	}

};

#endif // !STACK_H
