#include <stdio.h>
#include "list.h"
#include <unity.h>


void
PrintList( const List L )
{
    Position P = Header( L );

    if( IsEmpty( L ) )
        printf( "Empty list\n" );
    else
    {
        do
        {
            P = Advance( P );
            printf( "%d ", Retrieve( P ) );
        } while( !IsLast( P, L ) );
        printf( "\n" );
    }
}
void test_list(void)
{
    List L;
    Position P;
    int i;

    L = MakeEmpty( NULL );

    TEST_ASSERT_NOT_NULL(L);
    P = Header( L );
    PrintList( L );//how should design return?

    for( i = 0; i < 10; i++ )
    {
        Insert( i, L, P );
        PrintList( L );
        P = Advance( P );
    }
    for( i = 0; i < 10; i+= 2 )
        Delete( i, L );

    for( i = 0; i < 10; i++ )
        if( ( i % 2 == 0 ) == ( Find( i, L ) != NULL ) )
            printf( "Find fails\n" );

    printf( "Finished deletions\n" );

    PrintList( L );

    DeleteList( L );
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_list);
    return UNITY_END();
    //return 0;
}

