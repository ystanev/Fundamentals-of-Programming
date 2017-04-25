#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Car{
    private:
        int yearModel, speed;
        string make;
    public:
        Car();
        Car(int, string, int);

        int getYear() const;
        string getMake() const;
        int getSpeed() const;

        int accelerate();
        int brake();
};

Car::Car() {
    yearModel = 0;
    speed = 0;
}

Car::Car(int ym, string m, int s) {
    yearModel = ym;
    make = m;
    speed = s;
}

int Car::getYear() const {
    return yearModel;
}

string Car::getMake() const {
    return make;
}

int Car::getSpeed() const {
    return speed;
}

int Car::accelerate() {
    return speed += 5;
}

int Car::brake() {
    return speed -= 5;
}

int main(){
    Car car_1;

    for(int i=0; i<5; i++){
        car_1.accelerate();
        cout << car_1.getSpeed() << endl;
    }

    for(int i=0; i<5; i++){
        car_1.brake();
        cout << car_1.getSpeed() << endl;
    }

    return 0;
}
