// string_example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string str1, str2;

	cout << "Enter string:";
	cin >> str1;

	cout << str1 << endl;

	str2 = "_suffix";

	string str3 = str1 + str2;

	cout << str3 << endl;

	str1 = str2;

	if(str1 == str2)
		cout << "Strings 1 and 2 are equal" << endl;

	cin.ignore();
	cin.get();

	return 0;
}

