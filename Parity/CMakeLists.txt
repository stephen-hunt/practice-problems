cmake_minimum_required(VERSION 3.25.1)
project (Parity VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Program
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/config.hpp.in ${CMAKE_CURRENT_SOURCE_DIR}/include/config.hpp)
file(GLOB TARGET_SRCS src/*.cpp)
add_executable(parity ${TARGET_SRCS})
target_include_directories(parity PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Test
file(GLOB TEST_SRCS tests/*.cpp)
list(REMOVE_ITEM TARGET_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/parity.cpp")
find_package(Catch2 REQUIRED)
add_executable(parity_test ${TEST_SRCS} ${TARGET_SRCS})
target_link_libraries(parity_test Catch2::Catch2WithMain)
target_include_directories(parity_test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")