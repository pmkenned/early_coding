#include <iostream.h>

const int nan		= 1;
const int DivByZero	= 2;

void enter_number();
int check_input(char x[]);
double divide(double x, double y);

int main()
{
  enter_number();

  double x, y;
  cout << "Enter x:";
  cin >> x;
  cout << "Enter y:";
  cin >> y;

  try
  {
    cout << "X/Y = " << divide(x,y) << endl;
  }
  catch(const int DivByZero)
  {
    cerr << "Cannot divide by Zero\n";
  }

  return 0;
}

void enter_number()
{
  cout << "Enter a number:";

  char x[256];
  cin >> x;
  try
  {
    int a = check_input(x);
    cout << a << endl;
  }
  catch(const int nan)
  {
    cerr << "You did not enter a number.\n";
  }
}

int check_input(char x[])
{
  if(atoi(x) == NULL && x[0] != '0')
    throw nan;
  return atoi(x);
}

double divide(double x, double y)
{
  if(y == 0)
    throw DivByZero;
  return x/y;
}