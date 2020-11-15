/*
** replaces newline binary characters (char)10 with "\n"
*/

#include <iostream.h>
#include <string.h>
#include <fstream.h>

int main(int argc, char *argv[])
{
  char filename[256], outname[256];

  if(argv[1] == NULL)
  {
    cout << "Enter filename: ";
    cin.getline(filename, 255);
  }
  else
  {
    strcpy(filename, argv[1]);
  }

  strcpy(outname, filename);
  strcat(outname, "_out");

  ifstream infile (filename, ios::in|ios::binary);
  ofstream outfile (outname, ios::out);

  do
  {
    char c = infile.get();
    if(c == (char)10)
      outfile << "\n";
    else if(c == (char)255)
      break;
    else
      outfile << c;
  }
  while(infile.eof() == NULL);

  infile.close();
  outfile.close();

  return 0;
}