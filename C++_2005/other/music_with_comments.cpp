/****************************************************************

Program:	Music

File:		music.cpp

Functions:	main (inputs and plays notes)

Description:	Asks user for number of notes, octave and note
		of each note, whether they are sharp, flat, or
		natural, displays the frequency in Hertz
		duration in milliseconds, and plays each note.

Author:		Paul Kennedy

Enviroment:	Digital Mars Compiler Version 8.42n, 800MHz, 128
		MB RAM, Windows XP Pro

Notes:		None

Revisions:	1.00 9/1/05	First Release

****************************************************************/

#include <iostream.h>	// For cin and cout
#include <stdlib.h>
#include <math.h>	// For pow() in exponential equation
#include <sound.h>	// For playing notes

int main()
{
	unsigned int index, octave, n;
	char note, sharp_flat;

	cout << "Amount of notes:";		// Number of notes to be entered and played
	cin >> n;

	unsigned int freq[n];			// Array contains frequency of each note
	unsigned int duration[n];		// Arary Contains duration of each note

	int a = 1;
//	cout << "Random seed:";
//	cin >> a;
//	srand(a);

	for(int i = 0; i < n; i++)		// Input loop
	{
//		cout << "Enter Octave (2-9):";	// Octave of note
		octave = 1;
//		cin >> octave;
		index = octave*12+3;		// Converts octave into index
//		cout << "Enter note (A-G):";	// Note in octave
//		cin >> note;
		note = a+65;
		a++;

		switch((int)note)		// Adds value to index
		{
		case 65: index += 9; break;	// A
		case 66: index += 11; break;	// B
		case 67: index += 0; break;	// C
		case 68: index += 2; break;	// D
		case 69: index += 4; break;	// E
		case 70: index += 5; break;	// F
		case 71: index += 7; break;	// G
		default: cout << "Error" << endl;
		}		

		switch((int)note)		// Flat/Sharp or Natural (Yes or No)
		{
		case 65:			// A Flat
		case 66:			// B Flat
//		cout << "Flat [Y/N]?";
//		cin >> sharp_flat;
		sharp_flat = random(2)+89;
		if (sharp_flat == 89)
			index++;
		break;

		case 67:			// C Sharp
		case 68:			// D Sharp
		case 70:			// F Sharp
//		cout << "Sharp [Y/N]?";
//		cin >> sharp_flat;
		sharp_flat = random(2)+89;
		if (sharp_flat == 89)
			index++;
		break;
		}

		freq[i] = 13.7499730586*pow(1.0594631354808, index);
			// Converts index number to frequency using exponetial equation

//		cout << "Duration (500 milliseconds = 1 beat):";	// Duration of beat
//		cin >> duration[i];
		duration[i] = 500;
	}

	for (int i = 0; i < n; i++)	// Playback loop
	{
		cout << freq[i] << "Hz " << duration[i] << " milliseconds" << endl;
			// Dispays frequency and duration of note

		sound_note(freq[i], duration[i]);
			// Plays note
	}

	return 0;
}