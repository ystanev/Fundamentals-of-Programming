//#include "stdafx.h" // Header File used VS.
#include <iostream>
//#include <iomanip> // Used to format the output.
#include <cstdlib> // Used for system().
#include <math.h> // Used for sqrt().
#include <stdio.h>  /* printf, NULL */
#include <time.h>  /* time */
using namespace std;// ?
#include <string> // Used to work with srings.

double calculateCR (double bounce_height, double drop_height); // Function Declaration

int main (){

    double bounce_height, drop_height;

    cout << "Enter bounce height: ";
    cin >> bounce_height;
    cout << "Enter drop height: ";
    cin >> drop_height;

    double coefficient = calculateCR(bounce_height, drop_height); // Calls the function

    if (coefficient > -1){
        cout.precision(3);
        cout << coefficient << endl;
    }
    else{
        cout << "ERROR" << endl;
    }

    system("PAUSE"); // Pauses the program before termination.
    return 0;
}

double calculateCR (double bounce_height, double drop_height){ // Function Definition
    double CR = sqrt(bounce_height/drop_height); // Calculates Coefficient of Restriction
    if(bounce_height <= 0 || drop_height <= 0 || bounce_height > drop_height){
        return -1.0;
    }
    else{
        return CR;
    }
}