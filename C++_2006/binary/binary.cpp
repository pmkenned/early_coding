#include <iostream.h>
#include <fstream.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int filesize(char*);
int ten2bin(int);

int main(int argc, char* argv[])
{
  char filename[256];

  if( argv[1] == NULL )
  {
    cout << "Enter filename: ";
    cin.getline(filename, 255);
  }
  else
  {
    strcpy(filename,argv[1]);
  }

  ifstream infile (filename, ios::in|ios::binary);

  int n = filesize(filename);

  for(int i=0; i<n; i++)
  {
    int x = ten2bin(infile.get());
    int m=0;
    while( x - pow(10,m) >= 0){m++;}
    for(; 8-m > 0; m++){cout << "0";}
    if(x!=0) cout << x;
    cout << " ";
    if((i+1)%8 == 0)
      cout << endl;
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

int ten2bin(int x)
{
  int n=0;
  while(x>0)
  {
    int i=0;
    while(x-pow(2,i)>=0)
      i++;
    n+=pow(10,i-1);
    x-=pow(2,i-1);
  }

  return n;
}