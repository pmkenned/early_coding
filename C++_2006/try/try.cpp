#include <iostream.h>
#define DivByZero 10

class DivideByZero
{
    public:
        double divisor;
        DivideByZero(double x);
};
DivideByZero::DivideByZero(double x) : divisor(x)
{}
int divide(int x, int y)
{
    if(y==0)
    {
        throw DivideByZero(x);
    }
  return x/y;
}

double divide(double, double);

int main()
{
  try
  {
    divide(12, 0);
  }
  catch (DivideByZero divZero)
  {
    cerr<<"Attempted to divide "<<divZero.divisor<<" by zero\n";
  }

  double x, y;
  cout << "Enter x:";
  cin >> x;
  cout << "Enter y:";
  cin >> y;

  try
  {
    cout << "X/Y = " << divide(x,y) << endl;
  }
  catch(int i)
  {
    if(i==DivByZero)
      cerr << "Cannot divide by Zero\n";
  }


  return 0;
}

double divide(double x, double y)
{
  if(y == 0)
    throw DivByZero;
  return x/y;
}