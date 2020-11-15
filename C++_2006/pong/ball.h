#include <math.h>
#include <time.h>

class ball
{
public:
  ball();
  ~ball();
  void move(int, int);
  void disp();
private:
  double hpos;
  double vpos;
  double vvel;
  double hvel;
};

ball::ball(): hpos(HSIZE/2), vpos(VSIZE/2), hvel(-0.5), vvel(0.08)
{
}

ball::~ball()
{
}

void ball::move(int p0vpos, int p1vpos)
{
  if(hpos == 1 && p0vpos == (int)vpos)
    hvel = -hvel;
  hpos += hvel;
  vpos += vvel;
}

void ball::disp()
{
  disp_move(vpos+1,hpos);
  cout << " "; flush(cout);
  disp_move(vpos-1,hpos);
  cout << " "; flush(cout);
  disp_move(vpos,hpos-1);
  cout << " "; flush(cout);
  disp_move(vpos,hpos+1);
  cout << " "; flush(cout);
  disp_move(vpos-1,hpos-1);
  cout << " "; flush(cout);
  disp_move(vpos-1,hpos+1);
  cout << " "; flush(cout);
  disp_move(vpos+1,hpos-1);
  cout << " "; flush(cout);
  disp_move(vpos+1,hpos+1);
  cout << " "; flush(cout);

  disp_move(vpos,hpos);
  cout << (char)221; flush(cout);
  usleep(10000);
}