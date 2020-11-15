#include <iostream.h>

int main()
{
	cout << "Data type sizes in bytes" << endl;
	cout << "char:\t\t" << sizeof(char) << endl;
	cout << "short:\t\t" << sizeof(short) << endl;
	cout << "long:\t\t" << sizeof(long) << endl;
	cout << "int:\t\t" << sizeof(int) << endl;
	cout << "float:\t\t" << sizeof(float) << endl;
	cout << "double:\t\t" << sizeof(double) << endl;
	cout << "long double:\t" << sizeof(long double) << endl;
	cout << "bool:\t\t" << sizeof(bool) << endl;
	cout << "wchar_t:\t" << sizeof(wchar_t) << endl;
	return 0;
}