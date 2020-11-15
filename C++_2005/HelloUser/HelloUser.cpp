#include <iostream.h>

char username[128];

int main ()
{
	cout << "What's your name? ";
	cin.getline (username, 128);
	cout << "Hi, " << username << endl;
	return 0;
}
