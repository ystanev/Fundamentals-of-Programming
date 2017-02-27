#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm> //Used for sort()
using namespace std;

//Function Prototype
//void bubbleSort(int nums[], int SIZE);
void distinct_numbers (int nums[], int SIZE);

int main (){
    //Random Nums.
    srand(time(NULL));

    const int SIZE = 100;
    int nums[SIZE];

    for (int i=0; i<SIZE; i++) {
        nums[i] = rand() % 100 + 0; //Generate rand. nums. 0-100
        cout << nums[i] << " ";
    }

    //Function Call
    //bubbleSort(nums, SIZE); //Sort array using Bubble Sort
    sort(begin(nums), end(nums));
    distinct_numbers(nums, SIZE);

}

/*void bubbleSort(int nums[], int SIZE){
    bool swapped = true;
    int j = 0;
    int tmp;
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < SIZE - j; i++) {
            if (nums[i] > nums[i + 1]){
                tmp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = tmp;
                swapped = true;
            }
        }
    }
}*/

void distinct_numbers (int nums[], int SIZE){
    //Checking for duplicates.
    int dup_count = 0;
    int uni_num;
    for (int i=1; i<SIZE; i++){
        if(nums[i] == nums[i+1]){
            dup_count++;//Counts the number of duplicates.
            uni_num = SIZE - dup_count;
        }
    }
    cout << "\n" << "The # of distinct integers between 0 and 100 = " << uni_num;
}
