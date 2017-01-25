/*
	3.	Create a program that will output the volume V of a sphere for a given radius R.  
		The program user inputs the initial, incremental, and ending values of the radius.  
		For each value of the radius, the program will calculate the corresponding volume V= 4πR^3/3 
		and will print the radius and the volume in tabular format (2 columns). Use SI units.
*/

#include <iostream>
//#include <iomanip> // Used to format the output.
#include <cstdlib> // Used for system().
#include <math.h> // Used for pow().
using namespace std;// ?

int main(){

	
	const double PI = 3.14159;
	double volume;
	int r_initial, r_incremental, r_ending;
	
	cout << "Enter initial value: ";
	cin >> r_initial;
	
	cout << "Enter incremental value: ";
	cin >> r_incremental;
	
	cout << "Enter ending value: ";
	cin >> r_ending;
	
	for ( int i=r_initial; i <= r_ending; i = i + r_incremental ) {
		
		volume = (4 * PI * pow(i, 3.0) ) / 3;
		
		cout << "The volume of the sphere is: " << volume << endl;
		
		//cout << i << endl;
	
	}
	

	/*for( int a = 5; a < 20; a = a + 5 ) {
      cout << "value of a: " << a << endl;
   }*/
	
	system("PAUSE");
    return 0;
}