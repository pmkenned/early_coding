#include <iostream.h>

int main()
{
  int i_max, x, a, b, c;

  cout << "Enter i_max:";
  cin >> i_max;
  cout << "Enter x_init:";
  cin >> x;
  cout << "Enter a, b, c:";
  cin >> a;
  cin >> b;
  cin >> c;

  for(int i = 0; i < i_max; i++)
  {
    x = (a*x+b)%c;
    cout << (double)(x)/c << endl;
  }

  return 0;
}