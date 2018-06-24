add_library(linkedlist STATIC
        linkedlist/list.c
        )

target_include_directories(linkedlist PUBLIC linkedlist include)
# include common file

