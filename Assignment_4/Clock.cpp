#include "Clock.h"
#include <iostream>
#include <cstdlib> //system()

Clock::Clock(void){ //Default Constructor
    hours = 0;
    mins = 0;
    secs = 0;
}

Clock::Clock(int h, int m, int s){ //Overloaded Constructor
    hours = h;
    mins = m;
    secs = s;

    //Function Call Increment Values
    incrementHours();
    incrementMins();
    incrementSecs();
}

void Clock::setClock(int h, int m, int s){ //Sets values for the variables
    if(0<h && h<24)
        hours = h;
    if(0<m && m<60)
        mins = m;
    if(0<s && s<60)
        secs = s;
}

void Clock::getClock(int *h, int *m, int *s){ //Pointers. Gets the values after user enters them
    *h = hours, *m = mins, *s = secs;
}

//Incrementing default values by one

void Clock::incrementHours(){
    hours++;
}

void Clock::incrementMins(){
    mins++;
}

void Clock::incrementSecs(){
    secs++;
}

//Overloading Functions ***Same Name, Different # of Arguments***

void Clock::incrementHours(int user_h){
    hours = hours + user_h; //Increment by value entered by the user
}

void Clock::incrementMins(int user_m){
    mins = mins + user_m;
}

void Clock::incrementSecs(int user_s){
    secs = secs + user_s;
}