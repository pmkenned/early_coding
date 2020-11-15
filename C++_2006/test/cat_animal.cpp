#include <stdio.h>
#include <iostream.h>

class Cat
{
public:
  Cat();
  Cat(const Cat &);
  ~Cat();
  int GetAge() const { return *itsAge; }
  int GetWeight() const { return *itsWeight; }
  void SetAge(int age) { *itsAge = age; }

private:
  int *itsAge;
  int *itsWeight;
};

Cat::Cat()
{
  itsAge = new int;
  itsWeight = new int;
  *itsAge = 5;
  *itsWeight = 9;
}

Cat::Cat(const Cat & rhs)
{
  itsAge = new int;
  itsWeight = new int;
  *itsAge = rhs.GetAge();
  *itsWeight = rhs.GetWeight();
}

Cat::~Cat()
{
  delete itsAge;
  itsAge = 0;
  delete itsWeight;
  itsWeight = 0;
}

int main(int argc, char *argv[])
{
  Cat frisky;
  cout << "Frisky's age: " << frisky.GetAge() << endl;
  cout << "Setting Frisky to age 6...\n";
  frisky.SetAge(6);
  cout << "Creating boots from Frisky...\n";
  Cat boots(frisky);
  cout << "Frisky's age: " << frisky.GetAge() << endl;
  cout << "Boot's age: " << boots.GetAge() << endl;
  cout << "Setting frisky to age 7..\n";
  frisky.SetAge(7);
  cout << "Frisky's age: " << frisky.GetAge() << endl;
  cout << "Boot's age: " << boots.GetAge() << endl;
  getchar();
  return 0;
}
