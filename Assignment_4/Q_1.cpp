#include "Clock.h"
#include "Box.h"
#include <iostream>
#include <cstdlib> //system()

using namespace std;

int main(){

    Clock clock_1; // Create clock_1 object

    int h_1, m_1, s_1; // Variables for the user input

    //User Input
    cout << "Enter hours: ";
    cin >> h_1;
    clock_1.incrementHours(h_1); //Increment by value entered by the user

    cout << "Enter minutes: ";
    cin >> m_1;
    clock_1.incrementMins(m_1);

    cout << "Enter seconds: ";
    cin >> s_1;
    clock_1.incrementSecs(s_1);

    clock_1.setClock(h_1, m_1, s_1); // Setter
    clock_1.getClock(&h_1, &m_1, &s_1); // Getter

    Clock clock_2 (h_1, m_1, s_1);

    clock_2.setClock(h_1, m_1, s_1);
    clock_2.getClock(&h_1, &m_1, &s_1);

    cout << "The time is: " << h_1 << ":" << m_1 << ":" << s_1 << endl;

/*====================================================================================================================*/

    // Print total number of objects before creating object.
    cout << "Inital Stage Count: " << Box::getObjectCount() << endl;

    Box Box1(3.3, 1.2, 1.5);    // Declare box1
    Box Box2(8.5, 6.0, 2.0);    // Declare box2

    // Print total number of objects after creating object.
    cout << "Final Stage Count: " << Box::getObjectCount() << endl;


    system("PAUSE");
    return 0;
}