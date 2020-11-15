#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>

short int get_index();	// prompts user for octave, note, sharp/flat/natural and returns index #
void out_cat(short int *out_begin, short int *out_end, short int splice);	// splices in notes
void save(short int *out_begin, short int len);					// saves to file

int main()
{
  short int out_begin[512] = {77,84,104,100,0,0,0,6,0,0,0,1,1,128,77,84,114,107,0,0,0,35,0,255,88,4,4,2,96,8,0,255,127,3,0,0,65,0,255,81,3,7,161,32};
  short int out_end[16] = {0,255,47,0};

  short int splice = 44;	// points to location to splice in notes
  short int n = 0;		// number of notes
  char choice;			// when choice = 'y', program quits

  do	// do-while loops (exits when choice = 'y')
  {
    short int index = get_index();				// gets index number for note
    short int note[] = {0,144,index,100,130,0,128,index,64};	// note
    out_cat(out_begin, note, splice);				// splices in note at splice
    splice += 9;						// each note is 9 numbers

    cout << "Done? [y/n] ";	// asks user is they're done
    cin >> choice;		// user inputs choice

    if(choice == 'n')		// user isn't done
    {
      out_begin[splice] = 129;	// add note separater
      splice++;			// add one to splice
    }
    n++;			// increment note variable (note added)
  }
  while(choice != 'y');		// continue until user enters 'y'

  out_begin[21] = n*10+33;		// char depends on number of notes
  out_cat(out_begin, out_end, splice);	// add end of song
  save(out_begin, splice+4);		// save to file

  return 0;
}

short int get_index()
{
  short int index, octave;	// index and octave of note
  char note, sharp_flat;	// note is between A and G, sharp_flat is either 'y' or 'n'

  cout << "Enter Octave (2-9):";		// Octave of note
  cin >> octave;
  index = octave*12+12;			// Converts octave into index
  cout << "Enter note (A-G):";		// Note in octave
  cin >> note;

  switch((short int)note)		// Adds value to index
  {
  case (int)'A': index += 9; 	break;	// A
  case (int)'B': index += 11; 	break;	// B
  case (int)'C': index += 0; 	break;	// C
  case (int)'D': index += 2; 	break;	// D
  case (int)'E': index += 4; 	break;	// E
  case (int)'F': index += 5; 	break;	// F
  case (int)'G': index += 7; 	break;	// G
  default: cout << "Error" << endl;
  }

  switch((short int)note)	// Flat/Sharp or Natural (Yes or No)
  {
  case (int)'A':		// A Flat
  case (int)'B':		// B Flat
  cout << "Flat [Y/N]?";
  cin >> sharp_flat;
  if (sharp_flat == (int)'Y' | sharp_flat == (int)'y')
    index++;
  break;

  case (int)'C':		// C Sharp
  case (int)'D':		// D Sharp
  case (int)'F':		// F Sharp
  cout << "Sharp [Y/N]?";
  cin >> sharp_flat;
  if (sharp_flat == (int)'Y' | sharp_flat == (int)'y')
    index++;
  break;
  }

  return index;
}

void out_cat(short int out_begin[], short int out_end[], short int splice){	// inserts note
  for(short int i = splice; i < splice+16; i++)
    out_begin[i] = out_end[i-splice];}

void save(short int out_begin[], short int len)		// saves output to file
{
  ofstream output ("output.mid");

  if ( !output.is_open() )
    output.open ("output.mid", ios::binary);	// OUTPUT IN BINARY MODE

  for(short int i=0; i < len; i++)
  {
    cout << (char)out_begin[i];			// cout character
    output << (char)out_begin[i];		// output character to file
  }

  if( output.is_open() )
    output.close();
}