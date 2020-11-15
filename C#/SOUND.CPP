#include <iostream.h>
#include <sound.h>

typedef unsigned long int ULONG;

const ULONG
C4 = 261,
D4 = 293,
E4 = 329,
F4 = 349,
G4 = 391,
A4 = 440,
B4 = 493,
C5 = 523;

int main()
{
	ULONG array_size;

	cout << "Enter number of notes:";
	cin >> array_size;

	ULONG notes[array_size];
	ULONG duration[array_size];
	char note;

	for(int i = 0; i < array_size; i++)
	{
		cout << "Enter note " << i << ":";
		cin >> note;
		notes[i] = (int) note;
		cout << "Enter duration:";
		cin >> duration[i];
	}

	for(int i = 0; i < array_size; i++)
	{
		switch(notes[i])
		{
		case 67:
		sound_note(C4, duration[i]);
		break;

		case 68:
		sound_note(D4, duration[i]);
		break;

		case 69:
		sound_note(E4, duration[i]);
		break;

		case 70:
		sound_note(F4, duration[i]);
		break;

		case 71:
		sound_note(G4, duration[i]);
		break;

		case 65:
		sound_note(A4, duration[i]);
		break;

		case 66:
		sound_note(B4, duration[i]);
		break;
		}
	}

	return 0;
}