#ifndef ASSIGNMENT_5_BASICSHAPE_H
#define ASSIGNMENT_5_BASICSHAPE_H

#include <cmath>

class BasicShape {
    private:
        double area;
    public:
        double getArea() const;
        virtual double calcArea() = 0; // Pure Virtual Function
};

#endif //ASSIGNMENT_5_BASICSHAPE_H