#include <iostream.h>

void print_table();
void char2int();
void int2char();

int main()
{
  char choice;

  do
  {
    cout << "What would you like to do?\n";
    cout << "1. Print the ascii table\n";
    cout << "2. Convert int to char\n";
    cout << "3. Convert char to int\n";
    cout << "4. Quit program\n";

    cin >> choice;

    switch(choice)
    {
    case '1':
    print_table();
    break;

    case '2':
    int2char();
    break;

    case '3':
    char2int();
    break;

    case '4':
    break;

    default:
    cout << choice << " is not a valid choice\n";
    break;
    }
  }
  while(choice != '4');

  return 0;
}

void print_table()
{
  for(int i=0; i<256; i++)
  {
    cout << i << ": " << (char) i << "\t";
  }
  cout << endl;
}

void char2int()
{
  char character;
  cout << "Enter character: ";
  cin >> character;
  cout << (int)character << endl;
}

void int2char()
{
  int integer;
  cout << "Enter integer: ";
  cin >> integer;
  cout << (char) integer << endl;
}