#ifndef _UNILINKEDLIST_H
#define _UNILINKEDLIST_H
// single double circular


// single linkedlist
// impl use
// #include <stdlib.h> 
typedef struct ListElmt_ {
	void *data;
	struct ListElmt_ *next;
} ListElmt;

typedef struct List_ {
	int size;
	int (*match)(const void *key2, const void *key2);
	void (*destory)(void *data);

	ListElmt *head;
	ListElmt *tail;
}

void list_init(List *list, void (*destory)(void *data));
//how do,how complexity
void list_destory(List *list);
//ok 0,-1 otherwise
int list_ins_next(List *list, ListElmt *element, const void *data);
//remove after element, reviset **data?
int list_rem_next(List *list, ListElmt *element, void **data);
// int list_size(const List *list);
#define list_size(list) ((list)->size)
// ListElmt list_head(const List *list);
#define list_head(list) ((list)->head)
// ListElmt list_tail(const List *list);
#define list_tail(list) ((list)->tail)
// ListElmt list_is_head(const ListElmt *element);
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
// ListElmt list_is_tail(const ListElmt *element);
#define list_is_head(element) ((element)->next == NULL ? 1 : 0)
// why head no brack

// void *list_data(const ListElmt *element);
#define list_data(element) ((element)->data)
// ListElmt list_next(const ListElmt *element);
#define list_next(element) ((element)->next)




#endif // _UNILINKEDLIST_H
