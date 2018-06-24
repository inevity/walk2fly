add_library(linkedlist STATIC
        linkedlist/linkedlist.c
        )

target_include_directories(linkedlist PUBLIC
        linkedlist
        )

