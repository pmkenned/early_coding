#include <iostream.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void rand_area();

int main()
{
  rand_area();
  return 0;
}

void rand_area()
{
	double x,y;
	int a = 0,b = 0,n;

	srand(time(NULL));

	cout << "Iterate for loop:";
	cin >> n;

	for(int i = 0 ; i < n; i++)
	{
		x = (rand()/(double)RAND_MAX)*2-1;
		y = (rand()/(double)RAND_MAX)*2-1;

		if (pow(pow(x,2)+pow(y,2), .5) <= 1) {a++;}
		b++;

//		cout << 4 * (double)a/b << endl;
	}
	cout << 4 * (double)a/b << endl;
}