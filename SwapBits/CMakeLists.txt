cmake_minimum_required(VERSION 3.25.1)
project (SwapBits VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Program
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/config.hpp.in ${CMAKE_CURRENT_SOURCE_DIR}/include/config.hpp)
file(GLOB TARGET_SRCS src/*.cpp)
add_executable(swapbits ${TARGET_SRCS})
target_include_directories(swapbits PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Test
file(GLOB TEST_SRCS tests/*.cpp)
list(REMOVE_ITEM TARGET_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/swapbits.cpp")
find_package(Catch2 REQUIRED)
add_executable(swapbits_test ${TEST_SRCS} ${TARGET_SRCS})
target_link_libraries(swapbits_test Catch2::Catch2WithMain)
target_include_directories(swapbits_test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")