// linked_lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int menu();

int _tmain(int argc, _TCHAR* argv[])
{
	class node * start = NULL;
	class node * list = NULL;
	int choice = 0;

	while(choice != 5)
	{
		choice = menu();

		switch(choice)
		{
		case 1:
		break;

		case 2:
		{
			int n, index;
			cout << "Add how many elements? ";
			cin >> n;
			cout << "Add elements where? ";
			cin >> index;
			if(index >= index)
			{
				cout << "There are currently only " << node::getNumber() << " elements." << endl;
				continue;
			}
		}
		break;

		case 3:
		break;

		case 4:
		break;

		case 5:
		break;

		default:
		cout << "You did not enter a valid choice." << endl;
		break;
		}
	}

	return 0;
}

int menu()
{
	int choice;

	cout << "What would you like to do?" << endl
		 << "1. Print the list" << endl
		 << "2. Add an element to the list" << endl
		 << "3. Modify an element" << endl
		 << "4. Delete an element" << endl
		 << "5. Exit this program" << endl;
	cin >> choice;

	return choice;
}