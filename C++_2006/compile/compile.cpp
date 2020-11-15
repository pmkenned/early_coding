#include <iostream.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 

void open_existing();
void compile();
void run();
void create_new();
void setup();

char compiler[128] = "C:\\Progra~1\\Digita~1\\bin\\dmc.exe", source[128] = {NULL};
char program[128] = {NULL};

int main()
{
  char choice[128];
  int ch;

  do
  {
    cout << "What would you like to do?\n";
    cout << "1. Open an existing source code file\n";
    cout << "2. Compile an existing source code file\n";
    cout << "3. Run an existing program\n";
    cout << "4. Create a new source code file\n";
    cout << "5. Setup compiler and source code path variables\n";
    cout << "6. Exit this program\n";

    cin >> choice;
    ch = atoi(choice);

    switch(ch)
    {
    case 1: open_existing();	break;
    case 2: compile();		break;
    case 3: run();		break;
    case 4: create_new();	break;
    case 5: setup();		break;
    case 6: 			break;		
    default:
    cout << "Invalid choice\n";	break;
    }
  }
  while (ch != 6);

  return 0;
}

void open_existing()
{
  char notepad[128] = "notepad";

  if (source[0] == 0)
  {
    cout << "Enter the path and file name of your source code:";
    cin.ignore(127, '\n');
    cin.getline(source, 127);
  }

  strcat(notepad, " ");
  strcat(notepad, source);

  system (notepad);
}

void compile()
{
  char compiler_source[128] = {NULL};

  if (compiler[0] == 0)
  {
    cout << "Enter the path and file name of your compiler:";
    cin.ignore(127, '\n');
    cin.getline(compiler, 127);
  }

  if (source[0] == 0)
  {
    cout << "Enter the path and file name of your source code:";
    cin.ignore(127, '\n');
    cin.getline(source, 127);
  }

  strcat (compiler_source, compiler);
  strcat (compiler_source, " ");
  strcat (compiler_source, source);

  system (compiler_source);
}

void run()
{
  if (program[0] != 0)
    system(program);
  else
  {
    cout << "Enter the path and file name of your program:";
    cin.ignore(127, '\n');
    cin.getline(program, 127);
    system(program);
  }
}

void create_new()
{
  cout << "Enter path and file name of new source code file:";
  cin.ignore(127, '\n');
  cin.getline(source, 127);

  open_existing();
}

void setup()
{
  char choice[128];
  int ch;

  cout << "Compiler path and file name:" << compiler << endl;
  cout << "Source code path and file name:" << source << endl;

  cout << "What do you want to do?\n";
  cout << "1. Change compiler path and file name\n";
  cout << "2. Change the source code path and file name\n";
  cout << "3. Change the program path and file name\n";
  cout << "4. Cancel and return to main menu\n";

  cin >> choice;
  ch = atoi(choice);

  switch(ch)
  {
  case 1:
  cout << "Enter the path and file name of your compiler:";
  cin.ignore(127, '\n');
  cin.getline(compiler, 127);
  break;

  case 2:
  cout << "Enter the path and file name of your source code:";
  cin.ignore(127, '\n');
  cin.getline(source, 127);
  break;

  case 3:
  cout << "Enter the path and file name fo your program:";
  cin.ignore(127, '\n');
  cin.getline(program, 127);
  break;

  case 4:
  break;

  default:
  cout << "Invalid choice";
  break;
  }
}