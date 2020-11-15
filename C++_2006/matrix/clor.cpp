#include <iostream.h>
#include <disp.h>

int main()
{
  disp_open();
  for(int i=0; i<512; i++)
  {
    disp_setattr(i);
    cout << i << " " << flush;
  }
  disp_close();
  return 0;
}