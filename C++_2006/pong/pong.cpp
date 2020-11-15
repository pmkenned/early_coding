#include <iostream.h>
#include <disp.h>
#include <conio.h>

#define VSIZE	20
#define HSIZE	79
#define UP	56
#define	DOWN	50

#include "paddle.h"
#include "ball.h"

int control();

int main(int argc, char * argv[])
{
  disp_open();

  paddle player0(0), player1(1);
  ball ball1;

  int direction = 0;
  while(direction != 5+'0')
  {
    direction = control();

    player0.move(direction);
    player0.disp();
    player1.move();
    player1.disp();

    ball1.move(player0.getvpos(), player1.getvpos());
    ball1.disp();
  }

  disp_close();

  return 0;
}

int control()
{
  if(kbhit())
    return getch();
  return 0;
}