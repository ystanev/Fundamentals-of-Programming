/*
2.Create a program that performs the following tasks:

	a.	Prompt the user for an integer value.
	
	b.	Display the following menu:
	
			1.Integer divisible by 3?
			2.Integer between 10 and 100?
			
	c.	If the user enters the value 1, determine whether the value 3 is a divisor of the integer and output an appropriate message. If the user enters the value 2, calculate whether the 
		value is between 10 and 100 or not and output an appropriate message (The value is less than 10, between 10 and 100, or greater than 100). If the user enters a value other 
		than  1  or  2,  output  a  message  indicating  that  the  value  is not  a  menu  item.  It  is  not expected to loop back to show the menu again. This is a run once application.
*/

#include <iostream>
#include <cstdlib> // Used for system().
using namespace std;// ?

int main(){

    int choice;// Stores the menu choice.
	
	cout << "Pick one of the options: \n\n";
	cout << "1.Integer divisible by 3? \n2.Integer between 10 and 100?\n\n";
	cout << "Your choice is: ";
	cin >> choice;
	
	if (choice == 1){ //First choice.
		
		int num; //Number entered by the user to determine the devisor.
		
		cout << "Enter a number: \n";
		cin >> num;
		
		if (num%3 == 0){ //If the number is divisible by 3.
			cout << "Number entered is divisible by 3.";		
		}
		else{
			cout << "he isn't divisible by 3.";
		}
		
	}
	else if (choice == 2){ //Second choice.
	
		int num_2; //Number entered by the user for comparassion.
		
		cout << "Enter a number: ";
		cin >> num_2;
		
		if(num_2 < 10){
			cout << "The number entered is less than a 100.\n";
		}
		
		else if(num_2 >= 10 && num_2 <= 100){
			cout << "The number entered is between 10 and a 100.\n";
		}
		else{
			cout << "The number entered is bigget than a 100.\n";
		}
		
	}
	else{ //Invalid choice.
		cout << "This not a valid choice.";
	}

    system("PAUSE");
    return 0;
};