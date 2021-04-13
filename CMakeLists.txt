cmake_minimum_required(VERSION 2.8)
project(csv-parser)

include_directories(.)
include(gtest.cmake)

find_package(Threads)
set (CMAKE_CXX_STANDARD 11)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -pthread")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif()

add_executable(csv-parser src/main.cpp parser.cpp)

add_executable(csv-parser-test test/test.cpp src/parser.cpp.cpp)
target_link_libraries(csv-parser-test gtest ${CMAKE_THREAD_LIBS_INIT})