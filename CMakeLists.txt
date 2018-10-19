#
# Main target: simple-libfuzzer
#

cmake_minimum_required(VERSION 3.6.0)

add_compile_options(
  # TODO[4] Comment out these coverage options.
  -fsanitize-coverage=trace-pc-guard
  -fsanitize-coverage=trace-cmp
  -fsanitize=fuzzer,address
  -std=c++14
)

link_libraries(
  -fsanitize=address
)

project(simple CXX)
set(CMAKE_VERBOSE_MAKEFILE on)

file(GLOB simple_SOURCES
  simple/*.cpp
)

add_library(simple STATIC
  ${simple_SOURCES}
)

add_executable(simple_harness
  harness.cpp
)

target_link_libraries(simple_harness
  simple
  -fsanitize=fuzzer
  -fuse-ld=lld
)
