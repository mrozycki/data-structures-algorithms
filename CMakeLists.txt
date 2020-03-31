cmake_minimum_required(VERSION 3.10)

project(algorithms)

set(CMAKE_CXX_FLAGS "-O3")

add_executable(array_sum
    array.cpp
    array_sum.cpp)

add_executable(list_sum
    linked_list_struct.cpp
    list_sum.cpp)

add_executable(generate
    generate.cpp)

add_executable(list_stack_test
    linked_list_struct.cpp
    list_stack.cpp)

add_executable(array_stack_test
    array.cpp
    array_stack.cpp
    array_stack_test.cpp)

add_executable(stack_queue_test
    array.cpp
    array_stack.cpp
    stack_queue.cpp)

add_executable(array_queue_test
    array_queue.cpp)

add_executable(linked_list_queue_test
    linked_list_queue.cpp)

add_executable(list_sort_test
    linked_list_struct.cpp
    list_sort.cpp)

add_executable(array_sort_test
    array.cpp
    array_sort.cpp)