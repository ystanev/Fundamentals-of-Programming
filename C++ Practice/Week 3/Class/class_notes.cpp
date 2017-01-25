//#include "stdafx.h" // Precompiled Header File.
#include <iostream>
//#include <string> // Required for string object.
#include <cstdlib> //Required for system().
using namespace std;// Input / Ouput commands.

int main (){

	double grade;
	
	cout << "What is your grade: ";
	cin >> grade;
	
	if(grade>80){
		cout << "Good Job.";
	}
	else if(grade>85){
		cout << "You are admitted with scholarship";
	}
	else{
		cout << "Too bad.";
	}
	
	system("PAUSE");
	return 0;
}