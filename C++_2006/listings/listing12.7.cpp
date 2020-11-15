#include <iostream.h>

class Mammal
{
public:
  void Move() const { cout << "Mammal move one step\n"; }
  void Move(int distance) const
  {
    cout << "Mammal move ";
    cout << distance << " steps.\n";
  }

protected:
  int itsAge;
  int itsWeight;
};

class Dog : public Mammal
{
public:
  void Move() const;
};

void Dog::Move() const
{
  cout << "In dog move...\n";
  Mammal::Move(3);
}

int main()
{
  Mammal bigAnimal;
  Dog fido;
  bigAnimal.Move(2);
  fido.Mammal::Move(6);
  return 0;
}