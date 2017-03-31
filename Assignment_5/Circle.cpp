#include "BasicShape.h"
#include "Circle.h"

#include <cmath>

Circle::Circle(long int x, long int y, double r){
    centerX = x;
    centerY = y;
    radius = r;

    calcArea(); // Function Call
}

long Circle::getCenterX() const {
    return centerX;
}

long Circle::getCenterY() const {
    return centerY;
}

double Circle::calcArea() {
    return 3.141159*radius*radius;
}