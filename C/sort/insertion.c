#include <stdlib.h>
#include <stdio.h>

#define NUM_ITEMS 100

void insertionSort(int numbers[], int array_size);

int numbers[NUM_ITEMS];

int main()
{
  int i;  //seed random number generator
  srand(getpid());  //fill array with random integers
  for (i = 0; i < NUM_ITEMS; i++)
    numbers[i] = rand();  //perform insertion sort on array
  insertionSort(numbers, NUM_ITEMS);
  printf("Done with sort.\n");
  for (i = 0; i < NUM_ITEMS; i++)
    printf("%i\n", numbers[i]);
}

void insertionSort(int numbers[], int array_size)
{
  int i, j, index;
  for (i=1; i < array_size; i++)
  {
    index = numbers[i];
    j = i;
    while ((j > 0) && (numbers[j-1] > index))
    {
      numbers[j] = numbers[j-1];
      j = j - 1;
    }
    numbers[j] = index;
  }
}