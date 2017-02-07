#include <iostream>
#include <cstdlib>
using namespace std;

void countNegative(int testArray[], int n);

int main(){

    int testArray[] = {-2,0,44,12,-45,17,934,-21,67,88,91,1,0,6};
    int n= 14;
    countNegative(testArray, n);

    system("PAUSE");
    return 0;
}

void countNegative(int testArray[], int n){
    for(int i=0; i<=n; i++){
        if(testArray[i]<0){
            cout << testArray[i] << " ";
        }
    }
}