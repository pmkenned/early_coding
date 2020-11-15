#include <iostream.h>
#include <conio.h>
#include <disp.h>

int main()
{
  disp_open();
  disp_move(0,0);
  disp_eeop();

  cout << "  ";
  for(int i=0; i<10; i++)
    cout << i;
  cout << endl;
  flush(cout);

  for(int i=0; i<10; i++)
  {
    cout << i << " ";
    for(int j=0; j<10; j++)
      cout << 'o';
    cout << endl;
  }
  flush(cout);

  int x = 1;
  int y = 2;
  disp_move(x,y);
  cout << 'x';
  flush(cout);
  int input = 0;
  while( (input = getch() - '0') != 5){

  disp_move(x,y);

  switch(input)
  {
  case 2: x++; break;
  case 4: y--; break;
  case 6: y++; break;
  case 8: x--; break;
  }

  cout << 'o';
  flush(cout);

  disp_move(x,y);

  cout << "x" << endl; }

  disp_move(10,10);
  disp_close();

  return 0;
}