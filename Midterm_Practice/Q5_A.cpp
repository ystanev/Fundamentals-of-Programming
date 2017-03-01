#include <iostream>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct points{
    int x_1,y_1;
};

int main() {

    ifstream infile;
    ofstream outfile;

    //Open file to write to.
    outfile.open("plane.txt");
    infile.open("plane.txt");

    //Variables.
    const int SIZE = 1000;
    int q1_num = 0, q2_num = 0, q3_num = 0, q4_num = 0;

    //Arrays.
    int x[SIZE];
    int y[SIZE];
    points pairs[SIZE];

    srand(time(NULL));

    //Fill array with random #s & save to file.
    for (int i=0; i<SIZE; i++){
        x[i] = rand() % 200 + (-100);
        y[i] = rand() % 200 + (-100);
        outfile << setw(3) << x[i] << setw(5) << y[i] << endl;
    }

    while(!infile.eof()) { //Loops runs until the end of file is reached.
        for (int j = 0; j < SIZE; j++){
            //Read data from file into array of structures.
            infile >> pairs[j].x_1 >> pairs[j].y_1;
        }
    }

    for (int k = 0; k < SIZE; k++){
        //Quadrant Pairs.
        if (pairs[k].x_1 >= 1 && pairs[k].y_1 >= 1){
            q1_num++;
        }
        else if (pairs[k].x_1 <= -1 && pairs[k].y_1 >= 1){
            q2_num++;
        }
        else if (pairs[k].x_1 <= -1 && pairs[k].y_1 <= -1){
            q3_num++;
        }
        else{
            q4_num++;
        }
    }

    cout << "First Quadrant has : " << q1_num << " pairs." <<endl;
    cout << "Second Quadrant has : " << q2_num << " pairs." <<endl;
    cout << "Third Quadrant has : " << q3_num << " pairs." <<endl;
    cout << "Fourth Quadrant has : " << q4_num << " pairs." <<endl;

    //Close file.
    outfile.close();
    infile.close();

    system("PAUSE");
    return 0;
}
