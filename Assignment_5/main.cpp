#include "BasicShape.h"
#include "Circle.h"
#include "Rectangle.h"

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    long int x,y, w, l;
    double r;

    cout << "Enter X coordinate of the circle's center: ";
    cin >> x;
    cout << "Enter Y coordinate of the circle's center: ";
    cin >> y;
    cout << "Enter radius of the circle: ";
    cin >> r;

    Circle c_1 (x, y, r);
    cout << "Area of the circle is: " << c_1.calcArea() << endl;

    cout << "Enter width of the rectangle: ";
    cin >> w;
    cout << "Enter length of the rectangle: ";
    cin >> l;

    Rectangle r_1 (w,l);
    cout << "Area of the rectangle is: " << r_1.calcArea() << endl;

    return 0;
}