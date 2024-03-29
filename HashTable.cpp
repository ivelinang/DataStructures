//*****************************************************************
//  HashTable.cpp
//  HashTable
//
//  
//  This header file contains the Hash Table class definition.
//  Hash Table array elements consist of Linked List objects.
//*****************************************************************

#include "HashTable.h"

// Constructs the empty Hash Table object.
// Array length is set to 13 by default.
HashTable::HashTable(int tableLength)
{
	if (tableLength <= 0) tableLength = 13;
	array = new LinkedList*[tableLength]; //array of length tablelength, each elem is pointer to LinkedList
	std::fill_n(array, tableLength, nullptr);
	length = tableLength;
}

// Returns an array location for a given item key.
int HashTable::hash(string itemKey)
{
	int value = 0;
	for (int i = 0; i < itemKey.length(); i++)
		value += itemKey[i];
	return (itemKey.length() * value) % length;
}

// Adds an item to the Hash Table.
void HashTable::insertItem(Item * newItem)
{
	int index = hash(newItem->key);
	if (!array[index])
		array[index] = new LinkedList; //create new linkedlist
	array[index]->insertItem(newItem);
}

void HashTable::insertItem(string key)
{
	Item* temp = new Item;
	temp->key = key;
	temp->next = NULL;

	insertItem(temp);

}

// Deletes an Item by key from the Hash Table.
// Returns true if the operation is successful.
bool HashTable::removeItem(string itemKey)
{
	int index = hash(itemKey);
	return array[index]->removeItem(itemKey);
}

// Returns an item from the Hash Table by key.
// If the item isn't found, a null pointer is returned.
Item * HashTable::getItemByKey(string itemKey)
{
	int index = hash(itemKey);
	return array[index]->getItem(itemKey);
}

// Display the contents of the Hash Table to console window.
void HashTable::printTable()
{
	cout << "\nHash Table:\n";
	for (int i = 0; i < length; i++)
	{
		cout << "Bucket " << i + 1 << ": ";
		if (array[i])
			array[i]->printList();
	}
}

// Prints a histogram illustrating the Item distribution.
void HashTable::printHistogram()
{
	cout << "\n\nHash Table Contains ";
	cout << getNumberOfItems() << " Items total\n";
	for (int i = 0; i < length; i++)
	{
		cout << i + 1 << ":\t";
		for (int j = 0; j < array[i]->getLength(); j++)
			cout << " X";
		cout << "\n";
	}
}

// Returns the number of locations in the Hash Table.
int HashTable::getLength()
{
	return length;
}

// Returns the number of Items in the Hash Table.
int HashTable::getNumberOfItems()
{
	int itemCount = 0;
	for (int i = 0; i < length; i++)
		itemCount += array[i]->getLength();
	return itemCount;
}

// De-allocates all memory used for the Hash Table.
HashTable::~HashTable()
{
	delete[] array;
}

//*****************************************************************
// End of File
//*****************************************************************