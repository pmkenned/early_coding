#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>

int main()
{
  unsigned int a = 16807;
  unsigned int m = 2147483647;
  unsigned int x;

  cout << "Enter x:";
  cin >> x;

  ofstream outfile("output");

  for(int i=0; i<1024*256; i++)
  {
    x = (a*x) % m;
    outfile << (char)(x/8388608);
  }

  outfile.close();

  return 0;
}