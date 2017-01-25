/*
	4.	Create a program that validates input as follows:

		a.	Prompt the user for a value that could be a decimal value.

		b.	Use a loop structure to test the value. The value must be between 0 and 200, 
			including 0 and 200. If the value is outside this range, output an appropriate 
			message and prompt the user for a new value. If the value is within the range, 
			output a message that displays the value and indicates it is in the appropriate range.
*/

//#include "stdafx.h"
#include <iostream>
//#include <string> // Required for string object.
#include <cstdlib> //Required for system().
using namespace std;// Input / Ouput commands.

int main(){

	double num; // Stores the value entered by the user.
	
	cout << "Enter a decimal value between 0 and 200: "; // Promts user for input.
	cin >> num;
	
	//If the number isn't between 0 & 200 enter the loop.
	while (!(num >= 0 && num <= 200)){ // Checks if the number is between 0 & 200.
		cout << "Wrong Value.\n Enter a new value: "; // Promps the user for the new value.
		cin >> num;
	}
	
	cout << "Good Job.\n";
	
	system("PAUSE");
    return 0;
}

