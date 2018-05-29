cmake_minimum_required(VERSION 2.8)

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

set(binary_tree  binary_tree.h binary_tree_test.cpp )
add_executable(binary_tree ${binary_tree} )


set(linked_list  linked_list.h linked_list_test.cpp )
add_executable(linked_list ${linked_list} )


set(heap  heap.h heap_test.cpp )
add_executable(heap ${heap} )


