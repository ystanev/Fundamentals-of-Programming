//#include "stdafx.h" // Header File used VS.
#include <iostream>
//#include <iomanip> // Used to format the output.
#include <cstdlib> // Used for system().
#include <math.h> // Used for sqrt().
#include <stdio.h>  /* printf, NULL */
#include <time.h>  /* time */
using namespace std;// ?
#include <string> // Used to work with srings.

string print_title (string title); // Function Declaration

int main (){

    string title; // Stores user input

    cout << "Enter a title: ";
    cin >> title;

    print_title(title); // Calls function.

    system("PAUSE"); // Pauses the program before termination.
    return 0;
}

string print_title (string title){ // Function Definition
    cout << title << endl;
    int length = title.length();
    for (int i=0; i<=length-1; i++){
        cout << "="; // endl & \n forces the output to go to new line
    }
}