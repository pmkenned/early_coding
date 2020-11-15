#include <iostream.h>
#include <math.h>

int main()
{
	double principle, rate, n, time;

	cout << "Principle: ";
	cin >> principle;
	cout << "Interest Rate: ";
	cin >> rate;
	cout << "Paid per year: ";
	cin >> n;
	cout << "Years: ";
	cin >> time;

	cout << principle * pow(1+(.01*rate/n), (n*time));

	return 0;
}