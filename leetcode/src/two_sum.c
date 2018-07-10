#include "two_sum.h"
//#include <stdio.h>
#include <stdlib.h>
//for malloc
#include <assert.h>
int *two_sum(int *nums, int length, int target) {
   int * result = (int *)malloc(2* sizeof(int));

   assert(result);
   result[0]=1;
   result[1]=2;
   return result;
}
