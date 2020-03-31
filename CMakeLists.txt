cmake_minimum_required(VERSION 3.10)

project(algorithms)

set(CMAKE_CXX_FLAGS "-O3")
include_directories(.)

add_executable(generate
    generate.cpp)

add_executable(vector_sum
    vector/vector.cpp
    vector_sum.cpp)

add_executable(list_sum
    list/linked_list.cpp
    list_sum.cpp)

add_executable(vector_stack_test
    vector/vector.cpp
    stack/vector_stack.cpp
    vector_stack_test.cpp)

add_executable(list_stack_test
    list/linked_list.cpp
    stack/list_stack.cpp
    list_stack_test.cpp)

add_executable(vector_queue_test
    queue/vector_queue.cpp)

add_executable(list_queue_test
    queue/list_queue.cpp)

add_executable(stack_queue_test
    vector/vector.cpp
    stack/vector_stack.cpp
    queue/stack_queue.cpp)

add_executable(list_sort_test
    list/linked_list.cpp
    sort/list_sort.cpp)

add_executable(vector_sort_test
    vector/vector.cpp
    sort/vector_sort.cpp)