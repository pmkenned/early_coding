#include <iostream.h>

int main()
{
	int n;
	cout << "Enter degree of polynomial:";
	cin >> n;

	double a[n+1];

	for (int i = n; i >= 0; i--)
	{
		cout << "Enter coefficient for X^" << i << ":";
		cin >> a[i];
	}

	cout << "F(x)=";

	for (int i = n; i >= 0; i--)
	{
		cout << (a[i])/(i+1) << "X^" << i+1;
		if (i != 0)
			cout << "+";
	}

	cout << "+C";

	return 0;
}