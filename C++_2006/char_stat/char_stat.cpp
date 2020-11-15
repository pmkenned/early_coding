#include <iostream.h>
#include <fstream.h>
#include <string.h>

int main(int argc, char* argv[])
{
  char filename[256];
  if(argv[1] == NULL)
  {
    cout << "Enter filename:";
    cin.getline(filename, 255);
  }
  else
    strncpy(filename, argv[1], 255);

  ifstream infile(filename);
  ofstream outfile("output");

  int x[224];

  for(int i=0; i<224; i++)
    x[i] = 0;

  while(infile.eof() == NULL)
  {
    char ch = infile.get();
    if((int)ch >= 65 && (int)ch <= 122)
      x[(int)ch]++;
  }

  for(int i=65; i<=122; i++)
  {
    cout << "x[" << i << "]:\t" << x[i] << endl;
    outfile << (char)i << "\t" << x[i] << endl;
  }

  if(outfile.is_open() != NULL)
    outfile.close();
  if(infile.is_open() != NULL)
    infile.close();

  return 0;
}