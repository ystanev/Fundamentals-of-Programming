#ifndef ASSIGNMENT_5_CIRCLE_H
#define ASSIGNMENT_5_CIRCLE_H
#include "BasicShape.h"

#include <cmath>

class Circle : public BasicShape{
    private:
        long int centerX;
        long int centerY;
        double radius;

    public:
        // Default Constructor
        Circle(long centerX, long centerY, double radius);

        // Accessor Functions
        long getCenterX() const;
        long getCenterY() const;
        double calcArea();
};

#endif //ASSIGNMENT_5_CIRCLE_H