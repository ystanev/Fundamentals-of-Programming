//#include "stdafx.h" // Header File used VS.
#include <iostream>
//#include <iomanip> // Used to format the output.
#include <cstdlib> // Used for system().
#include <math.h> // Used for sqrt().
//#include <stdio.h>  /* printf, NULL */
//#include <time.h>  /* time */
using namespace std;// ?
//#include <string> // Used to work with srings.
//#include <algorithm>    // std::min_element, std::max_element

int findClosest(int aa, int b, int c);

int main (){
    int a, b, c;
    cout << "First #: ";
    cin >> a;
    cout << "Second #: ";
    cin >> b;
    cout << "Third #: ";
    cin >> c;

    findClosest(a, b, c);
    /*bool exit = false;

    cout << "Enter 000 to exit.";

    if (exit){

    }*/


    system("PAUSE"); // Pauses the program before termination.
    return 0;
}

int findClosest(int a, int b, int c){
    int nums [3]= {abs(a), abs(b), abs(c)}; // Array stores absolute value of entered #s
    int min = nums[0];
    for(int i=1; i < sizeof(nums)/sizeof(nums[0]) /*i<3*/; ++i){
        if(min>nums[i]){ // Returns minimum value in the array
            min=nums[i];
        }
        cout << min << endl;
    }
}