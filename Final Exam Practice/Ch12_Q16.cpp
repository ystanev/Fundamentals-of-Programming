#include <iostream>

using namespace std;

class Temperature {
private:
    int temp;
public:
    Temperature() { temp = 0; }

    Temperature(int t) { temp = t; }

    void setTemp(int t) { temp = t; }

    int getTemp() { return temp; }

    //Boiling Freezing Points

    bool isEthylFreezing() {
        if (temp <= -173) {
            cout << "Ethyl is Frozen.";
            return true;
        } else {
            cout << "Ethyl isn't Frozen.";
            return false;
        }
    }

    bool isEthylBoiling() {
        if (temp >= 172) {
            cout << "Ethyl is Boiling.";
            return true;
        } else {
            cout << "Ethyl isn't Boiling.";
            return false;
        }
    }

    bool isOxygenFreezing() {
        if (temp <= -362) {
            cout << "Oxygen is Frozen.";
            return true;
        } else {
            cout << "Oxygen isn't Frozen.";
            return false;
        }
    }

    bool isOxygenBoiling() {
        if (temp >= -306) {
            cout << "Oxygen is Boiling.";
            return true;
        } else {
            cout << "Oxygen isn't Boiling.";
            return false;
        }
    }

    bool isWaterFreezing() {
        if (temp <= 32) {
            cout << "Water is Frozen.";
            return true;
        } else {
            cout << "Water isn't Frozen.";
            return false;
        }
    }

    bool isWaterBoiling() {
        if (temp >= 212) {
            cout << "Water is Boiling.";
            return true;
        } else {
            cout << "Water isn't Boiling.";
            return false;
        }
    }
};

int main() {
    int t;

    cout << "Enter Temperature (F): ";
    cin >> t;

    Temperature point;

    point.setTemp(t);
    point.getTemp();

    cout << point.isEthylBoiling() << " " << point.isEthylFreezing() << endl
         << " " << point.isOxygenBoiling() << " " << point.isOxygenFreezing() << endl
         << " " << point.isWaterBoiling() << " " << point.isWaterFreezing() << endl;


    return 0;
}
