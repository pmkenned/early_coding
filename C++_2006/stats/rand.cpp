#include <fstream.h>
#include <stdlib.h>

int main()
{
  ofstream outfile("rand.txt");

  for(int i=0; i<1024; i++)
    outfile << (char)random(256);

  outfile.close();

  return 0;
}