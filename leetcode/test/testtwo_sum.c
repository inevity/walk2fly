#include "unity.h"
#include "two_sum.h"

void setUp(void)
{
}

void tearDown(void)
{
}

//void test_two_sum_NeedToImplement(void)
//{
//    //must not be comment!!
//    TEST_IGNORE_MESSAGE("Need to Implement two_sum");
//    
//}
void test_two_sum_twosum(void)
{
    //TEST_IGNORE_MESSAGE("Need to Implement two_sum");
    //int nums = [2, 7, 11, 15];
    //int nums[4] = [2, 7, 11, 15];
    int nums[4] = {2, 7, 11, 15};
    //??
    int target = 9;
    int length = sizeof(nums)/sizeof(int);
    int a[2] = {0,1};
    TEST_ASSERT_EQUAL_INT_ARRAY(a, two_sum(nums,length,target), 2);
}
//void test_two_sum_twosum_useset(void)
//{
//    int nums[4] = {2, 7, 11, 15};
//    int target = 9;
//    int length = sizeof(nums)/sizeof(int);
//    int a[2] = {0,1};
//    TEST_ASSERT_EQUAL_INT_ARRAY(a, two_sum_useset(nums,length,target), 2);
//}
void test_two_sum_twosum_useht(void)
{
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int length = sizeof(nums)/sizeof(int);
    int a[2] = {0,1};
    TEST_ASSERT_EQUAL_INT_ARRAY(a, two_sum_useht(nums,length,target), 2);
}
void test_two_sum_whether(void)
{
    TEST_ASSERT_EQUAL(1,1);
}
