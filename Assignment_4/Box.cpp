#include "Box.h"

int Box::objectCount = 0;

Box::Box(double l=2.0, double w=2.0, double h=2.0) { //Constructor
    length = l;
    width = w;
    heigt = h;

    // Increase every time object is created
    objectCount++;
}

double Box::Volume() {
    return heigt*length*width;
}

int Box::getObjectCount() { // Static Function
    return objectCount;
}
