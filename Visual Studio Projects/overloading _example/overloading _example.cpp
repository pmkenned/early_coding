// overloading _example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class X
{
public:
	X();
	X(int);
	~X();
	int getData(){return itsData;}
	void setData(int data){itsData = data;}
	void operator ++ () { itsData++; }

private:
	int itsData;
};

X::X()
{
}

X::X(int data): itsData(data)
{
}

X::~X()
{
}

int _tmain(int argc, _TCHAR* argv[])
{
	X a, b;
    ++a;
	return 0;
}

