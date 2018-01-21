#include "Iterator.h"

//default constructor gets null ptr
MyIterator::MyIterator() {
	currentItem = nullptr;
}

MyIterator::MyIterator(Item* node) {
	currentItem = node;
}

MyIterator::MyIterator(const MyIterator& other)
{
	currentItem = other.currentItem;
}

MyIterator::MyIterator(MyIterator&& other)
{
	currentItem = other.currentItem;
	other.currentItem = nullptr;
}

MyIterator& MyIterator::operator=(const MyIterator& other)
{
	currentItem = other.currentItem;
	return *this;
}

MyIterator& MyIterator::operator=(MyIterator&& other)
{
	currentItem = other.currentItem;
	//remove the other
	other.currentItem = nullptr;

	return *this;
}

MyIterator& MyIterator::operator++()
{
	if (currentItem)
		currentItem = currentItem->next;
	
	return *this;
}

MyIterator& MyIterator::operator++(int)
{
	MyIterator& newMyIterator = *this;
	++*this;
	return newMyIterator;
}


std::string MyIterator::operator*()
{
	return currentItem->key;
}

//comparison
bool MyIterator::operator!=(const MyIterator& MyIterator)
{
	//return currentItem->key != MyIterator.currentItem->key;
	return !(*this == MyIterator);
}

//comparison
bool MyIterator::operator==(const MyIterator& MyIterator)
{
	if (!currentItem && !MyIterator.currentItem)
	{
		return true;
	}
	else if (!currentItem || !MyIterator.currentItem)
	{
		return false;
	}
	else
	{ 
		return currentItem->key == MyIterator.currentItem->key;
	}
	

}