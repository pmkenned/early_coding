#include <iostream.h>
#include <string.h>
#include <fstream.h>
#include <stdlib.h>

void encrypt(char*, char*, char*);
int filesize(char*);

int main(int argc, char* argv[])
{
  char filename[256], output[256], key[255];

  if(argv[1] != NULL)
  {
    strcpy(filename,argv[1]);
  }
  else
  {
    filename[256];

    cout << "Enter input filename:";
    cin.getline(filename, 255);    
  }

  if(argv[2] != NULL)
  {
    strcpy(output,argv[2]);
  }
  else
  {
    output[256];

    cout << "Enter output filename:";
    cin.getline(output, 255);
  }

  cout << "Enter encryption key: ";
  cin >> key;

  encrypt(filename, output, key);

  return 0;
}

void encrypt(char* filename, char* output, char* key)
{
  for(unsigned int i = 0; i < strlen(key); i++)
    srand((int)key[i]);

  cout << "Opening " << filename << "..." << endl;
  ifstream infile (filename, ios::in|ios::binary);

  ofstream outfile (output, ios::out|ios::binary);

  cout << "Encrypting " << filename;

  int fsize = filesize(filename);

  for(int i = 0; i < fsize; i++)
  {
    int x = infile.get();
    int a = 224*rand()/RAND_MAX + 32;
    int b = x ^ a;

    outfile << (char)b;

    if( i % (fsize/10) == 0 )
      cout << ".";
  }
  cout << endl;

  infile.close();
  cout << "Closing " << filename << "..." << endl;
  outfile.close();
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