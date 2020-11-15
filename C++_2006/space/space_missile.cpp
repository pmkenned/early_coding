#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <disp.h>
#include <time.h>

#define VALID	1
#define HSIZE	-79
#define VSIZE	-75

int objects = 0;

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
  void display();

private:
  double h_pos;
  double v_pos;
  double h_vel;
  double v_vel;
  double fuel;
};

ship::ship(): h_pos(-40), v_pos(-0), h_vel(0), v_vel(0), fuel(500)
{objects++;}

ship::~ship()
{objects--;}

int const ship::pos()
{
  if(v_pos <= 0 && v_pos > VSIZE && h_pos < 0 && h_pos > HSIZE)
    return 1;
  else
    return 0;
}

int ship::fuel_status(int input)
{
  if(fuel == 0 || fuel == -1)
  {
    init_screen();
    cout << "OUT OF FUEL!"; flush(cout);
    return 0;
  }
  else
  {
    init_screen();
    cout << "Fuel:" << fuel; flush(cout);
    return input;
  }
}

void ship::display()
{
    int hp = (int)-h_pos;
    int vp = (int)-v_pos;

    disp_move(vp,hp);
    cout << "x";
    flush(cout);
    disp_move(vp,hp);
    usleep(50000/objects);
    cout << " ";
    flush(cout);
}

class missile
{
public:
  missile();
  ~missile();
  void move() {v_pos -= 1;}
  int display();
private:
  double h_pos;
  double v_pos;
};

missile::missile(): h_pos( (-HSIZE*rand())/RAND_MAX), v_pos(-VSIZE)
{objects++;}

missile::~missile()
{objects--;}

int missile::display()
{
  if(v_pos > 0 && v_pos < -VSIZE && h_pos > 0 && h_pos < -HSIZE)
  {
    disp_move(v_pos,h_pos);
    cout << "x";
    flush(cout);
    disp_move(v_pos,h_pos);
    usleep(50000/objects);
    cout << " ";
    flush(cout);
    return 0;
  }
  else
    return 1;
  return 0;
}

int main()
{
  srand(time(NULL));

  init_screen();
  ship craft;
  missile mis[5]; int mis_ok[5] = {1,1,1,1,1};
  init_screen();

  while(craft.pos() == VALID)
  {
    craft.fall();
    craft.move();
    for(int i=0; i<5; i++)
      mis[i].move();
    int input = control();
    input = craft.fuel_status(input);

    switch(input)
    {
    case 8: craft.thrust_up();		break;
    case 4: craft.thrust_left();	break;
    case 6: craft.thrust_right();	break;
    default: break;
    }

    craft.display();
    for(int i=0; i<5; i++)
    {
      if (mis_ok[i]){
        if(mis[i].display() == 1){
          mis[i].~missile(); mis_ok[i] = 0;}}
    }
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