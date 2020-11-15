#include <iostream.h>
#include <math.h>

int main()
{
	int x;
	double b, h, l, r,w;

	cout << "1. Circle\n2. Rectangle\n3. Triangle\n4. Cylinder\n5. Rectangular Block\n6. Cone\n";
	cin >> x;
	switch (x)
	{
	case 1:	// Circle
	cout << "Radius: ";
	cin >> r;
	cout << "Circumference: " << 2*M_PI*r << endl;
	cout << "Area: " << M_PI*pow(r, 2) << endl;
	break;

	case 2:	// Rectangle
	cout << "Length: ";
	cin >> l;
	cout << "Width: ";
	cin >> w;
	cout << "Area: " << w*l << endl;
	cout << "Perimeter: " << 2*w+2*l << endl;
	break;
	
	case 3:	// Triangle
	cout << "Base: ";
	cin >> b;
	cout << "Height: ";
	cin >> h;
	cout << "Area: " << .5*b*h << endl;
	break;

	case 4:	// Cylinder
	cout << "Radius: ";
	cin >> r;
	cout << "Height: ";
	cin >> h;
	cout << "Surface Area:\n";
	cout << " Including ends: " << 2*M_PI*r*h+2*M_PI*pow(r, 2) << endl;
	cout << " Excluding ends: " << 2*M_PI*r*h << endl;
	cout << "Volume: " << M_PI*pow(r, 2)*h << endl;
	break;

	case 5:	// Rectangular Block
	cout << "Height: ";
	cin >> h;
	cout << "Length: ";
	cin >> l;
	cout << "Width: ";
	cin >> w;
	cout << "Surface Area: " << 2*(l*w+l*h+h*w) << endl;
	cout << "Volume: " << h*l*w << endl;
	break;

	case 6:	// Cone
	cout << "Radius at base: ";
	cin >> r;
	cout << "Height: ";
	cin >> h;
	cout << "Surface Area: " << M_PI*pow(r, 2)+M_PI*r*pow(pow(r, 2)*pow(h, 2), .5) << endl;
	cout << "Volume: " << (M_PI*pow(r, 2)*h)/3 << endl;
	break;

	default:
	cout << "Error: Unexpected input";
	return 1;
	break;
	}
	return 0;
}
