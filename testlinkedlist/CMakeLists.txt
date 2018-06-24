cmake_minimum_required(VERSION 3.10)
project(testlinkedlist)

add_executable(testlinkedlist testlist.c)


target_link_libraries(testlinkedlist Unity linkedlist)
enable_testing()
add_test(NAME testlinkedlist COMMAND testlinkdedlist)