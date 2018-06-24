add_library(linkedlist STATIC
        linkedlist/list.c
        )

target_include_directories(linkedlist PUBLIC linkedlist include)



add_library(linkedlistm STATIC
        linkedlistm/list.c
        )

target_include_directories(linkedlistm PUBLIC linkedlistm)





add_library(hashtable STATIC
        hashtable/chtbl.c
        )
target_link_libraries(hashtable linkedlistm)

target_include_directories(hashtable PUBLIC
        linkedlistm
        hashtable)
