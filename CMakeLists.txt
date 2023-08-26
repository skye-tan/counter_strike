cmake_minimum_required(VERSION 3.10)
project(MahsanProject)

set(CMAKE_CXX_STANDARD 14)

set(enable_testing OFF CACHE BOOL "An user-specified option for testing the classes.")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)

if(${enable_testing})
    add_subdirectory(libs/googletest)
    add_subdirectory(tests)
endif()
