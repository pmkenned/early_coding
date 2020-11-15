#ifndef MATH_H
#define MATH_H

#include <math.h>

#ifndef PI
#define PI 3.141592654
#endif

typedef unsigned short int USHORT;
typedef unsigned long int ULONG;

double x_avg(double *x, int n);		// average of x array
double sum_x(double *x, int n);		// sum of x array
double sum_x_squared(double *x, int n);	// sum of the square of each x array element
double sample(double *x, int n);	// sample standard deviation
double stan_dev(double *x, int n);	// standard deviation
double xmin(double *x, int n);		// lowest x element in array
double xmax(double *x, int n);		// highest x element in array
void sines(double, double, double, double &, double &);                 // uses law of sines to calculate length of sides b and c
void cosines_sss(double, double, double, double &, double &, double &); // uses law of cosines to calculate the interior angles
void cosines_sas(double, double, double, double &, double &, double &); // uses law of cosines to calculate the length of the remaining side
double herons(double, double, double);	// uses heron's area formula to calculate area of a triangle from length of sides
double degrees2radians(double);		// converts degrees to pi radians
double radians2degrees(double);		// converts pi radians to degrees
void lin_reg(double *x, double *y, int n, double &m, double &b); // &m=slope &b=y-intercept
double quad_eq(double, double, double, int);	// finds one real root
int fib(int);		// returns nth term in fibonacci series
int prime(ULONG);	// returns 1 (prime) or 0 (nonprime)
int lcm(ULONG, ULONG);	// finds least common multiple between x and y
int gcd(ULONG, ULONG);	// finds greatest common denominator between x and y
int nPc(int, int);	// permutation
int nCr(int, int);	// combination
int fact(int);		// factorial
int ten2bin(int x);	// convert base ten to base two
double round(double, double);				// rounds x to the nth digit
double interest(double, double, double, double);	// calculates compound interest

double x_avg(double x[], int n)
{
  return (sum_x(x, n)/n);
}

double sum_x(double x[], int n)
{
  double sum = 0;

  for (int i = 0; i < n; i++)
  {
    sum += x[i];		// adds each element to sum
  }

  return sum;
}

double sum_x_squared(double x[], int n)
{
  double sum_x_2;

  for (int i = 0; i < n; i++)
  {
    sum_x_2 += pow(x[i], 2);	// adds square of each element to sum_x_2
  }

  return sum_x_2;
}

double sample(double x[], int n)
{
  double sample_stan_dev, sum_xi_x_2;

  for (int i = 0; i < n; i++)
  {
    sum_xi_x_2 += pow(x[i] - x_avg(x, n), 2); // adds square of difference between each element and the average of x[] to sum_xi_2
  }

  sample_stan_dev = sqrt(1/((double)n-1) * sum_xi_x_2); // sample standard deviation equals the square root of 1/(n-1) * sum_xi_x_2

  return sample_stan_dev;
}

double stan_dev(double x[], int n)
{
  double stan_deviation, sum_xi_x_2;

  for (int i = 0; i < n; i++)
  {
    sum_xi_x_2 += pow(x[i] - x_avg(x, n), 2);	// adds the square of difference between each element and the average to sum_xi_x_2
  }

  stan_deviation = sqrt(sum_xi_x_2 / n);	// standard deviation equals the square root of sum_xi_x_2 divided by the number of elements

  return stan_deviation;
}

double xmin(double x[], int n)	// smallest value in x[]
{
  double minx = x[0];

  for (int i = 0; i < n; i++)
  {
    if (x[i] < minx)	// if the current element is lower than the current value, assign to minx
      minx = x[i];
  }

  return minx;
}

double xmax(double x[], int n) // largest value in x[]
{
  double maxx = x[0];

  for (int i = 0; i < n; i++)
  {
    if (x[i] > maxx)	// if the current element is higher than the current value, assign to maxx
      maxx = x[i];
  }

  return maxx;
}

void sines(double angle_a, double side_a, double angle_b, double &side_b, double &side_c)  // returns lengths of sides b and c by reference
{
      angle_a = degrees2radians(angle_a);        // converts angle a to radians
      angle_b = degrees2radians(angle_b);        // converts angle b to radians
      double angle_c = PI - (angle_a + angle_b); // converts angle c to radians
      side_b = side_a * sin(angle_b)/sin(angle_a);  // calculates length of side b using law of sines
      side_c = side_a * sin(angle_c)/sin(angle_a);  // calculates length of side c using law of sines
}

void cosines_sss(double side_a, double side_b, double side_c, double &angle_a, double &angle_b, double &angle_c) // law of cosines with three known sides
{
      angle_a = acos((side_b*side_b + side_c*side_c - side_a*side_a)/(2*side_b*side_c));        // law of cosines calculating angle a
      angle_b = acos((side_a*side_a + side_c*side_c - side_b*side_b)/(2*side_a*side_c));        // law of cosines calculating angle b
      angle_c = acos((side_a*side_a + side_b*side_b - side_c*side_c)/(2*side_a*side_b));        // law of cosines calculating angle c

      angle_a = radians2degrees(angle_a);        // converts angle a to radians (returned by reference)
      angle_b = radians2degrees(angle_b);        // converts angle b to radians (returned by reference)
      angle_c = radians2degrees(angle_c);        // converts angle c to radians (returned by reference)
}

void cosines_sas(double side_a, double side_b, double angle_c, double &side_c, double &angle_a, double &angle_b)  // law of cosines with two known sides and one known angle
{
      angle_c = degrees2radians(angle_c);        // converts angle c to radians

      side_c = sqrt(side_a*side_a + side_b*side_b - 2*side_a*side_b*cos(angle_c));              // law of cosines calculating length of side c
      angle_a = acos((side_b*side_b + side_c*side_c - side_a*side_a)/(2*side_b*side_c));        // law of cosines calculating angle a
      angle_b = acos((side_a*side_a + side_c*side_c - side_b*side_b)/(2*side_a*side_c));        // law of cosines calculating angle b

      angle_a = radians2degrees(angle_a);        // converts angle a to radians (returned by reference)
      angle_b = radians2degrees(angle_b);        // converts angle b to radians (returned by reference)
}

double herons(double side_a, double side_b, double side_c){  // calculates the area of a triangle by using heron's area formula
      double s = (side_a+side_b+side_c)/2;                   // s = semiperimeter = (a+b+c)/2
      return sqrt(s*(s-side_a)*(s-side_b)*(s-side_c));}      // returns area

double degrees2radians(double degrees){
      return (PI/180.0)*degrees;}

double radians2degrees(double radians){
      return (180.0/PI)*radians;}

void lin_reg(double x[], double y[], int n, double &m, double &b)	// slope and intercept returned by reference
{
  double sum_x_squared = 0, sum_xy = 0;

  double x_mean = x_avg(x, n);
  double y_mean = x_avg(y, n);

  for(int i = 0; i < n; i++)
  {
    sum_xy += (x[i] - x_mean) * (y[i] - y_mean);
    sum_x_squared += pow(x[i] - x_mean, 2);
  }

  m = sum_xy / sum_x_squared;	// slope
  b = y_mean - m * x_mean;	// y-intercept
}

double quad_eq(double a, double b, double c, int sign)	// returns one real root
{
  return (-1*b + sign*sqrt(b*b-4*a*c))/(2*a);	// sign determines whether to add or subtract discriminant
}

int fib(int n)
{
  int a = 1, b = 0;

  for(int i = 0; 2*i < n+1; i++)	// each iteration finds two terms in series
  {
    a = a + b;
    b = a + b;
  }
  if(int (n/2) == n/2.)	// if n is even, return first value
    return a;
  else			// else, return second value
    return b;
}

int prime(ULONG x)	// returns 1 (prime) or 0 (nonprime)
{
  for(int i = 2; i <= (x/2); i++){
    if(x%i==0)		// if modulo equals 0, then x is evenly divisible by i and nonprime
      return 0;}
  return 1;		// if modulo of every number to x/2 is not whole, then prime
}

int lcm(ULONG x, ULONG y)
{
  ULONG greater = max(double(x),double(y)), lesser = min(double(x), double(y));
  USHORT i = 1;

  while(i*greater%lesser != 0)	// finds multiples of greater value and test for divibility by lesser
    i++;

  return (int)(i*greater);
}

int gcd(ULONG x, ULONG y)
{
  ULONG greater = max(x,y), lesser = min(x,y);
  USHORT a;

  if (prime(greater) == 1)	// if prime, then 1 is gcm
    return 1;

  for(USHORT i = 1; i <= lesser; i++){
    if(greater%i == 0 && lesser%i == 0)	// searches for common i which divides evenly between greater and lesser
      a = i;}

  return a;
}

int nCr(int x, int y)
{
  return fact(x)/(fact(y)*fact((x-y)));	// x!/(y! * (x-y)!)
}

int nPr(int x, int y)
{
  return fact(x)/fact((x-y));	// x!/(x-y)!
}

int fact(int x)
{
  int x_fact = 1;

  for(int i = 1; i <= x; i++){	// multiplies x by every integer less then x and above 0
    x_fact *= i;}

  return x_fact;
}

int ten2bin(int x)
{
  int n=0;
  while(x>0)
  {
    int i=0;
    while(x-pow(2,i)>=0)
      i++;
    n+=pow(10,i-1);
    x-=pow(2,i-1);
  }

  return n;
}

double round(double x, int y)
{
  x = (int)(x*pow(10,y));			// drops digits after y
  if (x*pow(10,y)-(int)(x*pow(10,y))>=0.5){	// if next digit is greater or equal to .5, round up
    x++;}
  x /= pow(10,y);				// return x to correct decimal value

  return x;
}

double interest(double principle, double rate, double n, double time)
{
  return principle * pow(1+(.01*rate/n), (n*time));	// 1+(rate/number of times compounded per year)^(number of times compounded per year*years)
}

#endif /* MATH_H */