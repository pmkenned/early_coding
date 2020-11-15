#include <stdio.h>
#include <stdlib.h>
#include <disp.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#define GRAY	7
#define GREEN   10

#define WIDTH   79
#define HEIGHT  49
#define LIN_LEN	20

class line
{
public:
  line();
  ~line();
  void move();

private:
  int x_pos, y_pos, length;
  char ch;
};

line::line(): x_pos(random(WIDTH)), y_pos(-1), length(0), ch(random(256-32)+32)
{
}

line::~line()
{
}

void line::move()
{
  y_pos++;
  if(y_pos>HEIGHT+LIN_LEN)
  {
    x_pos = random(WIDTH);
    y_pos = -1;
    length = 0;
  }
  else
  {
    if(y_pos<HEIGHT)
    {
      disp_move(y_pos,x_pos);
      ch = random(256-32)+32;
      disp_putc(ch);
    }
  }

  if(length>LIN_LEN)
  {
    disp_move(y_pos-LIN_LEN, x_pos);
    disp_setattr(GRAY);
    disp_printf(" ");
    disp_setattr(GREEN);
  }
  length++;
}

int main()
{
  randomize();

  disp_open();

  disp_setattr(GREEN);

  line lines[WIDTH];

  while(1)
  {
    lines[random(WIDTH)].move();
    usleep(1000);
  }

  disp_close();

  return 0;
}
