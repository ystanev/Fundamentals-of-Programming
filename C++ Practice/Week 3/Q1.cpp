/*
1. Create a program that performs the following tasks:
	a. Prompt the user for a temperature that is the boiling point of a substance and store this in an appropriate variable.
	b. Prompt the user for the current temperature of the substance.
	c. Output the boiling point temperature and the current substance temperature.
	d. Output an appropriate message. The message will be one of the following:
		I. The substance temperature is below the boiling point.
		II. The substance temperature is at or above the boiling point
*/

#include <iostream>
#include <cstdlib> // Used for system().
using namespace std;// ?

int main(){

    double boiling_point, current_temp; //Variables used to store the data.

    cout << "Enter the boiling point of the substance: ";
    cin >> boiling_point; // Stores the boiling point information.

    cout << "Enter the current tempreture of the substance: ";
    cin >> current_temp;// Stores the current temperature.

    cout << "The boiling point is: " << boiling_point << endl;
    cout << "The current tempreture is: " << current_temp << endl;

    if (current_temp >= boiling_point){// Used to compare two given varibales and output the result based on the information.
        cout << "The substance temperature is at or above the boiling point.";
    }
    else{
        cout << "The substance temperature is below the boiling point. \n";// "\n" is used to go to new line.
    }

    system("PAUSE");
    return 0;
};
