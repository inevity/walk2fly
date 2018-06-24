//#ifndef LIST_H
//#define LIST_H
//
//#include <stdlib.h>
//
//typedef struct ListElmt_ {
//    void *data;
//    struct ListElmt_ *next;
//} ListElmt;
//
//typedef struct List_ {
//    int size;
//    int (*match)(const void *key1, const void *key2);
//    void (*destory)(void *data);
//    ListElmt *head;
//    ListElmt *tail;
//} List;
//
//void list_init(List *list, void (*destory)(void *data));
//void list_destory(List *list);
//int list_ins_next(List *list, ListElmt *element, const void *data);
//int list_rem_next(List *list, ListElmt *element, void **data);//why?
//#define list_size(list) ((list)->size)
//#define list_head(list) ((list)->head)
//#define list_tail(list) ((list)->tail)
//#define list_is_head(list, element) ((element) == (list)->head ? 1 :0)
//#define list_is_tail(list, element) ((element)->next == NULL ? 1 :0)
//#define list_data(element) ((element)->data)
//#define list_next(element) ((element)->next)
//#endif

typedef int ElementType;

/* START: fig3_6.txt */
#ifndef _List_H
#define _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty( List L );
int IsEmpty( List L );
int IsLast( Position P, List L );
Position Find( ElementType X, List L );
void Delete( ElementType X, List L );
Position FindPrevious( ElementType X, List L );
void Insert( ElementType X, List L, Position P );
void DeleteList( List L );
Position Header( List L );
Position First( List L );
Position Advance( Position P );
ElementType Retrieve( Position P );

#endif    /* _List_H */
/* END */

