#include <iostream>
#include <iomanip> // Used to format the output.
#include <cstdlib> // Used for system().
# define M_PI           3.14159265358979323846  /* pi */
#include <math.h> // Used for sqrt(). fabs()
//#indlude <cmath> // and() double
//#include <complex> // Used for complex numbres
using namespace std;// ?

// Functions Prototypes
void calculateNum(double real_part, double imag_part, double *magnitude, double *angle, int *quadrant); /*complex <double> compl_num (),*/

int main(){

    double real_part, imag_part;
    double magnitude_1, angle_1;
    int quadrant_num;

    // User Input
    cout << "Enter real part of complex number: ";
    cin >> real_part;
    cout << "Enter imaginary part of complex number: ";
    cin >> imag_part;

    calculateNum(real_part, imag_part, &magnitude_1, &angle_1, &quadrant_num);

    cout << "The magnitude of i is: " << magnitude_1 << endl;
    cout << "The angle is: " << angle_1 << '\370' << endl; // '\370' = °
    cout << "This number lies is quadrant " << quadrant_num << endl;

    /*complex <double> compl_num (real_part, imag_part); // Imaginary numbers.
    cout << "Real Part " << real(compl_num) << " Imaginary Part: " << imag(compl_num) << endl;*/ // Num Check

    system("PAUSE");
    return 0;
}

void calculateNum(double real_part, double imag_part, double *magnitude, double *angle, int *quadrant){ /*complex <double> compl_num (),*/
    *magnitude = sqrt( pow(real_part,2) + pow(imag_part,2) ); /*pow(compl_num(real_part)*/ /*compl_num(imag_part)*/
    *angle = atan( fabs ( imag_part / real_part ) ) * (180 / M_PI); // Degrees /*compl_num(real_part)/compl_num(imag_part)*/

    if(real_part >= 1 && imag_part >= 1){
        *quadrant = 1;
    }
    else if(real_part <= -1 && imag_part >= 1){
        *quadrant = 2;
    }
    else if(real_part <= -1 && imag_part <= -1){
        *quadrant = 3;
    }
    else if(real_part >= 1 && imag_part <= -1){
        *quadrant = 4;
    }
    else{
        cout << "Error";
    }
}
