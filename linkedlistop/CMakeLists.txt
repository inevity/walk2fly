cmake_minimum_required(VERSION 3.10)
project(linkedlistop)

add_executable(linkedlistop linkedlistop.c list.h)


target_link_libraries(linkedlistop Unity)
enable_testing()
add_test(NAME linkedlistop COMMAND linkedlistop)