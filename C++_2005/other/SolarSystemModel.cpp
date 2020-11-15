#include <iostream.h>
#include <stdio.h>

#define PLUTO pluto_dist*x

void planet_name(int i);
void planet_dist(int i, double x);
void planet_diam(int i, double x);

const double
mercury_dist = .387,
venus_dist = .723,
earth_dist = 1,
mars_dist = 1.54,
jupiter_dist = 5.203,
saturn_dist = 9.539,
uranus_dist = 19.18,
neptune_dist = 30.06,
pluto_dist = 39.44,

sun_diam = 864000,
mercury_diam = 3100,
venus_diam = 7700,
earth_diam = 7926,
mars_diam = 4200,
jupiter_diam = 88700,
saturn_diam = 75100,
uranus_diam = 29200,
neptune_diam = 27700,
pluto_diam = 3500;

int main()
{
  double x;
  cout << "Enter scale: ";
  cin >> x;
  cout << "Planet:\t\tDistance from sun:\tDiameter:\n";
  for (int i=0; i <= 9; i++)
  {
    planet_name(i);
    planet_dist(i, x);
    planet_diam(i, x);
  }
  return 0;
}

void planet_name(int i)
{
  switch (i)
  {
    case 0: cout << "Sun:\t\t\t\t\t"; break;
    case 1: printf("Mercury:\t"); break;
    case 2: printf("Venus:\t\t"); break;
    case 3: printf("Earth:\t\t"); break;
    case 4: printf("Mars:\t\t"); break;
    case 5: printf("Jupiter:\t"); break;
    case 6: printf("Saturn:\t\t"); break;
    case 7: printf("Uranus:\t\t"); break;
    case 8: printf("Neptune:\t"); break;
    case 9: printf("Pluto:\t\t"); break;
    default: printf("Error"); break;
  }
}

void planet_dist(int i, double x)
{
  switch(i)
  {
    case 0: cout << ""; break;
    case 1: printf("%f\t\t", mercury_dist/PLUTO); break;
    case 2: printf("%f\t\t", venus_dist/PLUTO); break;
    case 3: printf("%f\t\t", earth_dist/PLUTO); break;
    case 4: printf("%f\t\t", mars_dist/PLUTO); break;
    case 5: printf("%f\t\t", jupiter_dist/PLUTO); break;
    case 6: printf("%f\t\t", saturn_dist/PLUTO); break;
    case 7: printf("%f\t\t", uranus_dist/PLUTO); break;
    case 8: printf("%f\t\t", neptune_dist/PLUTO); break;
    case 9: printf("%f\t\t", pluto_dist/PLUTO); break;
    default: cout << "Error"; break;
  }
}

void planet_diam(int i, double x)
{
  switch(i)
  {
    case 0: cout << sun_diam/PLUTO << endl; break;
    case 1: cout << mercury_diam/PLUTO << endl; break;
    case 2: cout << venus_diam/PLUTO << endl; break;
    case 3: cout << earth_diam/PLUTO << endl; break;
    case 4: cout << mars_diam/PLUTO << endl; break;
    case 5: cout << jupiter_diam/PLUTO << endl; break;
    case 6: cout << saturn_diam/PLUTO << endl; break;
    case 7: cout << uranus_diam/PLUTO << endl; break;
    case 8: cout << neptune_diam/PLUTO << endl; break;
    case 9: cout << pluto_diam/PLUTO << endl; break;
    default: cout << endl; break;
  }
}