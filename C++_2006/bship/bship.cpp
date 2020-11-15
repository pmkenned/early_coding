#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <disp.h>
#include <fstream.h>

int filesize(char* filename);

int main()
{
  int player;
  cout << "Enter player number:";
  cin >> player;

  disp_open();
  disp_move(0,0);
  disp_eeop();
  disp_move(12,0);

  cout << "  ";
  for(int i=0; i<10; i++)
    cout << i;
  cout << endl;
  flush(cout);

  for(int i=65; i<75; i++)
  {
    cout << (char)i << " ";
    for(int j=0; j<10; j++)
      cout << '.';
    cout << endl;
  }
  flush(cout);

int ships[5] = {2,3,3,4,5};

for(int ship = 0; ship < 5; ship++)
{
  int x = 1+12;
  int y = 2;
  disp_move(x,y);
  cout << (char)219;
  flush(cout);

  int input = 0; char before_a = '.', before_b = '.';
  while( (input = getch() - '0') != 5)
  {
    disp_move(x,y);
    int x_new = x, y_new = y;
    switch(input)
    {
    case 2: if(x<10+12 && x+ships[ship]-1<10+12) x_new = ++x; break;
    case 4: if(y>2 && y+ships[ship]-1>2) y_new = --y; break;
    case 6: if(y<11 && y+ships[ship]-1<11) y_new = ++y; break;
    case 8: if(x>1+12 && x+ships[ship]-1>1+12) x_new = --x; break;
    }
    cout << before_a;
    flush(cout);

    before_b = (char)disp_peekw(x,y);
    disp_move(x_new,y_new);
    before_a = (char)disp_peekw(x_new,y_new);
    cout << (char)219 << endl;
    flush(cout);
  }

  char before_h, before_v;

  disp_move(x+ships[ship]-1,y);
  before_v = (char)disp_peekw(x+ships[ship]-1,y);
  cout << (char)219; flush(cout);
  disp_move(x,y+ships[ship]-1);
  before_h = (char)disp_peekw(x,y+ships[ship]-1);
  cout << (char)219; flush(cout);

    input = getch() - '0';
    while(input != 2 && input != 6) {input = getch() - '0';};

    disp_move(x,y);

    switch(input)
    {
    case 2:
      for(int i=0; i<ships[ship]; i++){disp_move(x+i,y); cout << (char)219; flush(cout);}
      disp_move(x,y+ships[ship]-1); cout << before_h; flush(cout);
      break;
    case 6:
      for(int i=0; i<ships[ship]; i++){disp_move(x,y+i); cout << (char)219; flush(cout);}
      disp_move(x+ships[ship]-1,y); cout << before_v; flush(cout);
      break;
    }

}// next ship

  disp_move(0,0);

  cout << "  ";
  for(int i=0; i<10; i++)
    cout << i;
  cout << endl;
  flush(cout);

  for(int i=65; i<75; i++)
  {
    cout << (char)i << " ";
    for(int j=0; j<10; j++)
      cout << '.';
    cout << endl;
  }
  flush(cout);

while(1){
if(player){

  int x = 1;
  int y = 2;
  disp_move(x,y);
  cout << (char)219;
  flush(cout);

  int input = 0; char before_a = '.', before_b = '.';
  while( (input = getch() - '0') != 5)
  {
    disp_move(x,y);
    int x_new = x, y_new = y;
    switch(input)
    {
    case 2: if(x<10) x_new = ++x; break;
    case 4: if(y>2) y_new = --y; break;
    case 6: if(y<11) y_new = ++y; break;
    case 8: if(x>1) x_new = --x; break;
    }
    cout << before_a;
    flush(cout);

    before_b = (char)disp_peekw(x,y);
    disp_move(x_new,y_new);
    before_a = (char)disp_peekw(x_new,y_new);
    cout << (char)219 << endl;
    flush(cout);
  }

  ofstream outfile("fire", ios::out);

  outfile << x << endl << y << endl;

  if(outfile.is_open() != NULL)
    outfile.close();
  player = 0;
} // pass control
else
{
  disp_move(23,0);
  cout << "Waiting for other player to make a move...\n";
  int fs = filesize("fire");

  while(fs == filesize("fire")) ;

  int x = 0, y = 0;
  // get numbers from file

  char buffer[256];
  ifstream infile("fire", ios::in);
    infile.getline(buffer, 255);
    x = atoi(buffer)+12;
    infile.getline(buffer, 255);
    y = atoi(buffer);
  infile.close();
  
//  cout << "x:"; flush(cout);
//  cin >> x;
//  cout << "y:"; flush(cout);
//  cin >> y;
  int status = (char)disp_peekw(x,y);

  switch(status)
  {
  case  46: cout << "MISS"; flush(cout); disp_move(x,y); cout << "O"; flush(cout); break;
  case -37: cout << "HIT!"; flush(cout); disp_move(x,y); cout << "X"; flush(cout); break; 
  default:  cout << "other:" << status; flush(cout); break;
  }

  flush(cout);
  player = 1;
}}

  disp_close();

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