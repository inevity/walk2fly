#include "two_sum.h"
//#include <stdio.h>
#include <stdlib.h>
//for malloc
//#include <assert.h>
//brute force: for i for rest.. time o(n2), spaceo(1).  performance impace by cpu storage (mem and disk),network
//so to optimisze,we could go in this dirctions. or you will not to find a nice algo.

//
//int *two_sum(int *nums, int length, int target) {
//
//    int * result = (int *)malloc(2* sizeof(int));
//
//    assert(result);
//    result[0]=1;
//    result[1]=2;
//    return result;
//}
int *two_sum(int *nums, int length, int target) {
    for (int i = 0; i < length; i++) {
	    //now need to adjust the max for for loop
        for (int j = i + 1; j < length; j++) {
            if (nums[i] + nums[j] == target) {
                int *result = (int *) malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
		return result;

            }

        }

    }
    return NULL;
}


//
//    assert(result);
//    return result;
//}
//for whetch found,no need index.
//int *two_sum_useset(int *nums, int length, int target) {
//}
int *two_sum_useht(int *nums, int length, int target) {
}
