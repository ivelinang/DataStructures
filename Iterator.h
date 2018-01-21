#pragma once

#ifndef ITERATOR_H
#define ITERATOR_H

//#include "LinkedList.h"
#include "Struct.h"
#include <iostream>

class MyIterator
{
private:
	Item* currentItem;

public:
	//constructors
	MyIterator();
	MyIterator(Item* currentItem);
	MyIterator(const MyIterator& other);
	MyIterator(MyIterator&& other);


	//assignment operator
	MyIterator& operator=(const MyIterator & other);

	//move assignment
	MyIterator& operator=(MyIterator&& other);

	//prefix ++ overload
	MyIterator& operator++();

	//postfix ++ overload
	MyIterator& operator++(int);

	//* overload
	std::string operator*();

	//comparison
	bool operator!=(const MyIterator& Iterator);
	bool operator==(const MyIterator& MyIterator);




};

#endif // !MyIterator_H

