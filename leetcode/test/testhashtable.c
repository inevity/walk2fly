#include "unity.h"
#include "hashtable.h"

void setUp(void)
{
}

void tearDown(void)
{
}

//void test_hashtable_NeedToImplement(void)
void test_hashtable_allops(void)
{
    hashtable_t *hashtable = ht_create( 65536 );
    ht_set( hashtable, "key1", "inky" );
    ht_set( hashtable, "key2", "pinky" );
    ht_set( hashtable, "key3", "blinky" );
    ht_set( hashtable, "key4", "floyd" );
    //printf( "%s\n", ht_get( hashtable, "key1" ) );
    //	printf( "%s\n", ht_get( hashtable, "key2" ) );
    //	printf( "%s\n", ht_get( hashtable, "key3" ) );
    //	printf( "%s\n", ht_get( hashtable, "key4" ) );

   //TEST_IGNORE_MESSAGE("Need to Implement hashtable");
   TEST_ASSERT_EQUAL_STRING("inky", ht_get(hashtable, "key1"));
   TEST_ASSERT_EQUAL_STRING("pinky", ht_get(hashtable, "key2"));
   TEST_ASSERT_EQUAL_STRING("blinky", ht_get(hashtable, "key3"));
   TEST_ASSERT_EQUAL_STRING("floyd", ht_get(hashtable, "key4"));

}
