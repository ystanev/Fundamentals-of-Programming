#include "stdafx.h"
#include <iomanip>
#include <iostream>
using namespace std;

int main(){
	/*srand(time(NULL));
	int num = A + rand()%(B - A + 1);

	cout << "Random Num: " << num << endl;*/

	/*int x, y;

	x= 7;

	y = ++x;

	cout << "X is: " << x << endl;
	cout << "Y is: " << y << endl;*/

	/*int age, year;

	cout << "Enter you age: ";
	cin >> age;

	while (age <= 0)
	{
		cout << "Invalid age, Try again: ";
		cin >> age;
	}
	
	year = 2017 - age;

	cout << "You were born in: " << year << endl;*/

	/*int num;
	int sum = 0;
	int count = 0;

	while (count < 5){
		cout << "Enter a number: ";
		cin >> num;
		sum += num;
		count++;
	}

	cout << "The Sum of Numbers is: " << sum << endl;*/

	/*int choice;

	do{
		cout << "Enter a item from menu: ";
		cout << "1. Hamburger.";
		cout << "2. Fries.";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice){
			case 1:
				cout << "You've chosen Hamburger.\n";
			break;
			case 2:
				cout << "You've chosen Fries.\n";
			break;
			case 3:
				cout << "Menu is now terminating.\n";
			break;
			default:
				cout << "Wrong Choice.\n";
		}
	}while(choice != 3);*/

	/* int num;

	for(int i=2; i<=1000000; i*=2){
		if (i%2 == 0){
			cout << i << endl;
		}
	}*/

	int grade, sum, count;
	double average;

	sum = 0;
	count = 0;

	do{
		cout << "Enter a grade: ";
		cin >> grade;
		sum += grade;
		count++;

	}while(grade != -1);

	average = sum / count;
	cout << "Average is: " << average << endl;


	system("PAUSE");
	return 0;
}
