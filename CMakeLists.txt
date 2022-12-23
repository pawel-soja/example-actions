cmake_minimum_required(VERSION 3.18)
project(main CXX)

include (CheckFunctionExists)
include (CheckSymbolExists)

CHECK_FUNCTION_EXISTS(timespec_get HAVE_TIMESPEC_GET)
CHECK_FUNCTION_EXISTS(clock_gettime HAVE_CLOCK_GETTIME)

CHECK_SYMBOL_EXISTS(timespec_get HAVE_TIMESPEC_GET_SYMBOL)
CHECK_SYMBOL_EXISTS(clock_gettime HAVE_CLOCK_GETTIME_SYMBOL)

add_executable(main main.cpp)

target_compile_definitions(${PROJECT_NAME}
  PUBLIC
  $<$<BOOL:${HAVE_TIMESPEC_GET}>:HAVE_TIMESPEC_GET>
  $<$<BOOL:${HAVE_CLOCK_GETTIME}>:HAVE_CLOCK_GETTIME>
  $<$<BOOL:${HAVE_TIMESPEC_GET_SYMBOL}>:HAVE_TIMESPEC_GET_SYMBOL>
  $<$<BOOL:${HAVE_CLOCK_GETTIME_SYMBOL}>:HAVE_CLOCK_GETTIME_SYMBOL>
)

find_package(ZLIB REQUIRED)
target_link_libraries(main ZLIB::ZLIB)
