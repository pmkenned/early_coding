#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <disp.h>
#include <stdio.h>

#define LEN 75
#define WID 79

void rand_file();

int main(int argc, char* argv[])
{
  rand_file();

  disp_open();
  disp_move(0,0);
  disp_eeop();
  disp_close();

  short int grid0[LEN][WID] = {NULL};
  short int grid1[LEN][WID] = {NULL};

  if(argv[1] == NULL)
  {
    cout << "Enter a 1 for alive and 0 for dead\n";

    for(int r=0; r<LEN; r++)
    {
      for(int c=0; c<WID; c++)
      {
        cout << "row: " << r+1 << ", column: " << c+1 << " = ";
        cin >> grid0[r][c];
      }
    }
  }
  else
  {
    ifstream infile (argv[1]);

    for(int r=0; r<LEN; r++)
    {
      for(int c=0; c<WID; c++)
      {
        int x = infile.get() - '0';
        grid0[r][c] = x;
      }
      cout << endl;
    }
    cout << endl;

    infile.close();
  }

  do{

  for(int r=0; r<LEN; r++)
  {
    for(int c=0; c<WID; c++)
    {
      int sum = 0;
      if(r>0 && c>0)		sum += grid0[r-1][c-1];
      if(r>0)			sum += grid0[r-1][c];
      if(r>0 && c<WID-1)	sum += grid0[r-1][c+1];
      if(c>0)			sum += grid0[r][c-1];
      if(c<WID-1)		sum += grid0[r][c+1];
      if(r<LEN-1 && c>0)	sum += grid0[r+1][c-1];
      if(r<LEN-1)		sum += grid0[r+1][c];
      if(r<LEN-1 && c<WID-1)	sum += grid0[r+1][c+1];
      if(sum < 2 || sum > 3)
        grid1[r][c] = 0;
      if(grid0[r][c] == 0 && sum == 3)
        grid1[r][c] = 1;
      if(grid0[r][c] == 1 && (sum == 2 || sum ==3) )
        grid1[r][c] = 1;
    }
  }

  for(int r=0; r<LEN; r++)
  {
    for(int c=0; c<WID; c++)
      grid0[r][c] = grid1[r][c];
  }

  disp_open();
  disp_move(0,0);
  disp_close();

  for(int r=0; r<LEN; r++)
  {
    for(int c=0; c<WID; c++)
      if(grid0[r][c])
        cout << (char)219;
      else
        cout << " ";
    cout << endl;
  }

//  getchar();

  }while(1);

  return 0;
}

void rand_file()
{
  char filename[256];
//  cout << "Enter filename:";
//  cin.getline(filename, 255);
  strcpy(filename, "rand.txt");

  srand(time(NULL));

  ofstream outfile (filename, ios::out);

  for(int i=0; i < (LEN*WID); i++)
    outfile << (2*rand())/RAND_MAX;

  if(outfile.is_open() != NULL)
    outfile.close();
}