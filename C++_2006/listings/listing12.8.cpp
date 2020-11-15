#include <iostream.h>

class Mammal
{
public:
  Mammal():itsAge(1) { cout << "Mammal constructor...\n"; }
  ~Mammal() { cout << "Mammal destructor...\n"; }
  void Move() const { cout << "Mammal move one step\n"; }
  virtual void Speak() const { cout << "Mammal speak!\n"; }
protected:
  int itsAge;
};

class Dog : public Mammal
{
public:
  Dog() { cout << "Dog Constructor...\n"; }
  ~Dog(){ cout << "Dog destructor...\n"; }
  void WagTail() { cout << "Wagging tail...\n"; }
  void Move() const { cout << "Dog moves 5 steps...\n"; }
  void Speak() const { cout << "Woof\n"; }
};

int main()
{
  Mammal *pDog = new Dog;
  Mammal *pMammal = new Mammal;
  pDog->Move();
  pDog->Speak();
  delete pDog;
  return 0;
}