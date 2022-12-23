cmake_minimum_required(VERSION 3.18)
project(main CXX)

include (CheckFunctionExists)
include (CheckLibraryExists)

CHECK_LIBRARY_EXISTS(rt clock_gettime "" HAVE_CLOCK_GETTIME)
if (NOT HAVE_CLOCK_GETTIME)
   set(CMAKE_EXTRA_INCLUDE_FILES time.h)
   CHECK_FUNCTION_EXISTS(clock_gettime HAVE_CLOCK_GETTIME)
   SET(CMAKE_EXTRA_INCLUDE_FILES)
endif()

CHECK_LIBRARY_EXISTS(rt timespec_get "" HAVE_TIMESPEC_GET)
if (NOT HAVE_TIMESPEC_GET)
   set(CMAKE_EXTRA_INCLUDE_FILES time.h)
   CHECK_FUNCTION_EXISTS(timespec_get HAVE_TIMESPEC_GET)
   SET(CMAKE_EXTRA_INCLUDE_FILES)
endif()


add_executable(main main.cpp)

target_compile_definitions(${PROJECT_NAME}
  PUBLIC
    $<$<BOOL:${HAVE_TIMESPEC_GET}>:HAVE_TIMESPEC_GET>
    $<$<BOOL:${HAVE_CLOCK_GETTIME}>:HAVE_CLOCK_GETTIME>
)

find_package(ZLIB REQUIRED)
target_link_libraries(main ZLIB::ZLIB)
