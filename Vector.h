//*****************************************************************
//  Vector.h
//  
//
//  
//
//  This header file contains the Vector class declaration.//  
//*****************************************************************

#ifndef VECTOR_H
#define VECTOR_H

//*****************************************************************
// Vector store a variable number of items.
//*****************************************************************
class Vector {
public:
	//default constructor
	Vector(int size);
	//copy constructor
	Vector(const Vector& a);
	//move constructor
	Vector(Vector&& a);
	//destructor
	~Vector();

	//this is get element
	double operator[](int i) const;
	//this is elem assignment
	double& operator[](int i);
	
	// get Size
	int getSize() const; 
	// get Capacity
	int getCapacity() const;

	//assignment operator
	Vector& operator=(const Vector& a);
	//you can also move objects, from one to the other, only one remains alive at the end
	//move assignment
	Vector& operator=(Vector&& a);

	//other methods
	// Resize
	void resize(int newSize);
	// Insert element at end
	void append(double value);
	// Apply a function to each element
	Vector apply(double f(double)) const;

private:
	// pointer to Array
	double *elem; 
	// Size
	int size; 
	// Capacity
	int capacity; 
};

#endif // !VECTOR_H


