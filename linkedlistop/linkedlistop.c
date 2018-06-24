//
// Created by Baul on 2018/6/9.
//

#include <stdlib.h>
#include <string.h>

#include <unity.h>
#include "list.h"
#include <stdint.h>

// #include <module_a.h>

int8_t AverageThreeBytes(int8_t a, int8_t b, int8_t c)
{
    return (int8_t)(((int16_t)a + (int16_t)b + (int16_t)c) / 3);
}

void test_AverageThreeBytes_should_AverageMidRangeValues(void)
{
    TEST_ASSERT_EQUAL_HEX8(40, AverageThreeBytes(30, 40, 50));
    TEST_ASSERT_EQUAL_HEX8(40, AverageThreeBytes(10, 70, 40));
    TEST_ASSERT_EQUAL_HEX8(33, AverageThreeBytes(33, 33, 33));
}
List *a= NULL;
void test_VerifyThatUnityIsAwesomeAndWillMakeYourLifeEasier(void) {
    //ASSERT_TRUE(1); no func ?? old
    TEST_ASSERT_TRUE(1);
}

void list_init(List *list, void (*destory)(void *data)) {
    list->size = 0;
    list->destory = destory;
    list->head = NULL;
    list->tail = NULL;
}
List * b;
//List * b = (List *) malloc(int * sizeof(List));

// b = (List *) malloc(sizeof(List));


//list_init(b,NULL);
//default should run in func not global?

void test_point_null(void)
        //void test_point_null(List * a)
        //void test_point_null(void * a)
{
    //if (a != NULL)
   // {
        TEST_ASSERT_NULL(a);
    //}
}
void test_point_nullb(void)
{
    TEST_ASSERT_NOT_NULL(b);
}
int main(void){
//list_init(a, void (*destory)(void *)(NULL)
    //weather need creat pointer?

    //list_init(b, NULL);
UNITY_BEGIN();//whihc linenum
//RUN_TEST(test_AverageThreeBytes_should_AverageMidRangeValues);
//RUN_TEST(test_AverageThreekBytes_should_AverageHighValues);
//TEST_ASSERT_NOT_NULL(a);


    //TEST_ASSERT_NULL(a);
//RUN_TEST(test_AverageThreeBytes_should_AverageMidRangeValues);
//RUN_TEST(test_point_null);
    //RUN_TEST(test_point_null((void*) a));
    //List * b = (List *) malloc(int * sizeof(List));
    b = (List *) malloc(sizeof(List));
    list_init(b,NULL);
    RUN_TEST(test_point_null);
    RUN_TEST(test_point_nullb);
    RUN_TEST(test_VerifyThatUnityIsAwesomeAndWillMakeYourLifeEasier);
   // RUN_TEST(test_point_null);
//RUN_TEST((TEST_ASSERT_NULL(a)));
return UNITY_END();
//UNITY_END();
  //  return 0;
}//must use main!!!
//unity-begin and end ,count test


