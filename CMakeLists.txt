cmake_minimum_required(VERSION 3.10)
project(walk2fly C)

set(CMAKE_C_STANDARD 11)
#add_subdirectory()
#add_executable(walk2fly
#        codeblocks/main.c
#        codechef/xoragn.c)
# ref:https://github.com/ltowarek/coding-interview/blob/master/CMakeLists.txt
#cmake_minimum_required(VERSION 3.4)
#project(coding_interview)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIB_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/lib/include)
#include_directories(${CMAKE_SOURCE_DIR}/inc)

set(LIB_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/lib)
#set(gtest_force_shared_crt ON CACHE BOOL "Always use msvcrt.dll")
#set(GTEST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest)
set(UTEST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/external)
#set(GTEST_INCLUDE_DIRS ${GTEST_ROOT}/include ${GTEST_ROOT})
set(UTEST_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity/src)
#set(UTEST_INCLUDE_DIRS ${UTEST_ROOT}/include ${UTEST_ROOT}/src)
#set(UTEST_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity/src)
#set(GTEST_LIBRARIES gtest gtest_main)
#set(UTEST_LIBRARIES Unity)
#add_library(Unity STATIC
#        Unity/src/unity.c
#        )
#add_subdirectory(${GTEST_ROOT} EXCLUDE_FROM_ALL)
#add_subdirectory(${UTEST_ROOT} EXCLUDE_FROM_ALL)
add_subdirectory(${UTEST_ROOT} EXCLUDE_FROM_ALL)

# from:https://github.com/rpoisel/cmake-unity-tutorial/blob/master/CMakeLists.txt
set(TARGET_GROUP test CACHE STRING "Group to build")

add_subdirectory(lib)

#add_subdirectory(${CMAKE_BINARY_DIR}/external)
if(TARGET_GROUP STREQUAL production)
    #add_subdirectory(main)
    add_subdirectory(linkedlist)
elseif(TARGET_GROUP STREQUAL test)
    #add_subdirectory(external) same as above UTEST_ROOT.
    include(CTest)
    enable_testing()

    #add_subdirectory(test)
    add_subdirectory(linkedlist)
    add_subdirectory(linkedlistop)
    add_subdirectory(testlinkedlist)
else()
    message(FATAL_ERROR "Given TARGET_GROUP unknown")
endif()

#enable_testing()

#add_subdirectory(linkedlist)