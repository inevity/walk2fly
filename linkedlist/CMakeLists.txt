#cmake_minimum_required(VERSION 3.10)
#project(linklist)
#
#set(CMAKE_C_STANDARD 99)
#
#set(SOURCE_FILES main.c)
#add_executable(linklist ${SOURCE_FILES})

cmake_minimum_required(VERSION 3.10)
#cmake_minimum_required(VERSION 3.4)
#set(CMAKE_C_STANDARD 99)
project(linkedlist)

add_executable(linkedlist linkedlist.c)
# linklist.c use test framework
#target_include_directories(linkedlist PUBLIC ${GTEST_INCLUDE_DIRS})
#target_link_libraries(linkedlist ${GTEST_LIBRARIES})

#target_link_libraries(linkedlist
#        module_a
#        Unity
#        )
#target_include_directories(linkedlist PUBLIC ${UTEST_INCLUDE_DIRS})
target_link_libraries(linkedlist Unity)
enable_testing()
add_test(NAME linkedlist COMMAND linkedlist)