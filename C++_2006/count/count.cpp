#include <iostream.h>
#include <time.h>
#include <sound.h>
#include <disp.h>
#include <string.h>

int main()
{
  int countdown;
  char message[] = "Time remaining:\t";

  cout << "Enter countdown time (seconds):";
  cin >> countdown;

  disp_open();
  disp_move(0,0);
  disp_eeop();
  disp_hidecursor();

  cout << message;
  flush(cout);

  for(int i=countdown; i>=0; i--)
  {
    disp_move(0,strlen(message));
    disp_eeol();
    cout << "\t" << i;
    flush(cout);
    sleep(1);
  }

  while(1)
  {
    disp_move(0,strlen(message));
    cout << "\t" << '0';
    flush(cout);
    sound_note(500,100);
    disp_move(0,strlen(message));
    disp_eeol();
    disp_move(0,strlen(message)+8);
    usleep(500000);
  }

  disp_close();

  return 0;
}