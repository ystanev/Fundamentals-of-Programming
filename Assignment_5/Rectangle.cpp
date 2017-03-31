#include "BasicShape.h"
#include "Rectangle.h"

#include <cmath>

Rectangle::Rectangle(long int w, long int l){
    width = w;
    length = l;
}

long Rectangle::getWidth() const {
    return width;
}

long Rectangle::getLength() const {
    return length;
}

double Rectangle::calcArea() {
    return width * length;
}