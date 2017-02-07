#include <iostream>
#include <time.h>
#include <cstdlib> //  rand()
using namespace std;

int main() {

   double nums [100];
   int sum = 0, average, max = nums[0], index;
   srand(time(NULL));

   for (int i=0; i<100; i++){
       nums[i]=rand()%101+100; // Random Nums.
       cout << nums[i] << " ";
       average = sum += nums[i] / 100;

       if(nums[i]>max){ // Find the max value in the array.
           max=nums[i];
           index = i;
       }
   }

   cout << "The Average is: " << average << endl;
   cout << "The Max Value is: " << max << " The Index is: " << index << endl;

   return 0;
}