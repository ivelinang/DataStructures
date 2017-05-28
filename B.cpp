#include "B.h"

B::B(int n)
	:A(n),
	number2(n)
{}

double B::getF()
{
	return 4;
}

///*
double B::getH()
{
	return A::getH();
}
//*/
double B::getS()
{
	return 6;
}

int B::getNumber()
{
	return A::getNumber();
}

C::C(A* inner)
	:A(1)
{

}

double C::getF()
{
	return 2;
}

double C::getS()
{
	return 3;
}

double C::getH()
{
	return 5;
}

int C::getNumber()
{
	return 9;
}