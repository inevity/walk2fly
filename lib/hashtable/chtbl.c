#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "chtbl.h"


int chtbl_init(CHTbl *htbl, int buckets, int (*h)(const void *key),
               int (*match)(const void *key1, const void *key2),
               void (*destory)(void *data) ){
    int i;

    if ((htbl->table = (List *)malloc(buckets * sizeof(List))) == NULL)
        return -1;

    htbl->buckets = buckets;

    for (i=0; i < htbl->buckets; i++)
        list_init(&htbl->table[i], destory);//preorder

    htbl->h = h;
    htbl->match =match;
    htbl->destory= destory;

    htbl->size = 0;
    return 0;
}

