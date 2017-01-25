#include <iostream>
using namespace std;
#include <string> //Required for strings.

int main (){

    /* Variables to store the data. */
    float degrees;
    float radians;
    float arc_length;
    const double radius = 5.0;
    const double PI = 3.14159;
    
    cout << "Enter the anle in degrees: ";
    cin >> degrees;

    radians = degrees * PI / 180; //Convets degrees to radians.
    arc_length = radius * radians;//Calculates arc lenth.

    cout << "The arc length is: " << arc_length << endl;

    //system("pause")
    return 0;
}
