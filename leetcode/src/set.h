#ifndef _SET_H
#define _SET_H
void set_init(Set *set, init (*match)(const void *key1, const void *key2),
		void (*destory)(void *data));
//todo: c style vim
void set_destory(Set *set);
//alread in,return 1,ok return 0,other -1
int set_insert(Set *set, const void *data);
//0 ok,-1 otherwise
int set_remove(Set *set, const void **data);
int set_union(Set *setu, const Set *set1, const Set *set2);
//found =1,0 otherwise
int set_is_member(Set *set, const void *data);
int set_size(const Set *set);



#endif // _SET_H
