/* IMCOMPLETE */

#ifndef _CHEMISTRY_H
#define _CHEMISTRY_H

#define AVOGRADO 6.0221415;

double g2m(double, double);
double m2g(double, double);
double m2a(double, double);
double a2m(double, double);
double g2a(double, double);
double a2m(double, double);

double g2m(g, m)
{
  return g / m;
}

double m2g(double number_moles, double molar_mass)
{
  return number_moles * molar_mass;
}

double m2a(double number_moles){
  return number_moles * AVOGRADO;}

double a2m(unsigned long int atoms)
{
  cin >> atoms;
  return double(atoms) / AVOGRADO; // *10^-23
}

double mass_to_atoms()
{
  double mass_element, molar_mass;
  cout << "Enter mass of element (grams): ";
  cin >> mass_element;
  cout << "Enter molar mass of element: ";
  cin >> molar_mass;
  cout << (mass_element / molar_mass) * AVOGRADO;
  cout << "*10^23 atoms\n";
}

double atoms_to_mass()
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

#endif /* _CHEMISTRY_H */