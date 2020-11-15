// string_example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	std::string str1, str2;

	str1 = "test";
    str2 = "ing123";

	str1 += str2;

	std::cout << str1;
	getchar();

	return 0;
}