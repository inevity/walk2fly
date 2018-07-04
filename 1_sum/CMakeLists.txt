cmake_minimum_required(VERSION 3.10)
project(1_sum)

add_executable(1_sum 1_sum.c)


target_link_libraries(1_sum Unity linkedlistm)
enable_testing()
add_test(NAME 1_sum COMMAND 1_sum)
