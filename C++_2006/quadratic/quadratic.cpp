#include <iostream.h>
#include <math.h>
#define DESC b*b-4*a*c

double quad_eq(double, double, double, int);
void imag_root(double, double, double, double, int);

int main()
{
  double a, b, c; // Coefficients for x^2 and x and constant

  cout << "f(x) = a*x^2+b*x+c\n";

  cout << "a: ";
  cin >> a;
  cout << "b: ";
  cin >> b;
  cout << "c: ";
  cin >> c;

  if(DESC == 0) // Double root
    cout << "Double Root: " << quad_eq(a, b, c, 1);

  else if(DESC > 0)
    cout << "Two Real Roots: " << quad_eq(a, b, c, 1) << ", " << quad_eq(a, b, c, -1);

  else if(DESC < 0)
  {
    cout << "Two conjugate imaginary roots: ";

    int imag_coeff = 1;
    double x = -1*(DESC);

    for(int i=2; i <= x; i++)
    {
      if((int)x==x && (int)x%i==0 && sqrt(i)==int(sqrt(i)))
        imag_coeff = i;
    }

    imag_root(a, b, c, x, imag_coeff);
  }

  return 0;
}

double quad_eq(double a, double b, double c, int sign)
{
  return (-1*b + sign*sqrt(DESC))/(2*a);
}

void imag_root(double a, double b, double c, double x, int imag_coeff)
{
  cout << "(" << (-1*b) << (char)241 << sqrt(imag_coeff) << "i" << char(251) << sqrt(x/imag_coeff) << ")" << "/" << 2*a;
}