#include <stdio.h>
#include <stdlib.h>

#define SIZE	52

int * shuffle(int *, int);

int main(int argc, char * argv[])
{
  int a[SIZE];
  int i;

  for(i=0; i<SIZE; i++)
    a[i] = i;

  shuffle(a,SIZE);

  for(i=0; i<SIZE; i++)
    printf("%d: %d\n", i, a[i]);

  return 0;
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