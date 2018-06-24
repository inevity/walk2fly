// //
// // Created by Baul on 2018/6/9.
// //
//
// #include <stdlib.h>
// #include <string.h>
//
// #include <unity.h>
// #include "list.h"
// #include <stdint.h>
//
// // #include <module_a.h>
//
// int8_t AverageThreeBytes(int8_t a, int8_t b, int8_t c)
// {
//     return (int8_t)(((int16_t)a + (int16_t)b + (int16_t)c) / 3);
// }
//
// void test_AverageThreeBytes_should_AverageMidRangeValues(void)
// {
//     TEST_ASSERT_EQUAL_HEX8(40, AverageThreeBytes(30, 40, 50));
//     TEST_ASSERT_EQUAL_HEX8(40, AverageThreeBytes(10, 70, 40));
//     TEST_ASSERT_EQUAL_HEX8(33, AverageThreeBytes(33, 33, 33));
// }
// List *a= NULL;
// void test_VerifyThatUnityIsAwesomeAndWillMakeYourLifeEasier(void) {
//     //ASSERT_TRUE(1); no func ?? old
//     TEST_ASSERT_TRUE(1);
// }
//
// void list_init(List *list, void (*destory)(void *data)) {
//     list->size = 0;
//     list->destory = destory;
//     list->head = NULL;
//     list->tail = NULL;
// }
// List * b;
// //List * b = (List *) malloc(int * sizeof(List));
//
// // b = (List *) malloc(sizeof(List));
//
//
// //list_init(b,NULL);
// //default should run in func not global?
//
// void test_point_null(void)
//         //void test_point_null(List * a)
//         //void test_point_null(void * a)
// {
//     //if (a != NULL)
//    // {
//         TEST_ASSERT_NULL(a);
//     //}
// }
// void test_point_nullb(void)
// {
//     TEST_ASSERT_NOT_NULL(b);
// }
// int main(void){
// //list_init(a, void (*destory)(void *)(NULL)
//     //weather need creat pointer?
//
//     //list_init(b, NULL);
// UNITY_BEGIN();//whihc linenum
// //RUN_TEST(test_AverageThreeBytes_should_AverageMidRangeValues);
// //RUN_TEST(test_AverageThreekBytes_should_AverageHighValues);
// //TEST_ASSERT_NOT_NULL(a);
//
//
//     //TEST_ASSERT_NULL(a);
// //RUN_TEST(test_AverageThreeBytes_should_AverageMidRangeValues);
// //RUN_TEST(test_point_null);
//     //RUN_TEST(test_point_null((void*) a));
    //List * b = (List *) malloc(int * sizeof(List));
//    b = (List *) malloc(sizeof(List));
//    list_init(b,NULL);
//    RUN_TEST(test_point_null);
//    RUN_TEST(test_point_nullb);
//    RUN_TEST(test_VerifyThatUnityIsAwesomeAndWillMakeYourLifeEasier);
   // RUN_TEST(test_point_null);
//RUN_TEST((TEST_ASSERT_NULL(a)));
//return UNITY_END();
//UNITY_END();
  //  return 0;
//}//must use main!!!
//unity-begin and end ,count test


#include "list.h"
#include <stdlib.h>
#include "fatal.h"

/* Place in the interface file */
struct Node
{
    ElementType Element;
    Position    Next;
};

List
MakeEmpty( List L )
{
    if( L != NULL )
        DeleteList( L );
    L = malloc( sizeof( struct Node ) );
    if( L == NULL )
        FatalError( "Out of memory!" );
    L->Next = NULL;
    return L;
}

/* START: fig3_8.txt */
/* Return true if L is empty */

int
IsEmpty( List L )
{
    return L->Next == NULL;
}
/* END */

/* START: fig3_9.txt */
/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */

int IsLast( Position P, List L )
{
    return P->Next == NULL;
}
/* END */

/* START: fig3_10.txt */
/* Return Position of X in L; NULL if not found */

Position
Find( ElementType X, List L )
{
    Position P;

/* 1*/      P = L->Next;
/* 2*/      while( P != NULL && P->Element != X )
/* 3*/          P = P->Next;

/* 4*/      return P;
}
/* END */

/* START: fig3_11.txt */
/* Delete from a list */
/* Cell pointed to by P->Next is wiped out */
/* Assume that the position is legal */
/* Assume use of a header node */

void
Delete( ElementType X, List L )
{
    Position P, TmpCell;

    P = FindPrevious( X, L );

    if( !IsLast( P, L ) )  /* Assumption of header use */
    {                      /* X is found; delete it */
        TmpCell = P->Next;
        P->Next = TmpCell->Next;  /* Bypass deleted cell */
        free( TmpCell );
    }
}
/* END */

/* START: fig3_12.txt */
/* If X is not found, then Next field of returned value is NULL */
/* Assumes a header */

Position
FindPrevious( ElementType X, List L )
{
    Position P;

/* 1*/      P = L;
/* 2*/      while( P->Next != NULL && P->Next->Element != X )
/* 3*/          P = P->Next;

/* 4*/      return P;
}
/* END */

/* START: fig3_13.txt */
/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */

void
Insert( ElementType X, List L, Position P )
{
    Position TmpCell;

/* 1*/      TmpCell = malloc( sizeof( struct Node ) );
/* 2*/      if( TmpCell == NULL )
/* 3*/          FatalError( "Out of space!!!" );

/* 4*/      TmpCell->Element = X;
/* 5*/      TmpCell->Next = P->Next;
/* 6*/      P->Next = TmpCell;
}
/* END */

#if 0
/* START: fig3_14.txt */
        /* Incorrect DeleteList algorithm */

        void
        DeleteList( List L )
        {
            Position P;

/* 1*/      P = L->Next;  /* Header assumed */
/* 2*/      L->Next = NULL;
/* 3*/      while( P != NULL )
            {
/* 4*/          free( P );
/* 5*/          P = P->Next;
            }
        }
/* END */
#endif

/* START: fig3_15.txt */
/* Correct DeleteList algorithm */

void
DeleteList( List L )
{
    Position P, Tmp;

/* 1*/      P = L->Next;  /* Header assumed */
/* 2*/      L->Next = NULL;
/* 3*/      while( P != NULL )
    {
/* 4*/          Tmp = P->Next;
/* 5*/          free( P );
/* 6*/          P = Tmp;
    }
}
/* END */

Position
Header( List L )
{
    return L;
}

Position
First( List L )
{
    return L->Next;
}

Position
Advance( Position P )
{
    return P->Next;
}

ElementType
Retrieve( Position P )
{
    return P->Element;
}