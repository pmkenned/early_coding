#include <stdio.h>
#include <stdlib.h>
#include <disp.h>

#define WIDTH	80
#define HEIGHT	49

int main()
{
  int attr;

  disp_open();
  attr = disp_getattr();	// save original attribute

  for(int i=32; i>-1; i++)
  {
    disp_move(random(HEIGHT), random(WIDTH));
    char str[2] = {random(256-32)+32,'\0'};
    disp_setattr(random(256));		// set to red on grey
    disp_printf(str);
  }

  disp_setattr(attr);		// restore original attribute
  disp_printf("\r\n");
  disp_close();

  return 0;
}