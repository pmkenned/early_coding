#include <iostream.h>
#include <stdlib.h>
#include <math.h>

#ifndef PI
#define PI 3.141592654
#endif

void sines(double, double, double, double &, double &);                 // uses law of sines to calculate length of sides b and c
void cosines_sss(double, double, double, double &, double &, double &); // uses law of cosines to calculate the interior angles
void cosines_sas(double, double, double, double &, double &, double &); // uses law of cosines to calculate the length of the remaining side
double herons(double, double, double);                                  // uses heron's area formula to calculate area of a triangle from length of sides
double degrees2radians(double);                                         // converts degrees to pi radians
double radians2degrees(double);                                         // converts pi radians to degrees

int main()
{
      short int choice;                                          // determines which law to use
      double angle_a, angle_b, angle_c, side_a, side_b, side_c;  // angles and lengths of sides of triangle

      cout << "Choose law:\n1) Law of Sines\n2) Law of Cosines\n3) Heron's Area Formula\n";
      cin >> choice;

      switch(choice)
      {
      case 1:       // law of sines
      cout << "Enter angle A (degrees): ";
      cin >> angle_a;
      cout << "Enter length of side A: ";
      cin >> side_a;
      cout << "Enter angle B (degrees): ";
      cin >> angle_b;
      sines(angle_a, side_a, angle_b, side_b, side_c); // lengths of sides b and c are returned by reference
      cout << "Side B = " << side_b << endl;
      cout << "Side C = " << side_c << endl;
      break;

      case 2:       // law of cosines
      cout << "Unknown:\n1) Angles\n2) Length of one Side\n";
      cin >> choice;

      switch(choice)
      {
      case 1:       // three known sides (sss)
      cout << "Enter side A: ";
      cin >> side_a;
      cout << "Enter side B: ";
      cin >> side_b;
      cout << "Enter side C: ";
      cin >> side_c;
      cosines_sss(side_a, side_b, side_c, angle_a, angle_b, angle_c);
      cout << "Angle A = " << angle_a << endl;
      cout << "Angle B = " << angle_b << endl;
      cout << "Angle C = " << angle_c << endl;
      break;

      case 2:        // two known sides and one known angle (sas)
      cout << "Enter side A: ";
      cin >> side_a;
      cout << "Enter side B: ";
      cin >> side_b;
      cout << "Enter angle C: ";
      cin >> angle_c;
      cosines_sas(side_a, side_b, angle_c, side_c, angle_a, angle_b);      // the length of side c and the angles a and b are returned by reference
      cout << "Side C = " << side_c << endl;
      cout << "Angle A = " << angle_a << endl;
      cout << "Angle B = " << angle_b << endl;
      break;

      default:
      cout << "You did not enter a valid choice\n";
      break;
      }
      break;

      case 3:      // heron's area formula
      cout << "Enter side A: ";
      cin >> side_a;
      cout << "Enter side B: ";
      cin >> side_b;
      cout << "Enter side C: ";
      cin >> side_c;
      cout << "Area = " << herons(side_a, side_b, side_c) << endl;;
      break;
      default:

      cout << "You did not enter a valid choice\n";
      break;
      }

      system("PAUSE");
      return 0;
}

void sines(double angle_a, double side_a, double angle_b, double &side_b, double &side_c)  // returns lengths of sides b and c by reference
{
      angle_a = degrees2radians(angle_a);        // converts angle a to radians
      angle_b = degrees2radians(angle_b);        // converts angle b to radians
      double angle_c = PI - (angle_a + angle_b); // converts angle c to radians
      side_b = side_a * sin(angle_b)/sin(angle_a);  // calculates length of side b using law of sines
      side_c = side_a * sin(angle_c)/sin(angle_a);  // calculates length of side c using law of sines
}

void cosines_sss(double side_a, double side_b, double side_c, double &angle_a, double &angle_b, double &angle_c) // law of cosines with three known sides
{
      angle_a = acos((side_b*side_b + side_c*side_c - side_a*side_a)/(2*side_b*side_c));        // law of cosines calculating angle a
      angle_b = acos((side_a*side_a + side_c*side_c - side_b*side_b)/(2*side_a*side_c));        // law of cosines calculating angle b
      angle_c = acos((side_a*side_a + side_b*side_b - side_c*side_c)/(2*side_a*side_b));        // law of cosines calculating angle c

      angle_a = radians2degrees(angle_a);        // converts angle a to radians (returned by reference)
      angle_b = radians2degrees(angle_b);        // converts angle b to radians (returned by reference)
      angle_c = radians2degrees(angle_c);        // converts angle c to radians (returned by reference)
}

void cosines_sas(double side_a, double side_b, double angle_c, double &side_c, double &angle_a, double &angle_b)  // law of cosines with two known sides and one known angle
{
      angle_c = degrees2radians(angle_c);        // converts angle c to radians

      side_c = sqrt(side_a*side_a + side_b*side_b - 2*side_a*side_b*cos(angle_c));              // law of cosines calculating length of side c
      angle_a = acos((side_b*side_b + side_c*side_c - side_a*side_a)/(2*side_b*side_c));        // law of cosines calculating angle a
      angle_b = acos((side_a*side_a + side_c*side_c - side_b*side_b)/(2*side_a*side_c));        // law of cosines calculating angle b

      angle_a = radians2degrees(angle_a);        // converts angle a to radians (returned by reference)
      angle_b = radians2degrees(angle_b);        // converts angle b to radians (returned by reference)
}

double herons(double side_a, double side_b, double side_c){  // calculates the area of a triangle by using heron's area formula
      double s = (side_a+side_b+side_c)/2;                   // s = semiperimeter = (a+b+c)/2
      return sqrt(s*(s-side_a)*(s-side_b)*(s-side_c));}      // returns area

double degrees2radians(double degrees){
      return (PI/180.0)*degrees;}

double radians2degrees(double radians){
      return (180.0/PI)*radians;}
