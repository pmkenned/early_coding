#include <stdlib.h>
#include <stdio.h>

#define NUM_ITEMS 100

void shellSort(int numbers[], int array_size);

int numbers[NUM_ITEMS];

int main()
{
  int i;  //seed random number generator
  srand(getpid());  //fill array with random integers
  for (i = 0; i < NUM_ITEMS; i++)
    numbers[i] = rand();  //perform shell sort on array
  shellSort(numbers, NUM_ITEMS);
  printf("Done with sort.\n");
  for (i = 0; i < NUM_ITEMS; i++)
    printf("%i\n", numbers[i]);
}

void shellSort(int numbers[], int array_size)
{
  int i, j, increment, temp;
  increment = 3;
  while (increment > 0)
  {
    for (i=0; i < array_size; i++)
    {
      j = i;
      temp = numbers[i];
      while ((j >= increment) && (numbers[j-increment] > temp))
      {
        numbers[j] = numbers[j - increment];
        j = j - increment;
      }
      numbers[j] = temp;
    }
    if (increment/2 != 0)
      increment = increment/2;
    else if (increment == 1)
      increment = 0;
    else
      increment = 1;
  }
}