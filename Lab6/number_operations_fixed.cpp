#include <iostream> 
#include <stdlib.h>
using namespace std;

int sum(int* nums, int size);
int* odds(int* nums, int size);
double getAverage(int arr[], int size);
void changeValue(int* nums, int new_value, int index);

/*
This main function has an array of integers and performs various operations on them.
There are bugs throughout - use GDB to try and find the errors. Refer to the comments
above each function as to what it is supposed to do
*/
int main() {
	// array of numbers to have operations performed on it
	int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int nums_size = sizeof(nums); 

	// getting array of odds and printing them out
	int * o = odds(nums, nums_size);
	cout << "ODD NUMBERS: " << endl;
	for (int i = 0; i < nums_size/4; i++) { //bytes not elements
		cout << *(o + i) << endl;
	}
	
	// getting sum of the array 
	int s = sum(nums, nums_size);
	cout << "SUM: " << endl;
	cout << s << endl;

	// average value of the numbers in nums
	double average = getAverage(nums, nums_size);
	cout << "AVERAGE: " << endl; //fixed syntax
	cout << average << endl;

	changeValue(nums, 2343, 6);
	cout << "NEW VALUE INSERTED: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << *(nums + i) << endl;
	}
 return 0; //good practice
}


// takes an array and a size as input and returns the sum of the elements
int sum(int* nums, int size) {
	int summ = 0;                       //changed name to avoid confusion with function

	for (int i = 0; i < size/4; i++){  //missing bracket, sizeof function returns size in bytes so need to divide by 4
		summ += *(nums+i);
	}
	return summ;
}

/*
 takes an array of numbers and it's size and returns an array of the same size
 but with only the odd numbers in the original array. The rest of the values in the
 new array are 0's. The odd values found in the original array should be placed into
 the new array starting at 0

 example:
 
 nums[5] = {1, 2, 7, 8, 8};
 odds[5] = {1, 7, 0, 0, 0}; <- array returned

 */
int* odds(int* nums, int size) {
static int* ptr;
ptr= (int*)malloc(256*size);	                  //needs to be of size "size" not always 10. sizeof function returns size in bytes so need to divide by 4, cant be static if size can change
	for (int i = 0; i < size/4; i++){ //sizeof function returns size in bytes so need to divide by 4
		if ( *(nums+i) % 2 !=0 ) { //Need the modulus operator to check if odd or not here
			*(ptr+i) = *(nums+i);   //make equal to nums if odd
		}else *(ptr+i)=0;       //equal to zero otherwise
	}
	return ptr;		//i used break and info to step by step debug

}

/*
  Takes an array of numbers and it's size and returns the average 
  of the numbers inside the array
*/
double getAverage(int* nums, int size) {
  int sum=0;       
  double avg;          

   for (int i = 0; i <= size/4; i++) {  //sizeof function returns size in bytes so need to divide by 4
      sum += *(nums+i);
   }
   avg = double(sum / (size/4));  //sizeof function returns size in bytes so need to divide by 4, avg must be double

   return avg;
}

/*
This function takes an array, a new value to be assigned, and the position of 
the new value to be overwritten
*/
void changeValue(int* nums, int new_value, int index) {
	*(nums+index)= new_value;	//need to use index location and assign it correctly
}

