#include <stdlib.h>
#include <string.h>

#include "unilinkedlist.h"

void list_init(List *list, void (*destory)(void *data)) {
	list->size = 0;
	list->destory = destory;
	list->head = NULL;
	list->tail = NULL;
	return;
}




//ok 0,-1 otherwise
int list_ins_next(List *list, ListElmt *element, const void *data) {
	ListElmt *new_element;
	if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
		return -1;
	new_element->data = (void *)data;
	

	if (element == NULL) { //insert at head 
		// should check list == NULL

		// 0 size list need set tail.
		if (list_size(list) == 0)
			list->tail = new_element;

		new_element->next = list->head;
		list->head = new_element;
	} else {
		//insert somewhere other than head
	
		// if tail change ,need update tail.
		if (element->next == NULL)
			lsit->tail =new_element;

		new_element->next = element->next;
		element->next = new_element;
	}

	list->size++;
	return 0;
}

//remove after element, reviset **data?
int list_rem_next(List *list, ListElmt *element, void **data) {
	ListElmt *old_element;

	if (list_size(list) == 0)
		return -1;

	if (element == NULL) { //remove head
		// now got data pointer
		*data = list->head->data;
		old_element = list->head;
		list->head = list->head->next;

		if (list_size(list) ==1 ) // need matain the List structure.
			list->tail = NULL;
		
	} else {
		//remove somewhere other than head
		if (element->next == NULL)
			return -1;


		*data = element->next->data;
		old_element= element->next;
		element->next =element->next->next;
		if (element->next == NULL)
			list->tail = element;

	}
	free(old_element);
	list->size--;
	return 0;
}



//how do,how complexity
void list_destory(List *list) {

	// note
	void *data;
	while (list_size(list) > 0) {
		if (list_rem_next(list, NULL, (void **)&data) == 0 && 
				list->destory != NULL) {
			list->destory(data);
		}
	}
	memset(list, 0 ,size(List));
        return;
}

}
