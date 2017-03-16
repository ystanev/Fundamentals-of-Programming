#ifndef ASSIGNMENT_4_CLOCK_H
#define ASSIGNMENT_4_CLOCK_H
#pragma once

class Clock {
    private:
        int hours, mins, secs;

    public:
        Clock(void);//Default Constructor

        Clock(int, int, int);//Overloaded Constructor

        void setClock(int, int, int);//Setter
        void getClock (int *hours, int *mins, int *secs);//Getter

        void incrementHours();
        void incrementMins();
        void incrementSecs();

        //Overloading Functions
        void incrementHours(int);
        void incrementMins(int);
        void incrementSecs(int);
};

#endif