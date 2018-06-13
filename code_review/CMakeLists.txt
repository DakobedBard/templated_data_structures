cmake_minimum_required(VERSION 2.8)

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

set(four_elements   four_elements.cpp )
add_executable(four_elements ${four_elements} )




