//*****************************************************************
//  LinkedList.cpp
//  HashTable
//	Singly linked List - pointer to next element
// 
//
//  This header file contains the Linked List class declaration.
//  Hash Table array elements consist of Linked List objects.
//*****************************************************************

#include "LinkedList.h"
#include <set>

// Constructs the empty linked list object.
// Creates the head node and sets length to zero.
LinkedList::LinkedList()
{
	head = new Item;
	head->next = NULL;
	length = 0;
}

// Copy constructor
LinkedList::LinkedList(const LinkedList& other)
{
	if (!other.head->next)
	{
		head = new Item;
		head->next = NULL;
		length = 0;
	}
	else
	{
		Item* p = other.head;
		Item* q = other.head;

		head = new Item;
		head->next = NULL;
		length = 0;
		
		Item* t = head;		

		while (q)
		{
			p = q;
			q = p->next;
			if (q)
			{
				t->next = new Item;
				t->next->key = q->key;
				t->next->next = NULL;				
	
				t = t->next;
				length++;
			}
			
			
		}
	}
	
}


// Assignment operator
LinkedList& LinkedList::operator=(const LinkedList& other)
{
	if (this != &other)
	{
		//if same length, just change the keys, no need for to delete memory
		if (length == other.length)
		{
			Item* q = other.head; //other
			Item* t = this->head; //this

			while (q)
			{
				q = q->next;
				t = t->next;
				if (q)
				{
					t->key = q->key;
				}
			}
			
		}
		else
		{
			//first delete internal
			Item* t = this->head;
			Item* d = this->head;
			while (t)
			{
				//d = t;
				d = t->next;
				delete t;
				t = d;
			}

			//create new memory following other
			if (!other.head->next)
			{
				head = new Item;
				head->next = NULL;
				length = 0;
			}
			else
			{
				Item* p = other.head;
				Item* q = other.head;

				head = new Item;
				head->next = NULL;
				length = 0;

				Item* t = head;

				while (q)
				{
					p = q;
					q = p->next;
					if (q)
					{
						t->next = new Item;
						t->next->key = q->key;
						t->next->next = NULL;

						t = t->next;
						length++;
					}


				}
			}

		}
	}
	
	return *this;
}


// Inserts an item at the end of the list.
void LinkedList::insertItem(Item* newItem)
{
	if (!head->next)
	{
		head->next = newItem;
		length++;
		return;
	}
	Item* p = head;
	Item* q = head;
	while (q)
	{
		p = q;
		q = p->next;
	}
	p->next = newItem;
	newItem->next = NULL;
	length++;
}

//Inserts an item at the end of the list (string).
void LinkedList::insertItem(string key_) 
{
	if (!head->next)
	{
		head->next = new Item;
		head->next->key = key_;
		head->next->next = NULL;
		length++;
	}
	else
	{
		Item* p = head;
		Item* q = head;
		while (q)
		{
			p = q;
			q = p->next;
		}
		p->next = new Item;
		p->next->key = key_;
		p->next->next = NULL;
		length++;
	}
}

void LinkedList::insertBegin(string key_)
{
	Item* temp = head->next;
	
	Item* newHead = new Item;
	newHead->key = key_;
	newHead->next = temp;

	head->next = newHead;
}

// Removes an item from the list by item key.
// Returns true if the operation is successful.
bool LinkedList::removeItem(string itemKey)
{
	if (!head->next) return false;
	Item * p = head;
	Item * q = head;
	while (q)
	{
		if (q->key == itemKey)
		{
			p->next = q->next;
			delete q;
			length--;
			return true;
		}
		p = q;
		q = p->next;
	}
	return false;
}

#include <set>
// Remove duplicate from list
void LinkedList::removeDuplicate()
{
	set<string> mySet;

	if (!head->next)
		return;

	Item * p = head;
	Item * q = head;
	while (q)
	{
		//if key not in hashset, add to the set
		//else replace the key with next key
		if (mySet.find(q->key) == mySet.end())
		{
			mySet.insert(q->key);
			p = q;
			q = p->next;
		}

		else
		{
			p->next = q->next;
			delete q;
			length--;
			q = p->next;
		}
		//p = q;
		

	}
}

// Searches for an item by its key.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
Item * LinkedList::getItem(string itemKey)
{
	Item * p = head;
	Item * q = head;
	while (q)
	{
		p = q;
		if ((p != head) && (p->key == itemKey))
			return p;
		q = p->next;
	}
	return NULL;
}

// Displays list contents to the console window.
void LinkedList::printList()
{
	if (length == 0)
	{
		cout << "\n{ }\n";
		return;
	}
	Item * p = head;
	Item * q = head;
	cout << "\n{ ";
	while (q)
	{
		p = q;
		if (p != head)
		{
			cout << p->key;
			if (p->next) cout << ", ";
			else cout << " ";
		}
		q = p->next;
	}
	cout << "}\n";
	cin.get();
}

//get the middle element (without using the lenght)
Item* LinkedList::getMidItem() const
{
	if (!head->next)
		return NULL;

	Item* p = head;
	Item* q = head;

	while (q)
	{
		p = p->next;
		q = q->next->next;
		if (!q)
			return p;
		if (!q->next)
			return p;
	}

	return p;
}

// Map function to all elements (as in map func in Scala)
LinkedList* LinkedList::apply(string f(string)) const
{
	LinkedList* result = new LinkedList;

	if (!head->next)
		return result;

	Item* p = head;
	Item* q = head;

	while (q)
	{
		p = q;		
		if (q != head)
		{			
			result->insertItem(f(q->key));			
		}
		q = p->next;
		//if (q != head)
		//	result.insertItem(f(q->key));
		//q = q->next;
	}
	
	return result;
}

LinkedList LinkedList::map(string f(string)) const
{
	LinkedList result;

	if (!head->next)
		return result;

	Item* p = head;
	Item* q = head;

	while (q)
	{
		p = q;
		
		if (q != head)
		{			
			result.insertItem(f(q->key));			
		}
		q = p->next;		
	}
	//result.printList();
	return result;
}

// begin iterator
///*
MyIterator LinkedList::begin()
{
	return MyIterator(head->next);
}
//*/

///*
MyIterator LinkedList::end()
{
	return MyIterator(nullptr);
}
//*/

// Return the head of the list
Item* LinkedList::getHead() const
{
	return head;
}

// Returns the length of the list.
int LinkedList::getLength()
{
	return length;
}

// De-allocates list memory when the program terminates.
LinkedList::~LinkedList()
{
	Item * p = head;
	Item * q = head;
	while (q)
	{
		p = q;
		q = p->next;
		//if (q) 
		delete p;
	}
}

//*****************************************************************
// End of File
//*****************************************************************


