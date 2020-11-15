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
  void Move() const { cout << "Dog move 5 steps.\n"; }
};

int main()
{
  Mammal bigAnimal;
  Dog fido;
  bigAnimal.Move();
  bigAnimal.Move(2);
  fido.Move();
  // fido.Move(10);
  return 0;
}