#include <iostream.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 

void main_menu();
void open_existing();
void compile();
void run();
void create_new();
void setup();

char compiler[128] = {"C:\\Progra~1\\Digita~1\\bin\\dmc.exe"}, source[128] = {NULL};

int main()
{
  main_menu();
  return 0;
}

void main_menu()
{
  int choice = 0;

  cout << "What would you like to do?\n";
  cout << "1. Open an existing source code file\n";
  cout << "2. Compile and existing source code file\n";
  cout << "3. Run and existing program\n";
  cout << "4. Create a new source code file\n";
  cout << "5. Setup compiler and source code path variables\n";
  cout << "6. Exit this program\n";

  cin >> choice;

  switch(choice)
  {
  case 1:
  open_existing();
  break;

  case 2:
  compile();
  break;

  case 3:
  run();
  break;

  case 4:
  create_new();
  break;

  case 5:
  setup();
  break;

  case 6:
  exit(0);
  break;

  default:
  cout << "Invalid choice\n";
  break;
  }

  main_menu();
}

void open_existing()
{
  char notepad[128] = {"C:\\Windows\\notepad.exe "};

  if (source[0] == 0)
  {
    cout << "Enter the path and file name of your source code:";
    cin >> source;
  }

  strcat(notepad, source);

  system (notepad);
}

void compile()
{
  char compiler_source[128] = {NULL};

  if (compiler[0] == 0)
  {
    cout << "Enter the path and file name of your compiler:";
    cin >> compiler;
  }

  if (source[0] == 0)
  {
    cout << "Enter the path and file name of your source code:";
    cin >> source;
  }

  strcat (compiler_source, compiler);
  strcat (compiler_source, " ");
  strcat (compiler_source, source);

  system (compiler_source);
}

void run()
{
  if (source[0] != 0)
    system(source);
}

void create_new()
{
  cout << "Enter path and file name of new source code file:";
  cin >> source;

  open_existing();
}

void setup()
{
  int choice = 0;

  cout << "Compiler path and file name:" << compiler << endl;
  cout << "Source code path and file name:" << source << endl;

  cout << "What do you want to do?\n";
  cout << "1. Change compiler path and file name\n";
  cout << "2. Change the source code path and file name\n";
  cout << "3. Cancel and return to main menu\n";

  cin >> choice;

  switch(choice)
  {
  case 1:
  cout << "Enter the path and file name of your compiler:";
  cin >> compiler;
  break;

  case 2:
  cout << "Enter the path and file name of your source code:";
  cin >> source;
  break;

  case 3:
  break;

  default:
  cout << "Invalid choice";
  break;
  }
}