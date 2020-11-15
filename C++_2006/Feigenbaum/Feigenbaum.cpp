#include <iostream.h>
#include <fstream.h>

int main()
{
  double x, i, par_min, par_max, inc;

  ofstream feigenbaum ("feigenbaum.txt");

  cout << "Enter parameter minimum:";
  cin >> par_min;
  cout << "Enter parameter maximum:";
  cin >> par_max;
  cout << "Enter parameter increment:";
  cin >> inc;

  for(i = par_min; i < par_max; i += inc)
  {
    x = i;

    for (int j = 0; j <= 50; j++)
      x = (x * x) - i;

    for(int j = 0; j <= 20; j++)
    {
      x = (x * x) - i;
      cout << x << endl;
      feigenbaum << x << endl;
    }
  }

  feigenbaum.close();
  cout << "\a";

  return 0;
}