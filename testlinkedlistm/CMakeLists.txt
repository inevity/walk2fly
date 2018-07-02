cmake_minimum_required(VERSION 3.10)
project(testlinkedlistm)

add_executable(testlinkedlistm testlistm.c)


target_link_libraries(testlinkedlistm Unity linkedlistm)
enable_testing()
add_test(NAME testlinkedlistm COMMAND testlinkdedlistm)
