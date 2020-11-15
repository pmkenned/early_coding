#include <iostream.h>
#include <fstream.h>

int main(int argc, char* argv[])
{
  ifstream infile (argv[1], ios::in|ios::binary);

  for(int i=0; infile.eof() == NULL; i++)
  {
    int x = infile.get();
    if(x!=7)
      cout << (char)x;
  }

  infile.close();

  return 0;
}