#include <iostream.h>
#include <conio.h>
#include <sound.h>
#include <math.h>

double index2freq(int index);

enum {a=65,s=83,d=68,f=70,g=71,h=72,j=74};
enum {w=87,e=69,t=84,y=89,u=85};

int main()
{
  int ch = 0, index = 0, octave = 4;
  cout << "Octave\tNote\tIndex #\tFrequency\n";
  while(ch != 17)
  {
    ch = getch();
    char note[3] = "";

    index = octave*12+3;

    switch(ch-32)
    {
      case u: index++; note[1] = '#'; case h: index += 9;  note[0] = 'A'; break;
                                      case j: index += 11; note[0] = 'B'; break;
      case w: index++; note[1] = '#'; case a: index += 0;  note[0] = 'C'; break;
      case e: index++; note[1] = '#'; case s: index += 2;  note[0] = 'D'; break;
                                      case d: index += 4;  note[0] = 'E'; break;
      case t: index++; note[1] = '#'; case f: index += 5;  note[0] = 'F'; break;
      case y: index++; note[1] = '#'; case g: index += 7;  note[0] = 'G'; break;

      default: index = 0; break;
    }
    if(ch-'0'>=1 && ch-'0'<=9)
    {
      octave = ch-'0';
      index = 0;
    }

    if(index != 0)
      cout << octave << "\t" << note << "\t" << index << "\t" << index2freq(index) << endl;

    sound_note(index2freq(index), 200);
  }

  return 0;
}

double index2freq(int index)
{
  return 13.7499730586*pow(1.0594631354808, index);
}