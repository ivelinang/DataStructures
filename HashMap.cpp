#include "HashMap.h"

HashMap::HashMap(int tableLength)
{
	if (tableLength <= 0) tableLength = 13;
	array = new list<HashNode>/***/[tableLength]; //just array of pointers to a linked list (std::list)
	//std::fill_n(array, tableLength, nullptr);
	length = tableLength;
}

int HashMap::hash(int key)
{
	return key % length;
}


void HashMap::insertItem(int key, string value)
{
	int index = hash(key);
	//if (!array[index])
	//	array[index] = /*new*/ list<HashNode>(); //you dont need pointer to a pointer to new List ? why, no need for pointer to std::vector??
	HashNode temp(key, value);
	array[index]/*->*/.push_front(temp);
}

string HashMap::getItemByKey(int itemKey)
{
	int index = hash(itemKey);
	if (/*!*/array[index].empty())
		throw std::runtime_error("key not found"); //if item has not been initiated
	else
	{
		auto myList = array[index];
		for (auto it = myList/*->*/.begin(); it != myList/*->*/.end(); ++it)
		{
			if (it->key == itemKey)
				return it->value;
		}
	}

	throw std::runtime_error("key not found");

}

HashMap::~HashMap()
{
	for (unsigned int i = 0; i < length; ++i)
	{
		/*if (array[i])
		{
			auto temp = array[i];
			delete temp;
		}*/
	}

	delete[] array;
}