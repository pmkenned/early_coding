#include <iostream.h>

unsigned int fib(int n);

int main()
{
  for(int i=0; i<1000; i++)
    cout << fib(i+7)%15 << "\t";

  return 0;
}

unsigned int fib(int n)
{
  unsigned int a = 1, b = 0;

  for(int i = 0; 2*i < n+1; i++)
  {
    a = a + b;
    b = a + b;
  }
  if(n%2 == 0)
    return a;
  else
    return b;
}