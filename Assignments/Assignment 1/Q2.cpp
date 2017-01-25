//#include "stdafx.h" // Header File used VS.
#include <iostream>
#include <iomanip> // Used to format the output.
#include <cstdlib> // Used for system().
#include <math.h> // Used for sqrt().
#include <stdio.h>  /* printf, NULL */
#include <time.h>  /* time */

using namespace std;// ?


int main (){

    int crew_num; // Between 1 & 2.
    double crew_weight_1, crew_weight_2; // Must be between 85 and 400 pounds.
    int empty_moment = 2751405; // Inch/Pound
    int empty_weight = 9021; // Pounds
    double fuel_moment = 1167167.3; // Inch/Pound
    int full_tank_weight = 3618; // Pounds

    cout << "Enter number of crew members: ";
    cin >> crew_num;

    //Input Validation
    while (!(0 <= crew_num && crew_num <= 2)){
        cout << "Crew size is restricted to 2 members.";
        cout << "Enter number of crew members: ";
        cin >> crew_num;
    }

    cout << "Enter the weight of the first crew member: ";
    cin >> crew_weight_1;
    cout << "Enter the weight of the second crew member: ";
    cin >> crew_weight_2;

    //Input Validation
    while (!((85 <= crew_weight_1 && crew_weight_1 <= 400) && (85 <= crew_weight_2 && crew_weight_2 <= 400))){
        cout << "The weight range for crew members is between 85 and 400 pounds.";
        cout << "Enter the weight of the first crew member: ";
        cin >> crew_weight_1;
        cout << "Enter the weight of the second crew member: ";
        cin >> crew_weight_2;
    }

    double crew_moment = ( crew_weight_1 + crew_weight_2 ) * 120;// Pound/Inch

    cout << "The number of crew members is: " << crew_num << endl;
    cout << "Crew members weights are: " << crew_weight_1 << "  "<< crew_weight_2 << "\n" << endl;

    //Table
    cout << "Cargo Weight       Center of Gravity" << endl;
    cout << "====================================" << endl;

    //Report Generation
    for ( int i=0; i<=5000; i= i+500){ // Possible cargo weight. 0-5000 pounds.
        double cargo_weight = i; // ***Check the formula for cargo calculation.
        double cargo_moment = cargo_weight * 345; // Inch/Pound
        double center_of_gravity = ( empty_moment + fuel_moment + crew_moment + cargo_moment) / ( crew_weight_1 + crew_weight_2 + full_tank_weight + empty_weight + cargo_weight ); // Calculates the center of gravity.

        //cout << "The number of crew members is: " << crew_num << endl;
        //cout << "Crew members weights are: " << crew_weight_1 << "  "<< crew_weight_2 << "\n" << endl;
        //Data Table
        //cout << "Cargo Weight       Center of Gravity" << endl;
        //cout << "====================================" << endl;

        if ( center_of_gravity < 315 ) {
                cout.precision(1); // Sets Cargo Weight to 1 decimal place.
                cout.precision(3); // Sets Center of Gravity to 3 decimal places.
                cout << setw(8) << cargo_weight << " lb." << setw(16) << center_of_gravity << " in." << endl;
        }

        if ( center_of_gravity >= 315 ){ // Prints * where the center of gravity is 315 inches or greater.
            cout.precision(1);
            cout.precision(3);
            cout << setw(8) << cargo_weight << " lb. *"  << setw(14) << center_of_gravity << " in." << endl;
        }
    }

    system("PAUSE"); // Pauses the program before termination.
    return 0;
}	