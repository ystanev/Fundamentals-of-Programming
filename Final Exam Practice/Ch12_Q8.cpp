#include <iostream>
#include <cmath>

using namespace std;

class Circle{
private:
    double radius, pi = 3.14159;
public:
    Circle(){
        radius = 0.0;
    }

    void setRadius(double r){
        radius = r;
    }

    double getRadius() const{
        return radius;
    }

    double getArea() const{
        return pi*radius*radius;
    }

    double getDiameter() const{
        return radius*2;
    }

    double getCircumference() const{
        return 2*pi*radius;
    }
};

int main(){
    double r;

    cout << "Enter Radius: ";
    cin >> r;

    Circle circle;

    circle.setRadius(r);

    cout << "Area: " << circle.getArea() << " Diameter: " << circle.getDiameter()
            << " Circumference: " << circle.getCircumference();
}
