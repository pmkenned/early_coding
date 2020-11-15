typedef unsigned short	USHORT;
#include <iostream>

using namespace std;

class Counter
{
public:
  Counter();
  ~Counter();
  USHORT GetItsVal()const { return itsVal; }
  void SetItsVal(USHORT x) {itsVal = x; }
  void operator++ () { ++itsVal; }

private:
  USHORT itsVal;
};

Counter::Counter(): itsVal(0)
{}

Counter::~Counter()
{}

int main()
{
  Counter i;
  cout << "The value of i is " << i.GetItsVal() << endl;
  ++i;
  cout << "The value of i is " << i.GetItsVal() << endl;
  return 0;
}