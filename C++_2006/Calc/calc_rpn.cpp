#include <iostream.h>
#include <string.h>
#include <sstream.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  char input[128], func[32], arg1[16], arg2[16];
  cout << ">";

  cin.getline(input,127);
  stringstream os(input);
  
  os >> func;

  // Functions
  if(strcmp(func, "log") == 0){				// log (common) x
    os >> arg1;
    cout << log10( _atold(arg1) ) << endl;}
  if(strcmp(func, "ln") == 0){				// log (base e) x
    os >> arg1;
    cout << log( _atold(arg1) ) << endl;}
  if(strcmp(func, "sin") == 0){				// sin x
    os >> arg1;
    cout << sin( _atold(arg1) ) << endl;}
  if(strcmp(func, "cos") == 0){				// cos x
    os >> arg1;
    cout << cos( _atold(arg1) ) << endl;}
  if(strcmp(func, "tan") == 0){				// tan x
    os >> arg1;
    cout << tan( _atold(arg1) ) << endl;}
  if(strcmp(func, "asin") == 0){			// asin x
    os >> arg1;
    cout << asin( _atold(arg1) ) << endl;}
  if(strcmp(func, "acos") == 0){			// acos x
    os >> arg1;
    cout << acos( _atold(arg1) ) << endl;}
  if(strcmp(func, "atan") == 0){			// atan x
    os >> arg1;
    cout << atan( _atold(arg1) ) << endl;}
  if(strcmp(func, "*") == 0){				// x*y
    os >> arg1;
    os >> arg2;
    cout << _atold(arg1) * _atold(arg2) << endl;}
  if(strcmp(func, "/") == 0){				// x/y
    os >> arg1;
    os >> arg2;
    cout << _atold(arg1) / _atold(arg2) << endl;}
  if(strcmp(func, "+") == 0){				// x+y
    os >> arg1;
    os >> arg2;
    cout << _atold(arg1) + _atold(arg2) << endl;}
  if(strcmp(func, "-") == 0){				// x-y
    os >> arg1;
    os >> arg2;
    cout << _atold(arg1) - _atold(arg2) << endl;}
  if(strcmp(func, "exp") == 0){				// e^x
    os >> arg1;
    cout << exp(_atold(arg1)) << endl;}
  if(strcmp(func, "^") == 0){				// x^y
    os >> arg1;
    os >> arg2;
    cout << pow(_atold(arg1), _atold(arg2)) << endl;}

  // Constants
  if(strcmp(func, "pi") == 0)				// pi
    cout << M_PI << endl;
  if(strcmp(func, "e") == 0)				// e
    cout << M_E << endl;

  return 0;
}