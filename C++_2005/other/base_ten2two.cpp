#include <iostream.h>
#include <math.h>

int main()
{
  double x;
  unsigned long int y = 0;
  int n;

  cout << "Enter X:";
  cin >> x;

  while (x > 1)
  {
    n = (int)(logf(x)/logf(2));
    x -= pow(2, n);
    y += pow(10, n);
  }

  if (x/2 != (int)(x/2))
    y++;

  cout << y << endl;

  return 0;
}                                                                                                                                                                                     