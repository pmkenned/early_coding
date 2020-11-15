#include <iostream.h>
#include <stdio.h>
#include <string.h>
#include <dos.h>
#include <disp.h>

#define SCR_WID		80
#define SCR_HEI		40
#define BLUE_WHITE	287
#define GRAY_BLUE	385

int main()
{
  char error1[] = " Windows ";
  char error2[] = "A fatal exception OE has occurred at 0157:BF7FF831. The current\n";
  char error3[] = "application will be terminated.\n";
  char error4[] = "\t*  Press any key to terminate the current application.\n\n";
  char error5[] = "\t*  Press CTRL+ALT+DEL again to restart your computer. You will\n";
  char error6[] = "  lose and unsaved information in all applications.\n\n";
  char error7[] = "Press any key to continue";

  disp_open();

  disp_move(0,0);
  disp_setattr(BLUE_WHITE);

  for(int j=0; j<SCR_HEI; j++)
  {
    for(int i=0; i<SCR_WID; i++)
      cout << " ";
    flush(cout);
  }
  flush(cout);

  disp_move(0,0);

  disp_setattr(BLUE_WHITE);

  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  flush(cout);

  for(int i=0; i<(SCR_WID-strlen(error1))/2; i++)
    cout << " ";
  flush(cout);

  disp_setattr(GRAY_BLUE);
  cout << error1 << "\n\n";
  flush(cout);
  disp_setattr(BLUE_WHITE);

  for(int i=0; i<(SCR_WID-strlen(error2))/2; i++)
    cout << " ";
  flush(cout);

  cout << error2;

  for(int i=0; i<(SCR_WID-strlen(error2))/2; i++)
    cout << " ";

  cout << error3 << "\n\n";
  flush(cout);

  cout << error4 << error5 << endl;

  for(int i=0; i<(SCR_WID-strlen(error5))/2; i++)
    cout << " ";
  flush(cout);

  cout << error6;  

  for(int i=0; i<(SCR_WID-strlen(error7))/2; i++)
    cout << " ";
  flush(cout);

  cout << error7;
  flush(cout);

  while(1){
    getchar();
  }

  disp_close();

  return 0;
}