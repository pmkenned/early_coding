#include <iostream.h>
#include <fstream.h>

int main()
{
  ofstream henon ("henon.txt");

  double x_init, y_init, xmin, xmax, ymin, ymax, n;

  cout << "x_init: ";
  cin >> x_init;
  cout << "y_init: ";
  cin >> y_init;
  cout << "xmin: ";
  cin >> xmin;
  cout << "xmax: ";
  cin >> xmax;
  cout << "ymin: ";
  cin >> ymin;
  cout << "ymax: ";
  cin >> ymax;
  cout << "n: ";
  cin >> n;

  double x0 = x_init, y0 = y_init, x1, y1;

  for(int i = 0; i < n; i++)
  {
    x1 = y0 + 1 - 1.4 * (x0 * x0);
    y1 = .3 * x0;
    x0 = x1;
    y0 = y1;
    if (xmin < x0 && x0 < xmax && ymin < y0 && y0 < ymax)
      henon << x0 << "\t" << y0 << endl;
  }

  henon.close();
}