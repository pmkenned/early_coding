#include <stdio.h>
#include <stdlib.h>
#include <disp.h>
#include <time.h>

#define WIDTH	80
#define HEIGHT	49

int main()
{
  randomize();

  int attr;

  disp_open();
  attr = disp_getattr();	// save original attribute


  for(int i=0; i<256; i++)
  {
    disp_setattr(i);
    disp_printf("%d", i);
  }


  char ch[WIDTH];
  char color[WIDTH];

  disp_setattr(10);
  for(int j=0; j<10; j++)
  {
    int a = random(WIDTH);
    ch[a] = random(256-128)+128;
    for(int i=0; i<HEIGHT+20; i++)
    {
      ch[a] = random(256-128)+128;
      char disp[2] = {ch[a], '\0'};
      disp_move(i, a);
      if(i<HEIGHT)
        disp_printf(disp);
      disp_setattr(7);
      if(i>20)
      {
        disp_move(i-20, a);
        disp_printf(" ");
      }
      disp_setattr(10);
      usleep(10000);
    }
  }

/*
  for(int i=32; i>-1; i++)
  {
    disp_move(i, random(WIDTH));
    char str[2] = {random(256-32)+32,'\0'};
    disp_setattr(random(256));		// set to red on grey
    disp_printf(str);
  }
*/

  disp_setattr(attr);		// restore original attribute
  disp_printf("\r\n");
  disp_close();

  return 0;
}