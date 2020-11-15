#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <stdlib.h>

int filesize(char* filename);

int main(int argc, char* argv[])
{
  char filename[256];
  int outsize;

  if(argv[1] == NULL)
  {
    cout << "Usage: split filename [split_size]\n";
    exit(0);
  }
  else
    strncpy(filename, argv[1], 255);

  if(argv[2] != NULL)
    outsize = atoi(argv[2]);
  else
    outsize = 1047552;

  ifstream infile(filename, ios::in|ios::binary);

  const int infsize = filesize(filename);

  for(int i=0; i<infsize/outsize+1; i++)
  {
    char outname[256];
    strncpy(outname, filename, 254);
    char ofsuffix[2] = {'0'+i,0};
    strcat(outname, ofsuffix);

    ofstream outfile(outname, ios::out|ios::binary);

    for(int j=0; j<outsize; j++)
    {
      char ch = infile.get();
      if(infile.eof() != NULL)
        break;
      outfile << ch;
    }
    
    outfile.close();
  }

  infile.close();

  return 0;
}

int filesize(char* filename)
{
  long begin,end;
  ifstream file (filename, ios::in|ios::binary);
  begin = file.tellg();
  file.seekg (0, ios::end);
  end = file.tellg();
  file.close();

  return end-begin;
}