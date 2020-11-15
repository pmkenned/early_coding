#include <iostream.h>
#include <fstream.h>
#include <string.h>

#define LINEWID	17	// number of hex numbers printed per line
#define ROWS	23	// number of rows in console (pauses after each screen full)

int filesize(char*);			// gets size of file
int ten2bin(int x);			// converts base ten numbers to base two
int byte2nibble(int x, char order);	// returns either H.O. or L.O nibble (order = either 'h' or 'l')
char bin2hex(int x);			// converts 4-bit binary number to hex (returns char 0-F)

int main(int argc, char* argv[])
{
  char filename[255];
  if(argv[1] == NULL)			// if user did not enter a filename argument...
  {					//
    cout << "Enter filename: ";		// then ask for a filename...
    cin >> filename;
  }
  else
    strcpy(filename, argv[1]);		// otherwise, copy the argument to the filename

  int n = filesize(filename);		// get size of file

  ifstream infile(filename, ios::in|ios::binary);	// open filename for input (binary)

  char buffer[256];			// buffer for each line of infile

  cout << "\t";
  for(int i=0; i<LINEWID; i++){ cout << i << " "; if(i<=9) cout << " ";}	// prints reference numbers across the top of hex values
  for(int i=0; i<LINEWID; i++){ cout << i - 10*(i/10); }			// prints reference numbers across the top of ascii chars
  cout << "\n00:\t";

  for(int i=0; i<n; i++)			// loop until i = size of file
  {
    if( i%(LINEWID*ROWS) == 0 && i != 0 )	// if i is divisible by size of console screen...
    {
      char choice = getchar();			// then wait for user input
      switch(choice)				// the user may want to enter a special command
      {						// such as
      case 'q':	exit(0);	break;		// 'q' for quit
      default:			break;		// user didn't enter a special command
      }

      cout << "\n\t";
      for(int i=0; i<LINEWID; i++){ cout << i << " "; if(i<=9) cout << " ";}	// prints reference numbers across the top of hex values
      for(int i=0; i<LINEWID; i++){ cout << i - 10*(i/10); }			// prints reference numbers across the top of ascii chars
      cout << "\n" << i << ":\t";
    }

    int c = infile.get();	// get char from file

    if(c != '\n' && c != 13 && c != '\t' && c != '\a' && c != '\0' && c != 8)	// these chars cannot be displayed (13 = carriage return, \a = beep, \0 = NULL, 8 = backspace)
      buffer[i%LINEWID] = c;						// store c in the buffer array at the remainder of i/LINEWID (if not unprintable)
    else
      buffer[i%LINEWID] = '.';						// if the char was unprintable, store a '.'

    c = ten2bin(c);			// convert the ascii value to binary

    int ho = byte2nibble(c, 'h');	// ho now holds the high order nibble of c
    int lo = byte2nibble(c, 'l');	// lo now holds the low order nibble of c

    cout << bin2hex(ho);		// print the hex value of ho
    cout << bin2hex(lo);		// print the hex value of lo

    cout << " ";			// put a space in between hex values
    if((i+1)%LINEWID == 0)		// if i%LINEWID == 0, the line is finished
    {
      buffer[i%LINEWID+1] = '\0';	// cap the buffer array with a NULL char
      cout << buffer << endl;		// print the buffer array and a new line
      cout << i << ":\t";		// print the position in the file
    }
  }	// end of file

  if(infile.is_open() != NULL)		// if the file is open...
    infile.close();			// close it

  return 0;
}

int filesize(char* filename)	// return size of file
{
  long begin,end;
  ifstream file (filename, ios::in|ios::binary);
  begin = file.tellg();
  file.seekg (0, ios::end);
  end = file.tellg();
  file.close();

  return end-begin;
}

int ten2bin(int x)		// converts base ten numbers to binary
{
  int n=0;
  while(x>0)
  {
    int i=0;
    while(x-pow(2,i)>=0)	// increment i until 2^i is greater than x
      i++;
    n+=pow(10,i-1);		// add 10^(i-1) to n
    x-=pow(2,i-1);		// reduce x by 2^(i-1)
  }

  return n;
}

int byte2nibble(int x, char order)	// returns H.O. or L.O. nibble of byte
{
  if(order == 'h')			// if order = high
    x = (int)(x/pow(10,4));		// strip low order bits
  if(order == 'l')			// if order = low
    x = x-pow(10,4)*(int)(x/pow(10,4));	// subtract high order
  return x;
}

char bin2hex(int x)	// returns a char from 0-F, converting a nibble to a hex value
{
  switch(x)
  {
  case 0:	return '0';
  case 1:	return '1'; case 100:	return '4'; case 111:	return '7'; case 1010:	return 'A'; case 1101:	return 'D';
  case 10:	return '2'; case 101:	return '5'; case 1000:	return '8'; case 1011:	return 'B'; case 1110:	return 'E';
  case 11:	return '3'; case 110:	return '6'; case 1001:	return '9'; case 1100:	return 'C'; case 1111:	return 'F';
  default: cout << "ERROR: " << x << " out of range\n"; break;
  }
  return 1;
}