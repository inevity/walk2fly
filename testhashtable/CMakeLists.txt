cmake_minimum_required(VERSION 3.10)
project(testhashtable)

#add_executable(testlinkedlist testlist.c $(LIB_ROOT)/linkedlist/list.h $(LIB_INCLUDE)))
add_executable(testhashtable testhashtable.c)
# add list.h
#target_include_directories(testlinkedlist PUBLIC $(LIB_ROOT)/linkedlist/ $(LIB_INCLUDE))


target_link_libraries(testhashtable Unity hashtable)
#linkedlist is lib from lib dir
enable_testing()
add_test(NAME testhashtable COMMAND testhashtable)