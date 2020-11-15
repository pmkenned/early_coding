#include <iostream.h>
#include <fstream.h>

int main()
{
	double r;
	double x[100];

	double r_min;
	double r_max;
	double r_inc;

	cout << "Initial parameter value:";
	cin >>	r_min;
	cout << "Final parameter value:";
	cin >> r_max;
	cout << "Paremeter increment:";
	cin >> r_inc;
	cout << "Initial Value for X:";
	cin >> x[0];

	ofstream logistic ("logistic.txt");
	ofstream parameter ("parameter.txt");

	for (r = r_min; r <= r_max; r += r_inc)
	{

	if (! logistic.is_open())
	logistic.open ("logistic.txt");

		for (int i = 0; i < 99; i++)
		{
			x[i+1] = r * x[i] * (1 - x[i]);
			cout << x[i] << endl;
			logistic << x[i] << endl;
		}

	if (logistic.is_open())
	logistic.close();

	parameter << x[99] << endl;

	}

	parameter.close();

	cout << "\a";

	return 0;
}