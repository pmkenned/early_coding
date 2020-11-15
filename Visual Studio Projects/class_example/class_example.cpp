// class_example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>

void const menu(void);

class Human
{
public:
	Human(void);
	~Human(void);

	int const GetWeight(void){return itsWeight;}
	int const GetAge(void){return (int)itsAge;}
	int const GetHappiness(void){return itsHappiness;}
	int const GetHunger(void){return itsHunger;}
	int const GetTiredness(void){return itsTiredness;}
	int const GetHomework(void){return itsHomework;}
	void const GetStats(void);

	void Feed(void);
	void Sleep(void);
	void Play(void);
	void Work(void);
	void Turn(void);

private:
	int itsWeight;
	double itsAge;
	int itsHappiness;
	int itsHunger;
	int itsTiredness;
	int itsHomework;
};

Human::Human(void)
{
	itsWeight = 130;	// pounds
	itsAge = 16;		// years
	itsHappiness = 5;	// low = unhappy	high = happy
	itsHunger = 5;		// low = full		high = hungry
	itsTiredness = 5;	// low = rested		high = tired
	itsHomework = 0;	// number of assignments
}

Human::~Human(void)
{
	std::cout << "Paul died\n";
}

void const Human::GetStats(void)
{
	std::cout << "\nPaul's\n";
	std::cout << " age is " << GetAge() << " year old\n";
	std::cout << " weight is " << GetWeight() << " pounds\n";
	std::cout << " got " << GetHomework() << " homework assignments\n";

	if(GetWeight() > 160 && GetWeight() <=180)
		std::cout << "Paul's overweight!\n";
	if(GetWeight() > 180){
		std::cout << "Paul had a heart attack\n";
		system("pause");
		exit(0);}
	if(GetWeight() < 100 && GetWeight() >= 80)
		std::cout << "Paul's underweight!\n";
	if(GetWeight() < 80){
		std::cout<< "Paul starved to death\n";
		system("pause");
		exit(0);}

	if(GetHappiness() >= 0)
		std::cout << "Paul is content\n";
	if(GetHappiness() < 0 && GetHappiness() >= -5)
		std::cout << "Paul's sad... :(\n";
	if(GetHappiness() < -5 && GetHappiness() >= -10)
		std::cout << "Paul should probably see a psychiatrist :'(\n";
	if(GetHappiness() < -10){
		std::cout << "Paul committed suicide. Nice one\n";
		system("pause");
		exit(0);}

	if(GetHunger() > 10 && GetHunger() <= 15)
		std::cout << "Paul's gettin' kinda hungry\n";
	if(GetHunger() > 15){
		std::cout << "Paul starved to death\n";
		system("pause");
		exit(0);}

	if(GetTiredness() > 10 && GetTiredness() <= 15)
		std::cout << "Paul is starting to get drowsey...\n";
	if(GetTiredness() > 15){
		std::cout << "Paul passed out\n";
		system("pause");
		Sleep();}

	if(GetHomework() > 5 && GetHomework() <= 10)
		std::cout << "Paul is getting behind in his school work\n";
	if(GetHomework() > 10 && GetHomework() <=15)
		std::cout << "Paul got a detention\n";
	if(GetHomework() > 15)
		std::cout << "Paul got expelled\n";
}

void Human::Feed(void)
{
	itsHunger -= 5;
	itsWeight += 5;
	Turn();
}

void Human::Play(void)
{
	itsHappiness += 5;
	Turn();
}

void Human::Sleep(void)
{
	if(GetTiredness() <= 0)
	{
		std::cout << "Paul isn't tired\n";
		system("pause");
	}
	else
	{
		itsTiredness -= 5;
		Turn();
	}
}

void Human::Work(void)
{
	if (GetHomework() == 0)
	{
		std::cout << "Paul doesn't have any homework to do\n";
		system("pause");
	}
	else
	{
		itsTiredness += 1;
		itsHappiness -= 1;
		itsHomework -= 2;
		Turn();
	}
}

void Human::Turn(void)
{
	itsWeight -= 1;
	itsHunger += 1;
	itsTiredness += 1;
	itsAge += (1.0/12.0);
	itsHomework += 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Human Paul;
	char choice;
	do
	{
		Paul.GetStats();
		menu();
		std::cin >> choice;
		switch(choice)
		{
		case '1': Paul.Feed(); break;
		case '2': Paul.Play(); break;
		case '3': Paul.Work(); break;
		case '4': Paul.Sleep(); break;
		case '5': break;
		default:std::cout << choice << " is not a valid choice.\n";break;
		}
	}
	while(choice != '5');

	return 0;
}

void const menu(void)
{
	std::cout << "\nWhat would you like to do?\n";
	std::cout << "1. Feed Paul\n";
	std::cout << "2. Play with Paul\n";
	std::cout << "3. Make Paul do Homework\n";
	std::cout << "4. Let Paul Sleep\n";
	std::cout << "5. Exit Program\n";
}