// Given an array of integers, return indices of the two numbers such that they
// add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example:
//
// Given nums = [2, 7, 11, 15], target = 9,

//        Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
#include <stdlib.h>
#include <stdio.h>
//preprocess
//func where declare
static int * two_sum(int* nums, int length, int target);
static int * two_sum(int* nums, int length, int target){




}
// array size

int main(void){
    int nums = [2,7,11,15];
    int target = 9;
    //int * result = (int *) malloc( 2 * int );
    //return option or struct or c way?
    int * result;
    //sizeof(nums)/sizeof(nums[0])
    result = two_sum(nums, sizeof(nums)/sizeof(int), target);
    if (result != null){

        printf("result is %d,%d",result[0], result[1]);
    }
    else {
        printf("no found");
    }

    return 0;
}