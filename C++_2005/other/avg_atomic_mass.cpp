#include <iostream.h>

int main()
{
  unsigned long int amount;

  cout << "Enter number of isotopes: ";
  cin >> amount;

  double mass[amount], percentage[amount];
  double avg_atomic_mass;

  for (int i = 0; i < amount; i++)
  {
    cout << "Enter atomic mass for isotope " << i + 1 << ": ";
    cin >> mass[i];
    cout << "Enter percentage natural abundance: ";
    cin >> percentage[i];

    cout << mass[i] << " * " << percentage[i] << " = " << mass[i] * percentage[i] / 100 << endl;

    avg_atomic_mass += mass[i] * percentage[i] / 100;
  }

  cout << "Average atomic mass: " << avg_atomic_mass;

  return 0;
}