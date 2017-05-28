#pragma once
#ifndef B_H


#include "A.h"

class B :public A
{
public:
	B(int n);
	double getF();
	virtual double getH();
	virtual double getS();
	int getNumber();
	int getNumber2();
private:
	int number2;
};

class C :public A
{
public:
	C(A* inner);
	double getF();
	virtual double getS();
	virtual double getH();
	virtual int getNumber();
};

#endif // !B_H

