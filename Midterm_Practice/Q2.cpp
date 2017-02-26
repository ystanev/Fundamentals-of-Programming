#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm> //Used for sorting the array of nums.

using namespace std;

//Function Prototype.
int distinct_numbers (int nums, int SIZE);

int main (){

    //Random Nums.
    srand(time(NULL));

    const int SIZE = 100;
    int nums[SIZE];

    for (int i=0; i<SIZE; i++) {
         int rand = rand() % 100 + 0; //Generate rand. nums. 0-100
         nums[i] = rand;
        //Sorting array.
        //sort(nums.begin(), nums.end());
        cout << nums[i] << " ";
    }
}

int distinct_numbers (int nums[], int SIZE){
    //Checking for duplicates.
    for (int i=1; i<SIZE; i++){
        if(nums[i] == nums[i+1]){

        }
    }
}