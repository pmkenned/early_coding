#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>
#include <disp.h>

void save(char* filename, char* text);

int main()
{
  char filename[256];
  char* text = new char[0];

  disp_open();
  disp_move(0,0);
  disp_eeop();

  int ch; int n=0;
  while( (ch = getch()) != 17)	//Ctrl+Q
  {
    switch(ch)
    {
    case 15:				//Ctrl+O
      cout << "\nEnter filename:";
      cin.getline(filename, 255);
      break;
    case 19:				//Ctrl+S
      cout << "\nEnter filename:";
      cin.getline(filename, 255);
      save(filename, text);
      cout << "\nFile saved\n";
      break;
    case 10:
    case 13:
      ch = '\n';
    default:
      {
      cout << (char)ch;
      char* temp = new char[n];
      for(int i=0; i<n; i++)
        temp[i] = text[i];
      delete[] text;
      text = NULL;
      text = new char[n+1];
      for(int i=0; i<n; i++)
        text[i] = temp[i];
      delete[] temp;
      temp = NULL;
      text[n] = (char)ch;
      n++;
      }
      break;
    }
    flush(cout);
  }

  disp_close();

  cout << text;

  delete[] text;

  return 0;
}

void save(char* filename, char* text)
{
  ofstream outfile (filename, ios::out);

  outfile << text; flush(outfile);

  if(outfile.is_open() != NULL)
    outfile.close();
}