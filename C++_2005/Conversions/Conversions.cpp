#include <iostream.h>

int main()
{
	double userinput;
	cout << "Convert:\n1.)U.S. to Metric\n2.)Metric to U.S.\n";
	cin >> userinput;
	switch ((int) userinput)
	{
		case 1:	 // Convert U.S. to Metric
		cout << "Convert:\n1.)Length\n2.)Area\n3.)Volume\n4.)Mass\n5.)Temperature\n";
		cin >> userinput;
		switch ((int) userinput)
		{
			case 1: // Convert Length
			cout << "Convert:\n1.)Inches to millimeters\n2.)Inches to centimeters\n3.)Feet to centimeters\n4.)Feet to meters\n5.)Yards to centimeters\n6.)Yards to meters\n7.)Miles to kilomters\n";
			cin >> userinput;
			switch ((int) userinput)
			{
				case 1: // Convert inches to millimeters
				cout << "Enter inches: ";
				cin >> userinput;
				cout << ""<< userinput <<" inches equals "<< userinput * 25.40 <<" millimeters\n";
				break;

				case 2: // Convert inches to centimeters
				cout << "Enter inches: ";
				cin >> userinput;
				cout << ""<<userinput <<" inches equals "<<userinput * 2.540 <<" centimeters\n";
				break;

				case 3: // Convert feet to centimeters
				cout << "Enter feet: ";
				cin >> userinput;
				cout << ""<< userinput <<" feet equals "<<userinput * 30.480 <<" centimeters\n";
				break;

				case 4: // Convert feet to meters
				cout << "Enter feet: ";
				cin >> userinput;
				cout << ""<< userinput <<" feet equals "<<userinput * .30480 <<" meters\n";
				break;

				case 5: // Convert yards to centimeters
				cout << "Enter yards: ";
				cin >> userinput;
				cout << ""<< userinput <<" yards equals "<<userinput * 91.440 <<" centimeters\n";
				break;

				case 6: // Convert yards to meters
				cout << "Enter yards: ";
				cin >> userinput;
				cout << ""<< userinput <<" yards equals "<<userinput * .9144 <<" meters\n";
				break;

				case 7: // Convert miles to kilometers
				cout << "Enter miles: ";
				cin >> userinput;
				cout << ""<< userinput <<" miles equals "<<userinput * 30.480 <<" kilometers\n";
				break;

				default:
				cout << "You entered an invalid number.";
				break;
			}
			break;

			case 2: // Convert Area
			cout << "Convert:\n1.)Square inches to square milimeters\n2.)Square inches to square centimeters\n3.)Square feet to centimeters\n4.)Square feet to meters\n5.)Square yards to meters\n6.)Acres to hectare\n7.)Square miles to kilomters\n";
			cin >> userinput;
			switch ((int) userinput)
			{
				case 1: // Convert square inches to square milimeters
				cout << "Enter square inches: ";
				cin >> userinput;
				cout << ""<< userinput <<" square inches equals "<< userinput * 645.16 <<" square milimeters\n";
				break;

				case 2: // Convert square inches to square centimeters
				cout << "Enter square inches: ";
				cin >> userinput;
				cout << ""<< userinput <<" square inches equals "<< userinput * 6.4516 <<" square centimeters\n";
				break;

				case 3: // Convert square feet to square to centimeters
				cout << "Enter square feet: ";
				cin >> userinput;
				cout << ""<< userinput <<" square feet equals "<< userinput * 929.03 <<" square centimeters\n";
				break;

				case 4: // Convert square feet to meters
				cout << "Enter square feet: ";
				cin >> userinput;
				cout << ""<< userinput <<" square feet equals "<< userinput * .0929 <<" square meters\n";
				break;

				case 5: // Convert square yards to square meters
				cout << "Enter square yards: ";
				cin >> userinput;
				cout << ""<< userinput <<" square yards equals "<< userinput * .836 <<" square meters\n";
				break;

				case 6: // Convert acres to hectre
				cout << "Enter square acres: ";
				cin >> userinput;
				cout << ""<< userinput <<" acres equals "<< userinput * .4047 <<" square hectres\n";
				break;

				case 7: // Convert square miles to square kilometers
				cout << "Enter miles: ";
				cin >> userinput;
				cout << ""<< userinput <<" square miles equals "<< userinput * 2.59 <<" square kilomters";
				break;

				default:
				cout << "You entered an invalid number.";
				break;
			}
			break;

			case 3: // Convert Volume
			cout << "Convert:\n1.)Fluid ounces to centiliters\n2.)Pints to deciliters\n3.)Quarts to deciliters\n4.)Gallons to liters\n";
			cin >> userinput;
			switch ((int) userinput)
			{
				case 1: // Convert fluid ounces to centiliters
				cout << "Enter fluid ounces: ";
				cin >> userinput;
				cout << ""<< userinput <<" fluid ounces equals "<< userinput * 2.597 <<" centiliters\n";
				break;

				case 2: // Convert pints to deciliters
				cout << "Enter pints: ";
				cin >> userinput;
				cout << ""<< userinput <<" pints equals "<< userinput * 4.723 <<" deciliters\n";
				break;

				case 3: // Convert quarts to liters
				cout << "Enter quarts: ";
				cin >> userinput;
				cout << ""<< userinput <<" quarts equals "<<userinput * .9463 <<" liters\n";
				break;

				case 4: // Convert gallons to liters
				cout << "Enter gallons: ";
				cin >> userinput;
				cout << ""<< userinput <<" gallons equals "<< userinput * 3.7853 <<" liters\n";
				break;

				default:
				cout << "You entered an invalid number.";
				break;
			}
			break;

			case 4: // Convert Mass
			cout << "Convert:\n1.)Ounces to grams\n2.)Pounds to kilograms\n3.)Short tons\n4.)Short tons to metric tons\n";
			cin >> userinput;
			switch ((int) userinput)
			{
				case 1: // Convert ounces to grams
				cout << "Enter ounces: ";
				cin >> userinput;
				cout << ""<< userinput <<" ounces equals "<< userinput * 28.35 <<" grams\n";
				break;

				case 2: // Convert pounds to kilograms
				cout << "Enter pounds: ";
				cin >> userinput;
				cout << ""<< userinput <<" ounces equals "<< userinput * .4536 <<" kilograms\n";
				break;

				case 3: // Convert short tons to kilograms
				cout << "Enter short tons: ";
				cin >> userinput;
				cout << ""<< userinput <<" short tons equals "<< userinput * 907.2 <<" kilograms\n";
				break;

				case 4: // Convert short tons to metric tons
				cout << "Enter short tons: ";
				cin >> userinput;
				cout << ""<< userinput <<" short tons equals "<< userinput * .9072 <<" metric tons\n";
				break;

				default:
				cout << "You entered an invalid number.";
				break;
			}
			break;

			case 5: // Convert Temperature
			cout << "Convert Fahrenheit to:\n1.)Celsius\n2.)Kelvin\n";
			cin >> userinput;
			switch ((int) userinput)
			{
				case 1: // Convert Fahrenheit to Celsius
				cout << "Enter degrees Fahrenheit: ";
				cin >> userinput;
				cout << ""<< userinput <<" degrees Fahrenheit "<< (userinput-32) * 5/9 <<" degrees Celsius";
				break;

				case 2: // Convert Fahrenheit to Kelvin
				cout << "Enter degrees Fahrenheit: ";
				cin >> userinput;
				cout << ""<< userinput <<" degrees Fahrenheit "<< (userinput-32) * 5/9 + 273 <<" degrees Kelvin";
				break;

				default:
				cout << "You entered an invalid number.";
				break;
			}
			break;

			default:
			cout << "You entered an invalid number.";
			break;
		}
		break;

		case 2:	 // Convert Metric to U.S.
		cout << "Convert:\n1.)Length\n2.)Area\n3.)Volume\n4.)Mass\n5.)Temperature\n";
		cin >> userinput;
		switch ((int) userinput)
		{
			case 1: // Convert Length
			cout << "Convert\n1.)Millimeters to inches\n2.)Centimeters to inches\n3.)Meters to inches\n4.)Meters to feet\n5.)Meters to yards\n6.)Kilometers to miles\n";
			cin >> userinput;
			switch ((int) userinput)
			{
				case 1: // Convert millimeters to inches
				cout << "Enter millimeters: ";
				cin >> userinput;
				cout << ""<< userinput <<" millimeters equals "<< userinput * .03937 <<" inches";
				break;

				case 2: // Convert centimeters to inches
				cout << "Enter centimeters: ";
				cin >> userinput;
				cout << ""<< userinput <<" centimeters equals "<< userinput * .3937 <<" inches";
				break;

				case 3: // Convert meters to inches
				cout << "Enter meters: ";
				cin >> userinput;
				cout << ""<< userinput <<" meters equals "<< userinput * 39.37 <<" inches";
				break;

				case 4: // Convert meter to feet
				cout << "Enter meters: ";
				cin >> userinput;
				cout << ""<< userinput <<" meters equals "<< userinput * 3.2808 <<" feet";
				break;

				case 5: // Convert meter to yards
				cout << "Enter meters: ";
				cin >> userinput;
				cout << ""<< userinput <<" meters equals "<< userinput * 1.0936 <<" yards";
				break;

				case 6: // Convert kilometers to miles
				cout << "Enter kilometers: ";
				cin >> userinput;
				cout << ""<< userinput <<" kilometers equals "<< userinput * .62137 <<" miles";
				break;

				default:
				cout << "You entered an invalid number.";
				break;
			}
			break;

			case 2: // Convert Area
			cout << "Convert:\n1.)Square millimeters to square inches\n2.)Square centimeters to square inches\n3.)Square meters to square feet\n4.)Square meters to square yards\n5.)Hectres to acres\n6.)Square kilometers to square miles\n";
			cin >> userinput;
			switch ((int) userinput)
			{
				case 1: // Convert square millimeters to square inches
				cout << "Enter square millimeters: ";
				cin >> userinput;
				cout << ""<< userinput <<" square millimeters equals "<< userinput * .00155 <<" square inches\n";
				break;

				case 2: // Convert square centimeters to square inches
				cout << "Enter square centimeters: ";
				cin >> userinput;
				cout << ""<< userinput <<" square centimeters equals "<< userinput * .1550 <<" square inches\n";
				break;

				case 3: // Convert square meters to square feet
				cout << "Enter square meters: ";
				cin >> userinput;
				cout << ""<< userinput <<" square meters equals "<< userinput * 10.7640 <<" square feet\n";
				break;

				case 4: // Convert square meters to square yards
				cout << "Enter square meters: ";
				cin >> userinput;
				cout << ""<< userinput <<" square meters equals "<< userinput * 1.196 <<" square yards\n";
				break;

				case 5: // Convert hectres to acres
				cout << "Enter hectres: ";
				cin >> userinput;
				cout << ""<< userinput <<" hectres equals "<< userinput * 2.417 <<" acres\n";
				break;

				case 6: // Convert square kilometers to square miles
				cout << "Enter square kilometers: ";
				cin >> userinput;
				cout << ""<< userinput <<" square kilometers equals "<< userinput * .3861 <<" square miles\n";
				break;

				default:
				cout << "You entered an invalid number.";
				break;
			}
			break;

			case 3: // Convert Volume
			cout << "Convert:\n1.)Centiliter to fluid ounces\n2.)Deciliters to pints\n3.)Liters to quarts\n4.)Liters to gallons\n";
			cin >> userinput;
			switch ((int) userinput)
			{
				case 1: // Convert centiliters to fluid ounces
				cout << "Enter ceniliters: ";
				cin >> userinput;
				cout << ""<< userinput <<" centiliters equals "<< userinput * .338 <<" fluid ounces\n";
				break;

				case 2: // Convert deciliters to pints
				cout << "Enter decilites: ";
				cin >> userinput;
				cout << ""<< userinput <<" deciliters equals "<< userinput * .05428 <<" pints\n";
				break;

				case 3: // Convert liters to quarts
				cout << "Enter liters: ";
				cin >> userinput;
				cout << ""<< userinput <<" litesr equals "<< userinput * 1.0567 <<" quarts\n";
				break;

				case 4: // Convert liters to gallons
				cout << "Enter liters: ";
				cin >> userinput;
				cout << ""<< userinput <<" liters equals "<< userinput * .26417 <<" gallons\n";
				break;
				
				default:
				cout << "You entered an invalid number.";
				break;
			}
			break;

			case 4: // Convert Mass
			cout << "Convert:\n1.)Grams to ounces\n2.)Kilograms to pounds\n3.)Metric tons to pounds\n4.)Metric tons to short tons\n";
			cin >> userinput;
			switch ((int) userinput)
			{
				case 1: // Convert grams to ounces
				cout << "Enter grams: ";
				cin >> userinput;
				cout << ""<< userinput <<" grams equals "<< userinput * .03527 <<" ounces\n";
				break;

				case 2: // Convert kilograms to pounds
				cout << "Enter kilograms: ";
				cin >> userinput;
				cout << ""<< userinput <<" kilograms equals "<< userinput * 2.2046 <<" pounds\n";
				break;

				case 3: // Convert metric ton to pounds
				cout << "Enter metric tons: ";
				cin >> userinput;
				cout << ""<< userinput <<" metric tons equals "<< userinput * 2204.6 <<" pounds\n";
				break;

				case 4: // Convert metric tons to short tons
				cout << "Enter metric tons: ";
				cin >> userinput;
				cout << ""<< userinput <<" metric tons equals "<< userinput * 1.102 <<" short tons\n";
				break;

				default:
				cout << "You entered an invalid number.";
				break;
			}
			break;

			case 5: // Convert Temperature
			cout << "Convert:\n1.)Celsius to Fahrenheit\n2.)Celsius to Kelvin\n3.)Kelvin to Celsius\n4.)Kelvin to Fahrenheit\n";
			cin >> userinput;
			switch ((int) userinput)
			{
				case 1: // Convert Celsius to Fahrenheit
				cout << "Enter degrees Celsius: ";
				cin >> userinput;
				cout << ""<< userinput <<" equals "<< (userinput * 9/5)+32 <<" degrees Fahrenheit\n";
				break;

				case 2: // Convert Celsius to Kevlin
				cout << "Enter degrees Celsius: ";
				cin >> userinput;
				cout << ""<< userinput <<" degrees Celsius equals "<< userinput + 273 <<" degrees Kelvin\n";
				break;

				case 3: // Convert Kelvin to Celsius
				cout << "Enter degrees Kelvin: ";
				cin >> userinput;
				cout << ""<< userinput <<" degrees Kelvin equals "<< userinput - 273 <<" degrees Celsius\n";
				break;

				case 4: // Convert Kelvin to Fahrenheit
				cout << "Enter degrees Kelvin: ";
				cin >> userinput;
				cout << ""<< userinput <<" degrees Kelvin equals "<< ((userinput - 273) * 9/5) + 32 <<" degrees Fahrenheit\n";

				default:
				cout << "You entered an invalid number.";
				break;
			}
			break;

			default:
			cout << "You entered an invalid number.";
			break;
		}
		break;

		default:
		cout << "You entered an invalid number";
		break;
	}
	return 0;
}