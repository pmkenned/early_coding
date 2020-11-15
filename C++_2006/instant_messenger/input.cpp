#include <iostream.h>	// for cout, cin, and cin.getline
#include <fstream.h>	// for ofstream

int main()
{
  ofstream outfile;		// output file
  outfile.open ("conversation.txt", ios::trunc);	// truncate conversation.txt

  char conversation[256];	// user input string

  cout << "Enter q to quit.\n";

  while(conversation[0] != (char)113)	// while input != q
  {
    if(!outfile.is_open())		// if file is closed, then open
      outfile.open ("conversation.txt", ios::app);
    cout << ">";  			// prompt
    cin.getline(conversation, 255);	// get input
    outfile << conversation << endl;	// output to file
    outfile.close();			// close file
  }

  if(outfile.is_open())	// is output file open?
    outfile.close();	// if still open, then close

  return 0;
}