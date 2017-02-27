#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

//Structures.
struct point{
    float x;
    float y;
};

struct line{
    float slope;
    float y_intercept;
};

struct rectangle{
    int x1, x2;
    int y1, y2;
};

//Functions Prototype.
void line(point p_1, point p_2);
void intersection(line l_1, line l_2);

int main(){

    //Points.
    point p_1, p_2;
    //Lines.
    line l_1, l_2;

    //Menu.
    int choice;

    cout << "======= MENU =======" << endl;
    cout << "Option 1: Calculate Line." << endl;
    cout << "Option 2: Find POI." << endl;
    cout << "Option 3: Check is the point IN / OUT of rectange." << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice){
        case 1:
            line(p_1, p_2);
            break;
        case 2:
            intersection(l_1, l_2);
            break;
        case 3:
            break;
    }

    system("PAUSE");
    return 0;
}

//Functions.
void line(point p_1, point p_2){
    cout << "Enter the coordinates of the 1st point: ";
    cin >> p_1.x >> p_1.y;
    cout << "Enter the coordinates of the 2nd point: ";
    cin >> p_2.x >> p_2.y;

    //Calculations.
    float dx = p_2.x - p_1.x;
    float dy = p_2.y - p_1.y;

    float slope = dy / dx;
    //y = mx + c
    // intercept c = y - mx
    float intercept = p_1.y - slope * p_1.x;

    cout << "Equation of the line is: y =  ";
    cout << slope << "x " << ((intercept < 0) ? ' ' : '+') << intercept << "\n";
}

void intersection(line l_1, line l_2){
    cout << "Enter the slope & y-intercept for the 1st line: ";
    cin >> l_1.slope >> l_1.y_intercept;
    cout << "Enter the slope & y-intercept for the 2nd line: ";
    cin >> l_2.slope >> l_2.y_intercept;

    //Calculations.
    float x = (l_2.y_intercept - l_1.y_intercept) / (l_1.slope - l_2.slope);
    float y = l_1.slope * x + l_1.y_intercept;

    cout << "POI: (" << x << "," << y << ")" << endl;
}
