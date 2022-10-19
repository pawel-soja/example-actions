cmake_minimum_required(VERSION 3.18)
project(main CXX)

add_executable(main main.cpp)

find_package(ZLIB REQUIRED)
target_link_libraries(main ZLIB::ZLIB)
