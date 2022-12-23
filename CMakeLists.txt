cmake_minimum_required(VERSION 3.18)
project(main CXX)

include (CheckFunctionExists)
CHECK_FUNCTION_EXISTS(timespec_get HAVE_TIMESPEC_GET)
CHECK_FUNCTION_EXISTS(clock_gettime HAVE_CLOCK_GETTIME)


add_executable(main main.cpp)

target_compile_definitions(${PROJECT_NAME}
  PUBLIC
    $<$<BOOL:${HAVE_TIMESPEC_GET}>:HAVE_TIMESPEC_GET>
    $<$<BOOL:${HAVE_CLOCK_GETTIME}>:HAVE_CLOCK_GETTIME>
)

find_package(ZLIB REQUIRED)
target_link_libraries(main ZLIB::ZLIB)
