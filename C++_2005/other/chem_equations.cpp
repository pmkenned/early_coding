#include <iostream.h>
#include <string.h>

int main()
{
  char reactants[100], products[100];

  cout << "Enter chemical equation:";
  cin.get(reactants, 100, 62);
  cin.ignore();
  cin.get(products, 100);
  cout << reactants << ">" << products << endl;
  system("pause");

  return 0;
}