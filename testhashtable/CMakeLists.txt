cmake_minimum_required(VERSION 3.10)
project(testhashtable)

add_executable(testhashtable testhashtable.c)


target_link_libraries(testhashtable Unity linkedlistm hashtable)
enable_testing()
add_test(NAME testhashtable COMMAND testhashtable)