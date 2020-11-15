#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <disp.h>
#include <fstream.h>

int save(char* filename, char* text);

int main(int argc, char* argv[])
{
  char filename[256];
  char* text = new char[0];

  ifstream infile;
  ofstream outfile;

  disp_open();
  disp_move(0,0);
  disp_eeop();

  int ch, n=0;
  while( (ch = getch()) != 17)
  {
    switch(ch)
    {
      case 15:
        cout << "\nEnter filename:";
        cin.getline(filename, 255);
        break;

      case 19:
        cout << "\nEnter filename:";
        cin.getline(filename, 255);
        if( save(filename, text) == 0 )
          cout << "\nFile saved\n";
        else
          cout << "\nError saving file\n";
        break;

      default:
      {
        cout << (char)ch;
        char* temp = new char[n];
        for(int i=0; i<n; i++)
          temp[i] = text[i];
        delete[] text;
        text = new char[n+1];
        for(int i=0; i<n; i++)
          text[i] = temp[i];
        text[n] = (char) ch;
        delete[] temp;
        temp = NULL;
        n++;
      }
      break;
    }
    flush(cout);
  }

  disp_close();

  delete[] text;

  return 0;
}

int save(char* filename, char* text)
{
  ofstream outfile (filename, ios::out);

  if(!outfile.is_open())
    return 1;

  outfile << text; flush(outfile);

  if(!outfile.is_open())
    outfile.close();

  return 0;
}