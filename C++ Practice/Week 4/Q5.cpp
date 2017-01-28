
// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include <iomanip> // Used to format the output.
#include <cstdlib> // Used for system().
#include <math.h> // Used for sqrt().
#include <stdio.h>  /* printf, NULL */
#include <time.h>  /* time */
using namespace std;// ?
#include <string> // Used to work with srings.

bool calculateBox (double length, double height, double width, double *box_volume, double *box_surface_area);// Function Prototype

int _tmain(int argc, _TCHAR* argv[]){

	double length, height, width;
	double volume, area;

	cout << "Enter Length: ";
	cin >> length;
	cout << "Enter Height: ";
	cin >> height;
	cout << "Enter Width: ";
	cin >> width;

	calculateBox(length, height, width, &volume, &area);

	if(calculateBox(length, height, width, &volume, &area) == true){
		cout << "Box Volume is: " << volume << endl;
		cout << "Box Surface Area: " << area << endl;
	}
	else{
		cout << "ERROR" << endl;
	}

	system("PAUSE");
	return 0;
}

bool calculateBox (double length, double height, double width, double *box_volume, double *box_surface_area){
	*box_volume = length * height * width;
	*box_surface_area = (2 * length * height) + (2 * width * height);

	if (length <= 0 || height <= 0 || width <= 0){
		return false;
	}
	else{
		return true;
	}
}
