#include <iostream.h>
#include <stdlib.h>
#include <time.h>

double get_rand(int lower, int upper);

int main()
{
	srand(time(NULL));

	for(int j = 0; j < 5; j++){
	for(int i = 0; i < 12; i++)
	{
		cout << (char) (int) get_rand(33, 126);
	} cout << endl;}

	return 0;
}

double get_rand(int lower, int upper)
{
	return ((rand()/(float)RAND_MAX)*(upper-lower)+lower);
}