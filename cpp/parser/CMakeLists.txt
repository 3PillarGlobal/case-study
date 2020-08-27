project(parser)
cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 11)

add_executable(parser_test test/test_parser.cpp src/parser.cc src/logger.cc)
target_include_directories(parser_test PRIVATE 
                           "${PROJECT_SOURCE_DIR}/external"
                           "${PROJECT_SOURCE_DIR}/src")
