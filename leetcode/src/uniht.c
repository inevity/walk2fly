#include <stdlib.h>
#include <string.h>

#include "unilinkedlist.h"
#include "uniht.h"

// 
// typedef struct CHTbl_ {
// 	int buckets;
// 	int (*h)(const void *key);
// 	int (*match)(const void *key1, const void *key2);
// 	void (*destory)(void *data);
// 
// 	int size;
// 	//???
// 	List *table; // as array or first element
// 	
// } CHTbl;


// match 1,0 otherwise.
//
int chtbl_init(CHTbl *htbl, int buckets, int (*h)(const void *data), 
		int (*match)(const *void *key1, const void *key2), 
		void (*destory)(void *data)) {
	int i;
	if ((htbl->table = (List *)malloc(buckets * sizeof(List))) == NULL)
		retrun -1;

	htbl->buckets = buckets;
	for (i = 0; i < htbl->buckets; i++)
		list_init(&htbl->table[i], destory);
	//	list_init(&(htbl->table[i]), destory);

        htbl->h = h;
	htbl->match = match;
	htbl->destory = destory;

	htbl->size = 0;
	return 0;
}
void chtbl_destory(CHTbl *htbl) {
	int i;
	for (i = 0; i < htbl->buckets; i++)
		list_destory(&htbl->table[i]);

	free(htbl->table);

	memset(htbl, 0, sizeof(CHTbl));
	return;
}



//new element contains a pointer to data.
//which is key?
//ok 0, -1 otherwise
int chtbl_insert(CHTbl *htbl, const void *data) {
	void *temp;
	temp = (void *)data;
	// why need &temp
	if (chtbl_lookup(htbl, &temp) == 0)
		return -1;

	int bucket,retval;
	bucket = htbl->h(data) % htbl->buckets;
        if ((retval = list_ins_next(&htbl->table[bucket], NULL, data)) == 0)
		htbl->size++;

	return retval;
}

	



// remove one key **data?
// how? need first trasering then remove.loop
int chtbl_remove(CHTbl *htbl, void **data) {
	int bucket;
	bucket = htbl->h(*data) % htbl->buckets;

        ListElmt *element, *prev;
	for (element =list_head(&htbl->[bucket]); element != NULL; element = list_next(element)) {
		if (htbl->match(*data), list_data(element)) {
			if (list_rem_next(&htbl->table[bucket], prev, data) == 0) {
				htbl->size--;
				return 0;
			} else {
				return -1;
			}
		}
		prev = element;
	}
	return -1;
}


// how data pointer? pointer content return ??? 
// later test and understandng
int chtbl_lookup(const CHTbl *htbl, void **data) {
	int bucket;
	bucket = htbl->h(*data) % htbl->buckets;

	for (element= list_head(&htbl->table[bucket]); element != NULL; element = list_next(element)) {
		if (htbl->match(*data, list_data(element))) {
			// why? argument or para?
			// pass back the data from the table
			*data = list_data(element);
			return 0;
		}
	}
	return -1;
}


