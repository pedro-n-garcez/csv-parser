cmake_minimum_required(VERSION 2.8)
project(csv-parser)
project(food-inspections)

include_directories(.)
include(gtest.cmake)

find_package(Threads)
set (CMAKE_CXX_STANDARD 17)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -Werror -pthread")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif()

add_executable(csv-parser 4col_parser/main.cpp 4col_parser/parser.cpp)
add_executable(csv-parser-test 4col_test/test.cpp 4col_parser/parser.cpp)

add_executable(food-inspections food_inspections/main.cpp parser.cpp)

target_link_libraries(csv-parser-test gtest ${CMAKE_THREAD_LIBS_INIT})