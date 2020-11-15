#include <iostream.h>

int main()
{
	for (int i = 32; i < 512; i++)
	{
		cout << i << ": " << (char) i << "\t";
	}

	return 0;
}