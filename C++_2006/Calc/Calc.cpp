#include <iostream.h>
#include <stdio.h>
#include <math.h>

int fact(int);
double round(double, int);

int main(int argc, char *argv[])
{
  short int choice, value;
  double dx, dy;
  int ix, iy;

  do{

  cout << "Choose a function (0 to quit):\n";
  cout << "1. abs(x)\t2. cos (x)\t3. acos(x)\t4. cosh(x)\t5. sin(x)\n";
  cout << "6. asin(x)\t7. sinh(x)\t8. tan(x)\t9. atan(x)\t10. tanh(x)\t";
  cout << "11. ln(x)\t12.log(x)\t13. x!\t\t14. nCr\t\t15.nPr\n";
  cout << "16. round(x,y)\t17. x^y\t\t18. x*y\t\t19. x/y\t\t20. x+y\n";
  cout << "21. x-y\t\t22. x%y\n";

  cin >> choice;

  if(choice != 0){
  cout << "Enter x:";
  cin >> dx;}

  switch(choice)
  {
  case(1): cout << abs(dx); break;

  case(2): cout << cos(dx); break;
  case(3): cout << acos(dx); break;
  case(4): cout << cosh(dx); break;
  case(5): cout << sin(dx); break;
  case(6): cout << asin(dx); break;
  case(7): cout << sinh(dx); break;
  case(8): cout << tan(dx); break;
  case(9): cout << atan(dx); break;
  case(10): cout << tanh(dx); break;

  case(11): cout << log(dx); break;
  case(12): cout << log10(dx); break;

  case(13): ix = (int)dx; cout << fact(ix); break;
  case(14): ix = (int)dx; cout << "Enter y:"; cin >> iy; cout << fact(ix)/(fact(iy)*fact((ix-iy))); break;
  case(15): ix = (int)dx; cout << "Enter y:"; cin >> iy; cout << fact(ix)/fact((ix-iy)); break;

  case(16): cout << "Enter y:"; cin >> iy; cout << round(dx,iy); break;
  case(17): cout << "Enter y:"; cin >> dy; cout << pow(dx,dy); break;
  case(18): cout << "Enter y:"; cin >> dy; cout << dx*dy; break;
  case(19): cout << "Enter y:"; cin >> dy; cout << dx/dy; break;
  case(20): cout << "Enter y:"; cin >> dy; cout << dx+dy; break;
  case(21): cout << "Enter y:"; cin >> dy; cout << dx-dy; break;
  case(22): ix = (int)dx; cout << "Enter y:"; cin >> iy; cout << ix%iy; break;

  default:
  break;
  }

  getchar();

  } while(choice != 0);

  return 0;
}

int fact(int x)
{
  int x_fact = 1;

  for(int i = 1; i <= x; i++){
    x_fact *= i;}

  return x_fact;
}

double round(double x, int y)
{
  x = (int)(x*pow(10,y));
  if (x*pow(10,y)-(int)(x*pow(10,y))>=0.5){
    x++;}
  x /= pow(10,y);

  return x;
}
