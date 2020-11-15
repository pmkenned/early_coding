#include <iostream>

using namespace std;

#include "node.h"

int menu();

int main()
{
  int choice = 0;
  int x = 0;
  node * start = NULL;
  node * list = NULL;
  node * temp = NULL;

  start = list = new node;

  while(choice != 5)
  {
    choice = menu();

    switch(choice)
    {
      case 1:
      list = start;
      while(list->getNext() != NULL)
      {
        list->print();
        list = list->getNext();
      }
      cin.get();
      break;

      case 2:
      list = start;
      while(x != 0)
      {
        cin >> x;
        if(x == 4)
          continue;
        list->setData(x);
        list->setNext(new node);
        list = list->getNext();
      }
      list = start;
      break;

      case 5:
      break;

      default:
      std::cout << "You did not enter a valid choice\n";
      break;
    }
  }

  return 0;
}

int menu(void)
{
  int choice = 0;

  cout << "What would you like to do?\n";
  cout << "1. View list\n";
  cout << "2. Add elements to list\n";
  cout << "3. Remove elements from list\n";
  cout << "4. Edit an element in the list\n";
  cout << "5. Quit this program\n";

  cin >> choice;
  cin.get();

  return choice;
}
