#pragma once

#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>

// List items are keys with pointers to the next item.
//*****************************************************************
struct Item
{
	std::string key;
	Item* next;
};


#endif // !STRUCT_H
