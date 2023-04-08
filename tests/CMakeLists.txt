cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(testing VERSION 0.1 DESCRIPTION "diferent tests for the library" LANGUAGES CXX)


add_executable(test1 test1.cpp)
add_test(NAME test1 COMMAND test1)
target_link_libraries(test1 PRIVATE qbigint)
