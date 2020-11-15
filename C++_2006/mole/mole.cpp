#include <iostream.h>

#define AVOGRADO 6.0221415;

void mass_to_moles();
void moles_to_mass();
void moles_to_atoms();
void atoms_to_moles();
void mass_to_atoms();
void atoms_to_mass();

int main()
{
  char choice;

  do
  {
    cout << "Convert:\n";
    cout << "1. Mass (grams) to moles\n";
    cout << "2. Moles to mass (grams)\n";
    cout << "3. Moles to number of atoms\n";
    cout << "4. Number of atoms to moles\n";
    cout << "5. Mass (grams) to number of atoms\n";
    cout << "6. Number ot atoms to mass (grams)\n";
    cout << "(Enter Q to quit)\n";

    cin >> choice;

    switch((int)choice-48)
    {
    case 1: mass_to_moles(); break;
    case 2: moles_to_mass(); break;
    case 3: moles_to_atoms(); break;
    case 4: atoms_to_moles(); break;
    case 5: mass_to_atoms(); break;
    case 6: atoms_to_mass(); break;
    case 33: case 65: break;
    default: cout << "Invalid choice\n"; break;
    }
  }
  while (choice != 81 && choice != 113);

  return 0;
}

void mass_to_moles()
{
  double mass_element, molar_mass;
  cout << "Enter mass of element (grams): ";
  cin >> mass_element;
  cout << "Enter molar mass of element: ";
  cin >> molar_mass;
  cout << mass_element / molar_mass << " moles\n";
}

void moles_to_mass()
{
  double number_moles, molar_mass;
  cout << "Enter amount of element in moles: ";
  cin >> number_moles;
  cout << "Enter molar mass of element: ";
  cin >> molar_mass;
  cout << number_moles * molar_mass << " grams\n";
}

void moles_to_atoms()
{
  double number_moles;
  cout << "Enter amount of element in moles: ";
  cin >> number_moles;
  cout << number_moles * AVOGRADO;
  cout << "*10^23 atoms\n";
}

void atoms_to_moles()
{
  unsigned long int atoms;
  cout << "Enter number of atoms: ";
  cin >> atoms;
  cout << double(atoms) / AVOGRADO;
  cout << "*10^-23 moles\n";
}

void mass_to_atoms()
{
  double mass_element, molar_mass;
  cout << "Enter mass of element (grams): ";
  cin >> mass_element;
  cout << "Enter molar mass of element: ";
  cin >> molar_mass;
  cout << (mass_element / molar_mass) * AVOGRADO;
  cout << "*10^23 atoms\n";
}

void atoms_to_mass()
{
  unsigned long int atoms;
  double molar_mass;
  cout << "Enter number of atoms: ";
  cin >> atoms;
  cout << "Enter molar mass: ";
  cin >> molar_mass;
  cout << (atoms*molar_mass) / AVOGRADO;
  cout << "*10^-23 grams\n";
}