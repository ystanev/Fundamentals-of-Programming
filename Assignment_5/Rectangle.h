#ifndef ASSIGNMENT_5_RECTANGLE_H
#define ASSIGNMENT_5_RECTANGLE_H
#include "BasicShape.h"

#include <cmath>

class Rectangle : public BasicShape{
    private:
        long int width;
        long int length;
    public:
    // Default Constructor
    Rectangle(long width, long length);

    // Accessor Functions
    long getWidth() const;
    long getLength() const;

    double calcArea();
};

#endif //ASSIGNMENT_5_RECTANGLE_H