
cmake_minimum_required(VERSION 3.4)
project(MahsanProject)

set(CMAKE_CXX_STANDARD 14)
set_property(GLOBAL PROPERTY CMAKE_CXX_COMPILER_LAUNCHER ccache)

set(enable_testing FALSE)
set(enable_testing FALSE CACHE BOOL "A user-specified option to enable unit testing.")
if(${enable_testing})
    message("Testing Mode On")
else()
    message("Testing Mode Off")
endif()

include_directories(${PROJECT_SOURCE_DIR}/include
                    ${PROJECT_SOURCE_DIR}/include/Exceptions
)

add_subdirectory(src)

if(${enable_testing})
    add_subdirectory(libs/googletest)
    add_subdirectory(tests)
endif()
