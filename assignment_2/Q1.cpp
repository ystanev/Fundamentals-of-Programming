#include <iostream>
#include <iomanip> // Used to format the output.
#include <cstdlib> // Used for system().
#include <math.h> // Used for sqrt().
using namespace std;// ?

//Functions Prototype
double inputTime();
double inputGravity();
double fallingDistance (double *time, double *gravity);
void printResult(double *time, double *gravity, double *distance);

int main(){

    //Variable
    double time_1, gravity_1, distance_1;

    // Calling the functions.
    inputTime();
    inputGravity();
    fallingDistance(&time_1, &gravity_1);
    printResult(&time_1, &gravity_1, &distance_1);

    system("PAUSE");
    return 0;

}

double inputTime(){
    double time;
    cout << "Enter, how the long the object will be falling (sec): ";
    cin >> time;
    return time;
}

double inputGravity(){
    double gravity;
    cout << "Enter, acceletation due to gravity (m/sec^2): ";
    cin >> gravity;
    return gravity;
}

double fallingDistance (double *time, double *gravity){
    double distance = (1/2) * (*gravity) * pow((*time), 2); // Calculates the falling distance & assigns it to a variable.
    return distance;
}

void printResult(double *time, double *gravity, double *distance){
    //cout.setf(ios_base::fixed); // Getting rid of scientific notation. ***Causes the values to turn to 0s***
    cout << "The time is, " << *time << " sec." << " gravitational acceleration is, " << *gravity << " m/sec^2." << " there for the falling distance is, " << *distance << " m." << endl;
}
