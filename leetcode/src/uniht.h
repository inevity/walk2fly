#ifndef _UNIHT_H
#define _UNIHT_H
// chained hashtable

// load facture to select hash func
//
// How select
// integer , convert to integer
// string(diff postions)
// h(k) = k mod m, m not power of 2; prime number not too close to power of 2
// division method
//
//// h(k) = [ m(ka mod 1] where A ~~ (^5-1)/2=0.618
// todo vim insert charater.
//
//


#include <stdlib.h>

#include "unilinkedlist.h"

typedef struct CHTbl_ {
	int buckets;
	int (*h)(const void *key);
	int (*match)(const void *key1, const void *key2);
	void (*destory)(void *data);

	int size;
	//for each list
	List *table;
} CHTbl;


// match 1,0 otherwise.
//
int chtbl_init(CHTbl *htbl, int buckets, int (*h)(const void *data), 
		int (*match)(const *void *key1, const void *key2), 
		void (*destory)(void *data));

void chtbl_destory(CHTbl *htbl);

//new element contains a pointer to data.
//which is key?
//ok 0, -1 otherwise
int chtbl_insert(CHTbl *htbl, const void *data);
int chtbl_remove(CHTbl *htbl, void **data);
// how data pointer?
int chtbl_lookup(const CHTbl *htbl, void **data);

// int chtbl_size(CHTbl *htbl);
#define chtbl_size(htbl) ((htbl)->size)




#endif // _UNIHT_H
