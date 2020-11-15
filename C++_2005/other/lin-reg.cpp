#include <iostream.h>
#include <math.h>

double sum(int, double *);
double sum(int, double *, double *);
double sum_2(int, double *);

int main()
{
  int n;

  cout << "Enter number of points:";
  cin >> n;

  double x[n], y[n], m, b, r;

  for (int i = 0; i < n; i++)
  {
    cout << "Enter x[" << i << "]:";
    cin >> x[i];
    cout << "Enter y[" << i << "]:";
    cin >> y[i];
  }

  m = (n*sum(n,x,y)-sum(n,x)*sum(n,y))/(n*sum_2(n,x)-sum(n,x)*sum(n,x));
  b = (sum(n,y)-m*sum(n,x))/n;

  cout << (n*sum(n,x,y)-sum(n,x)*sum(n,y)) << endl;
  cout << (sqrt(n*sum_2(n,x)-sum(n,x)*sum(n,x))*sqrt(n*sum_2(n,y)-sum(n,y)*sum(n,y))) << endl;

  cout << "m = " << m << endl;
  cout << "b = " << b << endl;
//  cout << "r = " << r << endl;

  return 0;
}

double sum(int n, double x[])
{
  double sum = 0;

  for(int i = 0; i < n; i++)
    sum += x[i];

  return sum;
}

double sum(int n, double x[], double y[])
{
  double sum = 0;

  for(int i = 0; i < n; i++)
    sum += x[i] * y[i];

  return sum;
}

double sum_2(int n, double x[])
{
  double sum = 0;

  for(int i = 0; i < n; i++)
    sum += x[i] * x[i];

  return sum;
}