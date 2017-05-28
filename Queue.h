#pragma once
//*****************************************************************
//  Queue.h
//  
//
//  
//
//  This header file contains the Queue class declaration.//  
//*****************************************************************


#ifndef QUEUE_H
#define QUEUE_H

//*****************************************************************
// Queue stores a variable number of items.
//*****************************************************************

template <class T>
class Queue
{
private:
	// Struct with data member<T> and a pointer to the next Node
	struct Node {
		T data;
		Node* next;
	};
	// Pointer to the top Node
	Node* firstNode;

	// Size of the Queue
	int length;

public:
	//implementation is here as well

	// Constructor
	Queue()
	{
		firstNode = nullptr;
		length = 0;
	}

	// Push new data to the top of the Queue
	void add(T value)
	{
		if (!firstNode)
		{
			Node* newFirst = new Node;
			newFirst->data = value;
			newFirst->next = nullptr;

			firstNode = newFirst;

			length++;
		}
		else
		{
			Node* lastNode = new Node;
			lastNode->data = value;
			lastNode->next = nullptr;

			Node* q = firstNode;
			Node* p = firstNode;

			while (q)
			{
				p = q;
				q = p->next;
			}
			p->next = lastNode;
			length++;
			
		}
		
	}

	// Return the value of the first Node
	T top()
	{
		if (!firstNode)
		{
			std::cout << "Queue is empty";
			std::cin.get();
			throw("Queue is empty!");
		}
		else
			return firstNode->data;
	}

	// Return the top value + remove it
	T pop()
	{
		if (!firstNode)
		{
			std::cout << "Queue is empty";
			std::cin.get();
			throw("Queue is empty!");
		}
		else
		{
			Node *temp = firstNode;
			firstNode = firstNode->next;

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
		Node* p = firstNode;
		Node* q = firstNode;

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
	~Queue()
	{
		if (!firstNode)
			return;
		else
		{
			Node* p = firstNode;
			Node* q = firstNode;

			while (q)
			{
				p = q;
				q = p->next;
				delete p;
			}
		}
	}

};


#endif // !QUEUE_H
