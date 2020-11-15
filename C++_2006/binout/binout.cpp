#include <iostream.h>
#include <stdlib.h>
#include <fstream.h>
#include <string.h>

int main(int argc, char* argv[])
{
  char filename[256];
  if(argv[1] == NULL)
  {
    cout << "Enter filename: ";
    cin.getline(filename, 255);
  }
  else
    strcpy(filename, argv[1]);

  ofstream outfile(filename, ios::out|ios::app|ios::binary);

  char choice = 'n';
  while(choice == 'n' || choice == 'N')
  {
    int n;
    cout << "How many characters? ";
    cin >> n;

    for(int i=0; i < n; i++)
    {
      int x;
      cout << "Enter number: ";
      cin >> x;
      outfile << (char)x;
    }
    cout << "Done? (y/n) ";
    cin >> choice;
  }

  if(outfile.is_open() != NULL)
    outfile.close();

  return 0;
}