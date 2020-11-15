#include <stdio.h>

int foo(int a, int b)
{
  int c = a+b;
  return c;
}

int main()
{
  int x = 5;
  printf("Hello");
  foo(3,x);
  return 0;
}