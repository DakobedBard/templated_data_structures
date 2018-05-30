cmake_minimum_required(VERSION 2.8)

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

set(dijikstra   dijikstra.cpp )
add_executable(dijikstra ${dijikstra} )


set(topological_sort   topological_sort.cpp )
add_executable(topological_sort ${topological_sort} )

set(color   color.cpp )
add_executable(color ${color} )

set(stack   stack.h stack_test.cpp )
add_executable(stack_test ${stack} )

set(vector   vector.h vector_test.cpp )
add_executable(vector ${vector} )
