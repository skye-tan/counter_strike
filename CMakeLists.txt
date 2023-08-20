cmake_minimum_required(VERSION 3.10)
project(MahsanProject)

set(CMAKE_CXX_STANDARD 14)
set(weapon_lib_test FALSE)
set(exception_lib_test FALSE)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(libs/googletest)
add_subdirectory(src)
add_subdirectory(tests)
