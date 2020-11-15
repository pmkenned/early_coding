#include <iostream.h>
#include <string.h>
#include <fstream.h>

int main(int argc, char* argv[])
{
  char filename[256];
  if(argv[1] == NULL)
  {
    cout << "Enter filename:";
    cin.getline(filename, 255);
  }
  else
    strcpy(filename, argv[1]);

  ifstream infile(filename, ios::in);

  char buffer[256], tag[8];
  for(int i=0; i<8; i++)
    tag[i] = 0;

  int a=1, i=0;
  while(infile.eof() == NULL)
  {
    int x = infile.get();
    if(x == (int)'<')
      a=0;
    else if(x == (int)'>')
    {
      a=1;
      x = infile.get();
    }
    if(a==1)
      cout << (char)x;
    else if(a==0)
    {
      for(int i=0; i<2; i++)
        tag[i] = (char)infile.get();
      infile.unget();
    }
    if(strncmp(tag, "br", 2) == NULL)
    {
      cout << endl;
      strcpy(tag, "0");
      infile.get();
//      a=1;
    }
    i++;
  }

  if(infile.is_open() != NULL)
    infile.close();

  return 0;
}