#include <iostream.h>
#include <math.h>
#include <stdlib.h>

int prime_index(int p);		// returns the index of the prime number
int get_prime(int index);	// get prime number from index number (opposite of prime_index())
int get_factor(int x);		// get lowest prime factor of x
int prime(unsigned long x);	// returns 1 (prime) or 0 (nonprime)

int main()
{
  int x;
  cout << "Enter x:";
  cin >> x;

  int coeff = 1, rad = 1;

  const int array_size = prime_index(x/2)+1;		// a number can only be divisible by a number up to 1/2 of itself
  int* factors = new int[array_size];			// declare array of factors
  for(int i=0;i<array_size;i++) factors[i] = 0;		// initialize array to zeros

  for(int i=0; i<x; i++)
  {
    int y = get_factor(x);			// get lowest prime factor of x
    if(y==0){					// if y=0, then x was prime
      cout << (char)251 << x; exit(0);}		//  so print x and exit
    x = x/y;					// let x equal the other factor of the current x
    factors[prime_index(y)]++;			// increment the factors array at the index of the prime number y
    if(prime(x))			// if x is prime
    {
      factors[prime_index(x)]++;	//  then this is the end of factoring
      break;				//  so exit the for loop
    }
  }

  for(int i=0; i<array_size; i++)
  {
    if(factors[i] != 0)				// if the number of prime numbers with index of i is not 0
    {
      coeff *= pow(get_prime(i),factors[i]/2);	//  then multiply the coefficient of the radical by the prime factor raised to the number of pairs
      factors[i]%=2;				//  and remove that pair from beneath the radical
    }
  }

  for(int i=0; i<array_size; i++)
  {
    if(factors[i] != 0)				// if there is still one left over
      rad*=pow(get_prime(i),factors[i]);	//  then multiply the number under the radical by it
  }

  if(coeff != 1)				// print the coefficient if it is not 1
    cout << coeff;
  if(rad != 1)					// print the number under the radical if it is not 1
    cout << (char)251 << rad;

  return 0;
}

int prime_index(int p)
{
  long int x=3, index=0;
  while(x <= p)
  {
    x+=2;
    for (long int i = 2; i <= (float) x/2; i++)
    {
      if (!(x%i)){
        x+=2;
        continue;}
    }
    index++;
  }

  return index;
}

int get_prime(int index)
{
  if(index == 0)
    return 2;
  long int x=1, n=1;
  while(n <= index)
  {
    x+=2;
    for (long int i = 2; i <= (float) x/2; i++)
    {
      if (!(x%i)){
        x+=2;
        continue;}
    }
    n++;
  }

  return x;
}

int get_factor(int x)
{
  for(int i=2; i < x; i++)
  {
    if((x%i) == 0)
      return i;
  }
  return 0;
}

int prime(unsigned long x)	// returns 1 (prime) or 0 (nonprime)
{
  for(int i = 2; i <= (x/2); i++){
    if(x%i==0)		// if modulo equals 0, then x is evenly divisible by i and nonprime
      return 0;}
  return 1;		// if modulo of every number to x/2 is not whole, then prime
}