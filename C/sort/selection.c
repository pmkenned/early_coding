#include <stdlib.h>
#include <stdio.h>

#define NUM_ITEMS 100

void selectionSort(int numbers[], int array_size);

int numbers[NUM_ITEMS];

int main()
{
  int i;  //seed random number generator
  srand(getpid());  //fill array with random integers
  for (i = 0; i < NUM_ITEMS; i++)
    numbers[i] = rand();  //perform selection sort on array
  selectionSort(numbers, NUM_ITEMS);
  printf("Done with sort.\n");
  for (i = 0; i < NUM_ITEMS; i++)
    printf("%i\n", numbers[i]);
}

void selectionSort(int numbers[], int array_size)
{
  int i, j;
  int min, temp;
  for (i = 0; i < array_size-1; i++)
  {
    min = i;
    for (j = i+1; j < array_size; j++)
    {
      if (numbers[j] < numbers[min])
        min = j;
    }
    temp = numbers[i];
    numbers[i] = numbers[min];
    numbers[min] = temp;
  }
}