#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <disp.h>
#include <time.h>

#define HSIZE	-79
#define VSIZE	-48

void init_screen();
int control();

class ship
{
public:
  ship();
  ~ship();

  double const get_hp(){return h_pos;}
  double const get_vp(){return v_pos;}

  void fall()		{v_vel += 0.006;}
  void thrust_up()	{v_vel -= 0.030; fuel-=2;}
  void thrust_left()	{h_vel -= 0.080; fuel--;}
  void thrust_right()	{h_vel += 0.080; fuel--;}
  void move()		{v_pos -= v_vel; h_pos -= h_vel; h_vel *= 0.95;}
  int const pos();
  int fuel_status(int input);
  void print_vel();
  void display();

private:
  double h_pos;
  double v_pos;
  double h_vel;
  double v_vel;
  double fuel;
};

ship::ship(): h_pos(-40), v_pos(0), h_vel(0), v_vel(0), fuel(500)
{}

ship::~ship(){}

int const ship::pos()
{
  if(v_pos <= 0 && v_pos > VSIZE && h_pos < 0 && h_pos > HSIZE)
    return 1;
  else if(v_pos < VSIZE && v_vel < 0.3)
    return 2;
  else
    return 0;
}

int ship::fuel_status(int input)
{
  if(fuel == 0 || fuel == -1)
  {
    disp_move(0,0);
    cout << "OUT OF FUEL!"; flush(cout);
    return 0;
  }
  else
  {
    disp_move(0,0);
    disp_eeol();
    cout << "Fuel:" << fuel; flush(cout);
    return input;
  }
}

void ship::print_vel()
{
  disp_move(1,0);
  cout << "Vertical Velocity:" << v_vel << endl; disp_eeol();
  cout << "Horizontal Velocity:" << h_vel << endl; disp_eeol();
  cout << "Altitude:" << (int)-(VSIZE - v_pos) << endl; disp_eeol();
  flush(cout);
}

void ship::display()
{
    int hp = (int)-h_pos;
    int vp = (int)-v_pos;

    disp_move(vp,hp);
    cout << "x";
    flush(cout);
    disp_move(vp,hp);
    usleep(25000);
    cout << " ";
    flush(cout);
}

int main()
{
  init_screen();
  ship craft;

  while(craft.pos())
  {
    if(craft.pos() == 2)
    {
      cout << "SUCCESSFUL LANDING!";
      exit(0);
    }
    craft.fall();
    craft.move();
    int input = control();
    input = craft.fuel_status(input);
    craft.print_vel();

    switch(input)
    {
    case 8: craft.thrust_up();		break;
    case 4: craft.thrust_left();	break;
    case 6: craft.thrust_right();	break;
    default: break;
    }

    craft.display();
  }

  cout << "CRASH!";

  disp_close();

  return 0;
}

void init_screen()
{
  disp_open();
  disp_move(0,0);
  disp_eeop();
}

int control()
{
  if(kbhit())
    return getch() - '0';
  return 0;
}