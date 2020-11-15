#include <iostream.h>
#include <math.h>
#include <fstream.h>

double x, i, par_min, par_max, increment;

int main()
{
	ofstream feigenbaum ("feigenbaum.txt");

	cout << "Enter parameter minimum:";
	cin >> par_min;
	cout << "Enter parameter maximum:";
	cin >> par_max;
	cout << "Enter parameter increment:";
	cin >> increment;

	for(i = par_min; i < par_max; i += increment)
	{
		x = i;
		for (int j = 0; j <= 50; j++) {x = pow(x, 2) - i;}
		for(int j = 0; j <= 20; j++) {x = pow(x, 2) - i; cout << x << endl; feigenbaum << x << endl;}
	}

	feigenbaum.close();
	cout << "\a";

	return 0;
}