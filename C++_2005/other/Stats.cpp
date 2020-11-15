#include <iostream.h>

int random_input();
void frequency(int x[], int n);
void frequency_block();
void runs();

int main()
{
	int choice;
	cout << "1.  Frequency (Monobits) Test\n";
	cout << "2.  Test for Frequency within a Block\n";
	cout << "3.  Runs Test\n";
	cout << "4.  Test for the Longest Run of Ones in a Block\n";
	cout << "5.  Random Binary Matrix Rand Test\n";
	cout << "6.  Discrete Fourier Transform (Spectral) Test\n";
	cout << "7.  Non-overlapping (Aperiodic) Template Matching Test\n";
	cout << "8.  Overlapping (Periodic) Template Matching Test\n";
	cout << "9.  Maurer's Universal Statistical Test\n";
	cout << "10. Lempel-Ziv Complexity Test\n";
	cout << "11. Linear Complexity Test\n";
	cout << "12. Serial Test\n";
	cout << "13. Approximate Extropy Test\n";
	cout << "14. Cumulatice Sum (Cusum) Test\n";
	cout << "15. Random Excursions Test\n";
	cout << "16. Random Excursions Variant Test\n";
	cin >> choice;

	int n = random_input();
	int x[n];

	switch(choice)
	{
	case 1:
	frequency(x, n);
	break;

	case 2:
	frequency_block();
	break;

	case 3:
	runs();
	break;

	default:
	break;
	}

	return 0;
}

int random_input()
{
	int n;
	cout << "Number of random bits:";
	cin >> n;
	return n;
}

void frequency(int x[], int n)
{
	int a = 0, b = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> x[i];

		if (x[i] == 1)
			a++;
		else
			b++;
	}

	cout << (float) a/b << endl;
}

void frequency_block()
{
}

void runs()
{
}