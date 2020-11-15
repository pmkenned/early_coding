#include <stdio.h>

int main()
{
	FILE *park_miller = fopen("parkmill.txt", "w");

	int i, i_max, x, a, b, c;
	float rand;

	printf("Enter i_max:");
	scanf("%d", &i_max);
	printf("Enter x_init:");
	scanf("%d", &x);
	printf("Enter a:");
	scanf("%d", &a);
	printf("Enter b:");
	scanf("%d", &b);
	printf("Enter c:");
	scanf("%df", &c);

	for(i = 0; i < i_max; i++)
	{
	  x = ((a*x+b)%c);
	  printf("%f\n", (float)(x)/c);
	  fprintf(park_miller, "%d\t%f\n", x, (float)(x)/c);
	}

	fclose(park_miller);

	return 0;
}