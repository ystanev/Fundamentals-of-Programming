#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//Fucntion Prototype
int GCD(int num, int denom);
int reduce (int num, int denom);

int main() {

    int num = 5, denom = 25;

    //Function Call
    GCD(num, denom);
    reduce(num, denom);

    //system("PAUSE");
    return 0;
}

int reduce (int num, int denom){
    if(num <= 0 || denom <= 0){
        return 0;
    }
    else{
        int reduce_num = num / num;
        int reduce_denom = denom / num;

        cout << "The reduced fraction is: " << reduce_num << "/" << reduce_denom;
        return 1;
    }
}

int GCD(int num, int denom){
    while(num != denom)
    {
        if(num > denom)
            num -= denom;
        else
            denom -= num;
    }
    return num;
}

/*
void in_out(point p_3, rectangle r_1){

cout << " enter the rec. v alues: ";
cin << rectangle.x1 << rectangle.y1 << rectangle.x2 << rectangle.y2;

cout << "enter point: ";   
cin << p_3.x << p_3.y;
 
if( ( r_1.x1 < p_3.x && p_3.x < R_1.x2 ) && ( r_1.y1 < p_3.y && p_3.y < r_1.y2 ) ){
 cout << "In";	
}
else{
 cout << "In";	
}

} 
*/
