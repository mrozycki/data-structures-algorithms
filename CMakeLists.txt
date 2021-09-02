cmake_minimum_required(VERSION 3.10)

project(algorithms)

set(CMAKE_BUILD_TYPE RelWithDebInfo)
include_directories(.)

add_executable(generate
    generate.cpp)
set_property(TARGET generate PROPERTY CXX_STANDARD 17)

add_executable(vector_sum
    vector/vector.cpp
    vector_sum.cpp)
set_property(TARGET vector_sum PROPERTY CXX_STANDARD 17)

add_executable(list_sum
    list/linked_list.cpp
    list_sum.cpp)
set_property(TARGET list_sum PROPERTY CXX_STANDARD 17)

add_executable(vector_stack_test
    vector/vector.cpp
    stack/vector_stack.cpp
    vector_stack_test.cpp)
set_property(TARGET vector_stack_test PROPERTY CXX_STANDARD 17)

add_executable(list_stack_test
    list/linked_list.cpp
    stack/list_stack.cpp
    list_stack_test.cpp)
set_property(TARGET list_stack_test PROPERTY CXX_STANDARD 17)

add_executable(vector_queue_test
    queue/vector_queue.cpp)
set_property(TARGET vector_queue_test PROPERTY CXX_STANDARD 17)

add_executable(list_queue_test
    queue/list_queue.cpp)
set_property(TARGET list_queue_test PROPERTY CXX_STANDARD 17)

add_executable(stack_queue_test
    vector/vector.cpp
    stack/vector_stack.cpp
    queue/stack_queue.cpp)
set_property(TARGET stack_queue_test PROPERTY CXX_STANDARD 17)

add_executable(list_sort_test
    list/linked_list.cpp
    sort/list_sort.cpp)
set_property(TARGET list_sort_test PROPERTY CXX_STANDARD 17)

add_executable(vector_sort_test
    vector/vector.cpp
    sort/vector_sort.cpp)
set_property(TARGET vector_sort_test PROPERTY CXX_STANDARD 17)

add_executable(hash_map_test
    hash/hash_map.cpp)
set_property(TARGET hash_map_test PROPERTY CXX_STANDARD 17)

add_executable(hash_map_list_test
    hash/hash_map_list.cpp)
set_property(TARGET hash_map_list_test PROPERTY CXX_STANDARD 17)

add_executable(hash_map_flat_test
    hash/hash_map_flat.cpp)
set_property(TARGET hash_map_flat_test PROPERTY CXX_STANDARD 17)