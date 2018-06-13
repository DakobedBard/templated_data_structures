cmake_minimum_required(VERSION 2.8)

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

set(2d_array_test   2d_array_test.cpp )
add_executable(2d_array_test ${2d_array_test} )




