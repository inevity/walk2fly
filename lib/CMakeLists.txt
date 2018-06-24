add_library(linkedlist STATIC
        linkedlist/list.c
        )

target_include_directories(linkedlist PUBLIC linkedlist include)
# include common file

add_library(hashtable STATIC
        hashtable/chtbl.c
        )

target_include_directories(hashtable PUBLIC hashtable linkedlist)
