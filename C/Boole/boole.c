#include <stdio.h>

int main()
{
  int a,b,c;
  int ao,bo,co;
  int answer, i;

  a = b = c = ao = bo = co = 0;

  printf("a b c: ans\n");

  for(i=0; i<8; i++)
  {
    answer = (!a && !b && !c) || (!a && !b && c) || (!a && b && !c) || (a && b && !c) || (a && b && c);
    printf("%d %d %d:%d\n", a,b,c,answer);

    c=!c;
    if(co==1)
      b=!b;
    if(bo==1 && co==1)
      a=1;

   ao = a;
   bo = b;
   co = c;
  }

  printf("\n");

  a = b = c = ao = bo = co = 0;

  for(i=0; i<8; i++)
  {
    answer = (a && !a) || (a && b) || (a && c) || (a && !a) || (a && b) || (a && !c) || (!b && !a) || (!b && b) || (!b && c) || (!b && !a) || (!b && !c) || (!c && !a) || (!c && c) || (!c && c) || (!c && !a) || (!c && b) || (!c && !c) || (!a && !a) || (!a && b) || (!a && !c) || (b && !a) || (b && b) || (b && !c) || (c && !a) || (c && b) || (c && !c);

    printf("%d %d %d %d %d %d :%d\n", a,b,c,!a,!b,!c,answer);

    c=!c;
    if(co==1)
      b=!b;
    if(bo==1 && co==1)
      a=1;

   ao = a;
   bo = b;
   co = c;
  }

  return 0;
}