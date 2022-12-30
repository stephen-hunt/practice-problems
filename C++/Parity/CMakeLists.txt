cmake_minimum_required(VERSION 3.25.1)

project (Parity VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

configure_file(include/config.hpp.in include/config.hpp)

set(PARITY_SRCS ${Parity_SOURCE_DIR}/src/parity.cpp)

add_executable(parity ${PARITY_SRCS})

target_include_directories(parity PUBLIC "${CMAKE_SOURCE_DIR}/include")
