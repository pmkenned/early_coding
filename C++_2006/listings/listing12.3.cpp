#include <iostream.h>
#include <string.h>

class Animal
{
public:
  Animal();
  ~Animal();
  int GetAge() const {return itsAge;}
  int GetWeight() const {return itsWeight;}
  void SetAge(int age) {itsAge = age;}
  void SetWeight(int weight) {itsWeight = weight;}
protected:
  int itsAge;
  int itsWeight;
};

Animal::Animal(): itsAge(0), itsWeight(0)
{}

Animal::~Animal()
{}

class Bird: public Animal
{
public:
};

class Mammal: public Animal
{
public:
protected:
};

class Human: public Mammal
{
public:
  Human();
  Human(char* name);
  ~Human();
  char* GetName() const {return &itsName[0];}
  void SetName(char* name);
private:
  char itsName[256];
};

Human::Human()
{}

Human::Human(char* name)
{
  strcpy(itsName, name);
}

Human::~Human(){}

void Human::SetName(char* name)
{
  strcpy(itsName, name);
}

int main()
{
  char name[256];
  Human person;
  cout << "Enter name:";
  cin.getline(name, 255);
  person.SetName(name);
  cout << person.GetName() << "'s age is " << person.GetAge() << endl;
  
}