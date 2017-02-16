// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <fstream> //For work with files.
using namespace std;

struct wave_record{ //Single wave record.
    int year;
    int month;
    int day;
    int hour;
    int minute;
    double wave_height;
    double wave_length;
};

int _tmain(int argc, _TCHAR* argv[]){

    const int SIZE = 50;
    wave_record wave_data[SIZE];

    ifstream infile;
	ofstream outfile;
	outfile.open("wave_data.txt");
    infile.open("wave.txt"); //Opens file wave.txt

	//Variables
	double steep_lim = 0.14285714285;
    double steepness;
	int counter=0;
    double max_steepness = 0;
	double avr_steepness_1, avr_steepness_2, avr_steepness_3;

    if(infile.fail()){ //Checks for file opening.
        cout << "ERROR => File Failed to Open.";
    }

    while(!infile.eof()){ //Loops runs until the end of file is reached.
        for (int i=0; i<SIZE; i++){
            //Read data from file into array of structures.
            infile >> wave_data[i].year >> wave_data[i].month >> wave_data[i].day >> wave_data[i].hour >> wave_data[i].minute >> wave_data[i].wave_height >> wave_data[i].wave_length;

           steepness = wave_data[i].wave_height / wave_data[i].wave_length;

            if(steepness > steep_lim){
                outfile << "Wave Data:" << endl;
                outfile << wave_data[i].year << " " << wave_data[i].month << " " << wave_data[i].day << " " << wave_data[i].hour << " ";
                outfile << wave_data[i].minute << " " << wave_data[i].wave_height << " " << wave_data[i].wave_length << endl;
                outfile << "The steepness of the wave is: " << steepness << endl;
            }

            //Average Steepness by Year 2010-2012      
            //2010
            if(wave_data[i].year == 2010){
                counter++;
				avr_steepness_1 = (steepness++) / counter;                				
            }

            //2011
            if(wave_data[i].year == 2011){
                counter++;
                avr_steepness_2 = (steepness++) / counter;               
            }

            //2012
            if(wave_data[i].year == 2012){
                counter++;
                avr_steepness_3 = (steepness++) / counter;               
            }
        }
    }

	cout << "The average steepness of waves in 2010 is: " << avr_steepness_1 << endl;
	cout << "The average steepness of waves in 2011 is: " << avr_steepness_2 << endl;
	cout << "The average steepness of waves in 2012 is: " << avr_steepness_3 << endl;

    infile.close();
	outfile.close();

    system("PAUSE");
    return 0;
}
