#pragma once
#ifndef A_H
#define A_H

class A 
{
public:
	A(int n);
	virtual double getS() = 0;
	virtual double getH();
	virtual int getNumber();
private:
	int number;
};

#endif // !A_H
