#ifndef ASSIGNMENT_4_BOX_H
#define ASSIGNMENT_4_BOX_H
#pragma once

class Box {
    public:
        static int objectCount;

        Box(double, double, double); //Constructor

        double Volume();

        static int getObjectCount(); // Static Function

    private:
        double length, width, heigt;
};

int Box::objectCount = 0;

#endif