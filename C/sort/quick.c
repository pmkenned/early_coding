#include <stdio.h>
#include <stdlib.h>

#define SIZE	10000

void quicksort(int [], int, int);
int * shuffle(int *, int);

int main(void)
{
  int array[SIZE];
  int i;

  shuffle(array,SIZE);

  for(i=0; i<SIZE; i++)
    array[i] = i;

  quicksort(array, 0,SIZE);

  for(i=0; i<SIZE; i++)
    printf("%d\n", array[i]);

  return 0;
}

void quicksort(int a[], int lo, int hi)		/* sort a[lo..hi] */
{
  int left, right, median, temp;

  if( hi > lo )
  {
    left=lo; right=hi;
    median=a[lo];

    while(right >= left)
    {
      while(a[left] < median)
        left++;
      while(a[right] > median)
        right--;
      if(left > right)
        break;

      /* swap: */
      temp=a[left];
      a[left]=a[right];
      a[right]=temp;
      left++;
      right--;
    }

    quicksort(a, lo, right);
    quicksort(a, left,  hi);
  }
}

int * shuffle(int * array, int size)
{
  int r, t, i;

  randomize();

  for(i=0; i<size; i++)
  {
    r = random(size);
    t = array[i];
    array[i] = array[r];
    array[r] = t;
  }
  return array;
}