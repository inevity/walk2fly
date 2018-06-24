cmake_minimum_required(VERSION 3.10)
project(walk2fly C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIB_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/lib/include)

set(LIB_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(UTEST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/external)
set(UTEST_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity/src)
add_subdirectory(${UTEST_ROOT} EXCLUDE_FROM_ALL)
# ref:https://github.com/ltowarek/coding-interview/blob/master/CMakeLists.txt
# from:https://github.com/rpoisel/cmake-unity-tutorial/blob/master/CMakeLists.txt
set(TARGET_GROUP test CACHE STRING "Group to build")

add_subdirectory(lib)

if(TARGET_GROUP STREQUAL production)
    add_subdirectory(linkedlist)
elseif(TARGET_GROUP STREQUAL test)
    include(CTest)
    enable_testing()

    add_subdirectory(linkedlist)
    add_subdirectory(linkedlistop)
    add_subdirectory(testlinkedlist)
    add_subdirectory(testhashtable)
else()
    message(FATAL_ERROR "Given TARGET_GROUP unknown")
endif()

