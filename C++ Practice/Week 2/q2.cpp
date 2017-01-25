//#include "stdafx.h"
#include <iostream>
//#include <string> //Required for string type.

using namespace std;

int main()
{
	
	float celcius;
	float farenheit;

	cout << "Enter tempreture in Celsius: ";
	cin >> celcius;

	//Conversion

	farenheit  = (5.0/9) * (celcius + 32);
	cout << "Tempreture in Farenheit is: " << farenheit << endl;

	//system("pause");

	return 0;
}

