#include <stdlib.h>
#include <stdio.h>

#define NUM_ITEMS 1000

void bubbleSort(int numbers[], int array_size);

int numbers[NUM_ITEMS];


int main()
{
  int i;

  //seed random number generator
  srand(getpid());

  //fill array with random integers
  for (i = 0; i < NUM_ITEMS; i++)
    numbers[i] = rand();

  //perform bubble sort on array
  bubbleSort(numbers, NUM_ITEMS);

  printf("Done with sort.\n");
  for (i = 0; i < NUM_ITEMS; i++)
    printf("%i\n", numbers[i]);

}


void bubbleSort(int numbers[], int array_size)
{
  int i, j, temp;

  for (i = (array_size - 1); i >= 0; i--)
  {
    for (j = 1; j <= i; j++)
    {
      if (numbers[j-1] > numbers[j])
      {
        temp = numbers[j-1];
        numbers[j-1] = numbers[j];
        numbers[j] = temp;
      }
    }
  }
}