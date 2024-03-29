#pragma once


#include "LinkedList.h"
#include <list>

//*****************************************************************
// Hash Table objects store a fixed number of Linked Lists.
//*****************************************************************

//Hashnode class 
class HashNode
{
public:
	string value;
	int key;

	//Constructor of hashnode  
	HashNode(int key, string value)
	{
		this->value = value;
		this->key = key;
	}
};


class HashMap
{
private:

	// Array is a reference to an array of Linked Lists.
	list<HashNode>*/***/ array; //no need array of pointers (very inefficient), just pointer to array of Lists

	// Length is the size of the Hash Table array.
	int length;

	// Returns an array location for a given item key.
	int hash(int itemKey);

public:

	// Constructs the empty Hash Table object.
	// Array length is set to 13 by default.
	HashMap(int tableLength = 13);

	// Adds an item to the Hash Table.
	//void insertItem(HashNode * newItem);
	void insertItem(int key, string value);

	// Deletes an Item by key from the Hash Table.
	// Returns true if the operation is successful.
	//bool removeItem(int itemKey);

	// Returns an item from the Hash Table by key.
	// If the item isn't found, a null pointer is returned.
	string getItemByKey(int itemKey);

	// Display the contents of the Hash Table to console window.
	//void printTable();

	// Prints a histogram illustrating the Item distribution.
	//void printHistogram();

	// Returns the number of locations in the Hash Table.
	//int getLength();

	// Returns the number of Items in the Hash Table.
	//int getNumberOfItems();

	// De-allocates all memory used for the Hash Table.
	~HashMap();
};
