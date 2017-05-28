//*****************************************************************
//  LinkedList.h
//  HashTable
//
//  
//
//  This header file contains the Linked List class declaration.
//  Hash Table array elements consist of Linked List objects.
//*****************************************************************

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <string>
using namespace std;

//*****************************************************************
// List items are keys with pointers to the next item.
//*****************************************************************
struct Item
{
	string key;
	Item* next;
};

//*****************************************************************
// Linked lists store a variable number of items.
//*****************************************************************
class LinkedList
{
private:
	// Head is a reference to a list of data nodes.
	Item* head;

	// Length is the number of data nodes.
	int length;

public:
	// Constructs the empty linked list object.
	// Creates the head node and sets length to zero.
	LinkedList();

	// Copy constructor
	LinkedList(const LinkedList& other);

	// Assignment operator
	LinkedList& operator=(const LinkedList& other);

	// Inserts an item at the end of the list (item).
	void insertItem(Item* newItem);

	//Inserts an item at the end of the list (string).
	void insertItem(string key);

	//Inserts an item at the beginning
	void insertBegin(string key);

	// Removes an item from the list by item key.
	// Returns true if the operation is successful.
	bool removeItem(string itemKey);

	// Removes duplicate entries
	void removeDuplicate();

	// Searches for an item by its key.
	// Returns a reference to first match.
	// Returns a NULL pointer if no match is found.
	Item* getItem(string itemKey);

	//get the middle element (without using the length attribute)
	Item* getMidItem() const;

	//get head
	Item* getHead() const;

	// Displays list contents to the console window.
	void printList();

	// Returns the length of the list.
	int getLength();

	// Map function to all elements (as in map func in Scala)
	LinkedList* apply(string f(string)) const;
	LinkedList map(string f(string)) const;

	// De-allocates list memory when the program terminates.
	~LinkedList();
};

#endif

//*****************************************************************
// End of File
//**************************************************************