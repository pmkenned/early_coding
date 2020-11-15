#include <iostream.h>	// for cout, cin, and cin.getline
#include <fstream.h>	// for ifstream

int main()
{
  system("start input");		// calls input program

  ifstream infile ("conversation.txt");	// input file for conversation

  long begin, end, size_compare = 0;	// file size comparison variables

  while(1)				// output loop
  {
    if(!infile.is_open())
      infile.open ("conversation.txt", ios::in);
    begin = infile.tellg();		// points to beginning of file
    infile.seekg (0, ios::end);		// seeks end of file
    end = infile.tellg();		// points to end of file
    if(infile.is_open())
      infile.close();

    if(end-begin != size_compare)	// test file size for change
    {
      system("cls");
      size_compare = end-begin;		// resets size_compare
      char line[256];			// string buffer from file
      if(!infile.is_open())
        infile.open ("conversation.txt", ios::in);
      while (! infile.eof() )	// print each line of conversation.txt until EOF reached
      {
        infile.getline (line,255);	// getline from conversation.txt
        cout << line << endl;		// print line from conversation.txt
        if (line[0] == (char)113)
          {cout << "Conversation Terminated.\n"; exit(0);}	// if line=q, then exit(0)
      }
      infile.close();
    }	// end test for file size change
  }	// end while loop
  return 0;
}