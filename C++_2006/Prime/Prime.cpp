#include <iostream.h>
#include <math.h>

unsigned long int x = 1;

int main()
{
	for(unsigned long int i = 0; x < pow(2, (sizeof(long int)*8)); i++)
	{
		x+=2;

		for (unsigned long int j = 2; j <= (float) x/2; j++)
		{
			if (!(x%j))
			{
				x+=2;
				continue;
			}
		}

		cout << x << endl;
	}

	return 0;
}