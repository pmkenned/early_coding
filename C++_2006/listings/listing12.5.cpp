#include <iostream.h>
enum BREED { YORKIE, CAIRN, DANDIE, SHETLAN, DOBERMAN, LAB };

class Mammal
{
public:
  Mammal() { cout << "Mammal constructor...\n"; }
  ~Mammal() { cout << "Mammal destructor..\n"; }

  void Speak() const { cout << "Mammal sound\n"; }
  void Sleep() const { cout << "Sleeping...\n"; }

protected:
  int itsAge;
  int itsWeight;
};

class Dog: public Mammal
{
public:
  Dog() { cout << "Dog constructor...\n"; }
  ~Dog() { cout << "Dog destructor...\n"; }

  void WagTail() const { cout << "Tail wagging...\n"; }
  void BegForFood() const { cout << "Begging for food...\n"; }
  void Speak() const { cout << "Woof!\n"; }

private:
  BREED itsBreed;
};

int main()
{
  Mammal bigAnimal;
  Dog fido;
  bigAnimal.Speak();
  fido.Speak();
  return 0;
}