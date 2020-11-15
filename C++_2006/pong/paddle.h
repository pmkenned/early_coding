class paddle
{
public:
  paddle(int);
  ~paddle();
  void move(int);
  void move();
  void disp();
  int getvpos(){return vpos;}
private:
  int vpos;
  int hpos;
};

paddle::paddle(int player): vpos(VSIZE/2)
{
  if(player == 0)
    hpos = 0;
  else
    hpos = HSIZE;
}

paddle::~paddle()
{
}

void paddle::move(int direction)
{
  if(direction == UP)
    vpos--;
  if(direction == DOWN)
    vpos++;
}

void paddle::move()
{
}

void paddle::disp()
{
  disp_move(vpos+1,hpos);
  cout << " "; flush(cout);
  disp_move(vpos-1,hpos);
  cout << " "; flush(cout);
  disp_move(vpos,hpos);
  cout << (char)221 ; flush(cout);
}