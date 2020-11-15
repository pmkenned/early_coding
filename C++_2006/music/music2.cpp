#include <iostream.h>	// For cin and cout
#include <math.h>	// For pow() in exponential equation
#include <sound.h>	// For playing notes
#include <fstream.h>
#include <stdlib.h>
#include <stdio.h>

void note_input(unsigned int freq[], unsigned int duration[], unsigned int i);
void convert_to_freq(unsigned int freq[], unsigned int index, unsigned int i);
void play_back(unsigned int freq[], unsigned int duration[]);
void print();

unsigned int index, octave, n=0;
char note, sharp_flat;

int main(int argc, char* argv[])
{
	if(argc == 3)
		print();
	if(argv[1] == NULL)
	{
		cout << "Amount of notes:";		// Number of notes to be entered and played
		cin >> n;

		unsigned int freq[n];			// Array contains frequency of each note
		unsigned int duration[n];		// Arary Contains duration of each note

		for(int i = 0; i < n; i++)		// Input loop
		{
			note_input(freq, duration, i);
		}
		flush(cout);
		cout << "Save to File?"; flush(cout);
		char ch = (char)getchar();
		if(ch == 'y')
		{
			char filename[256];
			cout << "Enter filename:";
			cin >> filename;
			ofstream outfile(filename);
			for(int i=0; i<n; i++)
			{
				outfile << freq[i] << "\n" << duration[i] << endl;
			}
			outfile.close();
		}
		play_back(freq, duration);
	}
	else
	{
		ifstream infile(argv[1]);

		unsigned int* freq = new unsigned int[0];
		unsigned int* duration = new unsigned int[0];

		while(infile.eof() == NULL)
		{
			char buffer[256];

			unsigned int* temp = new unsigned int[n];
			for(int i=0; i<n; i++)
				temp[i] = freq[i];
			delete[] freq;
			freq = new unsigned int[n+1];
			for(int i=0; i<n; i++)
				freq[i] = temp[i];
			infile.getline(buffer, 255);
			freq[n] = atoi(buffer);
			delete[] temp; temp = NULL;

			temp = new unsigned int[n];
			for(int i=0; i<n; i++)
				temp[i] = duration[i];
			delete[] duration;
			duration = new unsigned int[n+1];
			for(int i=0; i<n; i++)
				duration[i] = temp[i];
			infile.getline(buffer, 255);
			duration[n] = atoi(buffer);
			delete[] temp; temp = NULL;

			n++;
		}

		delete[] duration;
		delete[] freq;

		infile.close();

		play_back(freq, duration);
	}

	return 0;
}

void note_input(unsigned int freq[], unsigned int duration[], unsigned int i)
{
	cout << "Enter Octave (2-9):";	// Octave of note
	cin >> octave;
	index = octave*12+3;		// Converts octave into index
	cout << "Enter note (A-G):";	// Note in octave
	cin >> note;

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
	cout << "Flat [Y/N]?";
	cin >> sharp_flat;
	if (sharp_flat == 89 | sharp_flat == 121)
		index++;
	break;

	case 67:			// C Sharp
	case 68:			// D Sharp
	case 70:			// F Sharp
	cout << "Sharp [Y/N]?";
	cin >> sharp_flat;
	if (sharp_flat == 89 | sharp_flat == 121)
		index++;
	break;
	}

	convert_to_freq(freq, index, i);

	cout << "Duration (500 milliseconds = 1 beat):";	// Duration of beat
	cin >> duration[i];
}

void convert_to_freq(unsigned int freq[], unsigned int index, unsigned int i)
{
		freq[i] = 13.7499730586*pow(1.0594631354808, index);
			// Converts index number to frequency using exponetial equation
}

void play_back(unsigned int freq[], unsigned int duration[])
{
	for (int i = 0; i < n; i++)	// Playback loop
	{
		cout << freq[i] << "Hz " << duration[i] << " milliseconds" << endl;
		// Dispays frequency and duration of note

		sound_note(freq[i], duration[i]);
			// Plays note
	}
}

void print()
{
	for(unsigned int i=0; i<65; i++)
		cout << (char)(i%7+65) << " " << i << ":" << "\t" << 13.7499730586*pow(1.0594631354808, i) << endl;
	exit(0);
}