#include <iostream.h>
#include <fstream.h>
#include <string.h>

int main(int argc, char* argv[])
{
  ofstream outfile(argv[argc-1], ios::out|ios::binary);

  for(int i=1; i<argc-1; i++)
  {
    ifstream infile(argv[i], ios::in|ios::binary|ios::app);

    while(infile.eof() == NULL)
    {
      char ch = infile.get();
      if(infile.eof() != NULL)
        break;
      outfile << ch;
    }

    infile.close();
  }

  outfile.close();

  return 0;
}