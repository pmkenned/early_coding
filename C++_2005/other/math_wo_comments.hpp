#ifndef _MATH_HPP
#define _MATH_HPP

#include <math.h>

typedef unsigned short int USHORT;
typedef unsigned long int ULONG;

double x_avg(double *x, int n);
double sum_x(double *x, int n);
double sum_x_squared(double *x, int n);
double sample(double *x, int n);
double stan_dev(double *x, int n);
double xmin(double *x, int n);
double xmax(double *x, int n);
void lin_reg(double *x, double *y, int n, double &m, double &b);
double quad_eq(double, double, double, int);
int fib(int);
int prime(ULONG);
int lcm(ULONG, ULONG);
int gcd(ULONG, ULONG);
int nPc(int, int);
int nCr(int, int);
int fact(int);
double round(double, double);
double interest(double, double, double, double);

double x_avg(double x[], int n)
{
  return (sum_x(x, n)/n);
}

double sum_x(double x[], int n)
{
  double sum = 0;

  for (int i = 0; i < n; i++)
  {
    sum += x[i];
  }

  return sum;
}

double sum_x_squared(double x[], int n)
{
  double sum_x_2;

  for (int i = 0; i < n; i++)
  {
    sum_x_2 += pow(x[i], 2);
  }

  return sum_x_2;
}

double sample(double x[], int n)
{
  double sample_stan_dev, sum_xi_x_2;

  for (int i = 0; i < n; i++)
  {
    sum_xi_x_2 += pow(x[i] - x_avg(x, n), 2);
  }

  sample_stan_dev = sqrt(1/((double)n-1) * sum_xi_x_2);

  return sample_stan_dev;
}

double stan_dev(double x[], int n)
{
  double stan_deviation, sum_xi_x_2;

  for (int i = 0; i < n; i++)
  {
    sum_xi_x_2 += pow(x[i] - x_avg(x, n), 2);
  }

  stan_deviation = sqrt(sum_xi_x_2 / n);

  return stan_deviation;
}

double xmin(double x[], int n)
{
  double minx = x[0];

  for (int i = 0; i < n; i++)
  {
    if (x[i] < minx)
      minx = x[i];
  }

  return minx;
}

double xmax(double x[], int n)
{
  double maxx = x[0];

  for (int i = 0; i < n; i++)
  {
    if (x[i] > maxx)
      maxx = x[i];
  }

  return maxx;
}

void lin_reg(double x[], double y[], int n, double &m, double &b)
{
  double sum_x_squared = 0, sum_xy = 0;

  double x_mean = x_avg(x, n);
  double y_mean = x_avg(y, n);

  for(int i = 0; i < n; i++)
  {
    sum_xy += (x[i] - x_mean) * (y[i] - y_mean);
    sum_x_squared += pow(x[i] - x_mean, 2);
  }

  m = sum_xy / sum_x_squared;
  b = y_mean - m * x_mean;
}

double quad_eq(double a, double b, double c, int sign)
{
  return (-1*b + sign*sqrt(b*b-4*a*c))/(2*a);
}

int fib(int n)
{
  int a = 1, b = 0;

  for(int i = 0; 2*i < n+1; i++)
  {
    a = a + b;
    b = a + b;
  }
  if(int (n/2) == n/2.)
    return a;
  else
    return b;
}

int prime(ULONG x)
{
  for(int i = 2; i <= (x/2); i++){
    if(x%i==0)
      return 0;}
  return 1;
}

int lcm(ULONG x, ULONG y)
{
  ULONG greater = max(double(x),double(y)), lesser = min(double(x), double(y));
  USHORT i = 1;

  while(i*greater%lesser != 0)
    i++;

  return (int)(i*greater);
}

int gcd(ULONG x, ULONG y)
{
  ULONG greater = max(x,y), lesser = min(x,y);
  USHORT a;

  if (prime(greater) == 1)
    return 1;

  for(USHORT i = 1; i <= lesser; i++){
    if(greater%i == 0 && lesser%i == 0)
      a = i;}

  return a;
}

int nCr(int x, int y)
{
  return fact(x)/(fact(y)*fact((x-y)));
}

int nPr(int x, int y)
{
  return fact(x)/fact((x-y));
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

double interest(double principle, double rate, double n, double time)
{
  return principle * pow(1+(.01*rate/n), (n*time));
}

#endif /* _MATH_HPP */