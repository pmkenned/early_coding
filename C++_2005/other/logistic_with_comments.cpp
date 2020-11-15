/****************************************************************

Program:	Logistic

File:		logistic.cpp

Function:	Main

Description:	Uses logistic equation x[next] = rx(1-1) to form
		steady-state, period two, period four, and
		chaotic patterns as the parameter (r) is 
		increased.

Author:		Paul Kennedy

Enviroment:	Digital Mars C/C++ Compiler Version 8.42n, Intel
		pentium 3, 800 MHz, 128 MB RAM, Windows XP Pro

Notes:		Outputs logistic equation results to logistic.txt
		and the last result of each for loop into
		parameter.txt as r is increased

Revisions:	1.00 08/15/05 (pk) First Release
		1.10 08/15/05 (pk) Added parameter loop
		1.20 08/15/05 (pk) Added parameter input

****************************************************************/

#include <iostream.h>
#include <fstream.h>

int main()
{
	double r;	// parameter
	double x[100];	// population involved in logistic equation

	double r_min;	// minimun value parameter in for loop
	double r_max;	// maximum value parameter in for loop
	double r_inc;	// increment value for parameter in for loop

	// Asks for input concerning parameter used in logistic equation

	cout << "Initial parameter value:";
	cin >>	r_min;
	cout << "Final parameter value:";
	cin >> r_max;
	cout << "Paremeter increment:";
	cin >> r_inc;
	cout << "Initial Value for X:";
	cin >> x[0];

	ofstream logistic ("logistic.txt");	// logistic.txt stores values of x during 						   each for loop involving int i
	ofstream parameter ("parameter.txt");	// parameter.txt stores values of r during 						   each for loop involving double r

	// for loop that increases the parameter and stores the final value of x in 	   a new line of parameter.txt

	for (r = r_min; r <= r_max; r += r_inc)
	{

	if (! logistic.is_open())
	logistic.open ("logistic.txt");

		// uses previous array value to store into the next value of x and output 			   to logistic.txt

		for (int i = 0; i < 99; i++)
		{
			x[i+1] = r * x[i] * (1 - x[i]);
			cout << x[i] << endl;
			logistic << x[i] << endl;	// outputs array value to 							   logistic.txt
		}

	if (logistic.is_open())
	logistic.close();

	parameter << x[99] << endl;	// outputs final array value to parameter.txt

	}

	parameter.close();

	return 0;
}