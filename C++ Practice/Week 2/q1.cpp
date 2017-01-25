// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string> //Required for string type.

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	/*cout <<"Hello World! ";
	system ("pause");*/

	string name;
	int age;
	float wage;
	char gender;

	cout <<"Enter your name: ";
	cin >> name;

	cout <<"Enter your age: ";
	cin >> age;

	cout <<"Enter your wage: ";
	cin >> wage;

	cout<<"Enter your gender (M/F): ";
	cin >> gender;

	cout <<"First Name: " << name << endl;
	cout <<"Age: " << age << endl;
	cout <<"Hourly Wage: " << wage <<endl;
	cout <<"Gender: " << gender << endl;

	system("pause");

	return 0;
}

