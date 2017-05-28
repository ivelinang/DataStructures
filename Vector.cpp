//*****************************************************************
//  Vector.cpp
//  
// 
//  
//*****************************************************************

#include <iostream>;
#include "Vector.h"; 
#include <assert.h>;

using namespace std;


//default constructor
Vector::Vector(int size_):
	size(size_),
	capacity(size_)
{ 
	if (size < 0) 
		throw length_error{ "size has to be positive" };

	elem = new double[size];	
	for (int i = 0; i != size; ++i) 
		elem[i] = 0; //initialize elements
}

//copy constructor
Vector::Vector(const Vector& other) { 
	elem = new double[other.size];
	size = other.size;
	capacity = other.capacity;
	for (int i = 0; i != size; ++i)
		elem[i] = other.elem[i];
}

//move constructor
Vector::Vector(Vector&& other) {
	elem = other.elem;
	size = other.size;
	capacity = other.capacity;

	//delete a -a has no elemnts
	other.elem = nullptr;
	other.size = other.capacity= 0;

}

//assignment operator, no effect on original
Vector& Vector::operator=(const Vector& other) {
	
	if (this != &other)
	{
		if (other.size > capacity)
		{
			delete[] elem; //release memory of this
			elem = new double[other.size]; //create new heap memory for this
			capacity = other.size;
		}

		size = other.size;

		//copy elements from other to this
		for (int i = 0; i != size; ++i)
			elem[i] = other.elem[i];
	}

	return *this;
	/*
	double *p = new double[a.sz];
	for (int i = 0; i != a.sz; ++i)
		p[i] = a.elem[i];
	delete[] elem; //delete old elements
	elem = p;
	sz = a.sz;
	return *this;
	*/
}

//http://en.cppreference.com/w/cpp/language/operators

//move assignment + delete the original array
Vector& Vector::operator=(Vector&& other) { 
	elem = other.elem; //assign internal pointer to the allocated memory
	size = other.size;
	capacity = other.capacity;

	//delete a -a has no elemnts
	//delete[] a.elem;
	//change the original pointer to nothing
	other.elem = nullptr;
	other.size = other.capacity= 0;

	return *this;

}

// destructor
Vector::~Vector() {

	delete[] elem; //release resources
}

// get operator []
double Vector::operator[](int i) const
{
	
	//exception handler
	if (i < 0 || size <= i)
	{
		std::cout << "out of range";
		cin.get();
		throw("vector out of range"); //out_of_range{ "Vector is out of range..." };
		
	}
	return elem[i];
}

// set operator []
double& Vector::operator[](int i)
{
	
	//assert(i < sz && "Vector index out of bounds");

	if (i < 0 || size <= i)
	{
		std::cout << "Vector out of range";
		cin.get();
		throw("vector out of range");
	}
		

	return elem[i];
}

// get Size
int Vector::getSize() const {
	return size;
}

// get Capacity
int Vector::getCapacity() const
{
	return capacity;
}

// Resize
void Vector::resize(int newSize)
{
	if (newSize > capacity)
	{
		delete[] elem; //release memory of this
		elem = new double[newSize]; //create new heap memory for this
		capacity = newSize;
	}

	size = newSize;
}

// Insert element at the end
void Vector::append(double value)
{
	if (size + 1 > capacity)
	{
		//increase capacity by 10, so that we dont have to call NEW every time we append. New is SLOW.
		capacity += 10;
		//size += 1;
		double* temp = new double[size+1];
		for (int i = 0; i < size; ++i)
			temp[i] = elem[i];
		temp[size] = value;

		//delete the current elem
		delete[] elem;
		elem = new double[capacity];
		for (int i = 0; i < size+1; ++i)
			elem[i] = temp[i];

		//delete the temp
		delete[] temp;
		size += 1;
	}
	else
	{
		elem[size] = value;
		size += 1;
	}


}

// Apply function to all elements
Vector Vector::apply(double f(double)) const
{
	Vector result(size);
	for (int i = 0; i < size; ++i)
	{
		result[i] = f(elem[i]);
	}

	return result;
}
