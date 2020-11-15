#include <iostream.h>
#include <math.h>

int main()
{
  int n;
  double x_sum, y_sum, x_mean, y_mean, sum_xy, sum_x_squared, m, b;

  cout << "Enter number of points:";
  cin >> n;

  double* x = new double[n];
  double* y = new double[n];
//  double x[n], y[n];

  for (int i = 0; i < n; i++)
  {
    cout << "Enter x[" << i << "]:";
    cin >> x[i];
    x_sum += x[i];
    cout << "Enter y[" << i << "]:";
    cin >> y[i];
    y_sum += y[i];
  }

  x_mean = x_sum / n;
  y_mean = y_sum / n;

  for(int i = 0; i < n; i++)
  {
    sum_xy += (x[i] - x_mean) * (y[i] - y_mean);
    sum_x_squared += pow(x[i] - x_mean, 2);
  }

  m = sum_xy / sum_x_squared;
  b = y_mean - m * x_mean;

  cout << "y= mx + b\n";
  cout << "m = " << m << endl;
  cout << "b = " << b << endl;

  return 0;
}