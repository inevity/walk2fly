cmake_minimum_required(VERSION 3.10)
project(linkedlisttest)

add_executable(linkedlisttest linkedlist.c)
target_link_libraries(linkedlisttest Unity)
enable_testing()
add_test(NAME linkedlisttest COMMAND linkedlisttest)