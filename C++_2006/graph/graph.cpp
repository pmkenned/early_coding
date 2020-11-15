#include <iostream.h>
#include <conio.h>
#include <disp.h>
#include <math.h>
#include <string.h>

#define HSIZE 79
#define VSIZE 79

char* equation();
void window(int &x_min,int &x_max,int &y_min,int &y_max);
void graph(int x_min,int x_max,int y_min,int y_max);

int main()
{
  int choice = 0; char* function = new char[256];
  int x_min = -HSIZE, x_max = HSIZE, y_min = -VSIZE, y_max = VSIZE;

  while(choice != 3)
  {
    cout << "1. Enter Equation\n";
    cout << "2. Modify Window\n";
    cout << "3. Graph\n";
    cin >> choice;

    switch(choice)
    {
    case 1: strcpy(function,equation()); getchar();		break;
    case 2: window(x_min,x_max,y_min,y_max);			break;
    case 3: graph(x_min,x_max,y_min,y_max);			break;
    default: cout << choice << " is not a valid choice.\n"; 	break;
    }
  }

//  getchar();

  return 0;
}

char* equation()
{
  char* equation = new char[256];
  cin.getline(equation,255);
  return &equation[0];
}

void window(int &x_min,int &x_max,int &y_min,int &y_max)
{
  cout << "Enter x_min:";
  cin >> x_min;
  cout << "Enter x_max:";
  cin >> x_max;
  cout << "Enter y_min:";
  cin >> y_min;
  cout << "Enter y_max:";
  cin >> y_max;
}

void graph(int x_min,int x_max,int y_min,int y_max)
{
  disp_open();
  disp_move(0,0);
  disp_eeop();

  for(double x=x_min; x<x_max; x+=0.01)
  {
    double y = 13*sin(x/4);
//    double y = pow(x,1.2);
    if(VSIZE/2-y < VSIZE && VSIZE/2-y > 0 && HSIZE/2+x > 0 && HSIZE/2+x < HSIZE)
    {
      disp_move((int)(VSIZE/2-y),(int)(HSIZE/2+x));
      cout << (char)219;
    }
    flush(cout);
  }

  disp_close();
}