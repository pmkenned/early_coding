#include <iostream.h>
#include <sound.h>
#include <stdio.h>
#include <fstream.h>
#include <stdlib.h>
#include <math.h>

void write();
void save(int* freq, int* duration, int n);
void save(char* filename, int* freq, int* duration, int n);
void open();
void open(char* filename);
void play(int* freq, int* duration, int n);
int note2index(int octave, char note, int sharp_flat);
double index2freq(int index);

int main(int argc, char* argv[])
{
   if(argv[1] == NULL)
   {
     cout << "1. Write Music\n";
     cout << "2. Open Music\n";
     flush(cout);
     int ch = getchar() -'0';

     switch(ch)
     {
       case 1: write(); break;
       case 2: open();  break;
       default:         break;
     }
  }
  else
    open(argv[1]);
}

void write()
{
  char buffer[256];
  int* duration = new int[0];
  int* freq = new int[0];

  char ch=0; int n=0;
  while(ch != 'y' && ch != 'Y')
  {
    cout << "How many notes?";
    cin.getline(buffer, 255);
    int x = atoi(buffer);

    for(int i=0; i<x; i++)
    {
      cout << "Enter octave:"; flush(cout);
      cin.getline(buffer, 255);
      int octave = atoi(buffer);

      cout << "Enter note:"; flush(cout);
      cin.getline(buffer, 255);
      char note = buffer[0];

      cout << "Sharp(1), flat(-1), or natural(0)?"; flush(cout);
      cin.getline(buffer, 255);
      int sharp_flat = atoi(buffer);

      int index = note2index(octave, note, sharp_flat);

      cout << "Duration:"; flush(cout);
      cin.getline(buffer, 255);

      int* temp = new int[n];
      for(int i=0; i<n; i++)
        temp[i] = duration[i];
      delete[] duration;
      duration = new int[n+1];
      for(int i=0; i<n; i++)
        duration[i] = temp[i];
      delete[] temp;
      temp = NULL;

      temp = new int[n];
      for(int i=0; i<n; i++)
        temp[i] = freq[i];
      delete[] freq;
      freq = new int[n+1];
      for(int i=0; i<n; i++)
        freq[i] = temp[i];
      delete[] temp;
      temp = NULL;

      duration[n] = atoi(buffer);
      freq[n] = index2freq(index);

      n++;
    }

    cout << "Done? (y/n) ";
    cin.getline(buffer, 255);
    ch = buffer[0];
  }

  cout << "Save to file? (y/n) ";
  cin.getline(buffer, 255);
  ch = buffer[0];

  if(ch == 'y' || ch == 'Y')
    save(freq, duration, n);

  play(freq, duration, n);

  delete[] freq;
  delete[] duration;
}

void save(int* freq, int* duration, int n)
{
  char filename[256];
  cout << "Enter filename:";
  cin >> filename;
  save(filename, freq, duration, n);
}

void save(char* filename, int* freq, int* duration, int n)
{
  ofstream outfile(filename);
  for(int i=0; i<n; i++)
    outfile << freq[i] << "\n" << duration[i] << endl;
  outfile.close();
}

void open()
{
  char filename[256];
  cout << "Enter filename:";
  cin.getline(filename, 255);
  open(filename);
}

void open(char* filename)
{
  ifstream infile(filename);

  int* freq = new int[0];
  int* duration = new int[0];

  int n=0;
  while(infile.eof() == NULL)
  {
    char buffer[256];
    infile.getline(buffer, 255);
    int* temp = new int[n];
    for(int i=0; i<n; i++)
      temp[i] = freq[i];
    delete[] freq;
    freq = new int[n+1];
    for(int i=0; i<n; i++)
      freq[i] = temp[i];
    freq[n] = atoi(buffer);
    delete[] temp;
    temp = NULL;

    infile.getline(buffer, 255);
    temp = new int[n];
    for(int i=0; i<n; i++)
      temp[i] = duration[i];
    delete[] duration;
    duration = new int[n+1];
    for(int i=0; i<n; i++)
      duration[i] = temp[i];
    duration[n] = atoi(buffer);
    delete[] temp;
    temp = NULL;

    n++;
  }

  play(freq, duration, n);

  delete[] freq;
  delete[] duration;

  infile.close();
}

void play(int* freq, int* duration, int n)
{
  for(int i=0; i<n; i++)
    sound_note(freq[i], duration[i]);
}

int note2index(int octave, char note, int sharp_flat)
{
  int index = octave*12+3;
  switch(note)		// Adds value to index
  {
    case (int)'A': index += 9;  break;
    case (int)'B': index += 11; break;
    case (int)'C': index += 0;  break;
    case (int)'D': index += 2;  break;
    case (int)'E': index += 4;  break;
    case (int)'F': index += 5;  break;
    case (int)'G': index += 7;  break;
  }
  index += sharp_flat;
  return index;
}

double index2freq(int index)
{
  return 13.7499730586*pow(1.0594631354808, index);
}