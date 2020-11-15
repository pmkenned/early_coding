#include <stdio.h>

void print_list(int *, const int);

int main()
{
  const int size = 6;
  int list[6] = {1,3,4,5,2,6};
  int i,j,o,s,temp;

  printf("Enter list:\n");
  for(i=0; i<size; i++)
    scanf("%d", &list[i]);

  print_list(list,size);

  s=0;
  for(i=0; i<size-1; i++)
  {
    o=0;
    for(j=0; j<size-1-i; j++)
    {
      if(list[j] > list[j+1])
      {
        temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
        s++;
      }
      else
        o++;
    }
    if(o >= size-1-i)
      break;
  }

  printf("%d\n", s);

  print_list(list,size);

  return 0;
}

void print_list(int * list, const int size)
{
  int i;
  putchar('\n');
  for(i=0; i<size; i++)
    printf("%d:%d\n", i, list[i]);
  putchar('\n');
}