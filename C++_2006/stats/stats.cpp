#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <math.h>

double freq_mono(ifstream& infile);
double freq_block(ifstream& infile);
int runs(ifstream& infile);
double long_run(ifstream& infile);
double bin_matrix(ifstream& infile);
double fourier(ifstream& infile);
double aperiodic(ifstream& infile);
double periodic(ifstream& infile);
double maurer(ifstream& infile);
double lempel(ifstream& infile);
double linear(ifstream& infile);
double serial(ifstream& infile);
double cusum(ifstream& infile);
double excursions(ifstream& infile);
double excursions_variant(ifstream& infile);

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

  ifstream infile(filename);

//  cout << "Frequency (monobits) test:\t\t\t\t" <<			freq_mono(infile) << endl;
  cout << "Test for Frequency within a Block:\t\t\t" <<			freq_block(infile) << endl;
  cout << "Runs Test:\t\t\t\t\t\t" <<					runs(infile) << endl;
  cout << "Test for the Longest Run of Ones in a Block:\t\t" <<		long_run(infile) << endl;
  cout << "Random Binary Matrix Rank Test:\t\t\t\t" <<			bin_matrix(infile) << endl;
  cout << "Discrete Fourier Transform (Spectral) Test:\t\t" <<		fourier(infile) << endl;
  cout << "Non-overlapping (Aperiodic) Template Matching Test:\t" <<	aperiodic(infile) << endl;
  cout << "Overlapping (Periodic) Template Matching Test:\t\t" <<	periodic(infile) << endl;
  cout << "Maurer's Universal Statistical Test:\t\t\t" <<		maurer(infile) << endl;
  cout << "Lempel-Ziv Complexity Test:\t\t\t\t" <<			lempel(infile) << endl;
  cout << "Linear Complexity Test:\t\t\t\t\t" <<			linear(infile) << endl;
  cout << "Serial Test:\t\t\t\t\t\t" <<					serial(infile) << endl;
  cout << "Cumulative Sum (Cusum) Test:\t\t\t\t" <<			cusum(infile) << endl;
  cout << "Random Excursions Test:\t\t\t\t\t" <<				excursions(infile) << endl;
  cout << "Random Excursions Variant Test:\t\t\t\t" <<			excursions_variant(infile) << endl;

  infile.close();

  return 0;
}

double freq_mono(ifstream& infile)
{
  double ones=0, zeros=1;

  while(infile.eof() == NULL)
  {
    int x = infile.get();

    int n=0;
    while(x>0)
    {
      int i=0;
      while(x-pow(2,i)>=0)
        i++;
      x-=pow(2,i-1);
      n++;
    }

    ones += n;
    zeros += 8-n;
  }

  return (double)(ones/zeros);
}

double freq_block(ifstream& infile)
{
  return 0;
}

int runs(ifstream& infile)
{
  return 0;
}

double long_run(ifstream& infile)
{
  return 0;
}

double bin_matrix(ifstream& infile)
{
  return 0;
}

double fourier(ifstream& infile)
{
  return 0;
}

double aperiodic(ifstream& infile)
{
  return 0;
}

double periodic(ifstream& infile)
{
  return 0;
}

double maurer(ifstream& infile)
{
  return 0;
}

double lempel(ifstream& infile)
{
  return 0;
}

double linear(ifstream& infile)
{
  return 0;
}

double serial(ifstream& infile)
{
  return 0;
}

double cusum(ifstream& infile)
{
  return 0;
}

double excursions(ifstream& infile)
{
  return 0;
}

double excursions_variant(ifstream& infile)
{
  return 0;
}